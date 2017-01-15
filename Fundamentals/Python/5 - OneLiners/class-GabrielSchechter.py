"""
This code is the demonstration of how to
print the complete current datetime
"""

from datetime import datetime

def test():
    print [x ** 2 for x in xrange(10) if x % 2 == 0]

    list1 = [1, 2, 3]
    list2 = [2, 3, 6, 7]
    print [x ** 2 for x in list1 if x in list2]

def main():
    """Main Function of the Program"""
    test()

if __name__ == '__main__':
    main()


