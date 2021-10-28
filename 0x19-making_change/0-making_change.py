#!/usr/bin/python3
"""
Determine the fewest number of coins
needed to meet a given amount
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins
    needed to meet a given amount
    """
    sum = 0
    coins.sort(reverse=True)
    for x in coins:
        if total // x != 0:
            sum += total // x
            total = total % x
    if total == 0:
        return sum
    else:
        return -1
