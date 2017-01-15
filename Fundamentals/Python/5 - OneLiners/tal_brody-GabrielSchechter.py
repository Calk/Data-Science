"""
This code is the implementation of a function
a function that receives a string, and returns a new string in which each character of the
original string is doubled
"""

def  double_function (word):
    """a function that receives a string, and returns a new string in which each character of the
        original string is doubled"""
    return ''.join([x+x for x in word])

def main():
    """Main Function of the Program"""

    assert double_function('wow') == "wwooww"
    assert double_function('ITC is cool!') == "IITTCC  iiss  ccooooll!!"

    print double_function('wow')
    print double_function('ITC is cool!')

if __name__ == '__main__':
    main()

