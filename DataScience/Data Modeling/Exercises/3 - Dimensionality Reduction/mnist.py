import os
import numpy as np
import struct
import gzip
import matplotlib.pyplot as plt

_MNIST_TRAIN_IMAGES_FILENAME = 'train-images-idx3-ubyte.gz'
_MNIST_TRAIN_LABELS_FILENAME = 'train-labels-idx1-ubyte.gz'
_DIGIT_HEIGHT = 28
_DIGIT_WIDTH = 28
_DIGIT_N_PIXELS = _DIGIT_HEIGHT * _DIGIT_WIDTH

def _read_gzip(filename):
    return gzip.open(filename, 'rb').read()

def _read_mnist_images_file(filename):
    unzipped_contents = _read_gzip(filename)
    (magic, num_images, height, width) = struct.unpack('>llll', unzipped_contents[:16])
    assert magic == 2051
    assert height == _DIGIT_HEIGHT
    assert width == _DIGIT_WIDTH
    images_array = np.fromstring(unzipped_contents[16:], np.uint8).reshape((num_images, (height*width)))
    return images_array.astype(np.float64)/255.
    
def _read_mnist_labels_file(filename):
    unzipped_contents = _read_gzip(filename)
    (magic, num_images) = struct.unpack('>ll', unzipped_contents[:8])
    assert magic == 2049
    labels_array = np.fromstring(unzipped_contents[8:], np.uint8)
    assert len(labels_array) == num_images
    return labels_array

def read_mnist_training_set(directory):
    '''Read the MNIST training set of handwritten digits

    Arguments:
        directory (string) - location of the files "train-images-idx3-ubyte.gz" and "train-labels-idx1-ubyte.gz"

    Returns:
        X (np.array, dtype = uint8, shape = (n, _DIGIT_N_PIXELS)) - MNIST training set digits, each row represents a flattened image of a digit.
        Y (np.array, dtype = uint8, shape = (n,)) - MNIST training set labels, its values are 0, 1, ... 9.
    '''
    X = _read_mnist_images_file(os.path.join(directory, _MNIST_TRAIN_IMAGES_FILENAME))
    Y = _read_mnist_labels_file(os.path.join(directory, _MNIST_TRAIN_LABELS_FILENAME))
    assert Y.shape == (X.shape[0],)
    assert X.shape[1] == _DIGIT_N_PIXELS
    return X,Y

def montage(digits):
    '''Display images on a square matrix using matplotlib.pyploy.imshow

    Arguments:
        digits (sequence of np.array) - MNIST digits to display, given as flat vectors.
    '''
    n_images = len(digits)

    ncols = int(np.ceil(np.sqrt(n_images)))
    nrows = int(np.ceil(n_images / float(ncols)))
    
    montage_image = np.zeros((nrows*_DIGIT_HEIGHT, ncols*_DIGIT_WIDTH))
    for (i, digit_image) in enumerate(digits):
        # assert digit_image.shape == (_DIGIT_N_PIXELS,)
        x = i % ncols
        y = i / ncols
        montage_image[_DIGIT_HEIGHT*y:_DIGIT_HEIGHT*(y+1), _DIGIT_WIDTH*x:_DIGIT_WIDTH*(x+1)] = digit_image.reshape((_DIGIT_HEIGHT,_DIGIT_WIDTH))

    plt.imshow(montage_image, cmap = plt.cm.gray_r)
