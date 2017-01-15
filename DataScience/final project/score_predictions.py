import numpy as np

def score_rmspe(Y, Y_hat):
    """score_rmspe(Y, Y_hat) -> score

    Computes the score for a prediction.

    Args:
        Y - list of true values (floating point)
        Y_hat - list of predictions
    Returns:
        Root Mean Square Percentage Error (RMSPE): sqrt(mean(((y - y_hat)/y)**2))
    """
    Y = np.asarray(Y, dtype=np.float)
    Y_hat = np.asarray(Y_hat, dtype=np.float)

    Y_filtered = Y[Y != 0]
    Y_hat_filtered = Y_hat[Y != 0]

    return np.mean(((Y_filtered - Y_hat_filtered) / Y_filtered)**2)**0.5
