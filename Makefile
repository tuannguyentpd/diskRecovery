CC = g++
PWD := $(shell pwd)
CFLAGS = -fPIC
LDFLAGS = -shared

RM = rm -f


SRCS := $(wildcard *.h)
OBJS := $(patsubst %.h,%.o,$(SRCS))
#TARGETS := $(patsubst %.h,%.so,$(SRCS))

#all: $(TARGETS) main
all: main

%.so:%.o
#	$(CC) $(INC) $(LDFLAGS) $(CFLAGS) -o $@ $^
	$(CC) $(INC) $(CFLAGS) -o $@ $^

main: main.cpp $(OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) $(PWD)/*.so $(PWD)/*.o main