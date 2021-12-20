CC = gcc
CFLAGS = -Wall -Werror
LDFLAGS = -lSDL2 -lm

TEST_VEC3FILES = src/vec3.o src/utils.o tests/test_vec3.o

TEST_VEC3 = test_vec3

$(TEST_VEC3): $(TEST_VEC3FILES)
	$(CC) -o $(TEST_VEC3) $(TEST_VEC3FILES) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TEST_VEC3FILES) $(TEST_VEC3) *~
