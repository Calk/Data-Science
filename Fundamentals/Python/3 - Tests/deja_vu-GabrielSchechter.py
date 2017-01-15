"""
This code is the implementation of the exercise
Jean Valjean but this time encapsulating the validation
within a function in order to write asserts in the main function.
"""

EXPECTED_LENGTH = 5

def validate_user_input_is_valid(number):
    """Function that validates the input of the user defining that it should be a number bigger than 10000"""
    if number.isdigit() and int(number)/10000 >= 1 and len(number) == EXPECTED_LENGTH:
        return True
    else:
        return False

def sum_digits_of_number(number):
    return sum(map(int, str(number)))

def analyze_number_digits():
    """This code has the purpose to show the execution of
    a funtion that  receives a 5-digit number, using the function raw_input.
     The function should print out:
    1) The number itself.
    2) The number's digits, one by one.
    3) The sum of the digits."""

    # Some Input Validation Tests
    assert validate_user_input_is_valid("10000")
    assert validate_user_input_is_valid("14235")
    assert not validate_user_input_is_valid("123")
    assert not validate_user_input_is_valid("0")
    assert not validate_user_input_is_valid("00001")
    assert not validate_user_input_is_valid("09999")
    assert not validate_user_input_is_valid("758765")

    number = ""
    while not validate_user_input_is_valid(number):
        number = raw_input("Please enter your number: ")

    print "You entered the number: %s" % number

    print "The digits of this number are:",
    list_of_digits = ""
    for digit in number:
        list_of_digits += digit + ', '
    print list_of_digits[:-2]

    # Some Summing Validation Tests
    assert sum_digits_of_number("10000") == 1
    assert sum_digits_of_number("11111") == 5
    assert sum_digits_of_number("10103") == 5
    assert sum_digits_of_number("55533") == 21

    result = sum_digits_of_number(number)
    print "The sum of the digits is: %s." % result
    return result

def main():
    """Main Function of the Program"""
    analyze_number_digits()

if __name__ == '__main__':
    main()


