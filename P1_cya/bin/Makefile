p01_single_grade: p01_single_grade.o fileManager.o students.o
	g++ -std=c++14 -g -Wall fileManager.o students.o p01_single_grade.o -o p01_single_grade

p01_multiple_grade: p01_multiple_grade.o students.o fileManager.o
	g++ -std=c++14 -g -Wall fileManager.o students.o p01_multiple_grade.o -o p01_multiple_grade

p01_single_grade.o: ../src/p01_single_grade.cc 
	g++ -std=c++14 -g -Wall -c ../src/p01_single_grade.cc

p01_multiple_grade.o: ../src/p01_multiple_grade.cc
	g++ -std=c++14 -g -Wall -c ../src/p01_multiple_grade.cc

fileManager.o: ../src/fileManager.cc ../lib/fileManager.h
	g++ -std=c++14 -g -Wall -c ../src/fileManager.cc

students.o : ../src/students.cc ../lib/students.h
	g++ -std=c++14 -g -Wall -c ../src/students.cc

clean: 
	rm -f *.o p01_multiple_grade p01_single_grade