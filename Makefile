CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL2 -lm

OBJFILES = src/vecs.o src/polygon.o src/mesh.o src/draw.o src/mats.o
CUBEFILES = src/vecs.o src/polygon.o src/mesh.o src/cube_example.o src/draw.o src/mats.o

TARGET = cengine
EXAMPLE_CUBE = cube

$(EXAMPLE_CUBE): $(CUBEFILES)
	$(CC) -o $(EXAMPLE_CUBE) $(CUBEFILES) $(CFLAGS) $(LDFLAGS)

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) $(LDFLAGS)

clean:
	@rm -f $(OBJFILES) $(TARGET) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(TARGET) obj files:\n $(OBJFILES)"
	@rm -f $(CUBEFILES) $(EXAMPLE_CUBE) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(EXAMPLE_CUBE) obj files:\n $(CUBEFILES)"
