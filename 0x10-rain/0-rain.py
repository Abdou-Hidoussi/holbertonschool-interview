#!/usr/bin/python3
""" calculate  square units of water
will be retained after it rains  """


def rain(walls):
    """ calculate  square units of water
    will be retained after it rains  """
    space = 0
    water = 0
    if walls is None:
        return 0
    if walls == []:
        return 0
    for y in range(len(walls)):
        if walls[y] != 0:
            break
    for x in range(y + 1, len(walls)):
        if walls[x] == 0:
            space += 1
        else:
            if walls[x] < walls[y]:
                water += walls[x] * space
            else:
                water += walls[y] * space
            y = x
            space = 0
    return water
