"""
This code is the implementation of a program that
prompts the user for a zip code and prints the name and
population of the corresponding town.

It would be easier to use some module for parsing html like Beautiful Soup
but for demonstration purposes this code is refining the raw html manually
"""

import urllib

def search_name_and_population(zip_code):
    """Search for population and name of city given the zipcode number """

    desired_url = "http://www.uszip.com/zip/"+zip_code
    print desired_url
    conn = urllib.urlopen(desired_url)

    city_name = ""
    population = ""
    for idx, line in enumerate(conn):

        current_line = line.strip()

        # Get name of the city
        if idx == 155:
            try:
                temp_string = current_line.split("<a")
                temp_string = temp_string[0].split("<h2><strong>")
                temp_string = temp_string[1].split(",")
                city_name = temp_string[0]
                print city_name
            except:
                city_name = ""

        # Get population
        if idx == 161:
            try:
                temp_string = current_line.split("<dt>Total population</dt><dd>")
                temp_string = temp_string[1].split("<span")
                population = temp_string[0]
                print population
            except:
                city_name = ""

    result_obj = {"city_name": city_name, "population": population}

    if city_name != "":
        print "The name of the city is %s and the population is %s" % (result_obj["city_name"], result_obj["population"])
    else:
        print "Information not found"

    return result_obj

def main():
    """Main Function of the Program"""

    #Test Cases
    print "Test Cases"
    city_info = search_name_and_population("02492")

    assert city_info["city_name"] == "Needham"
    assert city_info["population"] == "19,931"

    city_info2 = search_name_and_population("12545")

    assert city_info2["city_name"] == "Millbrook"
    assert city_info2["population"] == "4,763"

    city_info3 = search_name_and_population("34857")
    print city_info3
    assert city_info3["city_name"] == ""
    assert city_info3["population"] == ""

    number = raw_input("Please enter a zip code: ")
    search_name_and_population(number)

if __name__ == '__main__':
    main()



