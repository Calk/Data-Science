""" This program has been adapted for use by GVAHIM
    - the main revisions regard pep8 compliance and use of variable names

Copyright 2010 Google Inc.
Licensed under the Apache License, Version 2.0
http://www.apache.org/licenses/LICENSE-2.0

Google's Python Class
http://code.google.com/edu/languages/google-python-class/

Additional basic list exercises """

# D. Given a list of numbers, return a list where
# all adjacent == elements have been reduced to a single element,
# so [1, 2, 2, 3] returns [1, 2, 3]. You may create a new list or
# modify the passed in list.
def remove_adjacent(nums):

    if(len(nums) > 0):
        newlist = [nums[0]]
        for elem in nums[1:]:
            if (elem != newlist[-1]):
                newlist.append(elem)
    else:
        newlist = nums

    return newlist

# E. Given two lists sorted in increasing order, create and return a merged
# list of all the elements in sorted order. You may modify the passed in lists.
# Ideally, the solution should work in "linear" time, making a single
# pass of both lists.
#
# NOTE - DO NOT use return sorted(sorted1 + sorted2) - that's too easy :-)
#

def linear_merge(sorted1, sorted2):
    result = []
    i = j = 0
    total = len(sorted1) + len(sorted2)
    while len(result) != total:
        if len(sorted1) == i:
            result += sorted2[j:]
            break
        elif len(sorted2) == j:
            result += sorted1[i:]
            break
        elif sorted1[i] < sorted2[j]:
            result.append(sorted1[i])
            i += 1
        else:
            result.append(sorted2[j])
            j += 1
    return result

def test(got, expected):
    """ simple test() function used in main() to print
        what each function returns vs. what it's supposed to return. """
    if got == expected:
        prefix = ' OK '
    else:
        prefix = '  X '
    print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))

def main():
    """ main() calls the above functions with interesting inputs,
        using test() to check if each result is correct or not. """

    print '\nremove_adjacent'
    test(remove_adjacent([1, 2, 2, 3]), [1, 2, 3])
    test(remove_adjacent([2, 2, 3, 3, 3]), [2, 3])
    test(remove_adjacent([]), [])

    print '\nlinear_merge'
    test(linear_merge(['aa', 'xx', 'zz'], ['bb', 'cc']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(linear_merge(['aa', 'xx'], ['bb', 'cc', 'zz']),
         ['aa', 'bb', 'cc', 'xx', 'zz'])
    test(linear_merge(['aa', 'aa'], ['aa', 'bb', 'bb']),
         ['aa', 'aa', 'aa', 'bb', 'bb'])



if __name__ == '__main__':
    main()