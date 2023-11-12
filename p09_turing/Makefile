TM: Symbol.o String.o Alphabet.o State.o Transition.o Turing.o p09_TM.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o Transition.o State.o String.o Turing.o Alphabet.o p09_TM.o -o TM

TM.o: p09_TM.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p09_TM.cc

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
	rm -f *.o TM

.PHONY: run 
run: 
	./TM anbn.tm cinta.tape 0
run2:
	./TM abcc.tm cinta.tape 0
pal:
	./TM palindroma.tm cinta.tape 0
run_head:
	./TM anbn.tm cinta.tape 1
run2_head:
	./TM abcc.tm cinta.tape 1
pal_head:
	./TM palindroma.tm cinta.tape 1

.PHONY: execute
execute:
	make clean
	make
	make run
exe:
	make clean
	make
	make run
e:
	make clean
	make
	make run