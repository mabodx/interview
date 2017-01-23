import socket
import sys

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientsocket.connect(('localhost', 8089))

i = 10
while True:
	i = i - 1
	clientsocket.sendall('12')
	data = clientsocket.recv(16)
    # print 'received "%s"' % data
	print i
	if i < 1:
		break