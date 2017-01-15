"""
This code is the implementation of a function that recieves a number and determines whether it is prime
"""

def  is_prime (number):
    """function that recieves a number and determines whether it is prime"""
    return all(number % i for i in range(2, number))

def main():
    """Main Function of the Program"""

    assert is_prime(42) == False
    assert is_prime(43) == True
    assert is_prime(3) == True
    assert is_prime(9) == False

    print is_prime(42)
    print is_prime(43)

if __name__ == '__main__':
    main()

