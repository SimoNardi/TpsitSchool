import threading
import  socket
from db import Db

HOST = "127.0.0.1"
PORT = 8080
NumberOfClient = 0


class ClientThread(threading.Thread):
    def __init__(self, ip, skt):
        global NumberOfClient
        threading.Thread.__init__(self)
        self.ip_address = ip
        self.socket = skt
        NumberOfClient = NumberOfClient+1
        print("Client ", NumberOfClient, " connected with the ip: ", ip)

    def run(self):
        File_object = open(r"output.txt", "w")
        global NumberOfClient
        print("connection from: ", self.ip_address)
        msg = ''
        while True:
            with Db() as db:
                operations = db.operation()
                NumbOfOperation = db.NumbOfOper()

            for n in range(NumbOfOperation[0]):
                self.socket.send(bytes(str(operations[n]), 'UTF-8'))
                answer = self.socket.recv(2048).decode()
                if answer == -1:
                    print(f"{operations[n]} = error from {self.ip_address} - {PORT}")
                    File_object.write(f"{operations[n]} = error from {self.ip_address} - {PORT}\n")
                else:
                    print(f"{operations[n]} = {answer} from {self.ip_address} - {PORT}")
                    File_object.write(f"{operations[n]} = {answer} from {self.ip_address} - {PORT}\n")
            self.socket.send(bytes(str("exit"), 'UTF-8'))
        print("Client at ", self.ip_address, "disconnected...")
        NumberOfClient = NumberOfClient-1

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
print("server started...")
print("waiting for client input...")
while True:
    server.listen(1)
    port, ip = server.accept()
    newThread = ClientThread(ip, port)
    newThread.start()