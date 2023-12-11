#include"validation_header.h"

bool validaltion::chk_Valid_creditHour(int x)
{
    if (x > 0 && x <= 3)
    {
        return true;
    }
    return false;
}
// menu input
bool validaltion::check_valid_input(int x)
{
    if (x > 0 && x <= 6)
    {
        return true;
    }
    return false;
}
// valid course name 
bool validaltion::chk_valid_course(string n)
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
bool validaltion::chk_valid_course_code(string course_code)
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
char validaltion::is_valid_attendence(char ch)
{
    if (ch == 'A' || ch == 'P' || ch == 'L' || ch == 'a' || ch == 'p' || ch == 'l')
    {
        return true;
    }
    return false;
}
bool validaltion::is_numeric(char c)
{
    return c >= '0' && c <= '9';
}
// assumme roll number is 22l-0987 this format 
bool validaltion::numeric_checker(char c) {
    return c >= '0' && c <= '9';
}

bool validaltion::is_valid_roll_number(string& roll) {
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
bool validaltion::valid_contact(string cont)
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
bool validaltion::valid_age(int a)
{
    if (a >= 10 && a <= 80)
    {
        return true;
    }
    return false;
}
// check valid marks 
bool validaltion::valid_marks(int x)
{
    return  x >= 0 && x <= 100;  // assume 100 is max marks 
}
