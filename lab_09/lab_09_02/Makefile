CFLAGS := -Wall -Werror -std=gnu99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic -lm -lrt
OBJS := ./out/utils.o ./out/io.o ./out/struct_ctrl.o
UTOBJS := ./out/check_io.o
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

./out/struct_ctrl.o : ./src/struct_ctrl.c ./inc/struct_ctrl.h ./inc/struct.h
	$(CC) $(CFLAGS) -c $< -o $@ -lm

./out/utils.o : ./src/utils.c ./inc/utils.h ./inc/errors.h ./inc/struct.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o: ./src/main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/unit_test.o: ./unit_tests/check_main.c ./inc/*.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/check_io.o: ./unit_tests/check_io.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm ./out/*.o *.exe