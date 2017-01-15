"""
This code shows the implementation of a function named 'copy_paste' that
receives a filename(as an absolute path) and copies it to a given folder.
"""
from os.path import basename, isfile, isdir, join

START_POINT = 0
CONTENT_INDEX = 1

def copy_paste(src, dest):
    """  function named copy_paste, that receives a filename
    (as an absolute path) and copies it to a given folder. """

    origin1 = r"C:\Users\itc_admin\Desktop\ITC\Python\hello.txt"
    origin2 = r"C:\Users\itc_admin\Desktop\ITC\Python\photo1.jpg"
    destination = r"C:\Users\itc_admin\Desktop\ITC"

    assert isfile(origin1)
    assert isfile(origin2)
    assert isdir(destination)

    obj = copy_file(src)
    paste_file(obj, dest)

def copy_file(path):
    """ copy_file(string)
    Return all file data."""
    return basename(path), file(path, 'rb', START_POINT).read()

def paste_file(file_object, path):
    """ paste_file(tuple, string)
    Create all file data."""
    file(join(path, file_object[START_POINT]), 'wb', START_POINT).write(file_object[CONTENT_INDEX])

def main():
    """This is the main function  """

    origin1 = r"C:\Users\itc_admin\Desktop\ITC\Python\hello.txt"
    origin2 = r"C:\Users\itc_admin\Desktop\ITC\Python\photo1.jpg"
    destination = r"C:\Users\itc_admin\Desktop\ITC"

    copy_paste(origin1, destination)
    copy_paste(origin2, destination)

if __name__ == '__main__':
    main()


