

#CC = /opt/trendchip/mips-linux-3.4.6/bin/mips-linux-gcc
CC=$(CROSS)gcc
LIB = #-L/home/kidiger/trendchip/source_s_port/apps/dare/apps

all : msgLib
	$(CC) msgClient.c -o msgClient $(LIB) -L./ -lmsgLib
	$(CC) msgServer.c -o msgServer $(LIB) -L./ -lmsgLib

msgLib : msgLib.c msgdopt.c libmxml/XmlApi.c \
	usr.h \
	msgLib.h
	$(CC) -c msgLib.c 
	$(CC) -c msgdopt.c
	$(CC) -c libmxml/XmlApi.c -L../mxml-2.4 -lmxml 
	$(CC) -o libmsgLib.so -shared msgLib.o msgdopt.o XmlApi.o
	#sudo cp libmsgLib.so /usr/lib/
	#cp libmsgLib.so $(LIB_INSTALL)

clean :
	rm -rf libmsgLib.so
	rm -rf *.o
	rm -rf msgClient
	rm -rf msgServer
	rm -rf $(LIB_INSTALL)/libmsgLib.so

install :
	#cp msgClient msgServer ../../filesystem/DareGlobal/bin/
	cp libmsgLib.so $(LIB_INSTALL)
	cp libmsgLib.so $(LIB_INSTALL)/../lib

