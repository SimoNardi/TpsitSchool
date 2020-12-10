import socket
SERVER = "127.0.0.1"
PORT = 8080
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((SERVER, PORT))
print("the connection was successful", "\n\r")
while True:
    operation = client.recv(1024).decode()
    print("From Server: ", operation, "\n\r")
    if operation == 'exit':
        print("richiesta di uscita")
        break
    try:
        result = eval(operation)            #gestione errori: restituisce -1 se l'operaziuone non è esuguibile
    except ValueError:
        print("That operation is not correct!")
        break
    except SyntaxError:
        print("The syntax is not correct!")
        result = -1
    print("Answer: ", result, "\n\r")
    client.sendall(str(result).encode())
client.close()