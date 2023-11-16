#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

const int max_courses = 5;
const int MAX_courses = 20;  // courses offered

class filehandling;    // forward decleration 
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
public:
    static int course_index;
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
    void mark_attendence(string coursename, char choice)       // name and choice ( 0 and 1 ) 
    {
        bool check = false;
        for (int i = 0; i < max_courses; i++)
        {
            if (courses[i] == coursename)
            {
                check = true;
                attendance[attendence_index++] = choice;
                cout << "Attendence Marked for course " << coursename << endl;
                break;
            }
        }
        if (check == false)
        {
            cout << "No course exist with that name \n";
        }
    }
    void marks_assingn(string coursename, int marks_to_assign)
    {
        bool check = false;
        for (int i = 0; i < max_courses; i++)
        {
            check = true;
            if (courses[i] == coursename)
            {
                marks[marks_index++] = marks_to_assign;
                break;
            }
        }
        if (check == false)
        {
            cout << "No course exist with that name \n";
        }
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
        cout << "Name :" << name << "  ";
        cout << "ROll no :" << roll_num << "  ";
        cout << "Age :" << age << "  ";
        cout << "contacts :" << contact << "  ";
        cout << "\nStudent has following courses :\n";

        for (int i = 0; i < 5; i++)  // max 5 courses 
        {
            if (courses[i] != " ")
            {
                cout << courses[i];
                if (attendance[i] == 'P' || attendance[i] == 'A' || attendance[i] == 'L')
                {
                    cout << " Attendence : " << attendance[i] << endl ;
                }
                if (marks[i] > 1 && marks[i] < 100)
                {
                    cout << "MArks of course " << courses[i] << " is :" << marks[i];
                }
            }
        }
    }
    void set_name(string n)
    {
        name = n;
    }
    void set_contact(string c)
    {
        contact = c;
    }
    void set_age(int a)
    {
        age = a;
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
int student::course_index = 0;
int student::attendence_index = 0;
int student::marks_index = 0;
class Course : public student {
protected:
    int code;
    string name;
    string instructor;
    int credits;
    int capacity;
    student* students;

public:
    static int student_Course_count;
    Course()
    {
        code = 0;
        name = " ";
        instructor = " ";
        credits = 0;
        capacity = 0;
        students = nullptr;
    }
    Course(int code, string name, string instructor, int credits, int capacity)
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
    int get_code()
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
    void display_course()
    {
        cout << " Code " << code << " Name " << name << " Credits " << credits << " instructor " << instructor << endl ;

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
    filehandling();
    filehandling(const string& fname)
    {
        fileName = fname;
    }
    void write_Student_data_into_File(student& obj)
    {
        outFile.open(fileName, ios::app);  // open file in append mode 
        if (outFile.is_open())
        {
            outFile << obj.get_name() << "    ";
            outFile << obj.get_roll_number() << "    ";
            outFile << obj.get_age() << "    ";
            outFile << obj.get_contact() << '\n'; // Add a newline character to separate entries
        }
        else
        {
            cout << "File is not opening -- try Again !" << endl;
        }
    }
    void write_courses(Course** allCourses);
    void open(string);
    void close();
    void read(string);
};
class System : public student , public Course 
{

protected:
    student* students;
    Course courses[20];  // total availible courses 

public:
    static int student_count_System;
    System()
    {
        students = nullptr;
    }
    void allocatememory()
    {
        students = new student[20];  // assume max students is 20 
    }
    void avalibl_courses()
    {
        courses[0] = Course(1234, "PF", "Amirwali", 3, 50);
        courses[1] = Course(1235, "IICT", "Amirwali", 3, 50);
        courses[2] = Course(1236, "OOP", "Amirwali", 3, 50);
        courses[3] = Course(1237, "AP", "Amirwali", 3, 50);
        courses[4] = Course(1238, "Islamiat", "Amirwali", 3, 50);
        courses[5] = Course(1239, "Data", "Amirwali", 3, 50);
        courses[6] = Course(1212, "Algo", "Amirwali", 3, 50);
        courses[7] = Course(1213, "DS", "Amirwali", 3, 50);
        courses[8] = Course(1214, "Linear Algebra", "Amirwali", 3, 50);
        courses[9] = Course(1215, "Pks", "Amirwali", 3, 50);
        courses[10] = Course(1216, "Hhh", "Amirwali", 3, 50);
        courses[11] = Course(1217, "PF", "Amirwali", 3, 50);
        courses[12] = Course(1218, "PF", "Amirwali", 3, 50);
        courses[13] = Course(1219, "PF", "Amirwali", 3, 50);
        courses[14] = Course(1220, "PF", "Amirwali", 3, 50);
        courses[15] = Course(1221, "PF", "Amirwali", 3, 50);
        courses[16] = Course(1222, "PF", "Amirwali", 3, 50);
        courses[17] = Course(1223, "PF", "Amirwali", 3, 50);
        courses[18] = Course(1224, "PF", "Amirwali", 3, 50);
        courses[19] = Course(1225, "PF", "Amirwali", 3, 50);    // 0 - 19 = 20 
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
        cout << "2 - Register course" << endl;
        cout << "3 - back" << endl;
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
    //// Get user input
    //int getUserChoice()
    //{
    //    int choice;
    //    cout << "Enter your choice :\n";
    //    cin >> choice;
    //    return choice;
    //}
    //// Validate user input
    //bool isValidChoice(int choice, int maxChoice)
    //{
    //    return choice >= 1 && choice <= maxChoice;
    //}
    void performMainMenuAction()
    {
        // this will take user input from user 
        allocatememory(); // allocate memoriy 
        int choice;
        while (cout << "Enter any chocie from above main\n" && cin >> choice && choice != 6)
        {
            while (choice < 1 || choice > 6)
            {
                cout << "Invalid input try again :\n";
                cin >> choice;
            }
            cout << "You select option number :" << choice << endl;
            // this will check what user has chosse
       

             // enroll a student menu 
            if (choice == 1)
            {
                int choice2;           // for sub student menu 
                cout << "\n-------Choose from given below sub menu-------\n";
                displayStudentSubMenu();
                cin >> choice2;                  // sub menu choose kry gha ye 

                if (choice2 == 1)   // display already enrooll student 
                {
                    display_student_system();
                }
                else if (choice2 == 2)  // add student 
                {
                  
                    string n, c, r;
                    int a;
                    cout << "Enter name of student : ";
                    cin.ignore();
                    cin >> n ;
                    cout << "Enter contact number of student :";
                    cin.ignore();
                    cin >> c;
                    cout << "Enter roll number of student :";
                    cin.ignore();
                    cin >> r;
                    cout << "Enter age of student : ";
                    cin >> a;
                    student obj;
                    obj.enroll_student(n, r, a, c);
                    add_student(obj);  // add students using fucntion
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
                avalibl_courses();
                displayCourseSubMenu();
                int choice2;
                cout << "ENter sub menu choice : ";
                cin >> choice2;
                if (choice2 == 1)      // display courses 
                {
                    display_courses_system();        // display hardcore coourses that we have assing
                }
                else if (choice2 == 2)       // register courses 
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
                       // Register_courses();
                        int c;  // code of course to register
                        cout << "\nEnter code number of course to register\n";
                        cin >> c;

                        bool check_course_avalibility = false;

                        for (int i = 0; i < 20; i++)  // courses time chly gha 
                        {
                            if (courses[i].get_code() == c)
                            {
                                students[student_index].add_course_student(courses[i].get_name());
                                courses[i].addStudent(students[i]);   // add student into course (us course mai student ko addkrdo)


                                check_course_avalibility = true;
                                break;
                            }
                        }
                        if (check_course_avalibility)
                        {
                            cout << "\nCongratulation ! Registred successfully\n";
                        }
                        else
                            cout << " Sorry! No course with that course exist Try again...";

                    }
                    else
                        cout << "No student with that roll number exist Sorry !";
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
                    for (int i = 0; i < student_count_System; i++)
                    {
                        students[i].display_student();
                    }
                }
                else if (choice2 == 2)
                { 
                    string roll_num;
                    cout << "\nENter the roll number of student to mark attendence : ";
                    cin >> roll_num;

                    bool check_STudent = false;
                    for (int i = 0; i < student_count_System; i++)
                    {
                        if (roll_num == students[i].get_roll_number())
                        {
                            check_STudent = true;
                            string codeofcourse;
                            cout << "\nStudent FOund !\n";
                            cout << "\nEnter Name of course to mark attendece : ";
                            cin >> codeofcourse;

                            for (int j = 0; j < 5; j++) // max courses
                            {
                                if (students[i].get_course_student(j) == codeofcourse)
                                {
                                    char ch;
                                    cout << "\nEnter attendecce of student (P / A / L)  :";
                                    cin >> ch;
                                    students[i].mark_attendence(codeofcourse, ch);  // mark attendence for that course 
                                    break;
                                }
                            }
                        }
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
                if (choice == 1)
                {
                    for (int i = 0; i < student_count_System; i++)
                    {
                        students[i].display_student();
                    }
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
                            index_ofSTu = i ;
                            cout << "\nStudent Found\n";
                            break;
                        }
                    }
                    if (check_stU)
                    {
                        string sub_name; 
                        cout << "\nEnter subject name to Enter marks :";
                        cin >> sub_name;
                        for (int i = 0; i < 5; i++)
                        {
                            if (students[index_ofSTu].get_course_student(i) == sub_name) // checkk course 
                            {
                                int marks;
                                cout << "Enter marks for " << sub_name << " Course :";
                                cin >> marks;
                                students[index_ofSTu].marks_assingn(sub_name, marks);   // assign marks to courses 
                            }
                        }
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
                            string name_Of_coUrse;
                            cout << "WHich course you want to withdraw Enter course Name : ";
                            cin >> name_Of_coUrse;
                            for (int i = 0; i < 5; i++)
                            {
                                if (students[S_index].get_course_student(i) == name_Of_coUrse)
                                {
                                    students[S_index].withdraw_courses(name_Of_coUrse);
 
                                    cout << "\n----------Withdraw successfully---------------\n";
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    void Register_courses()
    {
        student::allocate_course_();
        int c;  // code of course to register
        cout << "\nEnter code number of course to register\n";
        cin >> c;
        
        bool check_course_avalibility = false;

        for (int i = 0; i < student_count_System ; i++)  // run only for students 
        {
            if (courses[i].get_code() == c /*&& courses[i].get_capacity() < student_Course_count*/)  // allocate students in course
            {
                students[student_count_System++].add_course_student(courses[i].get_name());
                courses[i].addStudent(students[i]);   // add student into course (us course mai student ko addkrdo)
                

                check_course_avalibility = true;
                break;
            }
        }
        if (check_course_avalibility)
        {
            cout << "\nCongratulation ! Registred successfully\n";
        }
        else
            cout << " Sorry! No course with that course exist Try again...";


    }
    void edit_student_detail(string roll)
    {
        bool check = false;
        int index = 0;
        for (int i = 0; i < 20; i++)
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
        }
        else
            cout << "Nos tudent exist with that roll number ";
    }
    void remove_student(string roll)
    {
        student* temp = new student[20];
        for (int i = 0; i < 19; i++)
        {
            if (students[i].get_roll_number() != roll)
            {
                temp[i] = students[i];
            }
        }
        delete[] students;
        students = new student[20];         // again assign max student 
        student_count_System--;  // descrse studenet count 
        for (int i = 0; i < 20; i++)
        {
            students[i] = temp[i];
        }
        cout << "\n-------Removed successfully----------\n";
        delete[] temp;
    }
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
        }
        else
            cout << "\nStudent detail not saved \n";

        student_count_System++;
    }
    void display_student_system() const 
    {
        cout << ":: Students ::\n";
        for (int i = 0; i < 20; i++)
        {

            if (students[i].get_roll_number() != " ")
            {
                students[i].display_student();
                cout << endl;
            }
        }
    }
    void display_courses_system()
    {
        for (int i = 0; i < 20; i++)
        {
            courses[i].display_course();
        }
    }
    //void performStudentSubMenuAction(int choice);
    //void performCourseSubMenuAction(int choice);
    
    //// Save data to file
    //void saveDataToFile();

    //// Load data from file
    //void loadDataFromFile();

};
int System::student_count_System = 0;

int main()
{
    System obj;
    obj.displayMainMenu();
    obj.performMainMenuAction();

    return 0;
}