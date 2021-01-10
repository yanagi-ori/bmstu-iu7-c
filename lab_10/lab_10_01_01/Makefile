CFLAGS := -Wall -Werror -std=gnu99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic -lm -lrt
OBJS := ./out/io.o ./out/lu.o ./out/mm.o
UTOBJS :=
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

./out/io.o : ./src/io.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/lu.o: ./src/list_utils.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/mm.o: ./src/memory_management.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/utils.o: ./src/utils.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/sort.o: ./src/sort.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/unit_test.o: ./unit_tests/check_main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	rm ./out/*.o *.exe