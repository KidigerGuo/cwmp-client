INCLUDE=-I./ -I./plugin/ -I./mxml-2.4/ -I../OPENSRC/openssl-1.0.1e/include/ -I./xmlapi/
LIBPATH=-L./mxml-2.4/ -L./OPENSRC/openssl-1.0.1e/
LIBS=-lpthread -lmxml -lssl -lcrypto -ldl

CROSS=/usr/bin/
CFLAGS=-g -DWITH_NONAMESPACES -DWITH_COOKIES -O2
CFLAGS+=$(INCLUDE) 
CFLAGS+=$(LIBPATH)
CFLAGS+=-Wl,-rpath=../lib
CLIENT_FLAGS = -DHTTP_GET -DSERVER_CONNECT_RES -DSUPPORT_EMPTYPOST -DBASIC_AUTH -DSUPPORT_EMPTYPOST_REQ -DWITH_OPENSSL -DDIGEST_AUTH -DWITH_IPV6 -DCWMP_TEST

CC=$(CROSS)gcc
AR=$(CROSS)ar
LD=$(CROSS)ld
STRIP=$(CROSS)strip

SOURCE_COMMON = soapC.c stdsoap2.c
SOURCE_XMLAPI = xmlapi/XmlApi.c ./mxml-2.4/libmxml.a
SOURCE_PLUGIN_COMMON = plugin/threads.c plugin/httpget.c plugin/httpform.c
SOURCE_PLUGIN_SSL = plugin/md5evp.c plugin/httpda.c plugin/cacerts.c
SOURCE_CLIENT = soapClient.c soapServer.c cwmpServer.c cwmpClient.c cwmpClientMain.c

ROOTFS=./Rootfs
CONFIG=./Config

all : Libmxml Client

Client: Libmxml
	$(CC) $(CFLAGS) $(CLIENT_FLAGS) $(SOURCE_COMMON) $(SOURCE_XMLAPI) $(SOURCE_PLUGIN_COMMON) $(SOURCE_PLUGIN_SSL) $(SOURCE_CLIENT) -o cwmpClient $(LIBS) 
	$(STRIP) cwmpClient

Libmxml:
	make -C ./mxml-2.4/

clean:
	rm -rf cwmpClient
	make -C ./mxml-2.4/ clean
	rm -rf $(ROOTFS)

install:
	@echo "##########Create Rootfs##########"
	mkdir -p $(ROOTFS)/Apps
	cp cwmpClient $(ROOTFS)/Apps
	cp $(CONFIG) $(ROOTFS)/ -R
	@echo "##########   Finish   ##########"
	
