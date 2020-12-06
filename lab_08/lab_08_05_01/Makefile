CFILES := ./../src/main.c ./../src/io.c ./../src/array_utils.c
CFLAGS := -Wall -Werror -std=c99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic
OBJS := ./out/array_utils.o ./out/io.o
CC := gcc

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0 -O2
endif

ifeq ($(mode), test)
	TEST += -lcheck
endif

app.exe: ./out/main.o $(OBJS)
	$(CC) $^ -o $@

unit_tests.exe: ./out/unit_test.o $(OBJS)
	$(CC) $^ -lcheck -o $@

./out/io.o : ./src/io.c ./inc/io.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/array_utils.o : ./src/array_utils.c ./inc/array_utils.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/unit_test.o: ./unit_tests/unit_tests.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm ./out/*.o *.exe