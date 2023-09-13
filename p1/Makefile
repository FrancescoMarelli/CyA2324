p01_single_grades: p01_single_grades.cc
	g++ -Wall -g -std=c++17 -o p01_single_grades p01_single_grades.cc

p01_multiple_grades: p01_multiple_grades.cc
	g++ -Wall -g -std=c++17 -o p01_multiple_grades p01_multiple_grades.cc
	
clean:
	rm -f *.o p01_single_grades p01_multiple_grades
	

run_single:
	./p01_single_grades grades.txt

run_multiple:
	./p01_multiple_grades grades.txt

execute_single:
	rm -f *.o p01_single_grades
	g++ -Wall -g -std=c++17 -o p01_single_grades p01_single_grades.cc
	./p01_single_grades grades.txt

execute_multiple:
	rm -f *.o p01_multiple_grades
	g++ -Wall -g -std=c++17 -o p01_multiple_grades p01_multiple_grades.cc
	./p01_multiple_grades grades.txt
