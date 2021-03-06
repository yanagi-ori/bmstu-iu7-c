CFLAGS := -Wall -Werror -std=gnu99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic -lm -lrt
OBJS := ./out/io.o ./out/list.o ./out/operations.o
UTOBJS := ./out/check_operations.o
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

./out/io.o : ./src/io.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/list.o: ./src/list.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/operations.o: ./src/operations.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/unit_test.o: ./unit_tests/check_main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_operations.o: ./unit_tests/check_operations.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm ./out/*.o *.exe