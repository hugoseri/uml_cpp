lists.o: lists.cpp lists.h student.h course.h
	g++ -c lists.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

interface.o: interface.cpp interface.h student.h lists.h
	g++ -c interface.cpp

main.o: main.cpp student.h interface.h course.h lists.h
	g++ -c main.cpp

uml: interface.o student.o lists.o course.o main.o
	g++ interface.o student.o lists.o course.o main.o -o uml

clean:
	rm -r *.o
