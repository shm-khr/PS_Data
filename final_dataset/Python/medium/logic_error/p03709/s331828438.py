from collections import OrderedDict
import heapq
import fileinput

# def file_iterator(file_name):
#     with open(file_name) as f:
#         for line in f:
#             yield line

iterator = fileinput.input()
# iterator = file_iterator('input2.txt')



MAX_VELOCITY = 1000000000
MAX_N = 200000
MODULO =  1000000007


# class Takahashi(object):
#     def __init__(self, position, velocity):
#         self.position = position
#         self.velocity = velocity
#         self.block_start = None
#         self.block_end = None

#     def set_block(self, start, end):
#         self.block_start = start
#         self.block_end = end

#     def __repr__(self):
#         return str({
#             'position': self.position,
#             'velocity': self.velocity,
#             'block_start': self.block_start,
#             'block_end': self.block_end
#         })


# HANDLE INPUT
n = int(iterator.next())
takahashis = [None] * n

for i in xrange(n):
    x, v = iterator.next().split()
    takahashis[i] = (int(x), int(v))
takahashis.sort()


# maps a block index (0...N-1) to start (or end) of its corresponding block.
block_starts = [None] * n
block_ends = [None] * n
# maps a position (0...N-1) to an index of a block, which starts (or ends) there.
block_starting_positions = OrderedDict()
block_ending_positions = OrderedDict()



def turn_input_into_blocks():
    # number_finder = FirstNumberFinder(
    #     sequence=(t[1] for t in takahashis),
    #     reversed_sequence=(t[1] for t in reversed(takahashis)),
    #     n=n)
    seen = [False] * n
    rightmost_smaller_velocity_index = 0
    sorted_velocities = [(t[1], i) for i, t in enumerate(takahashis)]
    sorted_velocities.sort(reverse=True)

    for i, velocity in enumerate((t[1] for t in takahashis)):
        #print i, rightmost_smaller_velocity_index
        #print seen
        # Was there a larger velocity before already?
        if seen[i]:
            continue
        # OK, this is the largest one so far.

        block_start = i
        # Determine end of block involving the smallest unseen velocity.
        # Also, get index of rightmost smaller velocity and mark as seen
        first = True
        while sorted_velocities and velocity >= sorted_velocities[-1][0]:
            upcoming_smaller_velocity, upcoming_smaller_velocity_index = sorted_velocities.pop()
            seen[upcoming_smaller_velocity_index] = True
            rightmost_smaller_velocity_index = max(
                rightmost_smaller_velocity_index, upcoming_smaller_velocity_index)
            if first:
                block_end = rightmost_smaller_velocity_index
                first = False

        #print rightmost_smaller_velocity_index
        #print sorted_velocities

        block_starts[i] = block_start
        block_ends[i] = block_end
        # check if already have a longer block ending at same position
        previous_longer_block = block_ending_positions.get(block_end)
        if previous_longer_block is not None:
            block_starting_positions
            del block_starting_positions[block_starts[previous_longer_block]]
        block_starting_positions[block_start] = i
        block_ending_positions[block_end] = i

    sentinel = [n - 1] if not n - 1 in block_ending_positions else []
    return heapq.merge(block_starting_positions, block_ending_positions, sentinel)



# possibilities[i] indicates the number of possibilities
# from block with indices 0 to i.
possibilities = [None] * (n + 1)

def compute_possibilities():
    # initialization hack, since index starts at 0
    possibilities[-1] = 1

    active_blocks = []
    def move_active_cursor_forwards(last_position, current_position):
        block_id = block_ending_positions.get(last_position)
        if block_id is not None:
            active_blocks.remove(block_id)
        block_id = block_starting_positions.get(current_position)
        if block_id is not None:
            active_blocks.append(block_id)

    def move_active_cursor_backwards(current_position, last_position):
        block_id = block_ending_positions.get(last_position)
        if block_id is not None:
            active_blocks.append(block_id)
        block_id = block_starting_positions.get(current_position)
        if block_id is not None:
            active_blocks.remove(block_id)

    def empty_gap_possibilities(possibilities_before_gap, gap_length):
        return (possibilities_before_gap * 2**gap_length) % MODULO

    def uniform_piece_possibilities_1(possibilities_at_first_index, gap_length):
        """Uniform piece was started by a new block."""
        return (possibilities_at_first_index * (2**gap_length - 1)) % MODULO

    def uniform_piece_possibilities_2(
        possibilities_before_gap, possibilities_at_first_index, gap_length):
        """Uniform piece was started by a block being removed."""
        p0, p1 = possibilities_before_gap, possibilities_at_first_index
        return (p1 * (2**gap_length - 1) - p0 * (2**gap_length - 2)) % MODULO

    def one_step_change_possibilities(i, possibilities, active_blocks):
        # SET i to AOKI
        # Possibilities we have guaranteed
        result = possibilities[i - 1]
        #print 'b'
        #print possibilities
        #print i
        #print result

        # Other possibilities, we might get by zeroing blocks going into i
        for block_id in active_blocks:
            block_start = block_starts[block_id]
            if block_start < i:
                result += possibilities[block_start - 1]

        # SET i NOT to AOKI (or explore if possible)
        # Do all active blocks move more to left? (Includes zero blocks.)
        all_blocks_move_to_left = True
        for block_id in active_blocks:
            block_start = block_starts[block_id]
            if block_start >= i:
                all_blocks_move_to_left = False
        if all_blocks_move_to_left:
            result += possibilities[i - 1]

        return result % MODULO


    # #print block_starting_positions
    # #print block_ending_positions

    POSITION_TYPE_START = 1
    POSITION_TYPE_END = 2
    last_position = -1
    last_position_type = None
    for position in blocks_iterator:
        # Sometimes a block has size 1.
        if position <= last_position:
            continue


        move_active_cursor_forwards(last_position, position)


        #print 'start'
        #print position, last_position
        #print active_blocks
        #print '---'


        indices_moved = position - last_position
        p = possibilities[last_position]
        i = position

        # PROCESS BLOCK START
        if position in block_starting_positions:
            if indices_moved > 1:
                # no blocks in earlier gap
                if len(active_blocks) == 1:
                    #print 'a'
                    possibilities[i - 1] = empty_gap_possibilities(p, indices_moved - 1)
                # one or more long blocks in earlier gap
                elif last_position_type == POSITION_TYPE_START:
                    possibilities[i - 1] = uniform_piece_possibilities_1(p, indices_moved)
                elif last_position_type == POSITION_TYPE_END:
                    move_active_cursor_backwards(position, last_position)
                    move_active_cursor_forwards(last_position, last_position + 1)
                    p1 = one_step_change_possibilities(last_position + 1, possibilities, active_blocks)
                    move_active_cursor_forwards(last_position + 1, position)
                    possibilities[i - 1] = uniform_piece_possibilities_2(p, p1, indices_moved - 1)

            # compute i-th position too now.
            possibilities[i] = one_step_change_possibilities(i, possibilities, active_blocks)
            last_position = i
            last_position_type = POSITION_TYPE_START

        # PROCESS BLOCK END
        elif position in block_ending_positions:
            if indices_moved == 1:
                possibilities[i] = one_step_change_possibilities(i, possibilities, active_blocks)
            elif last_position_type == POSITION_TYPE_START:
                possibilities[i] = uniform_piece_possibilities_1(p, indices_moved + 1)
            elif last_position_type == POSITION_TYPE_END:
                move_active_cursor_backwards(position, last_position)
                move_active_cursor_forwards(last_position, last_position + 1)
                p1 = one_step_change_possibilities(last_position + 1, possibilities, active_blocks)
                move_active_cursor_forwards(last_position + 1, position)
                #print '%', p, p1, indices_moved
                possibilities[i] = uniform_piece_possibilities_2(p, p1, indices_moved)

            last_position = i
            last_position_type = POSITION_TYPE_END

        # PROCESS SENTINEL
        else:
            possibilities[i] = empty_gap_possibilities(p, indices_moved)
            last_position = i
            last_position_type = None



blocks_iterator = turn_input_into_blocks()


#print block_starting_positions
#print block_ending_positions

compute_possibilities()

#print possibilities
print possibilities[n-1]
