import itertools
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix
from sklearn.metrics import precision_score
import matplotlib.cm


"""
Plots the confusion matrix and prints the derived accuracy parameter from it.
Also prints the accuracy, recall and precision.
Params:
cm - a confusion matrix (numpy 2-dim array)
classes - list of the different classes corresponding to the y labels in the data
normalize - Boolean, whether to normalize the matrix or not. Default: False
title - String, title for the plot. Default: 'Confusion Matrix'
cmap - colormap object, used to visualize the matrix. Default: Blues
"""
def plot_confusion_matrix(cm, classes,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):

    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        print("Normalized confusion matrix")
    else:
        print('Confusion matrix, without normalization')

    print(cm)

    thresh = cm.max() / 2.
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        plt.text(j, i, cm[i, j],
                 horizontalalignment="center",
                 color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.show()
    print "Accuracy: " + str(sum(np.diag(cm)) / float(sum(sum(cm))))
    print "Precision: " + str(cm[1,1]/float(sum(cm[1,:])))
    print "Recall: " + str(cm[1,1]/float(sum(cm[:,1])))

"""
Given tagged data and a prediction model, plots the decision boundary for the data.
X - the data that the prediction model will try to predict
Y - the true labels of the X data
model - the prediction model
"""
def decision_boundary(X, Y, model):
    h = 100
    x_min, x_max = X[[0]].min()[0] - 1, X[[0]].max()[0] + 1
    y_min, y_max = X[[1]].min()[0] - 1, X[[1]].max()[0] + 1
    xx, yy = np.meshgrid(np.linspace(x_min, x_max, h), np.linspace(y_min, y_max, h))
    Z = model.predict(np.c_[xx.ravel(), yy.ravel()])
    Z = np.array([1 if x == 'virginica' else 2 for x in Z])
    Z = Z.reshape(xx.shape)
    plt.contourf(xx, yy, Z, cmap=matplotlib.cm.Paired)

    # Plot also the training points
    orZ = np.array([1 if y == 'virginica' else 2 for y in Y]).reshape(X[[0]].shape)
    plt.scatter(X[[0]], X[[1]], c=orZ, cmap=matplotlib.cm.Paired)
    plt.xlabel(X.columns[0])
    plt.ylabel(X.columns[1])
    plt.show()
