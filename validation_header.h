#pragma once 

#include<iostream>
using namespace std;
class validaltion
{
public:
    // check valid credit hour 
    bool chk_Valid_creditHour(int x);
    // menu input
    bool check_valid_input(int x);
    // valid course name 
    bool chk_valid_course(string n);
    // valid course code 
    bool chk_valid_course_code(string course_code);
    // valid value to mark attendence 
    char is_valid_attendence(char ch);
    bool is_numeric(char c);
    // assumme roll number is 22l-0987 this format 
    bool numeric_checker(char c);

    bool is_valid_roll_number(string& roll);
    // check contact is valid or not 
    bool valid_contact(string cont);
    // check valid age 
    bool valid_age(int a);
    // check valid marks 
    bool valid_marks(int x);
};
