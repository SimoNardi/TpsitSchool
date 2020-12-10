import threading
import  socket

HOST = "127.0.0.1"
PORT = 8080


class ClientThread(threading.Thread):
    def __init__(self, ip, skt):
        threading.Thread.__init__(self)
        self.ip_address = ip
        self.socket = skt
        print("New connection added: ", ip)

    def run(self):
        print("connection from: ", self.ip_address)
        msg = ''
        while True:
            data = self.socket.recv(2048)
            msg = data.decode()
            if msg == 'end':
                break
            print("from client: ", msg)
            self.socket.send(bytes(msg,'UTF-8'))
        print("Client at ", self.ip_address, "disconnected...")

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
print("server started...")
print("waiting for client input...")
while True:
    server.listen(1)
    port, ip = server.accept()
    newThread = ClientThread(ip, port)
    newThread.start()
