"""
This code is the implementation of a function
a function that recieves a number, and returns a list of all of the numbers from 1 to the given
number that are divisable by 4 (without a remainder).
"""

def  four_dividers (number):
    """a function that recieves a number, and returns a list of all of the numbers from 1 to the given
    number that are divisable by 4 (without a remainder)."""
    return [x for x in range(1, number+1) if x % 4 == 0]

def main():
    """Main Function of the Program"""

    assert four_dividers(5) == [4]
    assert four_dividers(3) == []

    print four_dividers(5)
    print four_dividers(3)

if __name__ == '__main__':
    main()

