#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """
    a method that determines if all the boxes can be opened.
    """

    new = []
    for x in boxes[0]:
        new.append(x)

    for x in range(len(boxes)):
        if x in new:
            for y in range(len(boxes[x])):
                if not boxes[x][y] in new:
                    new.append(boxes[x][y])

    if len(new) is len(boxes) - 1:
        return True
    else:
        return False
