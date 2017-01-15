"""
This code is the demonstration of how to
use the module ArgParse framework
"""
import argparse

def add(n1, n2):
    """Adds the two numbers and prints the result"""
    return n1 + n2

def multiply(n1, n2):
    """Multiplies the two numbers and prints the result"""
    return n1 * n2

def subtract(n1, n2):
    """Substracts the second number from the first and prints the result."""
    return n1 - n2

def divide(n1, n2):
    """ Divides the first number by the second number and prints the result"""
    return n1 / n2

def main():
    """Main Function of the Program"""

    assert add(2, 2) == 4
    assert multiply(3, 6) == 18
    assert divide(6, 3) == 2
    assert subtract(6, 3) == 3

    #Parse Arguments passed by Users
    parser = argparse.ArgumentParser()
    choices = ['add', 'multiply', 'subtract', 'divide']
    parser.add_argument('action', nargs='+', choices=choices, help='Action that specifies the operation')
    parser.add_argument("first_number", type=float,  help="first_number")
    parser.add_argument("second_number", type=float, help="second_number")
    parser.add_argument("-w", "--optArg", action="count", default=0)
    args = parser.parse_args()

    if args.optArg:
        print "Good Morning"

    if args.action[0] == "add":
        print add(args.first_number, args.second_number)
    elif args.action[0] == 'multiply':
        print multiply(args.first_number, args.second_number)
    elif args.action[0] == 'subtract':
        print subtract(args.first_number, args.second_number)
    elif args.action[0] == "divide":
        print divide(args.first_number, args.second_number)

if __name__ == '__main__':
    main()


