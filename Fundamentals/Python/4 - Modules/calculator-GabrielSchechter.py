"""
This code shows the implementation of a function named 'summer' that
also sums the members of a list, but can work with both strings and numbers,
"""

import math

def circle_area(radius):
    """ Computes the area of a circle according to it's radius"""
    a = radius ** 2 * math.pi
    return a

def angle(first_line, second_line):
    """ Computes the angle between two lines: l1=m1x+n1, l2=m2x+n2"""
    temp_denominator = 1 + first_line[0]*second_line[0]
    if temp_denominator != 0:
        temp_calc = (first_line[0] - second_line[0])/(1 + first_line[0]*second_line[0])
        angle = math.degrees(math.atan(temp_calc))
        return abs(angle)
    else:
        return 90


def triangle_area(ray1, ray2, angle):
    """Computes the area of a triangle given the
    length of 2 of its rays and the angle between them"""

    area = ray1*ray2*abs(math.sin(angle))/2
    return area

def main():
    """This is Main Function"""

    assert round(circle_area(1.0 / math.sqrt(math.pi))) == 1.0
    assert angle((1, 1), (-1, 1)) == 90
    assert triangle_area(2, 2, math.pi / 2) == 2

    print circle_area(1.0 / math.sqrt(math.pi))
    print angle((1, 1), (-1, 1))
    print triangle_area(2, 2, math.pi/2)


if __name__ == '__main__':
    main()


