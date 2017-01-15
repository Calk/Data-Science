"""
This code is the implementation of a function
avg_diff that computes the average difference between 2 number lists
"""

def  avg_diff (list1, list2):
    """avg_diff that computes the average difference between 2 number lists"""
    return sum([abs(a - b) for a, b in zip(list1, list2)]) / float(len(list1))

def main():
    """Main Function of the Program"""
    assert avg_diff([1, 2, 3, 4], [1, 1, 1, 1]) == 1.5
    assert avg_diff([1, 1, 1, 1], [1, 1, 1, 1]) == 0

    print avg_diff([1, 2, 3, 4], [1, 1, 1, 1])

if __name__ == '__main__':
    main()


