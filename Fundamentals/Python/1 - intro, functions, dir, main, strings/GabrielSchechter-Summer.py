"""
This code shows the implementation of a function named 'summer' that
also sums the members of a list, but can work with both strings and numbers,
"""

def summer(list):
    """ function named 'summer' that also sums the members of a list, but can work with both strings and numbers,"""

    is_list_of_numbers = type(list[0]) is float or type(list[0]) is int
    if(is_list_of_numbers):
        output = 0
        for digit in list:
            output += digit
    else:
        output = ""
        for character in list:
            output += character

    print output


def main():
    """This is the main function  """
    summer([1, 2, 5, 6])
    summer([3, 0.5, 1.6])
    summer(['a', 'd', 'b', 'f'])


if __name__ == '__main__':
    main()


