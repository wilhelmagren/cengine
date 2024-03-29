CC = gcc
CFLAGS = -Wall -Werror -O3
LDFLAGS = -lSDL2 -lm

TEST_VEC3FILES = src/utils.o src/vec3.o tests/test_vec3.o
TEST_POLYGONFILES = src/CENGINE.o src/instance.o src/matrices.o src/mesh.o src/polygon.o src/utils.o src/vec3.o tests/test_polygon.o
TEST_MATRICESFILES = src/CENGINE.o src/instance.o src/matrices.o src/mesh.o src/polygon.o src/utils.o src/vec3.o tests/test_matrices.o
TEST_INSTANCEFILES = src/CENGINE.o src/instance.o src/matrices.o src/mesh.o src/polygon.o src/utils.o src/vec3.o  tests/test_instance.o
TEST_MESHFILES = src/mesh.o src/polygon.o src/CENGINE.o src/matrices.o src/utils.o src/vec3.o tests/test_mesh.o
TEST_CENGINEFILES = src/CENGINE.o src/instance.o src/matrices.o src/mesh.o src/polygon.o src/utils.o src/vec3.o tests/test_CENGINE.o


OBJFILES = src/CENGINE.o src/instance.o src/matrices.o src/mesh.o src/polygon.o src/utils.o src/vec3.o 

TEST_VEC3 = vec3_test
TEST_POLYGON = polygon_test
TEST_MATRICES = matrices_test
TEST_MESH = mesh_test
TEST_INSTANCE = instance_test
TEST_CENGINE = CENGINE_test

$(TEST_VEC3): $(TEST_VEC3FILES)
	$(CC) -o $(TEST_VEC3) $(TEST_VEC3FILES) $(CFLAGS) $(LDFLAGS)

$(TEST_POLYGON): $(TEST_POLYGONFILES)
	$(CC) -o $(TEST_POLYGON) $(TEST_POLYGONFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_MATRICES): $(TEST_MATRICESFILES)
	$(CC) -o $(TEST_MATRICES) $(TEST_MATRICESFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_MESH): $(TEST_MESHFILES)
	$(CC) -o $(TEST_MESH) $(TEST_MESHFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_INSTANCE): $(TEST_INSTANCEFILES)
	$(CC) -o $(TEST_INSTANCE) $(TEST_INSTANCEFILES) $(CFLAGS) $(LDFLAGS)

$(TEST_CENGINE): $(TEST_CENGINEFILES)
	$(CC) -o $(TEST_CENGINE) $(TEST_CENGINEFILES) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TEST_VEC3FILES) $(TEST_VEC3) *~
	rm -f $(TEST_POLYGONFILES) $(TEST_POLYGON) *~
	rm -f $(TEST_MATRICESFILES) $(TEST_MATRICES) *~
	rm -f $(TEST_MESHFILES) $(TEST_MESH) *~
	rm -f $(TEST_INSTANCEFILES) $(TEST_INSTANCE) *~
	rm -f $(TEST_CENGINEFILES) $(TEST_CENGINE) *~
