#pragma once 

#include<iostream>
#include<SFML/Graphics.hpp>
#include"filehandling.h"
#include"Course.h"
#include"validation_header.h"
#include"filehandling.h"
#include"SFMLMenuScreen.h"

using namespace std;
class System : public student, public Course
{
protected:
    student students[50];  // total student can be enrolled is 100 
    Course courses[50];  // total vacancy for courses courses 

public:
    static int student_count_System;
    static int course_count_system;
    static int Index_of_course_system;

    System();
    // this will add all courses in system 
    void add_new_courses();
    void displayStudentSubMenu(RenderWindow& Subwindow);
    void displayCourseSubMenu(RenderWindow& Subwindow);
    void displayattendencesubmenu(RenderWindow& Subwindow);
    void displaymarkssubmeenu(RenderWindow& Subwindow);
    void display_withdraw_submenu(RenderWindow& Subwindow);
    void performMainMenuAction2();
    void edit_student_detail(string roll, Window& renderwindow);
    void remove_student(string roll);
    bool add_student(student& obj);
    void load_student_data();
    void load_student_with_their_courses();
    void load_all_ava_courses();
};
