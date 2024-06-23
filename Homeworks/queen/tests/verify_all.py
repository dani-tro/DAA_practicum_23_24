import sys
import os

if len(sys.argv) != 4:
    print('Wrong number of arguments')
    exit(0)


PROGRAM = sys.argv[1]
FIRST_TEST = int(sys.argv[2])
LAST_TEST = int(sys.argv[3])

for test in range(FIRST_TEST, LAST_TEST+1):
    pcall = PROGRAM + " " + str(test)
    os.system(pcall)
    