"""
This code is the implementation of a function that receives a number and determines whether it is prime
"""

def  sum_of_digits (number):
    """ function that receives a number and determines whether it is prime"""
    return sum([int(x) for x in str(number)])

def main():
    """Main Function of the Program"""

    assert sum_of_digits(104) == 5
    assert sum_of_digits(111111) == 6

    print sum_of_digits(111111)
    print sum_of_digits(104)

if __name__ == '__main__':
    main()

