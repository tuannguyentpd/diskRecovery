CC = g++
PWD := $(shell pwd)
CFLAGS = -fPIC
LDFLAGS = -shared

RM = rm -f

SRCS := $(wildcard *.h)
OBJS := $(patsubst %.h,%.o,$(SRCS))
TARGETS := $(patsubst %.h,%.so,$(SRCS))

#all: $(TARGETS) main
#all: main run_console_output
all: main CPPlib.so run_redirect_ouput_to_file

%.so:%.o
	$(CC) $(INC) $(LDFLAGS) $(CFLAGS) -o $@ $^

main: main.cpp $(OBJS)
	$(CC) -o $@ $^

run_redirect_ouput_to_file:
	sudo ./main > manual_data.txt

run_console_output:
	sudo ./main

CPPlib.so:$(OBJS) main.cpp
	$(CC) -fPIC -Wall -Wextra -O2 -g -o $@ $^

clean:
	$(RM) $(PWD)/*.so $(PWD)/*.o main *.out