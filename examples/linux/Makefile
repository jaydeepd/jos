CC=gcc
CCFLAGS=-Wall
LDFLAGS=-lrt
SOURCES=$(wildcard *.c) $(wildcard ../../core/*.c) $(wildcard ../../ports/*/*.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=example_app

INCLUDES=-I../../core/				\
		 -I../../ports/				\
		 -I../../config/			\
		 -I../../examples/linux

all: objdir $(OBJECTS) $(TARGET)
	@echo $(SOURCES)

$(TARGET):
	$(CC) -o $@ obj/*.o $(LDFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ -c $<
	mv $@ obj/
	
objdir: clean
	mkdir -p obj/

clean:
	rm -rf obj/ $(TARGET)
