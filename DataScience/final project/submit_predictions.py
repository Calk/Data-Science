import urllib
import urllib2
import numbers

URL = 'http://35.156.80.27:8000/evaluate'
EXPECTED_NUM_PREDICTIONS = 46830

def submit(predictions_list, team_ID):
    assert len(predictions_list) == EXPECTED_NUM_PREDICTIONS
    for yh in predictions_list:
        isinstance(yh, numbers.Real)

    Y_hat_csv = ','.join(map(str, predictions_list))
    post_data = urllib.urlencode({'Y_hat_csv': Y_hat_csv, 'team_ID': team_ID})
    response = urllib2.urlopen(URL, post_data)
    text_response = response.read()
    return float(text_response)
