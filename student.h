
#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class student
{
protected:
    string name;
    string roll_num;
    int age;
    string contact;
    string courses[5];   // max courses
    char attendance[5];
    int marks[5];
    int course_index;
public:
    static int attendence_index;
    static int marks_index;
    student();
    void enroll_student(string name, string roll_num, int age, string contact);
    void mark_attendence(char choice);
    void marks_assingn(int marks_to_assign);
    void withdraw_courses(string coursename);
    void display_student(RenderWindow& Win, Text text[]);
    void display_enroll_students(RenderWindow& window_Enroll, Text text);
    void displayInfo();
    void set_name(string n);
    void set_contact(string c);
    void set_rollnumber(string a);
    int get_marks(int i);
    char get_attendence(int x);
    void set_age(int a);
    int get_course_count_student();
    string get_roll_number();
    string get_course_student(int x);
    void add_course_student(string s);
    int get_age();
    string get_name();
    string get_contact();
};
