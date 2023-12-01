#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<fstream>
#include<regex>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf; // for SFML 
const int max_courses = 5;
const int MAX_courses = 20;  // courses offered

class filehandling;    // forward decleration 
class validaltion;
class student
{
protected:
    string name;
    string roll_num;
    int age;
    string contact;
    string courses[5];   // max courses
    char attendance[max_courses];
    int marks[max_courses];
    int course_index;
public:
    static int attendence_index;
    static int marks_index;
    student()
    {
        name = " ";
        roll_num = " ";
        age = 0;
        contact = " ";
    }
    void enroll_student(string name, string roll_num, int age, string contact)
    {
        this->name = name;
        this->roll_num = roll_num;
        this->age = age;
        this->contact = contact;
    }
    void allocate_course_()
    {
        // courses = new string[5];
    }
    //void register_student(string name, int roll_num, int age, string contact, string* course)
    //{
    //    this->name = name;
    //    this->roll_num = roll_num;
    //    this->age = age;
    //    this->contact = contact;
    //   // this->courses = new string[5];
    //    for (int i = 0; i < 5; i++)
    //    {
    //        this->courses[course_index++] = course[i];
    //    }
    //    for (int i = 0; i < 5; i++)
    //    {
    //        this->attendance[i] = 0;          // assuning zero to attendece --- 1 for present 0 for absent
    //    }
    //    for (int i = 0; i < 5; i++)
    //    {
    //        this->marks[i] = 0;          // assuning zero to attendece --- 1 for present 0 for absent
    //    }
    //}
    void mark_attendence(char choice)       // name and choice ( 0 and 1 ) 
    {
        attendance[attendence_index++] = choice;
    }
    void marks_assingn(int marks_to_assign)
    {
        marks[marks_index++] = marks_to_assign;   // assign marks 
    }
    void withdraw_courses(string coursename)
    {
        for (int i = 0; i < 5; i++)
        {
            if (courses[i] == coursename)
            {
                courses[i] = " ";           // space for other course as max is five 
                attendance[i] = '\0';
                marks[i] = 0;
            }
        }

    }
    void display_student()
    {
        cout << name << "  ";
        cout << roll_num << " ";
        cout << age << " ";
        cout << contact << " ";
        cout << "Courses :\n";

        for (int i = 0; i < course_index; i++)  // max 5 courses 
        {
            cout << courses[i] << " " << endl;
            /*if (courses[i] != " ")
            {
                cout << courses[i];
                if (attendance[i] == 'P' || attendance[i] == 'A' || attendance[i] == 'L')
                {
                    cout << " Attendence : " << attendance[i] << endl;
                }
                if (marks[i] > 1 && marks[i] < 100)
                {
                    cout << "MArks of course " << courses[i] << " is :" << marks[i];
                }
            }*/

        }
    }
    void display_enroll_students()
    {
        cout << "Name is " << name << "  ";
        cout << "Roll no is " << roll_num << " ";
        cout << "Age  is " << age << " ";
        cout << "COntact is " << contact << " ";

        cout << endl;
    }
    void set_name(string n)
    {
        name = n;
    }
    void set_contact(string c)
    {
        contact = c;
    }
    void set_rollnumber(string a)
    {
        roll_num = a;
    }
    int get_marks(int i)
    {
        return marks[i];
    }
    char get_attendence(int x)
    {
        return attendance[x];
    }
    void set_age(int a)
    {
        age = a;
    }
    int get_course_count_student()
    {
        return course_index;
    }
    string get_roll_number()
    {
        return roll_num;
    }
    string get_course_student(int x)
    {
        return courses[x];
    }
    void add_course_student(string s)
    {
        courses[course_index++] = s;
    }
    int get_age()
    {
        return age;
    }
    string get_name()
    {
        return name;
    }
    string get_contact()
    {
        return contact;
    }
};
//int student::course_index = 0;
int student::attendence_index = 0;
int student::marks_index = 0;
class Course : public student {
protected:
    string code;
    string name;
    string instructor;
    int credits;
    int capacity;
    student* students;

public:
    static int student_Course_count;
    Course()
    {
        code = " ";
        name = " ";
        instructor = " ";
        credits = 0;
        capacity = 0;
        students = nullptr;
    }
    Course(string code, string name, string instructor, int credits, int capacity)
    {
        this->code = code;
        this->name = name;
        this->instructor = instructor;
        this->credits = credits;
        this->capacity = capacity;
        students = new student[capacity];   // max student enroll in course 
    }
    void addStudent(const student& student)
    {
        if (student_Course_count < capacity)
        {
            students[student_Course_count++] = student;
        }
        else
        {
            cout << "Max capacity reached \n";
        }
    }

    void removeStudent(string rollNumber)  // check student with roll number 
    {
        student* temp;
        temp = new student[student_Course_count - 1];

        for (int i = 0; i < student_Course_count; i++)
        {
            if (students[i].get_roll_number() != rollNumber)
            {
                temp[i] = students[i];
            }
        }
        delete[] students;
        student_Course_count--;
        students = new student[student_Course_count];
        for (int i = 0; i < student_Course_count; i++)
        {
            students[i] = temp[i];
        }

        delete[] temp;
    }
    void set_course_name(string n)
    {
        name = n;
    }
    void set_course_code(int a)
    {
        code = a;
    }
    void set_course_inst(string i)
    {
        instructor = i;
    }
    void set_capacity(int a)
    {
        capacity = a;
    }
    void set_credits(int c)
    {
        credits = c;
    }
    string get_code()
    {
        return code;
    }
    string get_name()
    {
        return name;
    }
    int get_capacity()
    {
        return capacity;
    }
    string get_instructor()
    {
        return instructor;
    }
    int get_credits()
    {
        return credits;
    }
    void display_course()
    {
        cout << " Code :" << code << " Name :" << name << " Credits :" << credits << " instructor :" << instructor << " Capacity :" << capacity << endl;
    }
    void displayStudents()
    {
        cout << "FOllowing students are enroll in course \n";
        cout << "\nCourse detail is as follow \n:";
        display_course();                                  // display course using class member function 
        cout << "\nSTudent detail is as follow \n";
        for (int i = 0; i < student_Course_count; i++)
        {
            students[i].display_student();              // display students enrool in courses 
        }
    }
};
int Course::student_Course_count = 0;

class filehandling : public student, public Course
{
protected:
    ofstream outFile;
    ifstream inFile;
    string fileName;
public:
    filehandling() {}  // default 
    filehandling(const string& fname)
    {
        fileName = fname;
    }
    void write_Student_data_into_File(student& obj)
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
    void write_courses(Course obj)
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
    void write_student_courses(student& obj)
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
    void write_student_courses_data_with_details(student& name, Course& obj)
    {
        outFile.open(fileName, ios::app);  // open in append mode 
        {
            if (outFile.is_open())
            {

            }
        }
    }
    void write_marks(student& obj, int x)  // x is number of courses 
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
    void write_attendence(student& obj, int x)  // x is number of courses 
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
    void open_file(string file)
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
};
class validaltion
{
public:
    // check valid credit hour 
    bool chk_Valid_creditHour(int x)
    {
        if (x > 0 && x <= 3)
        {
            return true;
        }
        return false;
    }
    // menu input
    bool check_valid_input(int x)
    {
        if (x > 0 && x <= 6)
        {
            return true;
        }
        return false;
    }
    // valid course name 
    bool chk_valid_course(string n)
    {
        for (int i = 0; n[i] != '\0'; i++)
        {
            if (n[i] >= '0' && n[i] <= '9')
            {
                return false;
            }
        }
        return true;
    }
    // valid course code 
    bool chk_valid_course_code(string course_code)
    {
        bool values1 = 0, values2 = 0;
        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (course_code[0] == i)
            {
                values1 = 1;
            }
        }
        for (char j = 'A'; j <= 'Z'; j++)
        {
            if (course_code[1] == j)
            {
                values2 = 1;
            }
        }
        bool value = 0, value2 = 0, value3 = 0;
        for (char b = '0'; b <= '9'; b++)
        {
            if (course_code[2] == b)
            {
                value = 1;
            }
        }
        for (char c = '0'; c <= '9'; c++)
        {
            if (course_code[3] == c)
            {
                value2 = 1;
            }
        }
        for (char d = '0'; d <= '9'; d++)
        {
            if (course_code[4] == d)
            {
                value3 = 1;
            }
        }
        if (values1 == 1 && values2 == 1 && value == 1 && value2 == 1 && value3 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    // valid value to mark attendence 
    char is_valid_attendence(char ch)
    {
        if (ch == 'A' || ch == 'P' || ch == 'L' || ch == 'a' || ch == 'p' || ch == 'l')
        {
            return true;
        }
        return false;
    }
    bool is_numeric(char c)
    {
        return c >= '0' && c <= '9';
    }
    // assumme roll number is 22l-0987 this format 
    bool numeric_checker(char c) {
        return c >= '0' && c <= '9';
    }

    bool is_valid_roll_number(string& roll) {
        if (roll.length() != 8) {
            return false;
        }
        if (!numeric_checker(roll[0]) || roll[0] == '0') {
            return false;
        }
        if (!numeric_checker(roll[1]) || roll[1] == '0') {
            return false;
        }
        if (!(roll[2] == 'L' || roll[2] == 'l')) {
            return false;
        }
        if (roll[3] != '-') {
            return false;
        }
        for (int i = 4; i < 8; ++i)
        {
            if (!numeric_checker(roll[i]))
            {
                return false;
            }
        }

        return true;
    }
    // check contact is valid or not 
    bool valid_contact(string cont)
    {
        if (cont.length() != 11)
        {
            return false;
        }
        for (int i = 0; i < 11; i++)
        {
            if (!numeric_checker(cont[i]))
            {
                return false;
            }
        }
        return true;
    }
    // check valid age 
    bool valid_age(int a)
    {
        if (a >= 10 && a <= 80)
        {
            return true;
        }
        return false;
    }
    // check valid marks 
    bool valid_marks(int x)
    {
        return  x >= 0 && x <= 100;  // assume 100 is max marks 
    }
};

class System : public student, public Course
{
protected:
    student students[50];  // total student can be enrolled is 100 
    Course courses[50];  // total vacancy for courses courses 

public:
    static int student_count_System;
    static int course_count_system;
    static int Index_of_course_system;

    System()
    {
        /*courses = nullptr;
        students = nullptr;*/
    }
    // this will add all courses in system 
    void add_new_courses()
    {
        string c;  // code of course to register
        string n;
        int Crdeit;
        string ins;
        int capa;
        bool check = false;
        do
        {
            cout << "\nEnter code number of course to register\n";
            cin >> c;
            validaltion obj;
            bool x = obj.chk_valid_course_code(c);
            check = x;
        } while (!check && cout << "RE-Enter code Code name is not valid");
        check = false;
        do {

            cout << "Enter name of course : ";
            cin >> n;
            validaltion obj;
            bool x = obj.chk_valid_course(n);
            check = x;

        } while (!check && cout << "Re-enter name is not valid ");

        check = false;

        do {
            cout << "Enter credits of course : ";
            cin >> Crdeit;
            validaltion obj;
            bool x = obj.chk_Valid_creditHour(Crdeit);
            check = x;
        } while (!check && cout << "Re-enter credits is not valid ");

        cout << "ENter instructor name : ";
        cin >> ins;
        cout << "Enter capacity of courses :";
        cin >> capa;
        courses[course_count_system] = Course(c, n, ins, Crdeit, capa);
        char ch;
        cout << "Are u sure to Save course :(y for yes N for no) ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {

            filehandling obj("courses.txt");

            obj.write_courses(courses[course_count_system]);
            cout << " REgistred successfully \n";
            course_count_system++;
        }
        else
            cout << "----Course is not saved in database---";

    }
    void displayMainMenu()
    {
        cout << "1 - Enroll a student " << endl;
        cout << "2 - Course Registration " << endl;
        cout << "3 - Attendance " << endl;
        cout << "4 - Marks " << endl;
        cout << "5 - Course Withdraw " << endl;
        cout << "6 - Exit " << endl;
    }
    void displayStudentSubMenu()
    {
        cout << "1 - display already enrolled students" << endl;
        cout << "2 - Add a student" << endl;
        cout << "3 - remove a student" << endl;
        cout << "4 - Edit student detail" << endl;
        cout << "5 - back" << endl;
    }
    void displayCourseSubMenu()
    {
        cout << "1 - Available Courses" << endl;
        cout << "2 - Add new courses " << endl;
        cout << "3 - Register course" << endl;
        cout << "4 - back" << endl;
    }
    void displayattendencesubmenu()
    {
        cout << "1 - Display Attendance(Subject wise)" << endl;
        cout << "2 - Mark Attendance." << endl;
        cout << "3 - back" << endl;
    }
    void markssubmeenu()
    {
        cout << "1 - Display Marks(Subject wise)" << endl;
        cout << "2 - Assign Marks." << endl;
        cout << "3 - back" << endl;
    }
    void display_withdraw_submenu()
    {
        cout << "1 - Enrolled courses" << endl;
        cout << "2 - Drop a course" << endl;
        cout << "3 - back" << endl;
    }
    void performMainMenuAction()
    {
        int choice;
        while (cout << "Enter any chocie from above main\n" && cin >> choice && choice != 6)
        {
            while (choice < 1 || choice > 6)
            {
                cout << "Invalid input try again :\n";
                cin >> choice;
            }
            cout << "You select option number :" << choice << endl;
            // this will check what user has choice
             // enroll a student menu 
            if (choice == 1)
            {
                int choice2;           // for sub student menu 
                cout << "\n-------Choose from given below sub menu-------\n";
                displayStudentSubMenu();
                cin >> choice2;                  // sub menu choose kry gha ye 

                if (choice2 == 1)   // display already enrooll student 
                {
                    for (int i = 0; i < student_count_System; i++)
                    {
                        students[i].display_enroll_students();             // display enroll students   
                    }

                    /*filehandling open_file;
                    cout << "-------------FOllowing are the existing students--------------\n";
                    open_file.open("studentdata.txt");*/
                }
                else if (choice2 == 2)  // add student 
                {
                    if (student_count_System < 100)
                    {
                        string n, c, r;
                        int a;
                        bool check = false;

                        cout << "Enter name of student : ";
                        cin.ignore();
                        cin >> n;

                        do
                        {

                            cout << "Enter contact number of student :";
                            cin.ignore();
                            cin >> c;
                            validaltion obj;
                            bool x = obj.valid_contact(c);
                            check = x;
                        } while (!check && cout << "Invalid combination - Enter again ");
                        check = false;
                        do
                        {
                            cout << "Enter roll number of student :";
                            cin.ignore();
                            cin >> r;
                            validaltion obj;
                            bool x = obj.is_valid_roll_number(r);
                            check = x;
                        } while (!check && cout << "Re-enter combination is not valid");
                        check = false;
                        do
                        {

                            cout << "Enter age of student : ";
                            cin >> a;
                            validaltion obj;
                            bool x = obj.valid_age(a);

                        } while (!check && cout << "invalid age enter agian");

                        student obj;
                        obj.enroll_student(n, r, a, c);
                        add_student(obj);  // add students using fucntion
                    }
                    else
                        cout << "\n\nStudent Limit reached Try next year !...\n\n";
                }
                else if (choice2 == 3)  // remove student 
                {
                    string r;
                    cout << "Enter roll number to remove :";
                    cin >> r;
                    remove_student(r);
                }
                else if (choice2 == 4)  // edit student detail 
                {
                    string roll;
                    cout << "Enter roll number : ";
                    cin >> roll;
                    edit_student_detail(roll);
                }
            }
            // Regitser courses 
            else if (choice == 2)           // course registration 
            {
                displayCourseSubMenu();    // display sub menu 
                int choice2;
                cout << "ENter sub menu choice : ";
                cin >> choice2;


                if (choice2 == 1)      // display courses 
                {

                    for (int i = 0; i < course_count_system; i++)
                    {
                        courses[i].display_course();
                    }
                }
                else if (choice2 == 2)   // add new course 
                {
                    add_new_courses();
                }
                else if (choice2 == 3)       // register courses 
                {
                    string roll_to_check;
                    int student_index = 0;
                    bool check_avalibilty = false;
                    cout << "Enter roll number of student to register course :";
                    cin.ignore();
                    getline(cin, roll_to_check);
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (roll_to_check == students[i].get_roll_number())
                        {
                            check_avalibilty = true;
                            student_index = i;
                            break;
                        }
                    }
                    if (check_avalibilty)
                    {
                        char choice_To_add;
                        do
                        {
                            string c;  // code of course to register
                            cout << "\nEnter code number of course to register\n";
                            cin >> c;

                            bool check_course_avalibility = false;
                            for (int i = 0; i < course_count_system; i++)
                            {
                                if (courses[i].get_code() == c)
                                {

                                    // cout << "Course index :" << students[student_index].get_course_count_student() << endl;
                                    if (students[student_index].get_course_count_student() > 4)
                                    {
                                        cout << "MAx course capacity reached \n";
                                    }
                                    else
                                    {
                                        students[student_index].add_course_student(courses[i].get_name());
                                        check_course_avalibility = true;

                                        break;
                                    }
                                }
                            }
                            if (check_course_avalibility)
                            {
                                cout << "\nCongratulation ! Registred successfully\n";
                            }
                            else
                            {
                                cout << " Sorry! No course with that course code exist Try again...";
                            }
                            cout << "Do U want to add more course into that student (Y/Yes | N/NO): ";
                            cin >> choice_To_add;
                        } while (choice_To_add != 'N' && choice_To_add != 'n');
                    }
                    else
                        cout << "No student with that roll number exist Sorry !";

                    // write all data into file first delete data then write new data 
                    {
                        ofstream Filee_NamE_Course("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file

                        filehandling obj("student_all_data.txt");
                        for (int i = 0; i < student_count_System; i++)
                        {
                            obj.write_student_courses(students[i]);   // write student data with courses 
                        }
                    }
                }
            }
            // attendence 
            else if (choice == 3)
            {
                int choice2;
                displayattendencesubmenu();  // display sub attendence menu 
                cout << "Choose anything from below : ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    /*for (int i = 0; i < student_count_System; i++)
                    {
                        students[i].display_student();
                    }*/
                    filehandling obj;
                    obj.open_file("student_attendence.txt");  // display already attendence of student 
                }
                else if (choice2 == 2)
                {
                    int index_ofSTu;
                    string roll_num;
                    cout << "\nENter the roll number of student to mark attendence : ";
                    cin >> roll_num;

                    bool check_STudent = false;
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (roll_num == students[i].get_roll_number())
                        {
                            check_STudent = true;
                            index_ofSTu = i;
                            //string codeofcourse;
                            //cout << "\nStudent FOund !\n";
                            //cout << "\nEnter Name of course to mark attendece : ";
                            //cin >> codeofcourse;
                            //for (int j = 0; j < 5; j++) // max courses
                            //{
                            //    if (students[i].get_course_student(j) == codeofcourse)
                            //    {
                            //        char ch;
                            //        cout << "\nEnter attendecce of student (P / A / L)  :";
                            //        cin >> ch;
                            //        students[i].mark_attendence(codeofcourse, ch);  // mark attendence for that course 
                            //        break;
                            //    }
                            //}
                        }
                    }
                    if (check_STudent)
                    {
                        int x = students[index_ofSTu].get_course_count_student();
                        if (x > 0)
                        {
                            for (int i = 0; i < x; i++)
                            {
                                char AttenDencE;
                                cout << "Enter Attendence for " << students[index_ofSTu].get_course_student(i) << " :";
                                cin >> AttenDencE;
                                students[index_ofSTu].mark_attendence(AttenDencE);
                            }
                            filehandling obj("student_attendence.txt");
                            obj.write_attendence(students[index_ofSTu], x);
                        }
                        else
                            cout << "\n Student has no courses \n";
                    }
                    if (!check_STudent)
                    {
                        cout << "\nNO student with that roll number exist \n";
                    }
                    else
                        cout << "\nStudent found and attendence marked \n";
                }
            }
            // Marks of students 
            else if (choice == 4)
            {
                bool check_stU = false;
                int choice2;
                markssubmeenu();   // sub menu of marks 
                cout << "CHoose anything from main menu : ";
                cin >> choice2;

                if (choice2 == 1)  // display already marks of students 
                {
                    filehandling obj;
                    obj.open_file("students_marks.txt");

                    /*for (int i = 0; i < student_count_System; i++)
                    {
                        students[i].display_student();
                    }*/
                }
                else if (choice2 == 2)
                {
                    string roll;
                    int index_ofSTu;
                    cout << "\nEnter roll number of student :";
                    cin >> roll;
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (roll == students[i].get_roll_number())
                        {
                            check_stU = true;
                            index_ofSTu = i;
                            cout << "\nStudent Found\n";
                            break;
                        }
                    }
                    if (check_stU)
                    {
                        int x = students[index_ofSTu].get_course_count_student();

                        if (x > 0)  // student atleast has one course 
                        {
                            for (int i = 0; i < x; i++)
                            {
                                int marks;
                                cout << "Enter marks for " << students[index_ofSTu].get_course_student(i);
                                cin >> marks;
                                students[index_ofSTu].marks_assingn(marks);   // assign marks to courses 
                            }
                            cout << "\n----MArks assigned Succesfully-----\n";

                            filehandling obj("students_marks.txt");
                            obj.write_marks(students[index_ofSTu], x);

                        }
                        else
                        {
                            cout << "\nStudent has no courses\n";
                        }
                        //string sub_name;
                        //cout << "\nEnter subject name to Enter marks :";
                        //cin >> sub_name;
                        //for (int i = 0; i < 5; i++)
                        //{
                        //    if (students[index_ofSTu].get_course_student(i) == sub_name) // checkk course 
                        //    {
                        //        int marks;
                        //        cout << "Enter marks for " << sub_name << " Course :";
                        //        cin >> marks;
                        //        students[index_ofSTu].marks_assingn(sub_name, marks);   // assign marks to courses 
                        //        cout << "-------------Marks assingned------------\n";
                        //        // this will store marks into files 
                        //       /* filehandling obj("studentmarks.txt");
                        //        for (int i = 0; i < student_count_System; i++)
                        //        {
                        //            obj.write_marks(students[i]);
                        //        }*/
                    }
                }
            }
            // withdraw course of student 
            else if (choice == 5)
            {
                int choice2;
                display_withdraw_submenu();
                cout << "Enter any choice from above menu : ";
                cin >> choice2;

                if (choice2 == 1)   // display student courses 
                {
                    string roll__;
                    cout << "ENter roll number of student to check enrolled courses :";
                    cin >> roll__;
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (students[i].get_roll_number() == roll__)
                        {
                            students[i].display_student();
                            break;
                        }
                    }
                }
                else if (choice2 == 2)  // drop a course 
                {
                    int S_index = 0;
                    string RoLl;
                    cout << "Enter your roll_number : ";
                    cin >> RoLl;
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (students[i].get_roll_number() == RoLl)
                        {
                            S_index = i;
                            string name_Of_coUrse;
                            cout << "WHich course you want to withdraw Enter course Name : ";
                            cin >> name_Of_coUrse;
                            for (int j = 0; j < 5; j++)  //max 5 courses 
                            {
                                if (students[S_index].get_course_student(j) == name_Of_coUrse)
                                {
                                    students[S_index].withdraw_courses(name_Of_coUrse);
                                    ofstream Filee_NamE_Course("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file

                                    filehandling obj("student_all_data.txt");
                                    for (int i = 0; i < student_count_System; i++)
                                    {
                                        obj.write_student_courses(students[i]);   // write student data with courses 
                                    }
                                    cout << "\n----------Withdraw successfully---------------\n";
                                    break;
                                }

                            }
                        }
                    }

                }
            }
        }
    }

    // this function will edit student details on compile ti
    void edit_student_detail(string roll)
    {
        bool check = false;
        int index = 0;
        for (int i = 0; i < student_count_System; i++)
        {
            if (students[i].get_roll_number() == roll)
            {
                check = true;
                index = i;
                break;
            }
        }
        if (check)
        {

            cout << "\n----------Enter updated details--------------\n";
            int edit_choice;
            cout << "\nWHat u want t edit\n 1- name \n2 - contact\n 3- age\n";
            cin >> edit_choice;
            if (edit_choice == 1)
            {
                string name;
                cout << "ENter name :";
                cin >> name;
                students[index].set_name(name);
            }
            else if (edit_choice == 2)
            {
                string name;
                cout << "ENter contact :";
                cin >> name;
                students[index].set_contact(name);
            }
            else if (edit_choice == 3)
            {
                int  a;
                cout << "Enter age :";
                cin >> a;
                students[index].set_age(a);
            }
            ofstream Filee_NamE("studentdata.txt", ios::trunc); // trunc remove all the existing data from the file 

            for (int i = 0; i < student_count_System; i++)
            {
                filehandling obj("Studentdata.txt");
                obj.write_Student_data_into_File(students[i]);    // again write data into file after trunc
            }
        }
        else {
            cout << "No student exist with that roll number ";
        }
    }
    // it will remove students from the file it has also method to remove during compile_time 
    void remove_student(string roll)
    {
        for (int i = 0; i < 50; i++)
        {
            if (students[i].get_roll_number() == roll)
            {
                students[i].set_age(0);
                students[i].set_name("");
                students[i].set_contact("");
                students[i].set_contact("");

                cout << "Deleted successfulyy \n";
                student_count_System--;  // descrse studenet count 
                break;
            }
        }
        string tempFilename = "temp.txt"; // Temporary file
        string filename = "studentdata.txt";
        ifstream inputFile(filename);
        ofstream tempFile(tempFilename);

        regex patternRegex(roll);
        string line;

        while (getline(inputFile, line)) {
            if (!regex_search(line, patternRegex)) {
                tempFile << line << endl;
            }
        }
        inputFile.close();
        tempFile.close();
        if (remove(filename.c_str()) != 0) {    // deleting original file data 
            cerr << "Error\n" << endl;
            return;
        }
        if (rename(tempFilename.c_str(), filename.c_str()) != 0) { // modifying data in the original file 
            cerr << "Error\n" << endl;
            return;
        }

    }

    // this function will add new students in a system 
    void add_student(student& obj)
    {
        students[student_count_System] = obj;
        char chh__ = 'a';
        cout << "DO u want to store student data Permanently : (Press Y for yes N for no) :";
        cin >> chh__;
        if (chh__ == 'Y' || chh__ == 'y')
        {
            filehandling obj("Studentdata.txt");
            obj.write_Student_data_into_File(students[student_count_System]);
            student_count_System++;
        }
        else
            cout << "\nStudent detail not saved \n";

    }

    // this function will display the detail of all student and save data in file_handling 

    //void display_student_system()
    //{
    //    filehandling obj("student_All_Data.txt");   // store student data with courses 
    //    cout << ":: Students ::\n";
    //    for (int i = 0; i < 100; i++)
    //    {
    //        if (students[i].get_roll_number() != " ")
    //        {
    //            //students[i].display_student();
    //            obj.write_student_courses(students[i]);   // save student data with courses 
    //            cout << endl;
    //        }
    //    }
    //}

    /*void display_courses_system()
    {
        for (int i = 0; i < 20; i++)
        {
            courses[i].display_course();
        }
    }*/

    void load_student_data()
    {
        student_count_System = 0;
        ifstream inputFile("studentdata.txt");

        if (!inputFile.is_open())
        {
            cout << "Error opening file!" << std::endl;
            return;
        }
        // Assuming one line contains all the data
        string line;
        while (getline(inputFile, line))
        {

            istringstream iss(line);

            string name, rollNumber, contact;
            int age_;

            // Assuming the data in the file is formatted as "Name RollNumber Age Contact"
            if (iss >> name >> rollNumber >> age_ >> contact)
            {
                // Set the data to the attributes of the Student object
                students[student_count_System].set_name(name);
                students[student_count_System].set_rollnumber(rollNumber);
                students[student_count_System].set_age(age_);
                students[student_count_System].set_contact(contact);
                student_count_System++;
            }
            else
            {
                cout << "Error parsing data from file!" << std::endl;
                break;  // Exit the loop if parsing fails
            }
        }
        inputFile.close();
    }
    void load_student_with_their_courses()
    {
        student_count_System = 0;
        ifstream inputFile("student_all_data.txt");

        if (!inputFile.is_open())
        {
            cout << "Error opening file!" << std::endl;
            return;
        }
        // assume 1 line contain all data of student 
        string line;
        while (getline(inputFile, line))
        {

            istringstream iss(line);    // input stream 

            string name, rollNumber, contact;
            int age_;
            string coursee__;
            // Assuming the data in the file is formatted as "Name RollNumber Age Contact"
            if (iss >> name >> rollNumber >> age_ >> contact)
            {
                // Set the data to the attributes of the Student object
                students[student_count_System].set_name(name);
                students[student_count_System].set_rollnumber(rollNumber);
                students[student_count_System].set_age(age_);
                students[student_count_System].set_contact(contact);
            }
            while (iss >> coursee__)   // check if line is empty or not as we need to extract data(courses) from it 
            {
                students[student_count_System].add_course_student(coursee__);
            }
            student_count_System++;
        }
        inputFile.close();
    }
    void load_all_ava_courses()
    {
        course_count_system = 0;
        ifstream inputFile("courses.txt");

        if (!inputFile.is_open())
        {
            cout << "Error opening file!" << std::endl;
            return;
        }


        string line;
        while (getline(inputFile, line))
        {

            if (course_count_system < 100) {
                istringstream iss(line);

                int code, capacCiTy, credit;
                string name, inst;

                // Assuming the data in the file is formatted as "Code Name Inst Capacity Credits"
                if (iss >> code >> name >> capacCiTy >> inst >> credit)    // iss is input stream 
                {
                    // Set the data to the attributes of the Course object
                    courses[course_count_system].set_course_code(code);
                    courses[course_count_system].set_course_name(name);
                    courses[course_count_system].set_capacity(capacCiTy);
                    courses[course_count_system].set_course_inst(inst);
                    courses[course_count_system].set_credits(credit);

                    course_count_system++;
                }
                else
                {
                    cout << "Error parsing data from file!" << std::endl;
                    break;  // Exit the loop if parsing fails
                }
            }
            else
            {
                cout << "Not enough space in the courses array!" << std::endl;
                break;
            }
        }
        inputFile.close();
    }
};
int System::student_count_System = 0;
int System::course_count_system = 0;
int System::Index_of_course_system = 0;
// this will check if student is enroll in university or not 
bool Authentication(string Student_ID)
{
    ifstream inputFile("authentification.txt");


    if (!inputFile.is_open())
    {
        cerr << "Error opening student data file." << endl;
        return false;
    }

    regex patternRegex(Student_ID);
    string line;
    bool check = false;

    while (getline(inputFile, line))
    {
        if (regex_match(line, patternRegex))
        {
            check = true;
            break;  // No need to continue searching if found
        }
    }
    return check;
}

int main()
{
    // this will load image 

    //RenderWindow window(VideoMode(900, 600), "FLEX managment System");
    ////Event evnt;
    ////Texture texture;
    ////texture.loadFromFile("C:/Users/echo/Desktop/hacker-3342696_640.jpg");
    //////texture.display();
    ////Sprite sprites(texture);
    ////window.draw(sprites);
    ////window.display();
    //// font 
    //Font font;
    //font.loadFromFile("arial.ttf");
    //if (!font.loadFromFile("arial.ttf"))
    //{
    //    cout << "Error loading file \n";
    //}
    //// text display 
    //Text text;
    //text.setFont(font); // Set the font
    //text.setString("For Authentification Enter Your ROll Number"); // Set the text content
    //text.setCharacterSize(24); // Set the character size
    //text.setFillColor(Color::White); // Set the fill color
    //text.setPosition(200, 100); // Set the position
    //window.draw(text);
    //window.display();

    char ch;
    do
    {
            RenderWindow window(VideoMode(900, 600), "FLEX managment System");
            // font 
          
                Font font;
                font.loadFromFile("arial.ttf");
                if (!font.loadFromFile("arial.ttf"))
                {
                    cout << "Error loading file \n";
                }
                // text display 
                Text text;
                text.setFont(font); // Set the font
                text.setString("For Authentification Enter Your ROll Number"); // Set the text content
                text.setCharacterSize(24); // Set the character size
                text.setFillColor(Color::White); // Set the fill color
                text.setPosition(200, 100); // Set the position
                window.draw(text);

                // Create a rectangle shape
                RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(500, 100)); // Set the size of the rectangle
                rectangle.setPosition(200, 200);           // Set the position of the rectangle
                rectangle.setFillColor(sf::Color::Transparent); // Set the fill color to transparent
                rectangle.setOutlineColor(sf::Color::White);    // Set the outline color
                rectangle.setOutlineThickness(2.0f);             // Set the outline thickness
                window.draw(rectangle);
                Event evnt;
                string ID;
                // setting detail for user input 
                Text userInputText;
                userInputText.setFont(font);
                userInputText.setCharacterSize(24);
                userInputText.setFillColor(sf::Color::White);
                userInputText.setPosition(50, 50);
                window.display();
                while (window.isOpen())
                {
                    while (window.pollEvent(evnt))
                    {
                        if (evnt.type == sf::Event::Closed) {
                            window.close();
                        }
                        else if (evnt.type == Event::TextEntered)
                        {
                            if (evnt.text.unicode < 128 && evnt.text.unicode > 31)
                            {
                                ID += evnt.text.unicode;
                                userInputText.setString(ID); // set input strig in SFML Window 
                                window.draw(userInputText);
                                window.display();
                            }
                            else if (evnt.text.unicode == 8) // backspace
                            {
                                ID.pop_back();
                            }
                        }
                        else if (Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                           
                            bool checking_student = Authentication(ID);   // check authentification of user 
                            if (checking_student)
                            {
                                cout << "FOUND : ";
                                window.clear();  // clear previous screen 
                                Text text_show;
                                text_show.setFont(font); // Set the font
                                text_show.setString("Welcome to FAST - NUCES Portal"); // Set the text content
                                text_show.setCharacterSize(24); // Set the character size
                                text_show.setFillColor(Color::White); // Set the fill color
                                text_show.setPosition(200, 200); // Set the position
                                window.draw(text_show);
                                window.display();
                                /* cout << "----------------Welcome " << ID << " to FAST - NU LHR menu Page-------------- - \n";*/
                                System obj;
                                //obj.load_student_data();
                                obj.load_student_with_their_courses();
                                obj.load_all_ava_courses();
                                obj.displayMainMenu();
                                obj.performMainMenuAction();
                            }
                    }
                }
            }
    } while (cin >> ch && (ch != 'Y' && ch != 'y'));
    cout << "-----THank u for using our service----------\n ";
    return 0;
}