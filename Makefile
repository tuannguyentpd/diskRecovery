CC = g++
PWD := $(shell pwd)
CFLAGS = -fPIC
LDFLAGS = -shared

RM = rm -f

SRCS := $(wildcard *.h)
OBJS := $(patsubst %.h,%.o,$(SRCS))
TARGETS := $(patsubst %.h,%.so,$(SRCS))

#all: $(TARGETS) main
#all: main CPPlib.so run_console_output
#all: main CPPlib.so run_redirect_ouput_to_file
#all: main run_redirect_ouput_to_file
# all: main run_console_output
all: main

%.so:%.o
	$(CC) $(INC) $(LDFLAGS) $(CFLAGS) -o $@ $^

main: main.cpp $(OBJS)
	$(CC) -o $@ $^

run_redirect_ouput_to_file:
	sudo ./main > treeDir.txt

run_console_output:
	sudo ./main

CPPlib.so:$(OBJS) main.cpp
	$(CC) -fPIC -Wall -Wextra -O2 -g -o $@ $^

Wrapping:
	g++ -o Wrapper.so Wrapper.cpp -std=c++11 -fPIC -shared -Wall -Wextra `python3.6-config --includes --libs` -lboost_python3

clean:
	$(RM) $(PWD)/*.so $(PWD)/*.o main *.oute b8 20
