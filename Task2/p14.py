import socket

def host(ip):
    try:
        hostname=socket.gethostbyaddr(ip)
        return hostname[0]
    except socket.herror as e:
        return str(e)
    
ip=input("Enter the ip address ")
name=host(ip)
if name:
    print(f'The domain name for {ip} is {name}')
else:
    print('error')
