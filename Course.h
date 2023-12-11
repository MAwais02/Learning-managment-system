#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>
#include"student.h"
using namespace std;
using namespace sf;
class Course : public student {
protected:
    string code;
    string name;
    string instructor;
    int credits;
    int capacity;
    student* students; // max student 50
    int numStudents;

public:
    static int student_Course_count;
    Course();
    Course(string code, string name, string instructor, int credits, int capacity);
    void addStudent(const student& student);
    void removeStudent(student* student);
    void displayStudents();
    void set_course_name(string n);
    void set_course_code(string a);
    void set_course_inst(string i);
    void set_capacity(int a);
    void set_credits(int c);
    string get_code();
    string get_name();
    int get_capacity();
    string get_instructor();
    int get_credits();
    void display_Course(RenderWindow& win, Text text);
};
