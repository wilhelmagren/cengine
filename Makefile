CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL2

OBJFILES = src/vecs.o src/polygon.o src/mesh.o src/main.o
CFILES = src/vecs.c src/polygon.c src/mesh.c src/main.c

TARGET = cengine

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	@rm -f $(OBJFILES) $(TARGET) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(OBJFILES) and $(TARGET)"
