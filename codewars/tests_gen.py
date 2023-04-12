from pathlib import Path
from argparse import ArgumentParser

def get_tests(file_name):
    with Path(file_name).open('r') as file:
        tests = file.readlines()
    return tests

def parse_args():
    parser = ArgumentParser()
    parser.add_argument('file', 
                        help='file containing sample tests from codewars.')
    return parser.parse_args()

def main():
    args = parse_args()
    file_name = args['file']
    tests = get_tests(file_name)
    parsed_tests = parse_tests(tests)
    print_tests(parsed_tests)

if __name__ == '__main__':
    main()