CFILES := ./../src/main.c ./../src/io.c ./../src/array_utils.c
CFLAGS := -Wall -Werror -std=c99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic
OBJS := ./out/array_utils.o ./out/io.o
CC := gcc

ifeq ($(mode), debug)
	CFLAGS += -ggdb3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0 -O2
endif

ifeq ($(mode), test)
	TEST += -lcheck
endif

app.exe: ./out/main.o $(OBJS)
	$(CC) $^ -o $@

unit_tests.exe: ./out/check_main.o ./out/check_elements_counter.o ./out/check_sort.o ./out/check_key.o $(OBJS)
	$(CC) $^ -lcheck -o $@

./out/io.o : ./src/io.c ./inc/io.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/array_utils.o : ./src/array_utils.c ./inc/array_utils.h ./inc/errors.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_main.o: unit_tests/check_main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@
./out/check_elements_counter.o : unit_tests/check_elements_counter.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@
./out/check_key.o : unit_tests/check_key.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@
./out/check_sort.o : unit_tests/check_sort.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY: clean

clean:
	rm ./out/*.o *.exe