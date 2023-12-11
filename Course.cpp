#include<iostream>
#include<SFML/Graphics.hpp>
#include"Course.h"
using namespace std;
using namespace sf;
Course::Course()
{
    code = " ";
    name = " ";
    instructor = " ";
    credits = 0;
    capacity = 0;
}
Course::Course(string code, string name, string instructor, int credits, int capacity)
{
    this->code = code;
    this->name = name;
    this->instructor = instructor;
    this->credits = credits;
    this->capacity = capacity;
    students = new student[capacity];   // max student enroll in course 
}
void Course::addStudent(const student& student)
{
    if (student_Course_count < capacity)
    {
        students[student_Course_count] = student;
    }
    student_Course_count++;
}
void Course::removeStudent(student* student)
{
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].get_roll_number() == student->get_roll_number())
        {
            for (int j = i; j < numStudents - 1; ++j)
            {
                students[j] = students[j + 1];
            }
            --numStudents;
            return;
        }
    }
}
void Course::displayStudents()
{
    cout << "Students enrolled in " << name << " Code: " << code << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        students[i].displayInfo();
        cout << endl;
    }
}
void Course::set_course_name(string n)
{
    name = n;
}
void Course::set_course_code(string a)
{
    code = a;
}
void Course::set_course_inst(string i)
{
    instructor = i;
}
void Course::set_capacity(int a)
{
    capacity = a;
}
void Course::set_credits(int c)
{
    credits = c;
}
string Course::get_code()
{
    return code;
}
string Course::get_name()
{
    return name;
}
int Course::get_capacity()
{
    return capacity;
}
string Course::get_instructor()
{
    return instructor;
}
int Course::get_credits()
{
    return credits;
}

void Course::display_Course(RenderWindow& win, Text text)
{
    // convert int to string 
    string stringCredits = to_string(credits);
    string stringCapacity = to_string(capacity);
    // code name instructor capacity credits
    text.setFillColor(Color::Black);
    text.setString("Code :" + code + "Name : " + name + "Instructor :" + instructor + "Capacity :" + stringCapacity + "Credits :" + stringCredits);
    win.draw(text);

}
int Course::student_Course_count = 0;
