import socket
SERVER = "192.168.88.106"
PORT = 6000
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((SERVER, PORT))
while True:
    out_data = input("inserisci il messaggio: ")
    client.sendall(out_data.encode())
    in_data = client.recv(1024)
    print("From Server :", in_data.decode(), "\n\r")
    if out_data == 'end':
        break

client.close()