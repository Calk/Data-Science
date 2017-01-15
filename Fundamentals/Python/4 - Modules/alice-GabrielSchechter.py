"""
For this exercise you must learn the tutorial of the regex module in Python by yourself
go to the tutorial on http://users-cs.au.dk/kmt/AP2012/RegularExpressions.html' and answer
the questions in each section  hand in a file containing the code you used to answer each question.
"""

import re

def search_name_and_population(zip_code):
    """Search for population and name of city given the zipcode number """
    print ""

def main():
    """Main Function of the Program"""

    # open a file
    f = open("alice_full.txt", "r")

    # read all lines into a list:
    text = f.readlines()

    # close the f
    f.close()

    print "\nwith a full stop character: \n"
    regexp = re.compile(r"\.")
    print "".join([line for line in text if regexp.search(line)])
    print """\nthat contain a three letter string consisting of "s", then any character, then "e" (such as "she"): \n"""
    regexp = re.compile(r"\b[sS][a-zA-Z][eE]\b")
    print "".join([line for line in text if regexp.search(line)])

    print """\nthat contain a word of any length that starts with "s" and ends with "e": \n"""
    regexp = re.compile(r"\b[s][a-zA-Z]*[e]\b")
    print "".join([line for line in text if regexp.search(line)])

    print """\nthat start with "a": \n"""
    regexp = re.compile(r"\b[a][a-zA-Z]*\b")
    print "".join([line for line in text if regexp.search(line)])

    print """\nwith an odd digit followed by an even digit : \n"""
    regexp = re.compile(r"\b[13579][02468]")
    print "".join([line for line in text if regexp.search(line)])

    print """\nwith a date in the form "April 14. 2011". That is, a word with a capital first letter, a space, one or two digits, a dot, a space and four digits : \n"""
    regexp = re.compile(r"\b[A-Z][a-zA-Z]*\s[0-9][0-9]?\.\s[0-9]{4}")
    print "".join([line for line in text if regexp.search(line)])

    print """\nthat do not contain "the": \n"""
    regexp = re.compile(r"^(?!.*(\bthe\b|\bThe\b)).*$")
    print "".join([line for line in text if regexp.search(line)])

    print """\nthat Matches Alice's Adventures in Wonderland (commonly shortened to Alice in Wonderland:\n"""
    regexp = re.compile(r"(Alice's Adventures).*(Alice in Wonderland)")
    for line in text:
        match = regexp.search(line)
        if match:
            print "Match: %s, Line: %s" % (match.group(0), line)

    print """\nthat Matches Alice's Adventures in Wonderland:\n"""
    regexp = re.compile(r"(Alice's Adventures in Wonderland)")
    for line in text:
        match = regexp.search(line)
        if match:
            print "Match: %s, Line: %s" % (match.group(0), line)

    print """\nthat Write a regular expression that matches two capitalized words like a name. Then retrieve and print the first name and the last name for each such match: \n"""
    regexp = re.compile(r"([A-Z]\w*)\s([A-Z]\w*)")

    for line in text:
        result = regexp.search(line)
        if result:
            print "First Name: ", result.group(1),
            print "Last Name: ", result.group(2)

    print """\nthat Replace all instances of "the " with "the bloody":\n"""
    regexp = re.compile(r"\b(the|The)\b")
    for line in text:
        print regexp.sub("the bloody", line)

    print """\nthat Delete all words with more than 3 characters. Hint: deleting means replacing with nothing:\n"""
    regexp = re.compile(r"\b(\w{4,})\b")
    for line in text:
        print regexp.sub(" ", line),


    print """\nPrint all lines in the alice.txt file that contain double characters like middle or good.: \n"""
    regexp = re.compile(r"(\w)\1")

    for line in text:
        result = regexp.search(line)
        if result:
            print line,

if __name__ == '__main__':
    main()



