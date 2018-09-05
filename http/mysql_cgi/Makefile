ROOT_PATH=$(shell pwd)
LIB=$(ROOT_PATH)/../lib
INCLUDE=-I$(LIB)/include
MYSQL_LIB=-L$(LIB)/lib
LD_FLAGS=-lmysqlclient

.PHONY:all
all:insert_cgi select_cgi

insert_cgi:insert_cgi.cpp comm.cpp
	g++ -o $@ $^ $(INCLUDE) $(MYSQL_LIB) $(LD_FLAGS)
select_cgi:select_cgi.cpp comm.cpp
	g++ -o $@ $^ $(INCLUDE) $(MYSQL_LIB) $(LD_FLAGS)

.PHONY:clean
clean:
	rm -f insert_cgi select_cgi
