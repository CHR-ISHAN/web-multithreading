
CURR_PATH=$(shell pwd)
src=httpd.c
bin=httpd
cc=gcc
LDFLAGS=-lpthread

$(bin):$(src)
	$(cc) -o $@ $^ $(LDFLAGS)
.PHONY:clean
clean:
	rm -f $(bin)
