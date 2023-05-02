#!/usr/bin/env python3
"""script that reads stdin line by line and computes metrics:"""


import sys

s_codes = {}
total_size = 0
counter = 0

for line in sys.stdin:
    try:
        _, _, _, _, _, sc, file_size = line.split()
        sc = int(sc)
        file_size = int(file_size)

        if method != 'GET' or path != '/projects/260':
            continue

        total_size += file_size

        if sc.isdigit():
            s_codes[sc] = s_codes.get(sc, 0) + 1

        counter += 1

        if counter % 10 == 0:
            print(f'Total file size: {total_size}')
            for code in sorted(s_codes.keys()):
                print(f'{code}: {s_codes[code]}')
            print()

    except ValueError:
        pass

    except KeyboardInterrupt:
        print(f'Total file size: {total_size}')
        for code in sorted(s_codes.keys()):
            print(f'{code}: {s_codes[code]}')
        sys.exit(0)

print(f'Total file size: {total_size}')
for code in sorted(s_codes.keys()):
    print(f'{code}: {s_codes[code]}')
