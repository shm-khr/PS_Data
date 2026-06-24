from collections import OrderedDict, deque
import heapq
import fileinput


MAX_VELOCITY = 1000000000
MAX_N = 200000
MODULO =  1000000007


# class Takahashi(object):
#     __slots__ = ['position', 'velocity', 'block_start', 'block_end', 'seen']

#     def __init__(self, position, velocity):
#         self.position = position
#         self.velocity = velocity
#         self.block_start = None
#         self.block_end = None
#         self.seen = False


n = 0
takahashis = []
velocities = []
# maps a block index (0...N-1) to start (or end) of its corresponding block.
block_starts = []
block_ends = []
seen = []
# all stops we take along the way
block_starting_positions = OrderedDict()
block_ending_positions = OrderedDict()
# possibilities[i] indicates the number of possibilities
# from block with indices 0 to i.
possibilities = []


# HANDLE INPUT
def file_iterator(file_name):
    with open(file_name) as f:
        for line in f:
            yield line


def handle_input(file_name=None):
    if file_name:
        iterator = file_iterator(file_name)
    else:
        iterator = fileinput.input()
    global n
    n = int(next(iterator))
    takahashis[:] = [None] * n
    for i in xrange(n):
        x, v = next(iterator).split()
        takahashis[i] = (int(x), int(v))


def preprocessing():
    takahashis.sort()
    block_starts[:] = [None] * n
    block_ends[:] = [None] * n
    seen[:] = [False] * n
    possibilities[:] = [None] * (n + 1)
    velocities[:] = ((t[1], i) for i, t in enumerate(takahashis))
    velocities.sort()


def turn_input_into_blocks():
    velocity_cursor = -1
    rightmost_smaller_velocity_index = 0

    for i in xrange(n):
        if seen[i]: continue

        # Determine end of block involving the smallest unseen velocity.
        # Also, get index of rightmost smaller velocity and mark as seen
        current_velocity = takahashis[i][1]
        first = True
        while velocity_cursor < n - 1 and current_velocity >= takahashis[velocities[velocity_cursor + 1][1]][1]:
            velocity_cursor += 1
            upcoming_smaller_velocity_index = velocities[velocity_cursor][1]
            seen[upcoming_smaller_velocity_index] = True
            rightmost_smaller_velocity_index = max(
                rightmost_smaller_velocity_index, upcoming_smaller_velocity_index)
            if first:
                block_end = rightmost_smaller_velocity_index
                first = False
        block_starts[i] = i
        block_ends[i] = block_end
        # check if already have a longer block ending at same position
        previous_longer_block = block_ending_positions.get(block_end)
        if previous_longer_block is not None:
            del block_starting_positions[block_starts[previous_longer_block]]
        block_starting_positions[i] = i
        block_ending_positions[block_end] = i

    sentinel = [n - 1] if n - 1 not in block_ending_positions else []
    return heapq.merge(block_starting_positions, block_ending_positions, sentinel)


def build_stops_iterator(stops):
    current_position = None
    while True:
        next_position = next(stops, None)
        if next_position == current_position:
            next_position = next(stops, None)
        current_position = next_position
        if current_position is not None:
            yield current_position
        else:
            break


def compute_possibilities(stops_iterator):
    possibilities[-1] = 1
    active_blocks = deque()
    current_position = 0
    alpha = 0
    while current_position < n:
        # fast track check
        next_position = next(stops_iterator, None)
        indices_to_move = next_position - current_position
        if indices_to_move > 0:
            # fast track for `indices_to_move` rounds where no block starts or ends.
            k, p = indices_to_move, possibilities[current_position - 1]
            possibilities[current_position - 1 + k] = (
                pow(2, k, MODULO) * p + (pow(2, k, MODULO) - 1) * alpha) % MODULO
            # move forward
            current_position += indices_to_move

        # update active blocks
        has_new_block = current_position in block_starting_positions
        if has_new_block:
            active_blocks.append(current_position)
            alpha += possibilities[current_position - 1]

        # compute result
        result = alpha + (2 * possibilities[current_position - 1] if not has_new_block else 0)
        possibilities[current_position] = result % MODULO

        # update active blocks
        if current_position in block_ending_positions:
            block_that_ended = active_blocks.popleft()
            alpha -= possibilities[block_starts[block_that_ended] - 1]

        current_position += 1

    return possibilities[n - 1]


def main():
    handle_input()
    preprocessing()
    stops = turn_input_into_blocks()
    return compute_possibilities(build_stops_iterator(stops))


if __name__ == '__main__':
    print main()
