p02_strings: p02_strings.o String.o Symbol.o Alphabet.o Language.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare String.o Symbol.o Alphabet.o Language.o p02_strings.o -o p02_strings

p02_strings.o: p02_strings.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p02_strings.cc

String.o: String.cc String.h
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Symbol.o: Symbol.cc Symbol.h
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

Alphabet.o: Alphabet.cc Alphabet.h
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

Language.o: Language.cc Language.h
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Language.cc

clean:
	rm -f *.o p02_strings fileout.txt 