import os

if __name__ == "__main__":
    with open("input.txt", "r") as f:
        string = f.readline()

    floor = 0
    for c in string:
        if c == "(":
            floor += 1
        elif c == ")":
            floor -= 1

    print(floor)
