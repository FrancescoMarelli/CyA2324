p05_automata_simulator: Symbol.o String.o Alphabet.o Language.o Automaton.o State.o Transition.o p05_automata_simulator.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o String.o Alphabet.o Language.o Transition.o State.o Automaton.o p05_automata_simulator.o -o p05_automata_simulator

p05_automata_simulator.o: p05_automata_simulator.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p05_automata_simulator.cc

Automaton.o: Automaton.h Automaton.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Automaton.cc

Transition.o: Transition.h Transition.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Transition.cc

State.o: State.h State.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c State.cc

Alphabet.o: Alphabet.h Alphabet.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

Language.o: Language.h Language.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Language.cc

String.o: String.h String.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Symbol.o: Symbol.h Symbol.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

clean:
	rm -f *.o p05_automata_simulator

.PHONY: all clean