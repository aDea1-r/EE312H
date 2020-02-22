from sys import argv
import re


CONTROL_LOG_PREFIX = "===>"

def get_file_lines(path):
    result = []
    with open(path) as f:
        result = f.readlines()
    result = map(lambda x: x.rstrip(), result)
    result = filter(lambda x: len(x) > 0, result)
    return result

def diff(regex_lines, output_lines):
    main_result = 0
    if len(regex_lines) != len(output_lines):
        print CONTROL_LOG_PREFIX, "different number of lines: expected length: %d, actual length: %d"\
            % (len(regex_lines), len(output_lines))
        main_result = 1

    for i in range(min(len(regex_lines), len(output_lines))):
        rline, oline = regex_lines[i], output_lines[i]
        if not re.search(rline, oline, re.IGNORECASE):
            print CONTROL_LOG_PREFIX, "line %d (zero based): output \"%s\" doesn't match the expected \"%s\""\
                % (i, oline, rline)
            if main_result == 0:
                main_result = 2

    if len(regex_lines) > len(output_lines):
        print CONTROL_LOG_PREFIX, "omitted lines:"
        for line in regex_lines[len(output_lines):] :
            print line

    if len(output_lines) > len(regex_lines):
        print CONTROL_LOG_PREFIX, "extra lines:"
        for line in output_lines[len(regex_lines):] :
            print line

    return main_result

def main():
    if len(argv) < 3:
        print "usage: python xxx.py regex_file_path output_file_path"
        exit(1)

    print CONTROL_LOG_PREFIX, "case sensitivity and blank lines are being ignored."

    regex_file_path, output_file_path = argv[1:3]
    regex_lines = get_file_lines(regex_file_path)
    output_lines = get_file_lines(output_file_path)
    main_result = diff(regex_lines, output_lines)
    exit(main_result)

main()
