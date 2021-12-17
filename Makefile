CC = gcc
CFLAGS = -Wall
LDFLAGS = -lSDL2 -lm

OBJFILES = src/vecs.o src/polygon.o src/mesh.o src/draw.o src/mats.o
CUBEFILES = src/vecs.o src/polygon.o src/mesh.o src/draw.o src/mats.o src/example_cube.o 
PYRAMIDFILES = src/vecs.o src/polygon.o src/mesh.o src/draw.o src/mats.o src/example_pyramid.o

TARGET = cengine
EXAMPLE_CUBE = cube
EXAMPLE_PYRAMID = pyramid

$(EXAMPLE_PYRAMID): $(PYRAMIDFILES)
	@echo "\e[0;32m[*]\e[0m  Compiling binary for $(EXAMPLE_PYRAMID) example..."
	$(CC) -o $(EXAMPLE_PYRAMID) $(PYRAMIDFILES) $(CFLAGS) $(LDFLAGS)

$(EXAMPLE_CUBE): $(CUBEFILES)
	@echo "\e[0;32m[*]\e[0m  Compiling binary for $(EXAMPLE_CUBE) example..."
	$(CC) -o $(EXAMPLE_CUBE) $(CUBEFILES) $(CFLAGS) $(LDFLAGS)

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) $(LDFLAGS)

clean:
	@rm -f $(OBJFILES) $(TARGET) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(TARGET) obj files:\n $(OBJFILES)"
	@rm -f $(CUBEFILES) $(EXAMPLE_CUBE) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(EXAMPLE_CUBE) obj files:\n $(CUBEFILES)"
	@rm -f $(PYRAMIDFILES) $(EXAMPLE_PYRAMID) *~
	@echo "\e[0;32m[*]\e[0m  Cleaning $(EXAMPLE_PYRAMID) obj files:\n $(PYRAMIDFILES)"
