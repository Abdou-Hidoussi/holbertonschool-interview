#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    method that determines if a given data set
    represents a valid UTF-8 encoding.
    """
    count = 0
    for elm in data:
        if count == 0:
            if (elm >> 5) == 0b110:
                count = 1
            elif (elm >> 4) == 0b1110:
                count = 2
            elif (elm >> 3) == 0b11110:
                count = 3
            elif (elm >> 7):
                return False
        else:
            if (elm >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
