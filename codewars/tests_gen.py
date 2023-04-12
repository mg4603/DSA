from pathlib import Path
from argparse import ArgumentParser
from re import compile

def get_tests(file_name):
    with Path(file_name).open('r') as file:
        tests = file.read()
    return tests

def parse_tests(tests):
    regex = compile('Assert::That\((.+), Equals\((.+)\)\);')
    tests = regex.findall(tests)
    parsed_tests = ''
    for test in tests:
        parsed_tests += 'assert('+test[0]+' == '+test[1]+');\n'
    return parsed_tests

def parse_args():
    parser = ArgumentParser()
    parser.add_argument('file', 
                        help='file containing sample tests from codewars.')
    return parser.parse_args()

def main():
    args = parse_args()
    file_name = args.file
    tests = get_tests(file_name)
    parsed_tests = parse_tests(tests)
    print_tests(parsed_tests)

if __name__ == '__main__':
    main()