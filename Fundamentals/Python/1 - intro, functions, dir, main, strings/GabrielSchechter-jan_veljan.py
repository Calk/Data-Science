"""
This code is the implementationof the exercise
Jean Valjean of the first lesson about Python
"""

def analyze_number_digits():
    """This code has the purpose to show the execution of
    a funtion that  receives a 5-digit number, using the function raw_input.
     The function should print out:
    1) The number itself.
    2) The number's digits, one by one.
    3) The sum of the digits."""

    number = raw_input("Please enter your number: ")

    print "You entered the number: %s" % number

    print "The digits of this number are:",
    list_of_digits = ""
    for digit in number:
        list_of_digits += digit + ', '
    print list_of_digits[:-2]

    print "The sum of the digits is: %s." % sum(map(int, str(number)))

def main():
    """Main Function of the Program"""
    analyze_number_digits()

if __name__ == '__main__':
    main()


