#include<sstream>
#include"System.h"
int System::student_count_System = 0;
int System::course_count_system = 0;
int System::Index_of_course_system = 0;
// this will check if student is enroll in university or not 

System::System() {}
// this will add all courses in system 
void System::add_new_courses()
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
void System::displayStudentSubMenu(RenderWindow& Subwindow)
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
        menuItems[i].setPosition(50, 300 + i * 100);
    }
    for (const Text& text : menuItems)
    {
        Subwindow.draw(text);
    }
    //Subwindow.display();
}
void System::displayCourseSubMenu(RenderWindow& Subwindow)
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
    menuItems[0].setString("1 - Avalible Course");
    menuItems[1].setString("2 - Register Course");
    menuItems[2].setString("5 - Back ");

    for (int i = 0; i < 3; ++i)
    {
        menuItems[i].setPosition(50, 300 + i * 100);
    }
    for (const Text& text : menuItems)
    {
        Subwindow.draw(text);
    }
}
void System::displayattendencesubmenu(RenderWindow& Subwindow)
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
void System::displaymarkssubmeenu(RenderWindow& Subwindow)
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
void System::display_withdraw_submenu(RenderWindow& Subwindow)
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
void System::performMainMenuAction2()
{
    VideoMode desktopMode = VideoMode::getDesktopMode();
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
                                        Validrollnumberprint.setPosition(70, 300 + 1 * 100 + 60);

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
                                                    else if (ageInputActive)
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
                                        int index = -1;
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
                                    UserInput.setPosition(950, 400);

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
                                // Add student into Course
                                if (eaevent.type == Event::KeyPressed && eaevent.key.code == Keyboard::Num3)
                                {
                                    RenderWindow AddstudentINtoCOurse(desktopMode, "AddstudentintoCourse");

                                    Text Entercode;
                                    Font font;
                                    font.loadFromFile("arial.ttf");
                                    Entercode.setFont(font);
                                    Entercode.setCharacterSize(50);
                                    Entercode.setPosition(50, 400);
                                    Entercode.setString("ENter Code OF Course :");
                                    Entercode.setFillColor(Color::Black);


                                    Text NostudentExistmsg;
                                    NostudentExistmsg.setFont(font);
                                    NostudentExistmsg.setCharacterSize(50);
                                    NostudentExistmsg.setPosition(50, 800);
                                    NostudentExistmsg.setFillColor(Color::Black);

                                    Text NocourseExistmsg;
                                    NocourseExistmsg.setFont(font);
                                    NocourseExistmsg.setCharacterSize(50);
                                    NocourseExistmsg.setPosition(50, 900);
                                    NocourseExistmsg.setFillColor(Color::Black);

                                    string Codee;
                                    Text UserInputforADD;
                                    UserInputforADD.setFont(font);
                                    UserInputforADD.setCharacterSize(50);
                                    UserInputforADD.setPosition(950, 400);
                                    UserInputforADD.setFillColor(Color::Black);
                                    bool Checkingofcourse = false;
                                    while (AddstudentINtoCOurse.isOpen())
                                    {
                                        Event evntforaddstudentintocourse;
                                        while (AddstudentINtoCOurse.pollEvent(evntforaddstudentintocourse))
                                        {
                                            if (evntforaddstudentintocourse.type == Event::Closed)
                                            {
                                                AddstudentINtoCOurse.close();
                                            }
                                            if (evntforaddstudentintocourse.key.code == Keyboard::Escape)
                                            {
                                                AddstudentINtoCOurse.close();
                                            }
                                            if (evntforaddstudentintocourse.type == Event::TextEntered)
                                            {
                                                if (evntforaddstudentintocourse.text.unicode < 128 && evntforaddstudentintocourse.text.unicode > 31)
                                                {
                                                    Codee += evntforaddstudentintocourse.text.unicode;
                                                    UserInputforADD.setString(Codee);
                                                    AddstudentINtoCOurse.draw(UserInputforADD);
                                                }
                                                else if (evntforaddstudentintocourse.text.unicode == 8 && !Codee.empty()) // backspace
                                                {
                                                    Codee.pop_back();
                                                    UserInputforADD.setString(Codee);
                                                    AddstudentINtoCOurse.draw(UserInputforADD);
                                                }
                                            }
                                            if (evntforaddstudentintocourse.type == Event::KeyReleased && evntforaddstudentintocourse.key.code == Keyboard::Enter)
                                            {

                                                for (int i = 0; i < course_count_system; i++)
                                                {
                                                    if (courses[i].get_code() == Codee)
                                                    {
                                                        Checkingofcourse = true;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        if (Checkingofcourse == true)
                                        {

                                            Text EnterRoll_NUmber;
                                            EnterRoll_NUmber.setFont(font);
                                            EnterRoll_NUmber.setCharacterSize(50);
                                            EnterRoll_NUmber.setPosition(50, 500);
                                            EnterRoll_NUmber.setString("ENter Roll number OF Student");
                                            EnterRoll_NUmber.setFillColor(Color::Black);

                                            Text text4;
                                            text4.setFont(font);
                                            text4.setCharacterSize(50);
                                            text4.setPosition(50, 700);
                                            text4.setFillColor(Color::Green);


                                            string Roll_NUmber;
                                            Text UserInputforADDRollNumber;
                                            UserInputforADDRollNumber.setFont(font);
                                            UserInputforADDRollNumber.setCharacterSize(50);
                                            UserInputforADDRollNumber.setPosition(950, 500);
                                            UserInputforADDRollNumber.setFillColor(Color::Black);


                                            while (AddstudentINtoCOurse.isOpen())
                                            {
                                                Event eevnt4;
                                                while (AddstudentINtoCOurse.pollEvent(eevnt4))
                                                {
                                                    if (eevnt4.key.code == Keyboard::Escape)
                                                    {
                                                        AddstudentINtoCOurse.close();
                                                    }
                                                    if (eevnt4.type == Event::TextEntered)
                                                    {

                                                        if (eevnt4.text.unicode < 128 && eevnt4.text.unicode > 31)
                                                        {
                                                            Roll_NUmber += eevnt4.text.unicode;
                                                            UserInputforADDRollNumber.setString(Roll_NUmber);
                                                            AddstudentINtoCOurse.draw(UserInputforADDRollNumber);

                                                        }
                                                        else if (eevnt4.text.unicode == 8 && !Roll_NUmber.empty()) // backspace
                                                        {
                                                            Roll_NUmber.pop_back();  // Remove the last character
                                                            UserInputforADDRollNumber.setString(Roll_NUmber);
                                                            AddstudentINtoCOurse.draw(UserInputforADDRollNumber);

                                                        }
                                                    }
                                                    if (eevnt4.key.code == Keyboard::Enter && eevnt4.type == Event::KeyReleased)
                                                    {
                                                        for (int i = 0; i < student_count_System; i++)
                                                        {
                                                            if (students[i].get_roll_number() == Roll_NUmber)
                                                            {
                                                                courses[i].addStudent(students[i]); // Student Added 
                                                                text4.setString("Entered Succesfully ");
                                                            }
                                                        }
                                                    }
                                                }
                                                AddstudentINtoCOurse.draw(text4);
                                                AddstudentINtoCOurse.draw(UserInputforADDRollNumber);
                                                AddstudentINtoCOurse.draw(EnterRoll_NUmber);
                                                AddstudentINtoCOurse.display();
                                            }
                                        }
                                        AddstudentINtoCOurse.clear(Color::White);
                                        sprite.setScale(newSize.x / sprite.getLocalBounds().width, newSize.y / sprite.getLocalBounds().height);
                                        AddstudentINtoCOurse.draw(sprite);
                                        AddstudentINtoCOurse.draw(Entercode);
                                        AddstudentINtoCOurse.draw(UserInputforADD);
                                        AddstudentINtoCOurse.display();
                                    }


                                }
                                if (eaevent.type == Event::KeyPressed && eaevent.key.code == Keyboard::Num5)
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
                                                    bool ENtermarksCheck = false;
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
                                                                        if (checkforx == 0 && checkforx < x)
                                                                        {
                                                                            UserInputforAttendece.setPosition(450 + 170, 300 + 100 * 0);
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            ENtermarksCheck = true;
                                                                        }
                                                                        if (checkforx == 1 && checkforx < x)
                                                                        {
                                                                            UserInputforAttendece.setPosition(450 + 170, 300 + 100 * 1);
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            ENtermarksCheck = true;

                                                                        }
                                                                        if (checkforx == 2 && checkforx < x)
                                                                        {
                                                                            UserInputforAttendece.setPosition(450 + 170, 300 + 100 * 2);
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            ENtermarksCheck = true;

                                                                        }
                                                                        if (checkforx == 3 && checkforx < x)
                                                                        {
                                                                            UserInputforAttendece.setPosition(450 + 170, 300 + 100 * 3);
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            ENtermarksCheck = true;

                                                                        }
                                                                        if (checkforx == 4 && checkforx < x)
                                                                        {
                                                                            UserInputforAttendece.setPosition(950 + 170, 300 * 100 * 4);
                                                                            Att += EnterAttendeceEVENT.text.unicode;
                                                                            UserInputforAttendece.setString(Att);
                                                                            ENtermarksCheck = true;
                                                                        }
                                                                    }
                                                                }

                                                                if (EnterAttendeceEVENT.key.code == Keyboard::Enter && !enterKeyPressed && ENtermarksCheck)
                                                                {
                                                                    students[index_ofSTu].mark_attendence(Att);
                                                                    checkforx++;
                                                                    Att = '\0';
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
                                                                    filehandling obj("student_attendence.txt");
                                                                    obj.write_attendence(students[index_ofSTu], x); // x is no of coursses
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
                                            if (Enroll_Course_Event.key.code == Keyboard::Enter)
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
                                                            students[i].display_student(Display_Enroll_Courses, textTODisplay);
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
void System::edit_student_detail(string roll, Window& renderwindow)
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
void System::remove_student(string roll)
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
bool System::add_student(student& obj)
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
void System::load_student_data()
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
void System::load_student_with_their_courses()
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
void System::load_all_ava_courses()
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
