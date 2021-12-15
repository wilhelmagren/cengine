CC = gcc
CFLAGS = -Wall
LDFLAGS =

OBJFILES = src/vecs.o src/polygon.o src/mesh.o

TARGET = cengine

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
