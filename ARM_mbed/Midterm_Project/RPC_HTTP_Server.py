import urllib2
import time

while(1):
	ip = '192.168.0.108'
	name = 'ACCControl'
	command = 'run'

	args = '1'
	response = urllib2.urlopen('http://' + ip + '/rpc/' + name + '/' + command + '%20' + " ".join(args))
	line = response.readline()
	print (line)