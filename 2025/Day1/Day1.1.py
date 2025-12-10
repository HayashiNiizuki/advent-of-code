import os

if __name__ == "__main__":
    with open("input.txt", "r") as f:
        lines = f.readlines()

    loc = 50
    times = 0
    for action in lines:
        dis = int(action[1:]) % 100
        if action[0] == "L":
            loc -= dis
        elif action[0] == "R":
            loc += dis

        if loc < 0:
            loc += 100

        elif loc > 99:
            loc -= 100

        if loc == 0:
            times += 1

    print(times)
