CC = g++
CFLAGS = -Wall -Wextra -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter

# Objetos
OBJS = main.o point_set.o point_types.o subtree.o

# Regla por defecto
all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

point_set.o: point_set.cpp point_set.hpp
	$(CC) $(CFLAGS) -c point_set.cpp

point_types.o: point_types.cpp point_types.hpp
	$(CC) $(CFLAGS) -c point_types.cpp

subtree.o: subtree.cpp subtree.hpp
	$(CC) $(CFLAGS) -c subtree.cpp

.PHONY: clean
clean:
	rm -f main $(OBJS)
run:
	./main
exec:
	rm -f main $(OBJS) && make && ./main