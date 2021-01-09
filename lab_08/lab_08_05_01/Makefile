CFILES := ./../src/main.c ./../src/io.c ./../src/matrix_creation.c \
./../src/matrix_operation.c ./../src/matrix_utils.c ./../src/utils.c

CFLAGS := -Wall -Werror -std=c99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic
OBJS := ./out/matrix_creation.o ./out/io.o ./out/matrix_utils.o ./out/matrix_operation.o ./out/utils.o
UTOBJS := ./out/check_matrix_creation.o ./out/check_matrix_operation.o ./out/check_matrix_utils.o
CC := gcc
LINKER := -o

ifeq ($(mode), debug)
	CFLAGS += -ggdb3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0 -O2
endif

ifeq ($(os), linux)
	LINKER := -lpthread -lrt -lsubunit -lm -o
endif

app.exe: ./out/main.o $(OBJS)
	$(CC) $^ $(LINKER) $@

unit_tests.exe: ./out/unit_test.o $(OBJS) $(UTOBJS)
	$(CC) $^ -lcheck $(LINKER) $@

./out/io.o : ./src/io.c ./inc/io.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/matrix_creation.o : ./src/matrix_creation.c ./inc/matrix_creation.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/matrix_operation.o : ./src/matrix_operations.c ./inc/matrix_operations.h ./inc/matrix_creation.h ./inc/matrix_utils.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/matrix_utils.o : ./src/matrix_utils.c ./inc/matrix_utils.h ./inc/errors.h ./inc/utils.h
	$(CC) $(CFLAGS) -c $< -o $@ -lm

./out/utils.o : ./src/utils.c ./inc/utils.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/unit_test.o: ./unit_tests/check_main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_matrix_creation.o: ./unit_tests/check_matrix_creation.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_matrix_operation.o: ./unit_tests/check_matrix_operation.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_matrix_utils.o: ./unit_tests/check_matrix_utils.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm ./out/*.o *.exe