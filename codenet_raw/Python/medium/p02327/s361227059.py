def new_max_rectangle(array):
    max_area = 0

    for i in range(1, max(array) + 1):
        mini_height = 99999
        count = 0
        for j in range(i, max(array) + 1):
            if array[j] == 0:
                if j == i:
                    mini_height = array[j]
                break
            else:
                mini_height = mini_height if array[j] > mini_height else array[j]
                count += 1

        max_area = count * mini_height if count * mini_height > max_area else max_area

    return max_area


def algorithm():
    r, c = map(int, input().split(' '))

    ans_array = [0 for _ in range(c)]
    input_matrix = []

    for _ in range(r):
        input_matrix.append(list(map(int, input().split(' '))))

    largest_square = 0

    for i in range(r):
        for j in range(c):
            ans_array[j] = ans_array[j] + 1 if input_matrix[i][j] == 0 else 0
        m = new_max_rectangle(ans_array)
        largest_square = largest_square if largest_square > m else m

    print(largest_square)


def main():
    algorithm()


if __name__ == '__main__':
    main()