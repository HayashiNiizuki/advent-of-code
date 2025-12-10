import os


def is_invalid(num: int):
    num_s = str(num)
    lens = len(num_s)
    for l in range(1, lens // 2 + 1):
        if lens % l == 0 and (num_s[:l] * (lens // l) == num_s):
            return True

    return False


with open("input.txt", "r") as f:
    sections = f.read().split(",")

    sum = 0
    for section in sections:
        head, tail = section.split("-")

        for num in range(int(head), int(tail) + 1):

            if is_invalid(num):
                sum += num

    print(sum)
