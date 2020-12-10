import socket

server_ip = "192.168.0.117"
server_ip_personal = "192.168.0.112"
port = 7000

def client(data):
    c = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    c.connect((server_ip,port))

    print(data)
    #data = "Error: Traceback send failed"
    c.sendall(data.encode())
    c.close()

def server():
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    s.bind((server_ip_personal,port))
    s.listen()
    c,address = s.accept()

    raw_data = c.recv(4096)

    s.close()

    print(str(address) + '>> ' + str("messaggio ricevuto:"))

    client(raw_data.decode())


if __name__ == "__main__":
    while True9:
        server()
