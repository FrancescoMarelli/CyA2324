MT: Symbol.o String.o Alphabet.o State.o Transition.o Turing.o p09_MT.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o Transition.o State.o String.o Turing.o Alphabet.o p09_MT.o -o MT

MT.o: p09_MT.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p09_MT.cc

Turing.o: Turing.h Turing.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Turing.cc

Transition.o: Transition.h Transition.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Transition.cc

Alphabet.o: Alphabet.h Alphabet.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

State.o: State.h State.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c State.cc

String.o: String.h String.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Symbol.o: Symbol.h Symbol.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

.PHONY: clean
clean:
	rm -f *.o MT

.PHONY: run 
run: 
	./MT anbn.tm cinta.tape

.PHONY: execute
execute:
	make clean
	make
	make run