from typing import Optional, List

with open("input.txt", "r") as f:
    lines = f.readlines()


class Range:
    def __init__(self, start, end) -> None:
        self._start = start
        self._end = end

    def contain(self, a: int):
        return a <= self._end and a >= self._start

    def union(self, b: "Range") -> Optional["Range"]:
        return merge(self, b)

    def canUnion(self, b: "Range") -> bool:
        return not (self.start > b.end + 1 or self.end + 1 < b.start)

    @property
    def start(self):
        return self._start

    @property
    def end(self):
        return self._end


def merge(a: "Range", b: "Range") -> Optional["Range"]:
    if a.start > b.end or a.end < b.start:
        return None

    else:
        return Range(min(a.start, b.start), max(a.end, b.end))


class Ranges:
    def __init__(self, rs: List["Range"] = []) -> None:
        self._rs = rs

    def merge(self, r: "Range"):
        to_merge = [r]
        to_merge_id = []

        for i, sr in enumerate(self._rs):
            if sr.canUnion(r):
                to_merge.append(sr)
                to_merge_id.append(i)

        pos = 0
        if to_merge_id:
            pos = to_merge_id[0]
            to_merge_id.reverse()
            for i in to_merge_id:
                self._rs.pop(i)

        self._rs.insert(
            pos, Range(min([x.start for x in to_merge]), max([x.end for x in to_merge]))
        )

    def contain(self, a: int) -> bool:
        for r in self._rs:
            if r.contain(a):
                return True

        return False

    def totalIds(self):
        return sum([(a.end - a.start + 1) for a in self._rs])


rs = Ranges()
for line in lines:
    if "-" in line:
        start, end = line.split("-")
        rs.merge(Range(int(start), int(end)))


print(rs.totalIds())
