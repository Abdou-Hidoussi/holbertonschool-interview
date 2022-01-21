#!/usr/bin/python3
""" prime number """


def isWinner(x, nums):
    """ prime number """

    if not nums or x < 1:
        return None

    big = max(nums)
    filters = [True for _ in range(max(big + 1, 2))]
    for x in range(2, int(pow(big, 0.5)) + 1):
        if not filters[x]:
            continue
        for y in range(x * x, big + 1, x):
            filters[y] = False

    filters[0] = filters[1] = False

    c = 0
    for x in range(len(filters)):
        if filters[x]:
            c += 1
        filters[x] = c

    p_1 = 0
    for big in nums:
        p_1 += filters[big] % 2 == 1
    if p_1 * 2 == len(nums):
        return None

    if p_1 * 2 > len(nums):
        return "Maria"
    return "Ben"
