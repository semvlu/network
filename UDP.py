from socket import *
serverName = '127.0.0.1'
serverPort = 65432
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Input lowercase sentence:')
clientSocket.sendto(message.encode(),(serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(65432)
print(modifiedMessage.decode())
clientSocket.close()