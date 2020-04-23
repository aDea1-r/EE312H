import sys
import re

def num_uninitialized(valgrind_output):
    return valgrind_output.count('Use of uninitialised value')

def num_invalid_read(valgrind_output):
    return valgrind_output.count('Invalid read of size');

def num_invalid_write(valgrind_output):
    return valgrind_output.count('Invalid write of size');

def num_invalid_free(valgrind_output):
    return valgrind_output.count('Invalid free() / delete / delete[] / realloc()');

def num_memory_leak(valgrind_output):
    substring='definitely lost: '
    if valgrind_output.count(substring) > 0:
        line = re.search(substring+'.*', valgrind_output, re.M|re.I).group(0)
        return int(line.split()[2].replace(',',''))
    else:
        return 0

filename = sys.argv[1]
content = ''

with open(filename) as f:
    content = f.read()

output_string = str(num_uninitialized(content)) + " " \
        + str(num_invalid_read(content)) + " " \
        + str(num_invalid_write(content)) + " " \
        + str(num_invalid_free(content)) + " " \
        + str(num_memory_leak(content)) + " "
print(output_string)
