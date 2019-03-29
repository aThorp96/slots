# This variable might need to be updated with each lab
PROG = slots

CC = gcc

CFLAGS = -g -c -Wall -std=c++11 -Og

$(PROG): $(PROG).c

	$(CC) $(CFALGS) $< -o $@


clean:
	rm $(OBJ) $(PROG)

