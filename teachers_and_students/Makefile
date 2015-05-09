test: Teacher.o Student.o main.cpp
	g++ -o test Teacher.o Student.o main.cpp
Teacher.o: Teacher.cpp TeacherAndStudent.h
	g++ -c Teacher.cpp
Student.o: Student.cpp TeacherAndStudent.h
	g++ -c Student.cpp
clean:
	rm Student.o Teacher.o
