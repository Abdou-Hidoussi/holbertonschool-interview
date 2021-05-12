#!/usr/bin/python3
def minOperations(n):
    count = 0
    for i in range(2, n):
        while (n % i == 0):
            count += i
            n = n / i
    return count
