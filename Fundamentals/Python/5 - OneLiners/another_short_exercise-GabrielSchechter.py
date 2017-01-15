"""
This code is the implementation of a function
trim_whitespace that receives a list of strings and returns a similar list in which
the strings have no whitespaces at the end (spaces, tabs and newlines).
"""

def  trim_whitespace (list):
    """trim_whitespace that receives a list of strings and returns a similar list in which
    the strings have no whitespaces at the end (spaces, tabs and newlines)."""
    return [x.rstrip() for x in list]

def main():
    """Main Function of the Program"""
    assert trim_whitespace((["hello", "hello there ", "\t\tthis is a cool exercise\t\t", "\nwow \n", "cool \n\n"])) == ['hello', 'hello there', '\t\tthis is a cool exercise', '\nwow', 'cool']

    print trim_whitespace((["hello", "hello there ", "\t\tthis is a cool exercise\t\t", "\nwow \n", "cool \n\n"]))

if __name__ == '__main__':
    main()




