"""
This code has the purpose to show some examples of slicing
strings in Python.
"""

def show_slice_examples():
    """Print some examples of slicing"""

    HELLO_WORLD = "Hello, my name is Inigo Montoya"

    print HELLO_WORLD[0:5]
    print HELLO_WORLD[7:14]
    print HELLO_WORLD[0::2]
    print HELLO_WORLD[0::2][1:10]

def main():
    show_slice_examples()

if __name__ == '__main__':
    main()


