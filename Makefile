CC=gcc
CFLAGS=-Wall
TARGET=prog
SOURCES=prog1.c libreria.c

prog: $(SOURCES)
	$(CC) $(SOURCES) -o $(TARGET)

clean:
	rm $(TARGET)