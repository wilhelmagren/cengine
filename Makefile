CC = gcc
CFLAGS = -Wall -Werror -O3
LDFLAGS = -lSDL2 -lm

TEST_VEC3FILES = src/vec3.o src/utils.o tests/test_vec3.o
TEST_POLYGONFILES = src/vec3.o src/utils.o src/polygon.o tests/test_polygon.o
TEST_MATRICESFILES = src/matrices.o src/utils.o tests/test_matrices.o
TEST_INSTANCEFILES = src/instance.o src/utils.o tests/test_instance.o
TEST_RENDERFILES = src/vec3.o src/utils.o src/polygon.o src/instance.o src/render.o tests/test_render.o

TEST_VEC3 = vec3_test
TEST_POLYGON = polygon_test
TEST_MATRICES = matrices_test
TEST_INSTANCE = instance_test
TEST_RENDER = render_test

$(TEST_VEC3): $(TEST_VEC3FILES)
	$(CC) -o $(TEST_VEC3) $(TEST_VEC3FILES) $(CFLAGS) $(LDFLAGS)

$(TEST_POLYGON): $(TEST_POLYGONFILES)
	$(CC) -o $(TEST_POLYGON) $(TEST_POLYGONFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_MATRICES): $(TEST_MATRICESFILES)
	$(CC) -o $(TEST_MATRICES) $(TEST_MATRICESFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_INSTANCE): $(TEST_INSTANCEFILES)
	$(CC) -o $(TEST_INSTANCE) $(TEST_INSTANCEFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_RENDER): $(TEST_RENDERFILES)
	$(CC) -o $(TEST_RENDER) $(TEST_RENDERFILES) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TEST_VEC3FILES) $(TEST_VEC3) *~
	rm -f $(TEST_POLYGONFILES) $(TEST_POLYGON) *~
	rm -f $(TEST_MATRICESFILES) $(TEST_MATRICES) *~
	rm -f $(TEST_INSTANCEFILES) $(TEST_INSTANCE) *~
	rm -f $(TEST_RENDERFILES) $(TEST_RENDER) *~
