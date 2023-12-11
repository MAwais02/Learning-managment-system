
#include<iostream>
#include"filehandling.h"


filehandling::filehandling() {}  // default 
filehandling::filehandling(const string& fname)
{
    fileName = fname;
}
void filehandling::write_Student_data_into_File(student& obj)
{
    outFile.open(fileName, ios::app);  // open file in append mode 
    if (outFile.is_open())
    {
        outFile << obj.get_name() << " ";
        outFile << obj.get_roll_number() << " ";
        outFile << obj.get_age() << " ";
        outFile << obj.get_contact();
        outFile << '\n'; // Add a newline character to separate entries
    }
    else
    {
        cout << "File is not opening -- try Again !" << endl;
    }
}
void filehandling::write_courses(Course obj)
{
    outFile.open(fileName, ios::app);  // open file in append mode 
    if (outFile.is_open())
    {
        outFile << obj.get_code() << "    ";
        outFile << obj.get_name() << "    ";
        outFile << obj.get_capacity() << "    ";
        outFile << obj.get_instructor() << "  ";
        outFile << obj.get_credits() << "\n";
        outFile.close();
    }
    else
    {
        cout << "File is not opening -- try Again !" << endl;
    }
}
void filehandling::write_Student_into_Course(student& obj)
{
    outFile.open(fileName, ios::app);
    {
        if (outFile.is_open())
        {
            outFile << obj.get_name() << "    ";
            outFile << obj.get_roll_number() << "    ";
            outFile << obj.get_age() << "    ";
            outFile << obj.get_contact() << " ";
            outFile << "\n";
            outFile.close();
        }
    }

}
void filehandling::write_student_courses(student& obj)
{
    outFile.open(fileName, ios::app);
    if (outFile.is_open())
    {
        outFile << obj.get_name() << "    ";
        outFile << obj.get_roll_number() << "    ";
        outFile << obj.get_age() << "    ";
        outFile << obj.get_contact() << " ";
        for (int i = 0; i < 5; i++)   // max 5 courses 
        {
            outFile << obj.get_course_student(i) << " ";
        }
        outFile << "\n";
        outFile.close();
    }
    else
    {
        cout << "File is not opening -- try Again !" << endl;
    }
}
void filehandling::write_student_courses_data_with_details(student& name, Course& obj)
{
    outFile.open(fileName, ios::app);  // open in append mode 
    {
        if (outFile.is_open())
        {

        }
    }
}
void filehandling::write_marks(student& obj, int x)  // x is number of courses 
{
    outFile.open(fileName, ios::app | ios::in);
    {
        if (outFile.is_open())
        {
            // name  course_name   Marks this pattern will be followed 
            outFile << obj.get_name();
            outFile << "\n";
            for (int i = 0; i < x; i++)
            {
                outFile << obj.get_course_student(i) << " ";
                outFile << obj.get_marks(i) << "\n";
            }
        }
    }
}
void filehandling::write_attendence(student& obj, int x)  // x is number of courses 
{
    outFile.open(fileName, ios::app | ios::in);
    {
        if (outFile.is_open())
        {
            // name  course_name   Marks this pattern will be followed 
            outFile << obj.get_name();
            outFile << "\n";
            for (int i = 0; i < x; i++)
            {
                outFile << obj.get_course_student(i) << " ";
                outFile << obj.get_attendence(i) << "\n";
            }
        }
    }
}
void filehandling::open_file(string file)
{
    string filename = file;
    ifstream cinn(filename);
    string str;
    while (getline(cinn, str))
    {
        cout << str << endl;
    }
    cout << endl;
}
