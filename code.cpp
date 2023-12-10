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

VideoMode desktopMode = VideoMode::getDesktopMode();




class filehandling;    // forward decleration 
class validaltion;
class Course; // Forward declaration

class SFMLWindow {
private:
    RenderWindow window;

public:
    SFMLWindow(const VideoMode& mode, const String& title) : window(mode, title)
    {
        window.setFramerateLimit(60);
    }

    void clear(const  Color& color) {
        window.clear(color);
    }

    void draw(const  Drawable& drawable) {
        window.draw(drawable);
    }

    void display() {
        window.display();
    }

    bool pollEvent(Event& event) {
        return window.pollEvent(event);
    }
};

class SFMLMenuScreen
{
private:
    int selectindex;
    Font font;
    Text text[6];  // as we have 5 menus 
public:
    SFMLMenuScreen() {}
    SFMLMenuScreen(float w, float h)
    {
        if (!(font.loadFromFile("arial.ttf")))
        {
            cout << "Error loadinf file :\n";
        }
        text[0].setFont(font);
        text[0].setFillColor(Color::Blue);
        text[0].setString("1- Enroll a student");
        text[0].setPosition(50, 300);
        text[0].setCharacterSize(50);

        text[1].setFont(font);
        text[1].setFillColor(Color::Black);
        text[1].setString("2- Course Registration");
        text[1].setPosition(50, 400);
        text[1].setCharacterSize(50);


        text[2].setFont(font);
        text[2].setFillColor(Color::Black);
        text[2].setString("3 - Attendence ");
        text[2].setPosition(50, 500);
        text[2].setCharacterSize(50);

        text[3].setFont(font);
        text[3].setFillColor(Color::Black);
        text[3].setString("4 - Marks");
        text[3].setPosition(50, 600);
        text[3].setCharacterSize(50);

        text[4].setFont(font);
        text[4].setFillColor(Color::Black);
        text[4].setString("5 - Course Withdraw");
        text[4].setPosition(50, 700);
        text[4].setCharacterSize(50);

        text[5].setFont(font);
        text[5].setFillColor(Color::Black);
        text[5].setString("6 - Exit ");
        text[5].setPosition(50, 800);
        text[5].setCharacterSize(50);

        selectindex = 0;
    }
    void draw(RenderWindow& window)
    {
        for (int i = 0; i < 6; i++)
        {
            window.draw(text[i]);
        }
    }
    int mainmenupress()
    {
        return selectindex;
    }
    void moveUp()
    {
        if (selectindex - 1 >= 0)
        {
            text[selectindex].setFillColor(Color::Black);
            selectindex--;
            text[selectindex].setFillColor(Color::Blue);
        }
    }
    void moveDown()
    {
        if (selectindex + 1 < 6)
        {
            text[selectindex].setFillColor(Color::Black);
            selectindex++;
            text[selectindex].setFillColor(Color::Blue);
        }
    }
};
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
    void display_student(RenderWindow &Win , Text text[])
    {
        Font font; 
        font.loadFromFile("arial.ttf");

        Text text2;
        text2.setFont(font);
        text2.setString("Student has follwoing courses : ");
        text2.setCharacterSize(50);
        text2.setFillColor(Color::Black);
        text2.setPosition(400, 500 - 50);
        
        Text text3;
        text3.setFont(font);
        text3.setString("Press ESC to Countinue");
        text3.setCharacterSize(50);
        text3.setFillColor(Color::Red);
        text3.setPosition(500, 500 + 50 * 6);
        for (int i = 0; i < course_index; ++i) {
            text[i].setFont(font);
            text[i].setString(courses[i]);
            text[i].setCharacterSize(50);
            text[i].setFillColor(Color::Black);
            text[i].setPosition(500, 500 + 50 * i );
        }

        Win.draw(text2);
        Win.draw(text3);
        for (int i = 0; i < course_index; ++i) 
        {
            Win.draw(text[i]);
        }
    }
    void display_enroll_students(RenderWindow& window_Enroll, Text text)
    {
        string s = to_string(age);    // first convert int into string data type 
        text.setString("Name :" + name + "Roll no : " + roll_num + "Contact " + contact + "Age : " + s);
        window_Enroll.draw(text);
    }
    void displayInfo()
    {
        cout << "Studen name : " << name;
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
    int numStudents;

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
    void removeStudent(student* student)
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
    void displayStudents()
    {
        cout << "Students enrolled in " << name << " Code: " << code << endl ;
        for (int i = 0; i < numStudents; ++i)
        {
            students[i].displayInfo();
            cout << endl;
        }
    }
    void set_course_name(string n)
    {
        name = n;
    }
    void set_course_code(string a)
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
    
    void display_Course(RenderWindow&win , Text text)
    {
        // convert int to string 
        string stringCredits = to_string(credits);
        string stringCapacity = to_string(capacity);
        // code name instructor capacity credits
        text.setFillColor(Color::Black);
        text.setString("Code :" + code + "Name : " + name + "Instructor :" + instructor + "Capacity :" + stringCapacity + "Credits :" + stringCredits);
        win.draw(text);
        
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
 
    

    void displayStudentSubMenu(RenderWindow& Subwindow)
    {
        Text menuItems[5];

        Font font;
        font.loadFromFile("arial.ttf");
        for (int i = 0; i < 5; ++i)
        {
            menuItems[i].setFont(font);
            menuItems[i].setCharacterSize(50);
            menuItems[i].setFillColor(Color::Black);
        }
        menuItems[0].setString("1 - Display Enroll Student ");
        menuItems[1].setString("2 - Add student");
        menuItems[2].setString("3 - Edit student Detail");
        menuItems[3].setString("4 - Remeove Student");
        menuItems[4].setString("5 - Edit");

        for (int i = 0; i < 5; ++i)
        {
            menuItems[i].setPosition(50 , 300 + i * 100);
        }
        for (const Text& text : menuItems)
        {
            Subwindow.draw(text);
        }
        //Subwindow.display();
    }
    void displayCourseSubMenu(RenderWindow& Subwindow)
    {
        Text menuItems[5];

        Font font;
        font.loadFromFile("arial.ttf");
        for (int i = 0; i < 5; ++i)
        {
            menuItems[i].setFont(font);
            menuItems[i].setCharacterSize(50);
            menuItems[i].setFillColor(Color::Black);
        }
        menuItems[0].setString("1 - Avalible Course");
        menuItems[1].setString("2 - Register Course");
        menuItems[2].setString("3 - Add student into Course");
        menuItems[3].setString("4 - Remove Student From COurse");
        menuItems[4].setString("5 - Back ");

        for (int i = 0; i < 5; ++i)
        {
            menuItems[i].setPosition(50, 300 + i * 100);
        }
        for (const Text& text : menuItems)
        {
            Subwindow.draw(text);
        }
    }
    void displayattendencesubmenu(RenderWindow& Subwindow)
    {
        Text menuItems[3];

        Font font;
        font.loadFromFile("arial.ttf");
        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setFont(font);
            menuItems[i].setCharacterSize(50);
            menuItems[i].setFillColor(Color::Black);
        }
        menuItems[0].setString("1 - Display Attendence ");
        menuItems[1].setString("2 - Mark Attendence");
        menuItems[2].setString("3 - Back ");

        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setPosition(50, 300 + i * 100);
        }
        for (const Text& text : menuItems)
        {
            Subwindow.draw(text);
        }
    }
    void displaymarkssubmeenu(RenderWindow& Subwindow)
    {
        Text menuItems[3];

        Font font;
        font.loadFromFile("arial.ttf");
        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setFont(font);
            menuItems[i].setCharacterSize(50);
            menuItems[i].setFillColor(Color::Black);
        }
        menuItems[0].setString("1 - Display Marks ");
        menuItems[1].setString("2 - Assign Marks ");
        menuItems[2].setString("3 - Back ");

        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setPosition(50, 300 + i * 100);
        }
        for (const Text& text : menuItems)
        {
            Subwindow.draw(text);
        }
    }
    void display_withdraw_submenu(RenderWindow& Subwindow)
    {
        Text menuItems[3];

        Font font;
        font.loadFromFile("arial.ttf");
        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setFont(font);
            menuItems[i].setCharacterSize(50);
            menuItems[i].setFillColor(Color::Black);
        }
        menuItems[0].setString("1 - Display Enroll Courses ");
        menuItems[1].setString("2 - Drop a Course ");
        menuItems[2].setString("3 - Back ");

        for (int i = 0; i < 3; ++i)
        {
            menuItems[i].setPosition(50, 300 + i * 100);

        }
        for (const Text& text : menuItems)
        {
            Subwindow.draw(text);
        }
    }
    void performMainMenuAction2()
    {
        Font font;
        font.loadFromFile("arial.ttf");
        RenderWindow WlcmScr(desktopMode, "WElcomtoFAST-NU");
        Text welcmtofatmsg;
        welcmtofatmsg.setFillColor(Color::Red);
        welcmtofatmsg.setCharacterSize(55);
        welcmtofatmsg.setPosition(500, 200);
        welcmtofatmsg.setFont(font);
        welcmtofatmsg.setString("Welcome to FAST-NU---Selext Any Options from Below");
        Texture texture;
        if (!texture.loadFromFile("C:/Users/echo/Desktop/NU-logo.jpg"));
        {
            cout << "Image not found\n";
        }
        Sprite sprite;
        sprite.setTexture(texture);
        Vector2f newSize(1000 * 1.9 + 30, 100 * 2);
        SFMLMenuScreen menu(WlcmScr.getSize().x, WlcmScr.getSize().y);
        while (WlcmScr.isOpen())
        {
            Event aevent;
            while (WlcmScr.pollEvent(aevent))
            {
                if (aevent.type == Event::Closed) {
                    WlcmScr.close();
                }
                if (aevent.type == Event::KeyReleased)
                {
                    if (aevent.key.code == Keyboard::Up)
                    {
                        menu.moveUp();
                        break;
                    }
                    if (aevent.key.code == Keyboard::Down)
                    {
                        menu.moveDown();
                        break;
                    }
                    if (aevent.key.code == Keyboard::Enter)
                    {
                        RenderWindow Enroll(desktopMode, "Enroll student");
                        RenderWindow Register(desktopMode, "Register student");
                        RenderWindow Attendence(desktopMode, "Attedence");
                        RenderWindow Marks(desktopMode, "Marks");
                        RenderWindow Withdraw(desktopMode, "Course Withdraw");
                        RenderWindow Exit(desktopMode, "Exit");

                        int x = menu.mainmenupress();
                        if (x == 0)
                        {
                            while (Enroll.isOpen())
                            {
                                Event eaevent;
                                while (Enroll.pollEvent(eaevent))
                                {
                                    if (eaevent.type == Event::Closed)
                                    {
                                        Enroll.close();
                                    }
                                    if (eaevent.type == Event::KeyPressed)
                                    {
                                        // display student 
                                        if (eaevent.key.code == Keyboard::Num1)
                                        {
                                            Text DisplayStudents[100];//make it 100 constant 
                                            Text STudentAvaliblemsg;
                                            STudentAvaliblemsg.setCharacterSize(60);
                                            STudentAvaliblemsg.setFillColor(Color::Black);
                                            STudentAvaliblemsg.setFont(font);
                                            STudentAvaliblemsg.setPosition(400, 200);
                                            STudentAvaliblemsg.setString("---Following STudents Are avalibles---");
                                            RenderWindow showEnrollStudent(desktopMode, "1 - Enroll Student Window");
                                            Font fontt;
                                            fontt.loadFromFile("arial.ttf");
                                            int check = true;
                                            Text text;
                                            text.setFont(fontt);
                                            text.setCharacterSize(30);
                                            text.setFillColor(Color::Black);

                                            string line;
                                            while (showEnrollStudent.isOpen())
                                            {
                                                ifstream inputFile("studentdata.txt");
                                                Event evnt;
                                                while (showEnrollStudent.pollEvent(evnt))
                                                {
                                                    if (evnt.type == Event::Closed)
                                                    {
                                                        showEnrollStudent.close();
                                                    }
                                                    if (evnt.key.code == Keyboard::Escape)
                                                    {
                                                        showEnrollStudent.close();
                                                    }
                                                }
                                                showEnrollStudent.clear(Color::White);
                                                int i = 0;
                                                while (getline(inputFile, line))
                                                {
                                                    text.setPosition(20, 300 + 50 * i);
                                                    text.setString(line);
                                                    showEnrollStudent.draw(text);
                                                    i++;
                                                }
                                                inputFile.close();
                                                showEnrollStudent.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                showEnrollStudent.display();
                                            }
                                        }
                                        // ADD student into this 
                                        if ((eaevent.key.code == Keyboard::Num2))
                                        {

                                            bool Save_Check = false;
                                            RenderWindow Add_Student(desktopMode, "Add Student");
                                            string name, rollnumber, contact;
                                            string  age;
                                            Font font;
                                            font.loadFromFile("arial.ttf");

                                            Text text_Addstudent[4];

                                            Text userInputTextname;
                                            userInputTextname.setFillColor(Color::Black);
                                            userInputTextname.setFont(font);
                                            userInputTextname.setCharacterSize(50);
                                            userInputTextname.setPosition(1000, 300 + 0 * 100);


                                            Text Sucesfullmsg;
                                            Sucesfullmsg.setFillColor(Color::Green);
                                            Sucesfullmsg.setFont(font);
                                            Sucesfullmsg.setCharacterSize(50);
                                            Sucesfullmsg.setPosition(800, 300 + 6 * 100);


                                            Text userInputTextrollno;
                                            userInputTextrollno.setFillColor(Color::Black);
                                            userInputTextrollno.setFont(font);
                                            userInputTextrollno.setCharacterSize(50);
                                            userInputTextrollno.setPosition(1000, 300 + 1 * 100);

                                            Text userInputTextcont;
                                            userInputTextcont.setFillColor(Color::Black);
                                            userInputTextcont.setFont(font);
                                            userInputTextcont.setCharacterSize(50);
                                            userInputTextcont.setPosition(1000, 300 + 2 * 100);

                                            Text userInputTextage;
                                            userInputTextage.setFillColor(Color::Black);
                                            userInputTextage.setFont(font);
                                            userInputTextage.setCharacterSize(50);
                                            userInputTextage.setPosition(1000, 300 + 3 * 100);
                                            //------------------Valid Inputs-------------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70 , 300 + 1 * 100 + 60 );

                                            Text ValidAgeprint;
                                            ValidAgeprint.setFillColor(Color::Red);
                                            ValidAgeprint.setFont(font);
                                            ValidAgeprint.setCharacterSize(28);
                                            ValidAgeprint.setPosition(1100, 300 + 3 * 100);

                                            Text Validcontctprint;
                                            Validcontctprint.setFillColor(Color::Red);
                                            Validcontctprint.setFont(font);
                                            Validcontctprint.setCharacterSize(28);
                                            Validcontctprint.setPosition(1100, 300 + 3 * 100);
                                            //---------------------------------------------------

                                            for (int i = 0; i < 4; i++)
                                            {
                                                text_Addstudent[i].setCharacterSize(50);
                                                text_Addstudent[i].setFont(font);
                                                text_Addstudent[i].setFillColor(Color::Black);
                                                text_Addstudent[i].setPosition(50, 300 + 100 * i);

                                            }
                                            //----Chk Validity------
                                            bool chkvalidage = false;
                                            bool chkvalidcontact = false;
                                            bool chkvalidrollnumber = false;
                                            bool chkvalidname = false;
                                            //----------------------

                                            bool nameInputActive = true;
                                            bool rollInputActive = false;
                                            bool contactInputActive = false;
                                            bool ageInputActive = false;
                                            while (Add_Student.isOpen())
                                            {
                                                Event Add_Student_Event;

                                                while (Add_Student.pollEvent(Add_Student_Event)) {
                                                    if (Add_Student_Event.type == Event::Closed) {
                                                        Add_Student.close();
                                                    }
                                                    if (Add_Student_Event.key.code == Keyboard::Escape)
                                                    {
                                                        Add_Student.close();
                                                    }

                                                    if (Add_Student_Event.type == Event::TextEntered)
                                                    {
                                                        if (Add_Student_Event.text.unicode < 128 && Add_Student_Event.text.unicode > 31)
                                                        {
                                                            if (nameInputActive)
                                                            {
                                                                name += Add_Student_Event.text.unicode;
                                                                userInputTextname.setString(name);
                                                                Add_Student.draw(userInputTextname);
                                                            }
                                                            else if (rollInputActive)
                                                            {
                                                                rollnumber += Add_Student_Event.text.unicode;
                                                                userInputTextrollno.setString(rollnumber);
                                                                Add_Student.draw(userInputTextrollno);
                                                            }
                                                            else if (contactInputActive)
                                                            {
                                                                contact += Add_Student_Event.text.unicode;
                                                                userInputTextcont.setString(contact);
                                                                Add_Student.draw(userInputTextcont);
                                                            }
                                                            else if (ageInputActive)
                                                            {
                                                                age += Add_Student_Event.text.unicode;
                                                                userInputTextage.setString(age);
                                                                Add_Student.draw(userInputTextage);
                                                            }
                                                        }
                                                        else if (Add_Student_Event.text.unicode == 8)
                                                        {
                                                            if (nameInputActive && !name.empty())
                                                            {
                                                                name.pop_back();
                                                                userInputTextname.setString(name);
                                                                Add_Student.draw(userInputTextname);
                                                            }
                                                            else if (rollInputActive && !rollnumber.empty())
                                                            {
                                                                rollnumber.pop_back();
                                                                userInputTextrollno.setString(rollnumber);
                                                                Add_Student.draw(userInputTextrollno);
                                                            }
                                                            else if (contactInputActive && !contact.empty())
                                                            {
                                                                contact.pop_back();
                                                                userInputTextcont.setString(contact);
                                                                Add_Student.draw(userInputTextcont);
                                                            }
                                                            else if (ageInputActive && !age.empty())
                                                            {
                                                                contact.pop_back();
                                                                userInputTextcont.setString(contact);
                                                                Add_Student.draw(userInputTextcont);
                                                            }
                                                        }
                                                    }
                                                    if (Add_Student_Event.type == Event::KeyPressed && Add_Student_Event.key.code == Keyboard::Enter) 
                                                    {
                                                        if (nameInputActive)
                                                        {
                                                            nameInputActive = false;
                                                            rollInputActive = true;
                                                        }
                                                        else if (rollInputActive)
                                                        {
                                                            validaltion objj;
                                                            chkvalidrollnumber = objj.is_valid_roll_number(rollnumber);

                                                            if (chkvalidrollnumber)
                                                            {
                                                                Validrollnumberprint.setString("");
                                                                rollInputActive = false;
                                                                contactInputActive = true;
                                                            }
                                                            else
                                                            {
                                                                Validrollnumberprint.setString("Roll Number is not valid Enter Again..");
                                                            }
                                                        }
                                                        else if (contactInputActive)
                                                        {
                                                            validaltion objj;
                                                            chkvalidcontact = objj.valid_contact(contact);
                                                            if (chkvalidcontact)
                                                            {
                                                                Validcontctprint.setString("");

                                                                contactInputActive = false;
                                                                ageInputActive = true;
                                                            }
                                                            else
                                                            {
                                                                Validcontctprint.setString("Contact is not Valid Enter Again");
                                                            }
                                                        }
                                                        else if(ageInputActive)
                                                        {
                                                            validaltion objj;
                                                            int x = stoi(age);
                                                            chkvalidage = objj.valid_age(x);
                                                            if (chkvalidage)
                                                            {
                                                                ValidAgeprint.setString("");
                                                                Save_Check = true;
                                                            }
                                                            else
                                                                ValidAgeprint.setString("Age is not Valid-Enter Again");
                                                        }
                                                    }
                                                }
                                                bool check_Fr_Save = false;
                                                Add_Student.clear(Color::White); // Clear the window before drawing

                                                text_Addstudent[0].setString("1 - Enter Student name                        :");
                                                text_Addstudent[1].setString("2 - Enter Student Roll number(17l-1234) :");
                                                text_Addstudent[2].setString("3 - Enter Student Contact Number          :");
                                                text_Addstudent[3].setString("4 - Enter Student Age                           :");
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Add_Student.draw(sprite);

                                                for (int i = 0; i < 4; i++)
                                                {
                                                    Add_Student.draw(text_Addstudent[i]);
                                                }
                                                //-----------Validity---------------------
                                                Add_Student.draw(Validrollnumberprint); // Roll NUmber 
                                                Add_Student.draw(Validcontctprint); // Contact 
                                                Add_Student.draw(ValidAgeprint); // Age 
                                                //-----------------------------------------

                                                Add_Student.draw(userInputTextname); // name 
                                                Add_Student.draw(userInputTextrollno);  // roll number 
                                                Add_Student.draw(userInputTextcont);  // contact
                                                Add_Student.draw(userInputTextage);   // age

                                                if (Save_Check)
                                                {
                                                    student obj;
                                                    int AgeInt = stoi(age);
                                                    obj.enroll_student(name, rollnumber, AgeInt, contact);
                                                    check_Fr_Save = add_student(obj);  // add student into file 
                                                    Save_Check = false;
                                                }
                                                if (check_Fr_Save)
                                                {
                                                    Sucesfullmsg.setString("Saved Succesfully-Press ESC to countinue");
                                                }
                                                
                                                Add_Student.draw(Sucesfullmsg);   // age
                                                Add_Student.display();
                                            }
                                        }

                                        // update student 
                                        if (eaevent.key.code == Keyboard::Num3)
                                        {
                                            string rollnumber__;

                                            Text text_Checker[3];
                                            RenderWindow Edit_detail(desktopMode, "Edit detail");
                                            Font fontt;
                                            fontt.loadFromFile("arial.ttf");
                                            Text text;
                                            text.setCharacterSize(50);
                                            text.setFont(fontt);
                                            text.setString("Enter your roll number :");
                                            text.setFillColor(Color::Black);
                                            text.setPosition(50, 400);
                                            Text userinputR;
                                            userinputR.setCharacterSize(50);
                                            userinputR.setFont(fontt);
                                            userinputR.setPosition(600, 400);
                                            userinputR.setFillColor(Color::Black);

                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                            //-------------------------------------------------
                                            int index = 0;
                                            while (Edit_detail.isOpen())
                                            {
                                                Event editdetailevent;
                                                while (Edit_detail.pollEvent(editdetailevent))
                                                {
                                                    if (editdetailevent.type == Event::Closed) {
                                                        Edit_detail.close();
                                                    }
                                                    if (editdetailevent.key.code == Keyboard::Escape)
                                                    {
                                                        Edit_detail.close();
                                                    }
                                                    if (editdetailevent.type == Event::TextEntered)
                                                    {
                                                        if (editdetailevent.text.unicode < 128 && editdetailevent.text.unicode > 31)
                                                        {
                                                            rollnumber__ += editdetailevent.text.unicode;
                                                            userinputR.setString(rollnumber__);
                                                            Edit_detail.draw(userinputR);
                                                        }
                                                        else if (editdetailevent.text.unicode == 8 && !rollnumber__.empty()) // backspace
                                                        {
                                                            rollnumber__.pop_back();
                                                            userinputR.setString(rollnumber__);
                                                            Edit_detail.draw(userinputR);
                                                        }
                                                    }
                                                    bool check = false;
                                                    if (Keyboard::isKeyPressed(Keyboard::Enter))
                                                    {
                                                        //----------Validity Check---------------
                                                        validaltion obj;
                                                        bool checkvalidrollnum = obj.is_valid_roll_number(rollnumber__);
                                                        if (checkvalidrollnum)
                                                        {
                                                            Validrollnumberprint.setString("");
                                                            for (int i = 0; i < student_count_System; i++)
                                                            {
                                                                if (students[i].get_roll_number() == rollnumber__)
                                                                {
                                                                    check = true;
                                                                    index = i;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            Validrollnumberprint.setString("Not Valid Try Again");
                                                        }

                                                        if (check)
                                                        {
                                                            RenderWindow EnterEditDetail(desktopMode, "Enter detail");
                                                            string name, rollnumber, contact;
                                                            string  age;
                                                            Font font;
                                                            font.loadFromFile("arial.ttf");


                                                            Text userInputTextname;
                                                            userInputTextname.setFillColor(Color::Black);
                                                            userInputTextname.setFont(font);
                                                            userInputTextname.setCharacterSize(50);
                                                            userInputTextname.setPosition(100 + 400, 400 + 50 * 0);



                                                            Text userInputTextcont;
                                                            userInputTextcont.setFillColor(Color::Black);
                                                            userInputTextcont.setFont(font);
                                                            userInputTextcont.setCharacterSize(50);
                                                            userInputTextcont.setPosition(100 + 400, 400 + 50 * 1);

                                                            Text userInputTextage;
                                                            userInputTextage.setFillColor(Color::Black);
                                                            userInputTextage.setFont(font);
                                                            userInputTextage.setCharacterSize(50);
                                                            userInputTextage.setPosition(100 + 400, 400 + 50 * 2);

                                                            bool nameInputActive = true;
                                                            bool rollInputActive = false;
                                                            bool contactInputActive = false;
                                                            bool ageInputActive = false;
                                                            bool Save_Check = false;
                                                            Text messges_Saved_Sucesfully;
                                                            messges_Saved_Sucesfully.setFont(fontt);
                                                            messges_Saved_Sucesfully.setCharacterSize(50);
                                                            messges_Saved_Sucesfully.setPosition(20, 400 + 50 * 5);
                                                            messges_Saved_Sucesfully.setFillColor(Color::Black);
                                                            while (EnterEditDetail.isOpen())
                                                            {

                                                                Event evt;
                                                                while (EnterEditDetail.pollEvent(evt))
                                                                {
                                                                    if (evt.type == Event::Closed) {
                                                                        EnterEditDetail.close();
                                                                    }
                                                                    if (evt.key.code == Keyboard::Escape)
                                                                    {
                                                                        EnterEditDetail.close();
                                                                    }
                                                                    if (evt.type == Event::Closed)
                                                                    {
                                                                        Edit_detail.close();
                                                                    }
                                                                    if (evt.key.code == Keyboard::Escape)
                                                                    {
                                                                        Edit_detail.close();
                                                                    }

                                                                    if (evt.type == Event::TextEntered)
                                                                    {
                                                                        if (evt.text.unicode < 128 && evt.text.unicode > 31)
                                                                        {
                                                                            if (nameInputActive)
                                                                            {
                                                                                name += evt.text.unicode;
                                                                                userInputTextname.setString(name);
                                                                                EnterEditDetail.draw(userInputTextname);
                                                                            }

                                                                            else if (contactInputActive)
                                                                            {
                                                                                contact += evt.text.unicode;
                                                                                userInputTextcont.setString(contact);
                                                                                EnterEditDetail.draw(userInputTextcont);
                                                                            }
                                                                            else if (ageInputActive)
                                                                            {
                                                                                age += evt.text.unicode;
                                                                                userInputTextage.setString(age);
                                                                                EnterEditDetail.draw(userInputTextage);
                                                                            }
                                                                        }
                                                                        else if (evt.text.unicode == 8)
                                                                        {
                                                                            if (nameInputActive && !name.empty())
                                                                            {
                                                                                name.pop_back();
                                                                                userInputTextname.setString(name);
                                                                                EnterEditDetail.draw(userInputTextname);
                                                                            }
                                                                            else if (contactInputActive && !contact.empty())
                                                                            {
                                                                                contact.pop_back();
                                                                                userInputTextcont.setString(contact);
                                                                                EnterEditDetail.draw(userInputTextcont);
                                                                            }
                                                                            else if (ageInputActive && !age.empty())
                                                                            {
                                                                                age.pop_back();
                                                                                userInputTextcont.setString(contact);
                                                                                EnterEditDetail.draw(userInputTextcont);
                                                                            }
                                                                        }
                                                                    }
                                                                    if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Enter) {
                                                                        if (nameInputActive)
                                                                        {
                                                                            nameInputActive = false;
                                                                            contactInputActive = true;
                                                                        }
                                                                        else if (contactInputActive)
                                                                        {
                                                                            contactInputActive = false;
                                                                            ageInputActive = true;
                                                                        }
                                                                        else
                                                                        {
                                                                            Save_Check = true;
                                                                        }
                                                                    }
                                                                    if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Enter && Save_Check == true)
                                                                    {
                                                                        int x = stoi(contact);
                                                                        students[index].set_age(x);
                                                                        students[index].set_contact(age);
                                                                        students[index].set_name(name);
                                                                        ofstream Filee_NamE("studentdata.txt", ios::trunc); // trunc remove all the existing data from the file 
                                                                        ofstream Filee_NamE2("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file 

                                                                        for (int i = 0; i < student_count_System; i++)
                                                                        {
                                                                            filehandling obj("Studentdata.txt");
                                                                            filehandling obj2("student_all_data.txt");
                                                                            obj.write_Student_data_into_File(students[i]);    // again write data into file after trunc
                                                                            obj2.write_student_courses(students[i]);

                                                                        }
                                                                        messges_Saved_Sucesfully.setString("UPdtaed Sucessfully press ESC for Exit ");
                                                                    }
                                                                }
                                                                EnterEditDetail.clear(Color::White);
                                                                EnterEditDetail.draw(sprite);
                                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                                EnterEditDetail.draw(messges_Saved_Sucesfully);
                                                                EnterEditDetail.draw(userInputTextname); // name 
                                                                EnterEditDetail.draw(userInputTextcont);  // contact
                                                                EnterEditDetail.draw(userInputTextage);   // age
                                                                for (int i = 0; i < 3; i++)
                                                                {
                                                                    text_Checker[i].setCharacterSize(50);
                                                                    text_Checker[i].setFillColor(Color::Black);
                                                                    text_Checker[i].setPosition(20, 400 + 50 * i);
                                                                    text_Checker[i].setFont(fontt);
                                                                }
                                                                text_Checker[0].setString("Enter Edited Name :");
                                                                text_Checker[1].setString("Enter Edited Age :");
                                                                text_Checker[2].setString("Enter Edited Contact :");
                                                                EnterEditDetail.draw(sprite);
                                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                                for (int i = 0; i < 3; i++)
                                                                {
                                                                    EnterEditDetail.draw(text_Checker[i]);
                                                                }
                                                                EnterEditDetail.display();
                                                            }
                                                        }
                                                    }
                                                }
                                                Edit_detail.clear(Color::White);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Edit_detail.draw(sprite);
                                                Edit_detail.draw(Validrollnumberprint);
                                                Edit_detail.draw(text);
                                                Edit_detail.draw(userinputR);
                                                Edit_detail.display();

                                            }
                                        }
                                        // remove student
                                        if (eaevent.key.code == Keyboard::Num4)
                                        {
                                            RenderWindow removeStudent(desktopMode, "Remove Student");
                                            Font fontt;
                                            fontt.loadFromFile("arial.ttf");
                                            Text Remove;
                                            Remove.setFont(fontt);
                                            Remove.setFillColor(Color::Black);
                                            Remove.setCharacterSize(50);
                                            Remove.setString("ENter ROll number to Remove Student : ");
                                            Remove.setPosition(50, 400);//rem

                                            Text Conformation;
                                            Conformation.setFillColor(Color::Black);
                                            Conformation.setCharacterSize(50);
                                            Conformation.setFont(fontt);
                                            Conformation.setPosition(20, 700);

                                            Text userinput;
                                            userinput.setFillColor(Color::Black);
                                            userinput.setCharacterSize(50);
                                            userinput.setPosition(950, 400);//user

                                            userinput.setFont(fontt);


                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(fontt);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                            //-------------------------------------------------

                                            string roll_Number;
                                            int index = -1 ;
                                            bool check_Ava = false;
                                            int assingn_value = 1;
                                            while (removeStudent.isOpen())
                                            {
                                                Event obj;
                                                while (removeStudent.pollEvent(obj))
                                                {
                                                    if (obj.type == Event::Closed)
                                                    {
                                                        removeStudent.close();
                                                    }
                                                    if (obj.key.code == Keyboard::Escape)
                                                    {
                                                        removeStudent.close();
                                                    }
                                                    if (obj.type == Event::TextEntered)
                                                    {
                                                        if (obj.text.unicode < 128 && obj.text.unicode > 31)
                                                        {

                                                            roll_Number += obj.text.unicode;
                                                            userinput.setString(roll_Number);
                                                            removeStudent.draw(userinput);
                                                        }
                                                        else if (obj.text.unicode == 8 && !roll_Number.empty()) // backspace
                                                        {
                                                            roll_Number.pop_back();
                                                            userinput.setString(roll_Number);
                                                            removeStudent.draw(userinput);
                                                        }
                                                    }
                                                    if (obj.key.code == Keyboard::Enter && obj.type == Event::KeyReleased)
                                                    {
                                                        validaltion objj;
                                                        bool checkVaLiD = objj.is_valid_roll_number(roll_Number);


                                                        if (checkVaLiD)
                                                        {
                                                            Validrollnumberprint.setString("");
                                                            for (int i = 0; i < student_count_System; i++)
                                                            {
                                                                if (students[i].get_roll_number() == roll_Number)
                                                                {
                                                                    students[i].set_age(0);
                                                                    students[i].set_name("");
                                                                    students[i].set_rollnumber("");
                                                                    students[i].set_contact("");

                                                                    int y = students[i].get_course_count_student();

                                                                    // make coourses null 
                                                                    for (int j = 0; j < y; j++)
                                                                    {
                                                                        students[i].add_course_student("");
                                                                    }

                                                                    // make attendence null 
                                                                    for (int j = 0; j < y; j++)
                                                                    {
                                                                        students[i].mark_attendence('\0');
                                                                    }

                                                                    // make marks zero 
                                                                    for (int j = 0; j < y; j++)
                                                                    {
                                                                        students[i].marks_assingn(0);
                                                                    }

                                                                    ofstream Filee_NamE("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file 
                                                                    ofstream Filee_NamE2("studentdata.txt", ios::trunc); // trunc remove all the existing data from the file 

                                                                    for (int z = 0; z < student_count_System; z++)
                                                                    {
                                                                        if (z != i)  // Check against the correct index
                                                                        {
                                                                            filehandling fileObj("student_all_data.txt");
                                                                            filehandling filee("studentdata.txt");
                                                                            fileObj.write_student_courses(students[z]);    // again write data into file after trunc
                                                                            filee.write_Student_data_into_File(students[z]);
                                                                        }
                                                                    }
                                                                    Conformation.setString("Remove Successfully. Press ESC To continue");
                                                                    student_count_System--;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        else
                                                            Validrollnumberprint.setString("Not Valid RollNumber input Enter(17l-1234)");
                                                    }
                                                }
                                                removeStudent.clear(Color::White);
                                                removeStudent.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                removeStudent.draw(Validrollnumberprint);
                                                removeStudent.draw(Remove);
                                                removeStudent.draw(Conformation);
                                                removeStudent.draw(userinput);
                                                removeStudent.display();
                                            }
                                        }
                                        if (eaevent.key.code == Keyboard::Num5)
                                        {
                                            Enroll.close();
                                        }
                                    }
                                }
                                Enroll.clear(Color::White);
                                Register.close();
                                Marks.close();
                                Attendence.close();
                                Withdraw.close();
                                Exit.close();
                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                Enroll.draw(sprite);
                                displayStudentSubMenu(Enroll);

                                Enroll.display();
                            }
                        }

                        if (x == 1)
                        {

                            while (Register.isOpen())
                            {
                                Event eaevent;

                                while (Register.pollEvent(eaevent))
                                {
                                    if (eaevent.type == Event::Closed)
                                    {
                                        Register.close();
                                        break; // Break out of the inner loop
                                    }

                                    // Show avalible courses 
                                    if (eaevent.key.code == Keyboard::Num1)
                                    {
                                        RenderWindow Avalible_Courses(desktopMode, "1 - Avalible courses");
                                        Font fontt;
                                        fontt.loadFromFile("arial.ttf");
                                        int check = true;
                                        Text text;
                                        text.setFont(fontt);
                                        text.setCharacterSize(50);
                                        text.setFillColor(Color::Black);

                                        string line;
                                        while (Avalible_Courses.isOpen())
                                        {
                                            Event evnt;
                                            while (Avalible_Courses.pollEvent(evnt))
                                            {
                                                if (evnt.type == Event::Closed)
                                                {
                                                    Avalible_Courses.close();
                                                }
                                                if (evnt.key.code == Keyboard::Escape)
                                                {
                                                    Avalible_Courses.close();
                                                }
                                            }
                                            Avalible_Courses.clear(Color::White);
                                            for (int i = 0; i < course_count_system; i++)
                                            {
                                                text.setFillColor(Color::Black);
                                                text.setPosition(20, 300 + 60 * i);
                                                courses[i].display_Course(Avalible_Courses, text);  // display courses 
                                            }
                                            Avalible_Courses.draw(sprite);
                                            sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                            Avalible_Courses.display();
                                        }
                                    }
                                    // Register courses 
                                    if (eaevent.key.code == Keyboard::Num2)
                                    {
                                        RenderWindow Register_Student_menu(desktopMode, "Register Student Menu");
                                        Text text;
                                        Font font;
                                        font.loadFromFile("arial.ttf");
                                        text.setFont(font);
                                        text.setCharacterSize(50);
                                        text.setPosition(50, 400);
                                        text.setString("ENter ROll number of student :");
                                        text.setFillColor(Color::Black);
                                        string roll_Number;
                                        Text UserInput;
                                        UserInput.setFont(font);
                                        UserInput.setCharacterSize(50);
                                        UserInput.setPosition(950 ,  400);

                                        UserInput.setFillColor(Color::Black);
                                        Text t1, t2;
                                        t1.setFillColor(Color::Black);
                                        t2.setFillColor(Color::Red);
                                        t1.setPosition(200, 300); t2.setPosition(200 * 6, 300);
                                        t1.setCharacterSize(50); t2.setCharacterSize(50);
                                        t1.setFont(font);
                                        t2.setFont(font);



                                        //-----------Valid RollNumber check----------------
                                        Text Validrollnumberprint;
                                        Validrollnumberprint.setFillColor(Color::Red);
                                        Validrollnumberprint.setFont(font);
                                        Validrollnumberprint.setCharacterSize(28);
                                        Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                        //-------------------------------------------------

                                        while (Register_Student_menu.isOpen())
                                        {
                                            Event evnt;
                                            while (Register_Student_menu.pollEvent(evnt))
                                            {
                                                if (evnt.type == Event::Closed)
                                                {
                                                    Register_Student_menu.close();
                                                }
                                                if (evnt.key.code == Keyboard::Escape)
                                                {
                                                    Register_Student_menu.close();
                                                }
                                                if (evnt.type == Event::TextEntered)
                                                {
                                                    if (evnt.text.unicode < 128 && evnt.text.unicode > 31)
                                                    {
                                                        roll_Number += evnt.text.unicode;
                                                        UserInput.setString(roll_Number);
                                                        Register_Student_menu.draw(UserInput);
                                                    }
                                                    else if (evnt.text.unicode == 8 && !roll_Number.empty()) // backspace
                                                    {
                                                        roll_Number.pop_back();
                                                        UserInput.setString(roll_Number);
                                                        Register_Student_menu.draw(UserInput);
                                                    }
                                                }
                                                int student_index = 0;

                                                if (evnt.key.code == Keyboard::Enter)
                                                {
                                                    validaltion obj; 
                                                    bool checkVlID = obj.is_valid_roll_number(roll_Number);
                                                    if (checkVlID)
                                                    {

                                                        Validrollnumberprint.setString("");
                                                        bool Chk_Ava = false;
                                                        int index = 0;
                                                        for (int i = 0; i < student_count_System; i++)
                                                        {
                                                            if (roll_Number == students[i].get_roll_number())
                                                            {
                                                                index = i;
                                                                student_index = i;
                                                                Chk_Ava = true;
                                                                break;
                                                            }
                                                        }
                                                        if (Chk_Ava)
                                                        {

                                                            t1.setString("Enter Code of course :");
                                                            string code_OF_Course;
                                                            Text usERinput;
                                                            usERinput.setFillColor(Color::Black);
                                                            usERinput.setCharacterSize(50);
                                                            usERinput.setFont(font);
                                                            usERinput.setPosition(800, 300);

                                                            Text Escapemsg;
                                                            Escapemsg.setFillColor(Color::Red);
                                                            Escapemsg.setCharacterSize(50);
                                                            Escapemsg.setFont(font);
                                                            Escapemsg.setPosition(300, 700);

                                                            Text No_Course_Exist;
                                                            No_Course_Exist.setFillColor(Color::Black);
                                                            No_Course_Exist.setCharacterSize(50);
                                                            No_Course_Exist.setFont(font);
                                                            No_Course_Exist.setPosition(300, 750);

                                                            Text COnformation;
                                                            COnformation.setFillColor(Color::Green);
                                                            COnformation.setCharacterSize(50);
                                                            COnformation.setFont(font);
                                                            COnformation.setPosition(300, 600);

                                                            Text max_Cap_Reached;
                                                            max_Cap_Reached.setFillColor(Color::Red);
                                                            max_Cap_Reached.setPosition(200, 800);
                                                            max_Cap_Reached.setCharacterSize(50);
                                                            max_Cap_Reached.setFont(font);

                                                            Register_Student_menu.draw(t1);
                                                            bool enterKeyPressed = false;
                                                            RenderWindow entercodewindow(desktopMode, "ENter code");
                                                            while (entercodewindow.isOpen())
                                                            {
                                                                Event evntforentercodewindow;
                                                                while (entercodewindow.pollEvent(evntforentercodewindow))
                                                                {
                                                                    if (evntforentercodewindow.type == Event::Closed)
                                                                    {
                                                                        entercodewindow.close();
                                                                    }
                                                                    if (evntforentercodewindow.key.code == Keyboard::Escape)
                                                                    {
                                                                        entercodewindow.close();
                                                                    }
                                                                    if (evntforentercodewindow.type == Event::TextEntered)
                                                                    {
                                                                        if (evntforentercodewindow.text.unicode < 128 && evntforentercodewindow.text.unicode > 31)
                                                                        {
                                                                            code_OF_Course += evntforentercodewindow.text.unicode;
                                                                            usERinput.setString(code_OF_Course);
                                                                            entercodewindow.draw(usERinput);
                                                                        }
                                                                        else if (aevent.text.unicode == 8 && !code_OF_Course.empty()) // backspace
                                                                        {
                                                                            code_OF_Course.pop_back();
                                                                            usERinput.setString(code_OF_Course);
                                                                            entercodewindow.draw(usERinput);
                                                                        }
                                                                    }
                                                                    bool check_course_avalibility = false;;

                                                                    if (evntforentercodewindow.type == Event::KeyReleased && evntforentercodewindow.key.code == Keyboard::Enter) {
                                                                        enterKeyPressed = true;
                                                                        for (int i = 0; i < course_count_system; i++)
                                                                        {
                                                                            if (courses[i].get_code() == code_OF_Course)
                                                                            {
                                                                                if (students[student_index].get_course_count_student() > 4)
                                                                                {
                                                                                    max_Cap_Reached.setString("MAx course count reached ! Thank you");
                                                                                }
                                                                                else
                                                                                {
                                                                                    students[student_index].add_course_student(courses[i].get_name());

                                                                                    COnformation.setString("Registered Sucessfylly");
                                                                                    Escapemsg.setString("Press Escape to countinue");
                                                                                    entercodewindow.draw(COnformation);
                                                                                    entercodewindow.draw(Escapemsg);
                                                                                    check_course_avalibility = true;
                                                                                    // write all data into file first delete data then write new data 
                                                                                    {
                                                                                        ofstream Filee_NamE_Course("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file

                                                                                        filehandling obj("student_all_data.txt");
                                                                                        for (int i = 0; i < student_count_System; i++)
                                                                                        {
                                                                                            obj.write_student_courses(students[i]);   // write student data with courses 
                                                                                        }
                                                                                    }
                                                                                    break;
                                                                                }

                                                                            }
                                                                        }
                                                                    }
                                                                    /*else
                                                                    {
                                                                        No_Course_Exist.setString("NO Course Exist with that Code number ");
                                                                        Escapemsg.setString("Press Escape to countinue");
                                                                        entercodewindow.draw(No_Course_Exist);
                                                                        entercodewindow.draw(Escapemsg);
                                                                    }*/
                                                                }
                                                                entercodewindow.clear(Color::White);
                                                                entercodewindow.draw(sprite);
                                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                                entercodewindow.draw(max_Cap_Reached);
                                                                entercodewindow.draw(t1);
                                                                entercodewindow.draw(COnformation);
                                                                entercodewindow.draw(No_Course_Exist);
                                                                entercodewindow.draw(usERinput);
                                                                entercodewindow.draw(Escapemsg);
                                                                entercodewindow.display();

                                                            }

                                                        }
                                                        else
                                                        {

                                                             t2.setString("No Student Exist...Try Again ");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        Validrollnumberprint.setString("Not-Valid Enter Again in that format(17l-0987)");
                                                    }

                                                }
                                            }
                                            Register_Student_menu.clear(Color::White);
                                            Register_Student_menu.draw(sprite);
                                            sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                            Register_Student_menu.draw(Validrollnumberprint);
                                            Register_Student_menu.draw(t2);
                                            Register_Student_menu.draw(text);
                                            Register_Student_menu.draw(UserInput);
                                            Register_Student_menu.display();
                                        }
                                    }
                                    if (eaevent.type == Event::KeyPressed && eaevent.key.code == Keyboard::Num3)
                                    {
                                        Register.close();
                                    }
                                }
                                Enroll.close();
                                Marks.close();
                                Attendence.close();
                                Withdraw.close();
                                Exit.close();
                                Register.clear(Color::White);
                                Register.draw(sprite);
                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                displayCourseSubMenu(Register);
                                Register.display();
                            }
                        }
                        // x == 2 is attendence 
                        if (x == 2)
                        {
                            while (Attendence.isOpen())
                            {
                                Event eaevent;
                                while (Attendence.pollEvent(eaevent))
                                {
                                    if (eaevent.type == Event::Closed)
                                    {
                                        Attendence.close();
                                    }
                                    if (eaevent.type == Event::KeyPressed)
                                    {
                                        if (eaevent.key.code == Keyboard::Num1)
                                        {
                                            // display student 
                                            if (eaevent.key.code == Keyboard::Num1)
                                            {
                                                RenderWindow Display_Attendece(desktopMode, "Display Attendece");
                                                Font fontt;
                                                fontt.loadFromFile("arial.ttf");
                                                int check = true;
                                                Text text;
                                                text.setFont(fontt);
                                                text.setCharacterSize(30);
                                                text.setFillColor(Color::Black);

                                                string line;
                                                while (Display_Attendece.isOpen())
                                                {
                                                    ifstream inputFile("student_attendence.txt");  // Replace "data.txt" with your actual file name
                                                    Event evnt;
                                                    while (Display_Attendece.pollEvent(evnt))
                                                    {
                                                        if (evnt.type == Event::Closed)
                                                        {
                                                            Display_Attendece.close();
                                                        }
                                                        if (evnt.key.code == Keyboard::Escape)
                                                        {
                                                            Display_Attendece.close();
                                                        }
                                                    }
                                                    Display_Attendece.clear(Color::White);
                                                    int i = 0;
                                                    while (getline(inputFile, line))
                                                    {
                                                        text.setPosition(20, 300 + 60 * i);
                                                        text.setString(line);
                                                        Display_Attendece.draw(text);
                                                        i++;
                                                    }

                                                    inputFile.close();
                                                    Display_Attendece.draw(sprite);
                                                    sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                    Display_Attendece.display();
                                                }
                                            }
                                        }
                                        // ADD attendence 
                                        if (eaevent.key.code == Keyboard::Num2)
                                        {
                                            RenderWindow Enter_Attendence(desktopMode, "Enter_Attendence");
                                            Text text;
                                            Font font;
                                            font.loadFromFile("arial.ttf");
                                            text.setFont(font);
                                            text.setCharacterSize(50);
                                            text.setPosition(0, 0);
                                            text.setFillColor(Color::Black);
                                            text.setString("ENter ROll number of student :");
                                            text.setPosition(50, 400);//rem


                                            Text text2;
                                            text2.setFont(font);
                                            text2.setCharacterSize(50);
                                            text2.setPosition(750, 300 + 60 * 7);
                                            
                                            text2.setFillColor(Color::Green);
                                            string roll_NumberR;
                                            Text UserInputR;

                                            UserInputR.setFont(font);
                                            UserInputR.setCharacterSize(50);
                                            UserInputR.setPosition(950, 400);
                                            UserInputR.setFillColor(Color::Black);

                                            Text NoCourseOUtput;

                                            NoCourseOUtput.setFont(font);
                                            NoCourseOUtput.setCharacterSize(50);
                                            NoCourseOUtput.setPosition(950, 900);
                                            NoCourseOUtput.setFillColor(Color::Red);


                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                            //-------------------------------------------------


                                            Text Attendence[5];
                                            bool checkkk = true;
                                            while (Enter_Attendence.isOpen())
                                            {
                                                Event evnt;
                                                while (Enter_Attendence.pollEvent(evnt))
                                                {
                                                    if (evnt.type == Event::Closed)
                                                    {
                                                        Enter_Attendence.close();
                                                    }
                                                    if (evnt.key.code == Keyboard::Escape)
                                                    {
                                                        Enter_Attendence.close();
                                                    }
                                                    if (evnt.type == Event::TextEntered)
                                                    {
                                                        if (evnt.text.unicode < 128 && evnt.text.unicode > 31)
                                                        {
                                                            roll_NumberR += evnt.text.unicode;
                                                            UserInputR.setString(roll_NumberR);
                                                            Enter_Attendence.draw(UserInputR);
                                                        }
                                                         else if (evnt.text.unicode == 8 && !roll_NumberR.empty()) // backspace
                                                         {
                                                            roll_NumberR.pop_back();
                                                            UserInputR.setString(roll_NumberR);
                                                            Enter_Attendence.draw(UserInputR);
                                                         }
                                                    }
                                                    bool chk = false;
                                                    int index_ofSTu = 0;
                                                    if (evnt.key.code == Keyboard::Enter)
                                                    {
                                                        validaltion obj;
                                                        bool cheking = obj.is_valid_roll_number(roll_NumberR);
                                                        if (cheking)
                                                        {
                                                            Validrollnumberprint.setString("");

                                                            for (int i = 0; i < student_count_System; i++)
                                                            {
                                                                if (roll_NumberR == students[i].get_roll_number())
                                                                {
                                                                    index_ofSTu = i;
                                                                    chk = true;
                                                                }
                                                            }
                                                        }
                                                        else
                                                            Validrollnumberprint.setString("Not Valid-Enter in that Order(17l-1234)");
                                                          
                                                    }
                                                    bool checkforenter = false;
                                                    if (chk)
                                                    {

                                                        char Att = '\0';
                                                        Text UserInputforAttendece;
                                                        UserInputforAttendece.setFont(font);
                                                        UserInputforAttendece.setCharacterSize(50);
                                                        UserInputforAttendece.setFillColor(Color::Black);

                                                        RenderWindow SubWindowENterAttendence(desktopMode, "ENter Attendence");
                                                        int x = students[index_ofSTu].get_course_count_student();
                                                        int checkforx = 0;
                                                        if (x > 0)
                                                        {
                                                            for (int i = 0; i < x; i++)
                                                            {
                                                                Attendence[i].setFillColor(Color::Black);
                                                                Attendence[i].setCharacterSize(50);
                                                                Attendence[i].setFont(font);
                                                                Attendence[i].setPosition(20, 300 + 60 * i);

                                                                Attendence[i].setString("Enter Attendence for " + students[index_ofSTu].get_course_student(i) + ":");

                                                            }
                                                            int p = 0;
                                                            bool enterKeyPressed = false;
                                                            while (SubWindowENterAttendence.isOpen())
                                                            {
                                                                Event EnterAttendeceEVENT;
                                                                while (SubWindowENterAttendence.pollEvent(EnterAttendeceEVENT))
                                                                {
                                                                    if (EnterAttendeceEVENT.type == Event::Closed)
                                                                    {
                                                                        SubWindowENterAttendence.close();
                                                                    }
                                                                    if (EnterAttendeceEVENT.key.code == Keyboard::Escape)
                                                                    {
                                                                        SubWindowENterAttendence.close();
                                                                    }
                                                                    if (EnterAttendeceEVENT.type == Event::TextEntered)
                                                                    {
                                                                        if (EnterAttendeceEVENT.text.unicode < 128 && EnterAttendeceEVENT.text.unicode > 31)
                                                                        {
                                                                            UserInputforAttendece.setPosition(750, 300 + 60 * p++);
                                                                            
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            checkforx++;
                                                                        }
                                                                       
                                                                    }

                                                                    if (Keyboard::isKeyPressed(Keyboard::Enter) && !enterKeyPressed)
                                                                    {
                                                                        cout << Att << endl;
                                                                        students[index_ofSTu].mark_attendence(Att);
                                                                        Att = '\0';
                                                                        enterKeyPressed = true;
                                                                    }
                                                                    else if (!Keyboard::isKeyPressed(Keyboard::Enter))
                                                                    {
                                                                        enterKeyPressed = false;
                                                                    }
                                                                    if (checkforx - 1 == x && checkkk)
                                                                    {
                                                                        checkkk = false;
                                                                        text2.setString("Entered Succesfully \n Press Escape To Countinue :");
                                                                        filehandling obj("student_attendence.txt");
                                                                        obj.write_attendence(students[index_ofSTu], x);
                                                                    }
                                                                }
                                                                SubWindowENterAttendence.clear(Color::White);

                                                                for (int i = 0; i < x; i++)
                                                                {
                                                                    SubWindowENterAttendence.draw(Attendence[i]);
                                                                }
                                                                SubWindowENterAttendence.draw(sprite);
                                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                                SubWindowENterAttendence.draw(text2);
                                                                SubWindowENterAttendence.draw(UserInputforAttendece);
                                                                SubWindowENterAttendence.display();
                                                            }


                                                        }
                                                        else
                                                        {
                                                            NoCourseOUtput.setString("Student has no Courses ");
                                                        }
                                                           
                                                    }
                                                }
                                                Enter_Attendence.clear(Color::White);
                                                Enter_Attendence.draw(Validrollnumberprint);
                                                Enter_Attendence.draw(sprite);
                                                Enter_Attendence.draw(NoCourseOUtput);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Enter_Attendence.draw(UserInputR);
                                                Enter_Attendence.draw(text);
                                                Enter_Attendence.display();
                                            }
                                        }
                                        if (eaevent.key.code == Keyboard::Num3)
                                        {
                                            Attendence.close();
                                        }

                                    }
                                }
                                Enroll.close();
                                Register.close();
                                Marks.close();
                                Withdraw.close();
                                Exit.close();
                                Attendence.clear(Color::White);
                                Attendence.draw(sprite);
                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                displayattendencesubmenu(Attendence);
                                Attendence.display();
                            }
                        }
                        // Marks of students 
                        if (x == 3)
                        {
                            while (Marks.isOpen())
                            {
                                Event eaevent;
                                while (Marks.pollEvent(eaevent))
                                {
                                    if (eaevent.type == Event::Closed)
                                    {
                                        Marks.close();
                                    }
                                    if (eaevent.type == Event::KeyPressed)
                                    {
                                        if (eaevent.key.code == Keyboard::Num1)
                                        {
                                            RenderWindow Display_Marks(desktopMode, "Display Marks");
                                            Font fontt;
                                            fontt.loadFromFile("arial.ttf");
                                            int check = true;
                                            Text text;
                                            text.setFont(fontt);
                                            text.setCharacterSize(24);
                                            text.setFillColor(Color::Black);
                                            
                                            string line;
                                            while (Display_Marks.isOpen())
                                            {
                                                ifstream inputFile("students_marks.txt");  
                                                Event evnt;
                                                while (Display_Marks.pollEvent(evnt))
                                                {
                                                    if (evnt.type == Event::Closed)
                                                    {
                                                        Display_Marks.close();
                                                    }
                                                    if (evnt.key.code == Keyboard::Escape)
                                                    {
                                                        Display_Marks.close();
                                                    }
                                                }
                                                int i = 0;
                                                Display_Marks.clear(Color::White);
                                                while (getline(inputFile, line))
                                                {
                                                    text.setPosition(20, 300 + 20 * i);
                                                    text.setString(line);
                                                    Display_Marks.draw(text);
                                                    i++;
                                                }
                                                inputFile.close();
                                                Display_Marks.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Display_Marks.display();
                                            }
                                        }
                                        // ENter marks of Students 
                                        if (eaevent.key.code == Keyboard::Num2)
                                        {
                                            RenderWindow Enter_MARKS(desktopMode, "Enter Students Marks");
                                            Text text;
                                            Font font;
                                            font.loadFromFile("arial.ttf");
                                            text.setFont(font);
                                            text.setCharacterSize(50);
                                            text.setPosition(50, 400);//rem
                                            text.setString("ENter ROll number of student :");
                                            text.setFillColor(Color::Black);
                                            Text text2;
                                            text2.setFont(font);
                                            text2.setCharacterSize(50);
                                            text2.setPosition(100, 700);
                                            text2.setFillColor(Color::Green);

                                            string roll_NumberR;
                                            Text UserInputR;
                                            UserInputR.setFont(font);
                                            UserInputR.setCharacterSize(50);
                                            UserInputR.setPosition(950, 400);
                                            UserInputR.setFillColor(Color::Black);

                                            Text NotExist;
                                            NotExist.setFont(font);
                                            NotExist.setCharacterSize(50);
                                            NotExist.setPosition(950, 800);
                                            NotExist.setFillColor(Color::Red);

                                            Text Nocourse;
                                            Nocourse.setFont(font);
                                            Nocourse.setCharacterSize(50);
                                            Nocourse.setPosition(950, 700);
                                            Nocourse.setFillColor(Color::Red);


                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                            //-------------------------------------------------


                                            Text Marksofstudent[5];
                                            bool checkkk = true;
                                            bool chk = false;
                                            int index_ofSTu = 0;
                                            while (Enter_MARKS.isOpen())
                                            {
                                                Event evnt;
                                                while (Enter_MARKS.pollEvent(evnt))
                                                {
                                                    if (evnt.type == Event::Closed)
                                                    {
                                                        Enter_MARKS.close();
                                                    }
                                                    if (evnt.key.code == Keyboard::Escape)
                                                    {
                                                        Enter_MARKS.close();
                                                    }
                                                    if (evnt.type == Event::TextEntered)
                                                    {
                                                        if (evnt.text.unicode < 128 && evnt.text.unicode > 31)
                                                        {
                                                            roll_NumberR += evnt.text.unicode;
                                                            UserInputR.setString(roll_NumberR);
                                                            Enter_MARKS.draw(UserInputR);
                                                        }
                                                        else if (evnt.text.unicode == 8 && !roll_NumberR.empty()) // backspace
                                                        {
                                                            roll_NumberR.pop_back();
                                                            UserInputR.setString(roll_NumberR);
                                                            Enter_MARKS.draw(UserInputR);
                                                        }
                                                    }

                                                    if (evnt.key.code == Keyboard::Enter)
                                                    {
                                                        validaltion obj;
                                                        bool checking = obj.is_valid_roll_number(roll_NumberR);
                                                        if (checking)
                                                        {
                                                            Validrollnumberprint.setString("");
                                                            for (int i = 0; i < student_count_System; i++)
                                                            {
                                                                if (roll_NumberR == students[i].get_roll_number())
                                                                {
                                                                    index_ofSTu = i;
                                                                    chk = true;
                                                                    break;
                                                                }
                                                            }
                                                            if (chk)
                                                            {
                                                                bool ENtermarksCheck = false;
                                                                string MArKsS;
                                                                int checkforx = 0;

                                                                Text UserInputforMarks;
                                                                UserInputforMarks.setFont(font);
                                                                UserInputforMarks.setCharacterSize(50);
                                                                UserInputforMarks.setFillColor(Color::Black);

                                                                int x = students[index_ofSTu].get_course_count_student();
                                                                if (x > 0)
                                                                {
                                                                    RenderWindow SubWindowENterMarks(desktopMode, "ENter MArks of STudent");
                                                                    for (int i = 0; i < x; i++)
                                                                    {
                                                                        Marksofstudent[i].setFillColor(Color::Black);
                                                                        Marksofstudent[i].setCharacterSize(50);
                                                                        Marksofstudent[i].setFont(font);
                                                                        Marksofstudent[i].setPosition(20, 300 + 60 * i);
                                                                        Marksofstudent[i].setString("Enter Marks for " + students[index_ofSTu].get_course_student(i) + ":");
                                                                    }
                                                                    int p = 0;
                                                                    bool enterKeyPressed = false;
                                                                    while (SubWindowENterMarks.isOpen())
                                                                    {
                                                                        Event EnterMarksEVENT;
                                                                        while (SubWindowENterMarks.pollEvent(EnterMarksEVENT))
                                                                        {
                                                                            if (EnterMarksEVENT.type == Event::Closed)
                                                                            {
                                                                                SubWindowENterMarks.close();
                                                                            }
                                                                            if (EnterMarksEVENT.key.code == Keyboard::Escape)
                                                                            {
                                                                                SubWindowENterMarks.close();
                                                                            }
                                                                            if (EnterMarksEVENT.type == Event::TextEntered)
                                                                            {
                                                                                if (EnterMarksEVENT.text.unicode < 128 && EnterMarksEVENT.text.unicode > 31)
                                                                                {
                                                                                    if (checkforx == 0 && checkforx < x)
                                                                                    {
                                                                                        UserInputforMarks.setPosition(450 + 170, 300 + 100 * 0);
                                                                                        MArKsS += EnterMarksEVENT.text.unicode;
                                                                                        UserInputforMarks.setString(MArKsS);
                                                                                        ENtermarksCheck = true;
                                                                                    }
                                                                                    if (checkforx == 1 && checkforx < x)
                                                                                    {
                                                                                        UserInputforMarks.setPosition(450 + 170, 300 + 100 * 1);
                                                                                        MArKsS += EnterMarksEVENT.text.unicode;
                                                                                        UserInputforMarks.setString(MArKsS);
                                                                                        ENtermarksCheck = true;

                                                                                    }
                                                                                    if (checkforx == 2 && checkforx < x)
                                                                                    {
                                                                                        UserInputforMarks.setPosition(450 + 170, 300 + 100 * 2);
                                                                                        MArKsS += EnterMarksEVENT.text.unicode;
                                                                                        UserInputforMarks.setString(MArKsS);
                                                                                        ENtermarksCheck = true;

                                                                                    }
                                                                                    if (checkforx == 3 && checkforx < x)
                                                                                    {
                                                                                        UserInputforMarks.setPosition(450 + 170, 300 + 100 * 3);
                                                                                        MArKsS += EnterMarksEVENT.text.unicode;
                                                                                        UserInputforMarks.setString(MArKsS);
                                                                                        ENtermarksCheck = true;

                                                                                    }
                                                                                    if (checkforx == 4 && checkforx < x)
                                                                                    {
                                                                                        UserInputforMarks.setPosition(950 + 170, 300 * 100 * 4);
                                                                                        MArKsS += EnterMarksEVENT.text.unicode;
                                                                                        UserInputforMarks.setString(MArKsS);
                                                                                        ENtermarksCheck = true;

                                                                                    }
                                                                                }
                                                                            }
                                                                            // yaha i thik s
                                                                            if (EnterMarksEVENT.key.code == Keyboard::Enter && !enterKeyPressed && ENtermarksCheck)
                                                                            {
                                                                                int MyINT = stoi(MArKsS);
                                                                                students[index_ofSTu].marks_assingn(MyINT);
                                                                                checkforx++;
                                                                                MArKsS = "";

                                                                                enterKeyPressed = true;
                                                                            }
                                                                            else if (!Keyboard::isKeyPressed(Keyboard::Enter))
                                                                            {
                                                                                enterKeyPressed = false;
                                                                            }
                                                                            if (checkforx == x && checkkk)
                                                                            {
                                                                                checkkk = false;
                                                                                text2.setString("Entered Succesfully \n Press Escape To Countinue :");
                                                                                filehandling obj("students_marks.txt");
                                                                                obj.write_marks(students[index_ofSTu], x);
                                                                            }

                                                                        }
                                                                        SubWindowENterMarks.clear(Color::White);

                                                                        SubWindowENterMarks.draw(sprite);
                                                                        sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                                        for (int i = 0; i < x; i++)
                                                                        {
                                                                            SubWindowENterMarks.draw(Marksofstudent[i]);
                                                                        }
                                                                        SubWindowENterMarks.draw(text2);
                                                                        SubWindowENterMarks.draw(UserInputforMarks);
                                                                        SubWindowENterMarks.display();
                                                                    }
                                                                }
                                                                else
                                                                    Nocourse.setString("Student has no Course");
                                                            }
                                                            else
                                                            {
                                                                cout << "NO student exit ";
                                                                NotExist.setString("Student Not Exist ..Try Again");
                                                            }
                                                        }
                                                        else
                                                            Validrollnumberprint.setString("Not Valid ENter in that Format(22l-1234)");
                                                    }
                                                    bool checkforenter = false;
                                                }
                                                Enter_MARKS.clear(Color::White);
                                                Enter_MARKS.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Enter_MARKS.draw(UserInputR);
                                                Enter_MARKS.draw(Nocourse);
                                                Enter_MARKS.draw(NotExist);
                                                Enter_MARKS.draw(Validrollnumberprint);
                                                Enter_MARKS.draw(text);
                                                Enter_MARKS.display();
                                            }
                                        }
                                        if (eaevent.key.code == Keyboard::Num3)
                                        {
                                            Marks.close();
                                        }
                                    }
                                }
                                Enroll.close();
                                Register.close();
                                Attendence.close();
                                Withdraw.close();
                                Exit.close();
                                Marks.clear(Color::White);
                                Marks.draw(sprite);
                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                displaymarkssubmeenu(Marks);
                                Marks.display();
                            }
                        }
                        //--------Withdraw the course-------------
                        if (x == 4)
                        {
                            while (Withdraw.isOpen())
                            {
                                Event eaevent;
                                while (Withdraw.pollEvent(eaevent))
                                {
                                    if (eaevent.type == Event::Closed)
                                    {
                                        Withdraw.close();
                                    }
                                    if (eaevent.type == Event::KeyPressed)
                                    {
                                        if (eaevent.key.code == Keyboard::Num1)  // display enroll courses 
                                        {
                                            RenderWindow Display_Enroll_Courses(desktopMode, "DIsplay Enroll Courses");

                                            Text text;
                                            Font font;
                                            font.loadFromFile("arial.ttf");
                                            text.setFont(font);
                                            text.setCharacterSize(50);
                                            text.setPosition(50, 400);//rem
                                            text.setString("ENter ROll number of student to see Enrolled Courses:");
                                            text.setFillColor(Color::Black);


                                            string roll_Number;
                                            Text UserInputR;
                                            UserInputR.setFont(font);
                                            UserInputR.setCharacterSize(50);
                                            UserInputR.setPosition(1050 + 250, 400);
                                            UserInputR.setFillColor(Color::Black);


                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);
                                            //-------------------------------------------------
                                            Text textTODisplay[5];

                                            while (Display_Enroll_Courses.isOpen())
                                            {
                                                Event Enroll_Course_Event;
                                                while (Display_Enroll_Courses.pollEvent(Enroll_Course_Event))
                                                {
                                                    if (Enroll_Course_Event.type == Event::Closed)
                                                    {
                                                        Display_Enroll_Courses.close();
                                                    }
                                                    if (Enroll_Course_Event.key.code == Keyboard::Escape)
                                                    {
                                                        Display_Enroll_Courses.close();
                                                    }
                                                    if (Enroll_Course_Event.type == Event::TextEntered)
                                                    {
                                                        if (Enroll_Course_Event.text.unicode < 128 && Enroll_Course_Event.text.unicode > 31)
                                                        {
                                                            roll_Number += Enroll_Course_Event.text.unicode;
                                                            UserInputR.setString(roll_Number);
                                                        }
                                                        else if (Enroll_Course_Event.text.unicode == 8 && !roll_Number.empty()) // backspace
                                                        {
                                                            roll_Number.pop_back();
                                                            UserInputR.setString(roll_Number);
                                                            Display_Enroll_Courses.draw(UserInputR);
                                                        }
                                                    }
                                                }
                                                Display_Enroll_Courses.clear(Color::White);
                                                int StudentcourseIndex = 0;
                                                if(Enroll_Course_Event.key.code == Keyboard::Enter)
                                                {
                                                    validaltion obj;
                                                    bool CheKinG = obj.is_valid_roll_number(roll_Number);
                                                    if (CheKinG)
                                                    {
                                                        Validrollnumberprint.setString("");
                                                        for (int i = 0; i < student_count_System; i++)
                                                        {
                                                            if (roll_Number == students[i].get_roll_number())
                                                            {
                                                                StudentcourseIndex = students[i].get_course_count_student();
                                                                students[i].display_student(Display_Enroll_Courses , textTODisplay);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        Validrollnumberprint.setString("Not Valid Try Again use that format(22l-0987)");
                                                    }
                                                }
                                                Display_Enroll_Courses.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Display_Enroll_Courses.draw(text);
                                                Display_Enroll_Courses.draw(Validrollnumberprint);
                                                Display_Enroll_Courses.draw(UserInputR);
                                                Display_Enroll_Courses.display();
                                            }
                                        }
                                        if (eaevent.key.code == Keyboard::Num2)
                                        {
                                            RenderWindow Withdar_Course(desktopMode, "Drop a Course");

                                            Text text;
                                            Font font;
                                            font.loadFromFile("arial.ttf");
                                            text.setFont(font);
                                            text.setCharacterSize(50);
                                            text.setPosition(50, 400);//rem
                                            text.setFillColor(Color::Black);
                                            text.setString("ENter ROll number of student to Drop Course:");

                                            string roll_NumberRR;
                                            Text UserInputR;
                                            UserInputR.setFont(font);
                                            UserInputR.setCharacterSize(50);
                                            UserInputR.setPosition(1050 + 250, 400);
                                            UserInputR.setFillColor(Color::Black);

                                            Text UserInput2; // code
                                            UserInput2.setFont(font);
                                            UserInput2.setCharacterSize(50);
                                            UserInput2.setPosition(1050 + 250, 600);
                                            UserInput2.setFillColor(Color::Black);

                                            Text courseEnter; // enter course
                                            courseEnter.setFont(font);
                                            courseEnter.setCharacterSize(50);
                                            courseEnter.setPosition(50, 600);//rem
                                            courseEnter.setFillColor(Color::Black);

                                            Text Withdraw_Succesfully;
                                            Withdraw_Succesfully.setFont(font);
                                            Withdraw_Succesfully.setCharacterSize(50);
                                            Withdraw_Succesfully.setPosition(0, 300);
                                            Withdraw_Succesfully.setFillColor(Color::Black);

                                            //-----------Valid RollNumber check----------------
                                            Text Validrollnumberprint;
                                            Validrollnumberprint.setFillColor(Color::Red);
                                            Validrollnumberprint.setFont(font);
                                            Validrollnumberprint.setCharacterSize(28);
                                            Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);


                                            Text ValidCourseprint;
                                            ValidCourseprint.setFillColor(Color::Red);
                                            ValidCourseprint.setFont(font);
                                            ValidCourseprint.setCharacterSize(28);
                                            ValidCourseprint.setPosition(70, 300 + 2 * 100 + 60);

                                            //-------------------------------------------------


                                            bool Rollnumbercheck = true;
                                            bool coursecheck = false;
                                            string courseCodename;
                                            int S_index = 0;
                                            bool chk = false;
                                            bool enterKeyPressed = false;
                                            bool tempcheck = false;
                                            while (Withdar_Course.isOpen())
                                            {
                                                Event Withdraw_Course_Event;
                                                while (Withdar_Course.pollEvent(Withdraw_Course_Event))
                                                {
                                                    if (Withdraw_Course_Event.type == Event::Closed)
                                                    {
                                                        Withdar_Course.close();
                                                    }
                                                    if (Withdraw_Course_Event.key.code == Keyboard::Escape)
                                                    {
                                                        Withdar_Course.close();
                                                    }
                                                    if (Withdraw_Course_Event.type == Event::TextEntered)
                                                    {
                                                        if (Withdraw_Course_Event.text.unicode < 128 && Withdraw_Course_Event.text.unicode > 31)
                                                        {   
                                                            if (Rollnumbercheck)
                                                            {
                                                                if (Withdraw_Course_Event.text.unicode == 8 && !roll_NumberRR.empty()) // Changed from Keyboard::Key::BackSpace to 8
                                                                {
                                                                    
                                                                    roll_NumberRR.pop_back();
                                                                    UserInputR.setString(roll_NumberRR);
                                                                    Withdar_Course.draw(UserInputR);
                                                                }
                                                                else
                                                                {
                                                                    roll_NumberRR += Withdraw_Course_Event.text.unicode;
                                                                    UserInputR.setString(roll_NumberRR);
                                                                }

                                                            }
                                                            if (coursecheck)
                                                            {
                                                                if (Withdraw_Course_Event.text.unicode == 8 && !courseCodename.empty()) // Changed from Keyboard::Key::BackSpace to 8
                                                                {
                                                                    courseCodename.pop_back();
                                                                    UserInput2.setString(courseCodename);
                                                                    Withdar_Course.draw(UserInput2);
                                                                }
                                                                else
                                                                {
                                                                    courseCodename += Withdraw_Course_Event.text.unicode;
                                                                    UserInput2.setString(courseCodename);
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (Withdraw_Course_Event.key.code == Keyboard::Enter && !enterKeyPressed && Rollnumbercheck)
                                                    {

                                                        validaltion obj;
                                                        bool cheking = obj.is_valid_roll_number(roll_NumberRR);
                                                        if (cheking)
                                                        {
                                                            Validrollnumberprint.setString("");
                                                            Rollnumbercheck = false;
                                                            coursecheck = true;
                                                            for (int i = 0; i < student_count_System; i++)
                                                            {
                                                                if (students[i].get_roll_number() == roll_NumberRR)
                                                                {
                                                                    S_index = i;

                                                                    courseEnter.setString("Enter Course Name Of student:");
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                           Validrollnumberprint.setString("Try Again NOT valid(17l-1234)");
                                                        }
                                                    }
                                                    bool withdraw_Check = false;
                                                    if (Withdraw_Course_Event.type == Event::KeyReleased)
                                                    {
                                                        if (Withdraw_Course_Event.key.code == Keyboard::Enter && enterKeyPressed && coursecheck && tempcheck)
                                                        {
                                                            validaltion obj;
                                                            bool checking2 = obj.chk_valid_course_code(courseCodename);
                                                            if (checking2)
                                                            {
                                                                for (int j = 0; j < 5; j++)  //max 5 courses 
                                                                {
                                                                    if (students[S_index].get_course_student(j) == courseCodename) // ROLLNUMBER ACT AS A COURSE NAME HERE 
                                                                    {
                                                                        students[S_index].withdraw_courses(courseCodename);
                                                                        ofstream Filee_NamE_Course("student_all_data.txt", ios::trunc); // trunc remove all the existing data from the file

                                                                        filehandling obj("student_all_data.txt");
                                                                        for (int i = 0; i < student_count_System; i++)
                                                                        {
                                                                            obj.write_student_courses(students[i]);   // write student data with courses 
                                                                        }
                                                                        withdraw_Check = true;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                            else
                                                            {
                                                                ValidCourseprint.setString("Not Valid COurse Code Try AGain (AB1234)");
                                                            }
                                                        }
                                                        if (withdraw_Check)
                                                        {
                                                            Withdraw_Succesfully.setString("Withdraw Succesfully");
                                                        }
                                                        if (coursecheck == true)
                                                        {
                                                            tempcheck = true;
                                                        }
                                                    }
                                                }
                                                Withdar_Course.clear(Color::White);
                                                Withdar_Course.draw(sprite);
                                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                                Withdar_Course.draw(ValidCourseprint);
                                                Withdar_Course.draw(Validrollnumberprint);
                                                Withdar_Course.draw(Withdraw_Succesfully);
                                                Withdar_Course.draw(courseEnter);
                                                Withdar_Course.draw(text);
                                                Withdar_Course.draw(UserInputR);
                                                Withdar_Course.draw(UserInput2);
                                                Withdar_Course.display();
                                            }
                                        }
                                        if (eaevent.key.code == Keyboard::Num3)
                                        {
                                            Withdraw.close();
                                        }

                                    }
                                }
                                Enroll.close();
                                Register.close();
                                Marks.close();
                                Attendence.close();
                                Exit.close();
                                Withdraw.clear(Color::White);
                                Withdraw.draw(sprite);
                                sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                display_withdraw_submenu(Withdraw);

                                Withdraw.display();
                            }
                        }
                        if (x == 5)
                        {
                            Enroll.close();
                            Register.close();
                            Marks.close();
                            Attendence.close();
                            Exit.close();
                            Withdraw.close();
                            return;
                        }
                    }
                }
            }
            WlcmScr.clear(Color::White);
            sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
            WlcmScr.draw(sprite);
            WlcmScr.draw(welcmtofatmsg);
            menu.draw(WlcmScr);
            WlcmScr.display();
        }
    }

    // this function will edit student details on compile ti
    void edit_student_detail(string roll , Window &renderwindow)
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
            cout << "Error\n" << endl;
            return;
        }
        if (rename(tempFilename.c_str(), filename.c_str()) != 0) { // modifying data in the original file 
            cout << "Error\n" << endl;
            return;
        }

    }
    // this function will add new students in a system also in file handling 
    bool add_student(student& obj)
    {
        bool check = false;
        // checking window for yes or no 
        RenderWindow checkwindow(VideoMode(500, 300), "Saved or not");

        Font font;
        if (!font.loadFromFile("arial.ttf")) {
            cout << "Error loading font file." << endl;
        }

        Text text;
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(Color::Black);

        text.setPosition(50, 50);
        text.setString("Do you want to store student\n data permanently(Y / N)?");

        while (checkwindow.isOpen())
        {
            Event evnt;
            while (checkwindow.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                {
                    checkwindow.close();
                }
                if (evnt.type == Event::KeyPressed)
                {
                    if (evnt.key.code == Keyboard::Y)
                    {
                        students[student_count_System] = obj;
                        filehandling obj("Studentdata.txt");
                        obj.write_Student_data_into_File(students[student_count_System]);
                        student_count_System++;
                        check = true;
                        checkwindow.close();
                    }
                    if (evnt.key.code == Keyboard::N)
                    {
                        checkwindow.close();
                    }
                }
            }
            checkwindow.clear(Color::White);
            checkwindow.draw(text);
            checkwindow.display();
        }
        return check;
    }

    void load_student_data()
    {
        student_count_System = 0;
        ifstream inputFile("studentdata.txt");

        if (!inputFile.is_open())
        {
            cout << "Error opening file!" << endl;
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
                cout << "Error parsing data from file!" << endl;
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
            cout << "Error opening file!" << endl;
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
            cout << "Error opening file!" << endl;
            return;
        }


        string line;
        while (getline(inputFile, line))
        {

            if (course_count_system < 100) {
                istringstream iss(line);

                int  capacCiTy, credit;
                string code, name, inst;

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
                    cout << "Error parsing data from file!" << endl;
                    break;  // Exit the loop if parsing fails
                }
            }
            else
            {
                cout << "Not enough space in the courses array!" << endl;
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
        cout << "Error opening student data file." << endl;
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
    bool checking_student = false;
    RenderWindow window(desktopMode, "FLEX managment System");
    Font font;
    font.loadFromFile("arial.ttf");
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Error loading file \n";
    }
    // text display 
    Text text;
    text.setFont(font); 
    text.setString("For Authentification Enter Your ROll Number"); 
    text.setCharacterSize(48); 
    text.setFillColor(Color::Black); 
    text.setPosition(200 * 4 - 100, 100 * 2); 


    Text Esc;
    Esc.setFont(font); 
    Esc.setString("Press ESC to Exit......"); 
    Esc.setCharacterSize(48); 
    Esc.setFillColor(Color::Red); 
    Esc.setPosition(200 * 7, 100 * 9); 


    RectangleShape rectangle;
    rectangle.setSize(Vector2f(650, 150)); 
    rectangle.setPosition(200 * 4 - 40, 100 * 3);
    rectangle.setFillColor(Color::Transparent); 
    rectangle.setOutlineColor(Color::Black);    
    rectangle.setOutlineThickness(4.0f);          
    string ID;


    Text userInputText;
    userInputText.setFont(font);
    userInputText.setCharacterSize(50);
    userInputText.setFillColor(Color::Black);
    userInputText.setPosition(200 * 4.5 - 100, 100 * 3.5);
    Text text_show;
    Text text_show2;

    bool shouldContinue = true;
    
    Texture texture;
    if (!texture.loadFromFile("C:/Users/echo/Desktop/NU-logo.jpg"));
    {
        cout << "Image not found\n";
    }
    Sprite sprite;
    sprite.setTexture(texture);
    Vector2f newSize(1000 * 1.9 + 30, 100 * 2);
    while (window.isOpen())
    {
        Event aevent;
        while (window.pollEvent(aevent))
        {
            if (aevent.type == Event::TextEntered)
            {
                if (aevent.type == Event::Closed)
                {
                    window.close();
                }
                if (aevent.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                if (aevent.text.unicode < 128 && aevent.text.unicode > 31)
                {
                    ID += aevent.text.unicode;
                    userInputText.setString(ID + "|");

                }
                else if (aevent.text.unicode == 8 && !ID.empty()) // backspace
                {
                    ID.pop_back();
                    userInputText.setString(ID + "|");
                }
                
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if(aevent.key.code == Keyboard::Enter)
        {
            
            checking_student = Authentication(ID);
            if (checking_student)
            {
                window.clear();
                System obj;
                obj.load_student_with_their_courses();
                obj.load_all_ava_courses();
                obj.performMainMenuAction2();
            }
            else
            {
                window.clear();
                text_show2.setFont(font);
                text_show2.setString("You are not a student of FAST - Try Again..");
                text_show2.setCharacterSize(50);
                text_show2.setFillColor(Color::Black);
                text_show2.setPosition(200 * 4 - 100, 100 * 5);
            }
        }
        window.clear(Color::White);
        window.draw(sprite);
        sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
        window.draw(Esc);
        window.draw(text);
        window.draw(userInputText);
        window.draw(rectangle);
        window.draw(text_show2);
        window.display();
    }
    return 0;
}