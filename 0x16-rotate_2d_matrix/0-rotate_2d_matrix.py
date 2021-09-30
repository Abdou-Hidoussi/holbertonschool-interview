#!/usr/bin/python3
"""
Task 0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotation """
    s = len(matrix)
    new = []
    for i in range(s):
        for j in range(s):
            new.append(matrix[s - j - 1][i])
    n = 0
    for i in range(s):
        for j in range(s):
            matrix[i][j] = new[n]
            n += 1
