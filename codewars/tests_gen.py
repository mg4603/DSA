

def main():
    args = parse_args()
    file_name = args['file']
    tests = get_tests()
    parsed_tests = parse_tests(tests)
    print_tests(parsed_tests)

if __name__ == '__main__':
    main()