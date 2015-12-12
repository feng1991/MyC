
# Memcached

## readme
- It is my mini version of memcached.
- It uses udp socket,in other words,it uses ip+port+udp to communicate.
- server.o file and client.o file is compiled with gcc in ubantu.
- It has server and client. 1.Server should be kept running. 2. Client uses "set name feng" to set "name:feng",a key-value,to the server and uses "get name" to get the value of the key named "name" in the server.

## To do
- Add input limit in case of error
- Use muti-thread to response
- Use LRU to reuse the stored key-values
- Finish dll for php,which support muti-memcached
