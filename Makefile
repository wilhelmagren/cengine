CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL2 -lm

OBJFILES = src/vecs.o src/polygon.o src/mesh.o src/cube_example.o src/draw.o src/mats.o
TARGET = cengine

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	@rm -f $(OBJFILES) $(TARGET) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(OBJFILES) and $(TARGET)"
