#!/usr/bin/python3

""" Function to find perimiter of an island """

def island_perimeter(grid):
    """ Function to find perimiter of an island """
    count = 0
    for x in range(len(grid)):
        for y in range(len(grid)):
            if grid[x][y] == 1:
                count += 2
                break;
    new_grid = []
    for i in range(len(grid)):
        new_grid.append(grid[i][::-1])
    grid = new_grid
    for x in range(len(grid)):
        for y in range(len(grid)):
            if grid[x][y] == 1:
                count += 2
                break;
    return (count)
