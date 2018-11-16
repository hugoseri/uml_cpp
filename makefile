interface.o: interface.cpp interface.h
	g++ -c interface.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

student.o: student.cpp student.h 
	g++ -c student.cpp

main.o: main.cpp student.h interface.h course.h
	g++ -c main.cpp

uml: course.o interface.o student.o main.o
	g++ course.o interface.o student.o main.o -o uml

clean:
	rm -r *.o
