#!/usr/bin/python3
import sys
size = 0
show = 0
count = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}

for line in sys.stdin:
    line = line.split(" ")
    if len(line) > 2:
        status = line[-2]
        file_size = int(line[-1])
        if status in count:
            count[status] += 1
        size += file_size

        show += 1
        if show == 10:
            print("File size: {:d}".format(size))
            for key, value in sorted(count.items()):
                if value != 0:
                    print("{}: {:d}".format(key, value))
            show = 0
