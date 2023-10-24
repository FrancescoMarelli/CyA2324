NFA2DFA: Symbol.o String.o Alphabet.o Automaton.o State.o Transition.o NFA2DFA.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o String.o Alphabet.o Transition.o State.o Automaton.o NFA2DFA.o -o NFA2DFA

NFA2DFA.o: p06_nfa2dfa.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p06_nfa2dfa.cc

Automaton.o: Automaton.h Automaton.cc
	g++ -std=c++14 -g -Wall -Wno-return-type -Wno-sign-compare -c Automaton.cc
	
Transition.o: Transition.h Transition.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Transition.cc

State.o: State.h State.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c State.cc

Alphabet.o: Alphabet.h Alphabet.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

String.o: String.h String.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Symbol.o: Symbol.h Symbol.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

.PHONY: clean
clean:
	rm -f *.o NFA2DFA

.PHONY: run 
run: 
	./NFA2DFA input.nfa output.dfa

.PHONY: execute
execute:
	make clean
	make
	make run
