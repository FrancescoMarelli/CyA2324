Grammar2CNF: Symbol.o String.o Alphabet.o Grammar.o p07_grammar2CNF.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o String.o Grammar.o Alphabet.o p07_grammar2CNF.o -o Grammar2CNF

Grammar2CNF.o: p07_grammar2CNF.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p07_grammar2CNF.cc

Grammar.o: Grammar.h Grammar.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Grammar.cc

Alphabet.o: Alphabet.h Alphabet.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

String.o: String.h String.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Symbol.o: Symbol.h Symbol.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

.PHONY: clean
clean:
	rm -f *.o Grammar2CNF

.PHONY: run 
run: 
	./Grammar2CNF input.gra output.gra

.PHONY: execute
execute:
	make clean
	make
	make run