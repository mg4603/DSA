from argparse import ArgumentParser
from shutil import copytree
from pathlib import Path

def parse_args():
    parser = ArgumentParser()
    parser.add_argument('template', help='folder of templates')
    parser.add_argument('name', help='question folder name')
    return parser.parse_args()

def main():
    args = parse_args()

    des_folder = Path(args.name)
    des_folder.mkdir(parents=True, exist_ok=True)

    template_folder = Path(args.template)
    
    copytree(template_folder, des_folder, dirs_exist_ok=True)
    

if __name__ == '__main__':
    main()