FLAGS := -Wall -Werror -std=gnu99 -Wvla -Wfloat-equal -Wfloat-conversion -pedantic -lm -lrt
OBJS := ./out/io.o ./out/list.o
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

./out/main.o: main.c *.h
	mkdir -p out
	$(CC) $(CFLAGS) -c $< -o $@

./out/io.o : io.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/list.o: list.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm ./out/*.o *.exe