import os

if __name__ == "__main__":
    with open("input.txt", "r") as f:
        lines = f.readlines()

    loc = 50
    times = 0

    for action in lines:
        dis = int(action[1:])
        if dis == 0:
            continue
        paths = []

        if action[0] == "L":
            for i in range(dis):
                paths.append(loc - i - 1)
        elif action[0] == "R":
            for i in range(dis):
                paths.append(loc + i + 1)

        for p in paths:
            if p % 100 == 0:
                times += 1

        loc = paths[-1] % 100

    print(times)
