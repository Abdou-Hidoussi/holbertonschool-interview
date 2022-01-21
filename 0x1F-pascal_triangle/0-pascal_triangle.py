#!/usr/bin/python3
"""Pascal Triangle module"""


def pascal_triangle(n):
    """function def pascal_triangle(n):
    that returns a list of lists of integers
    representing the Pascal’s triangle of n
    """
    if n <= 0:
        return []

    tri = []
    for x in range(n):
        row = [1] * (x + 1)
        for y in range(x - 1):
            row[y + 1] = tri[x - 1][y] + tri[x - 1][y + 1]
        tri.append(row)
    return tri
