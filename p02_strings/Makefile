p02_strings: Symbol.o String.o Alphabet.o Language.o p02_strings.o
	g++ -std=c++14 -g -Wall -Wno-sign-compare Symbol.o String.o Alphabet.o Language.o p02_strings.o -o p02_strings

Symbol.o: Symbol.h Symbol.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Symbol.cc

String.o: String.h String.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c String.cc

Alphabet.o: Alphabet.h Alphabet.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Alphabet.cc

Language.o: Language.h Language.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c Language.cc

p02_strings.o: p02_strings.cc
	g++ -std=c++14 -g -Wall -Wno-sign-compare -c p02_strings.cc

clean:
	rm -f *.o p02_strings
