#!/usr/bin/env python3

import sys

if __name__ == '__main__':
    with open(sys.argv[1], 'w') as fd:
        fd.write('__version__ = "' + sys.argv[2] + '"\n')
