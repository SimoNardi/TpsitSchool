import socket

ip_mio = '192.168.0.112'
port = 7000
ip_server = '192.168.0.117'
raw_data=0


def receiver():
    global raw_data
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    server.bind((ip_mio,port))

    Data, address = server.recvfrom(4096)

    print(str(address)+'>> ' + str("messaggio ricevuto:"))
    print(Data.decode())

    raw_data=Data.decode()

    server.close()


def sender():
    global raw_data
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    msg = raw_data

    client.sendto(msg.encode(), (ip_server, port))

    client.close()

if __name__ == "__main__":
    receiver()
    sender()