#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""


def go_again(boxes, check):
    """
    a method that determines if the operation will repeat.
    """
    again = False
    for y in range(len(boxes)):
        if len(check) > y:
            if check[y] is True:
                for x in boxes[y]:
                    if len(check) > x:
                        if check[x] is not True and len(check) > x:
                            check[x] = True
                            if y > x:
                                again = True
    return again


def canUnlockAll(boxes):
    """
    a method that determines if all the boxes can be opened.
    """

    check = []
    for x in range(len(boxes)):
        check.append(False)

    check[0] = True

    again = False

    for y in range(len(boxes)):
        if len(check) > y:
            if check[y] is True:
                for x in boxes[y]:
                    if len(check) > x:
                        if check[x] is not True and len(check) > x:
                            check[x] = True
                            if y > x:
                                again = True

    while (again):
        again = go_again(boxes, check)

    if False in check:
        return False
    else:
        return True
