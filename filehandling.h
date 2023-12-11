#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>
#include"student.h"
#include"Course.h"
#include<fstream>
#include<regex>
using namespace std;
using namespace sf;
class filehandling : public student, public Course
{
protected:
    ofstream outFile;
    ifstream inFile;
    string fileName;
public:
    filehandling(); // default 
    filehandling(const string& fname);
    void write_Student_data_into_File(student& obj);
    void write_courses(Course obj);
    void write_Student_into_Course(student& obj);
    void write_student_courses(student& obj);
    void write_student_courses_data_with_details(student& name, Course& obj);
    void write_marks(student& obj, int x);
    void write_attendence(student& obj, int x);
    void open_file(string file);
};
