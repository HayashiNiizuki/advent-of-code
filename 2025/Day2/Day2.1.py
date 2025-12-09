import os

with open("input.txt", "r") as f:
    sections = f.read().split(",")

    sum = 0
    for section in sections:
        head, tail = section.split("-")

        for num in range(int(head), int(tail) + 1):
            num_s = str(num)
            half = int(len(num_s) / 2)
            if num_s[:half] == num_s[half:]:
                sum += int(num_s)

    print(sum)
