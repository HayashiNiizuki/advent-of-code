with open("input.txt", "r") as f:
    lines = f.readlines()

for i in range(len(lines)):
    lines[i] = lines[i].strip()

w = len(lines[0])
h = len(lines)

picks = set()
for x in range(w):
    for y in range(h):
        if lines[x][y] == ".":
            continue

        num = 0
        for i, j in [
            (-1, -1),
            (-1, 0),
            (-1, 1),
            (0, -1),
            (0, 1),
            (1, -1),
            (1, 0),
            (1, 1),
        ]:

            if x + i in range(w) and y + j in range(h) and lines[x + i][y + j] == "@":
                num += 1

        if num < 4:
            picks.add((x, y))

print(len(picks))
