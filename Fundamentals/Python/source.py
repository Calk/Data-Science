"""
This code is the implementation of the bootstrap of socket connection
"""

import socket
import glob
import re

BASE_PATH = "C:\\wwwroot\\"

def start_server_socket_connection():

    """a server that listenes to connections at port 8820 and when its
    responds to the clients requests"""

    server_socket = socket.socket()
    server_socket.bind(('0.0.0.0', 8001))

    regexp_getrequest = re.compile(r'(GET)(.*)(HTTP\/1.1)()')

    #  The int parameter is how many connections can wait in line until they will be accepted by the accpet() method
    server_socket.listen(1)

    while True:

        (client_socket, client_address) = server_socket.accept()
        client_request = client_socket.recv(1024)

        print client_request

        if regexp_getrequest.search(client_request) is not None:

            # Parse page being searched
            parsed_page = client_request.split('/')[1].split("HTTP")[0]
            parsed_page = str(parsed_page).strip(' ')

            # List file present in the
            file_list = glob.glob(BASE_PATH+r"*")
            treated_list = [x.split(BASE_PATH)[1] for x in file_list]

            # Resolve page main object, parameters and extensions
            request_params = {}
            request_object = ""
            extension = ".html"
            if '?' in parsed_page:
                # Parse arguments key and values
                raw_params = parsed_page.split('?')[1]
                all_params = raw_params.split('&')
                for i in xrange(len(all_params)):
                    temp_key = all_params[i].split('=')[0]
                    temp_value = all_params[i].split('=')[1]
                    request_params[temp_key] = temp_value

            if '.' in parsed_page.split('?')[0]:
                extension = '.'+parsed_page.split('?')[0].split('.')[1]

            request_object = parsed_page.split('?')[0].split('.')[0]
            temp_page = (request_object+extension)

            # Case of rendering Index.html
            if request_object == "":
                content = generate_content(BASE_PATH+"index.html", "200 OK")
                client_socket.send(content)
            # Case of another page found
            elif temp_page in treated_list:
                temp_path = BASE_PATH + temp_page
                temp_header = "200 OK"
                optional_param = {}
                if temp_page == "forbidden.html""":
                    temp_header = "403 FORBIDDEN"
                if temp_page == "moved.html""":
                    temp_header = "302 MOVED TEMPORARILY"
                    temp_path = BASE_PATH + "moved_here.html"

                content = generate_content(temp_path, "200 OK", request_params)
                client_socket.send(content)

            # Treat Image Case
            elif request_object == "image":
                images_list = [im for im in treated_list if ('.jpg' in im.lower()) or ('.png' in im.lower())]
                temp_param = request_params['image-name']
                if (temp_param+'.png' in images_list) or (temp_param+'.jpg' in images_list):
                    image = open(BASE_PATH+'test-image.png', 'rb')
                    image_data = image.read()
                    image.close()
                    client_socket.send(image_data)
                else:
                    content = generate_content("", "404 NOT FOUND")
                    client_socket.send(content)

            # Case in which page was not found
            else:
                content = generate_content("", "404 NOT FOUND")
                client_socket.send(content)
                client_socket.close()

    server_socket.close()

def generate_content(page_path, header_code, optional_param = {}):

    file_content = ""
    if len(page_path) > 0:
        # open a file
        f = open(page_path, "r")
        file_content = f.readlines()
        file_content = ''.join(file_content)
        f.close()

    # Handle case with parameters
    if len(optional_param.values()) > 0:
        if page_path == BASE_PATH+"calculate-next.html":
            temp_next_number = str(int(optional_param['num'])+1)
            file_content = file_content.replace('{num}', temp_next_number)
        if page_path == BASE_PATH+"calculate-area.html":
            temp_area = str(float(optional_param['height']) * float(optional_param['width']))
            file_content = file_content.replace('{area}', temp_area)

    # Mount server response
    content_to_send = ""
    headers = """HTTP/1.1""" + header_code + """\r\n"""
    headers += """Content-Length:""" + str(len(file_content)) + """\r\n"""
    content_to_send += headers
    content_to_send += file_content

    return content_to_send

def main():
    """Main Function of the Program"""
    start_server_socket_connection()

if __name__ == '__main__':
    main()



