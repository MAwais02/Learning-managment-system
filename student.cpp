#include"student.h"
using namespace std;
using namespace sf;

student::student()
{
    name = " ";
    roll_num = " ";
    age = 0;
    contact = " ";
}
void student::enroll_student(string name, string roll_num, int age, string contact)
{
    this->name = name;
    this->roll_num = roll_num;
    this->age = age;
    this->contact = contact;
}
void student::mark_attendence(char choice)       // name and choice ( 0 and 1 ) 
{
    attendance[attendence_index++] = choice;
}
void student::marks_assingn(int marks_to_assign)
{
    marks[marks_index++] = marks_to_assign;   // assign marks 
}
void student::withdraw_courses(string coursename)
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
void student::display_student(RenderWindow& Win, Text text[])
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
        text[i].setPosition(500, 500 + 50 * i);
    }

    Win.draw(text2);
    Win.draw(text3);
    for (int i = 0; i < course_index; ++i)
    {
        Win.draw(text[i]);
    }
}
void student::display_enroll_students(RenderWindow& window_Enroll, Text text)
{
    string s = to_string(age);    // first convert int into string data type 
    text.setString("Name :" + name + "Roll no : " + roll_num + "Contact " + contact + "Age : " + s);
    window_Enroll.draw(text);
}
void student::displayInfo()
{
    cout << "Studen name : " << name;
}
void student::set_name(string n)
{
    name = n;
}
void student::set_contact(string c)
{
    contact = c;
}
void student::set_rollnumber(string a)
{
    roll_num = a;
}
int student::get_marks(int i)
{
    return marks[i];
}
char student::get_attendence(int x)
{
    return attendance[x];
}
void student::set_age(int a)
{
    age = a;
}
int student::get_course_count_student()
{
    return course_index;
}
string student::get_roll_number()
{
    return roll_num;
}
string student::get_course_student(int x)
{
    return courses[x];
}
void student::add_course_student(string s)
{
    courses[course_index++] = s;
}
int student::get_age()
{
    return age;
}
string student::get_name()
{
    return name;
}
string student::get_contact()
{
    return contact;
}
//int student::course_index = 0;
int student::attendence_index = 0;
int student::marks_index = 0;
