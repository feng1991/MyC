edit: memcache_lib.c memcache_lib.h use_memcache_lib.c
	gcc memcache_lib.c -fPIC -shared -o libmemcache.so
	gcc use_memcache_lib.c -L. -lmemcache -o use_memcache_lib.o
	sudo cp libmemcache.so /usr/lib/libmemcache.so
clean:
	rm libmemcache.so use_memcache_lib.o
