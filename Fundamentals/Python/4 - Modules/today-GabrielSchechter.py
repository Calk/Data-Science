"""
This code is the demonstration of how to
print the complete current datetime
"""

from datetime import datetime

def print_current_datetime():
    """Print current time in iso format"""
    now = datetime.now()
    print now.strftime("%Y/%m/%d") + 'T' + now.strftime("%H:%M:%S.%f")

def main():
    """Main Function of the Program"""
    print_current_datetime()

if __name__ == '__main__':
    main()


