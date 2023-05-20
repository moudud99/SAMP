/// Final Version

/// Student's Academic Management Project
/// Object Oriented Programming Lab CSE 4302

/// Aashnan Rahman   190041204
/// Syem Aziz        190041238
/// Moudud Hasan     190041240

#include <bits/stdc++.h>
#include<conio.h>
#include <ctime>
#include<windows.h>
#include <mmsystem.h>
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

using namespace std;

string access_ID,access_pass;

extern void dis(int x,int y);
extern void next();
void access();
extern check_id(string st_id);
extern void help();
extern void muchas_gracias();

enum IN
{
    IN_BACK = 8,
    IN_RET = 13

};

string takePasswdFromUser(char sp = '*')
{
    string passwd = "";
    char ch_ipt;
    while (true)
    {

        ch_ipt = getch();
        if (ch_ipt == IN::IN_RET)
        {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK && passwd.length() != 0)
        {
            passwd.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0)
        {
            continue;
        }

        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

void activity_log_input(string user,int a)
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    int c_year = 1900 + local_time->tm_year;
    int c_month = 1 + local_time->tm_mon;
    int c_date = local_time->tm_mday;
    int c_day = local_time->tm_wday;
    int c_hour = local_time->tm_hour;
    int c_min = local_time->tm_min;
    int c_sec = local_time->tm_sec;

    string day,ttype;

    if(c_day==1) day = "Monday";
    if(c_day==2) day = "Tuesday";
    if(c_day==3) day = "Wednesday";
    if(c_day==4) day = "Thursday";
    if(c_day==5) day = "Friday";
    if(c_day==6) day = "Saturday";
    if(c_day==7) day = "Sunday";

    if(a==1) ttype = "Administrator";
    if(a==2) ttype = "Teacher";
    if(a==3) ttype = "Student";

    //cout<<endl<<c_hour<<":"<<c_min<<":"<<c_sec<<"  "<<day<<"  "<<c_date<<"/"<<c_month<<"/"<<c_year<<endl;

    ifstream user1("activity_log.txt");

    if(user1)
    {
        user1.close();
        ofstream user1("activity_log.txt",ios::app);
        user1<<user<<" "<<ttype<<" "<<c_hour<<":"<<c_min<<":"<<c_sec<<"  "<<day<<"  "<<c_date<<"/"<<c_month<<"/"<<c_year<<endl;
        user1.close();
    }

    if(!user1)
    {
        user1.close();
        ofstream user1("activity_log.txt");
        user1<<user<<" "<<ttype<<" "<<c_hour<<":"<<c_min<<":"<<c_sec<<"  "<<day<<"  "<<c_date<<"/"<<c_month<<"/"<<c_year<<endl;
        user1.close();
    }
}

void activity_log()
{
    string userID, ttype, Date, Day, Time;
    ifstream user1("activity_log.txt");

    cout<<endl<<"ACTIVITY LOG"<<endl;
    dis(1,15);

    cout<<" User ID     Type of User      Date         Day         Time"<<endl;
    cout<<"*********    ************    *********    ********    ********"<<endl;

    if(user1)
    {
        while(user1>>userID>>ttype>>Time>>Day>>Date)
        {
            cout<<left<<setw(13)<<userID<<setw(16)<<ttype<<setw(13)<<Date<<setw(12)<<Day<<setw(12)<<Time<<endl;
        }
    }
}


void login_successful(int x)
{
    system("PAUSE");
    system("CLS");

    cout<<"Login Successful"<<endl<<endl;
    dis(3,30);

    if(x==1) cout<<"You are logged in as a Student.";
    if(x==2) cout<<"You are logged in as a Teacher.";
    if(x==3) cout<<"You are logged in as an Administrator.";

    cout<<endl;
    next();
}

bool check_pass(string id,string pass)
{
    int flag=0;
    ifstream password("Password.txt");
    string traverse_id,traverse_pass;
    if(password)
    {
        while(password>>traverse_id>>traverse_pass)
        {
            if(id==traverse_id && pass==traverse_pass)
            {
//        cout<<"Present"<<endl;
                access_ID = id; /// comment later
                access();
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"Wrong ID / Password "<<endl;
            return 1;
        }

    }
    else
    {
        cout<<"File Not Found"<<endl;
    }
    password.close();
    system("PAUSE");
    system("CLS");
    return 0;
}

void authorization()
{
begin:;
    cout<<endl<<endl<<"Welcome to STUDENT'S ACADEMIC MANAGEMENT PROJECT (SAMP) "<<endl<<endl;
    dis(3,60);

    cout<<endl<<endl;

    cout<< "Enter ID       : ";
    cin>>access_ID;

    cout<<endl<< "Enter Password : ";
    access_pass=takePasswdFromUser();

    cout<<endl;

    bool flag=check_pass(access_ID,access_pass);


    system("PAUSE");
    system("CLS");
    if(flag)goto begin;
}

void access()
{
    string str=access_ID;
    int x;

    Person *p1 = new Administrator;

    if (str.size()==9) /// student
    {
        login_successful(1);
        activity_log_input(str,3);
//        /// view details, view grade, view routine
        while(1)
        {
            cout<<"Choose one of the following options :"<<endl;
            dis(3,35);
            cout<<endl<<endl;
            cout<<" 1. View Personal Details "<<endl;
            cout<<" 2. View Grade "<<endl;   /// semester-wise
            cout<<" 3. Change password "<<endl;
            cout<<" 4. View Courses in this Semester "<<endl;
            cout<<" 5. View Routine "<<endl;
            cout<<" 6. Help Section "<<endl;
            cout<<" 7. Exit"<<endl<<endl;

            cout<<"Enter your choice : ";
            cin>>x;

            next();

            Student s1;

            if(x==1)
            {
                s1.showStudent(access_ID);
            }
            else if(x==2)
            {
                s1.showgrade(access_ID);
            }
            else if(x==3)
            {
                p1->edit_password(str);
            }
            else if(x==4)
            {
                s1.find_course();
            }
            else if(x==5)
            {
                s1.schedule();
            }
            else if(x==6)
            {
                help();
            }
            else break;
        }
    }
    else if(str.substr(0,1)=="T") ///teacher
    {
        login_successful(2);
        activity_log_input(str,2);
        /// view details , change pass, view the courses he takes
        while(1)
        {
            cout<<"Choose one of the following options :"<<endl;
            dis(3,35);
            cout<<endl<<endl;
            cout<<" 1. View Personal Details "<<endl;
            cout<<" 2. View Details of a Student "<<endl;   /// semester-wise
            cout<<" 3. View Grade of a Student"<<endl;
            cout<<" 4. Change password "<<endl;
            cout<<" 5. View Taken courses"<<endl;
            cout<<" 6. Help Section"<<endl;
            cout<<" 7. Exit"<<endl<<endl;

            cout<<"Enter your choice : ";
            cin>>x;

            next();

            Teacher t1;

            if(x==1)
            {
                t1.showTeacher(access_ID);
            }
            else if(x==2)
            {
                string xd;
                cout<<"Enter Student ID : ";
                cin>>xd;

                next();

                Student s2;
                s2.showStudent(xd);
            }
            else if(x==3)
            {
                string xd;
                cout<<endl<<"Enter Student ID  : ";
                cin>>xd;
                cout<<endl;
                Student s3;
                s3.showgrade(xd);
            }
            else if(x==4)
            {
                p1->edit_password(str);
            }
            else if(x==5)
            {
                t1.courses_taken(str);
            }
            else if(x==6)
            {
                help();
            }
            else break;

            next();
        }
    }
    else if(str.substr(0,1)=="A") ///administrator
    {
        login_successful(3);
        activity_log_input(str,1);
//
//        /// enter new student info, edit student info , marks entry

        while(1)
        {
            cout<<"Choose one of the following options :"<<endl;
            dis(3,35);
            cout<<endl<<endl;

            cout<<" 1 .  Enter New Student's Details "<<endl;
            cout<<" 2 .  Enter New Teacher's Details "<<endl;
            cout<<" 3 .  View Student's Details "<<endl;
            cout<<" 4 .  View Teacher's Details "<<endl;
            cout<<" 5 .  View Student's Grade "<<endl;
            cout<<" 6 .  Edit Student's Grade "<<endl;   /// semester-wise
            cout<<" 7 .  Assign Course to Teacher"<<endl;
            cout<<" 8 .  Course Taken by Teacher"<<endl;
            cout<<" 9 .  Change Password "<<endl;
            cout<<" 10.  Residence Details"<<endl;
            cout<<" 11.  Activity Log "<<endl;
            cout<<" 12.  Help Section"<<endl;
            cout<<" 13.  Back"<<endl<<endl;

            cout<<"Enter your choice : ";
            cin>>x;

            next();

            Administrator a1;

            if(x==1)
            {
                a1.setStudent();
            }
            else if(x==2)
            {
                //Teacher t1;
                a1.setData();
            }
            else if(x==3)
            {
                string xd;
                cout<<"Enter Student ID : ";
                cin>>xd;

                next();

                //Student s2;
                if(check_id(xd))a1.showStudent(xd);
                else
                {
                    cout<<"Error! ID not found.\n";
                }
            }
            else if(x==4)
            {
                string xd;
                cout<<"Enter Teacher ID : ";
                cin>>xd;

                next();

                //Teacher t2;
                if(check_id(xd)) a1.showTeacher(xd);
                else
                {
                    cout<<"Error! ID not found.\n";
                }
            }
            else if(x==5)
            {
                string xd;
                cout<<endl<<"Enter Student ID  : ";
                cin>>xd;
                cout<<endl;
                if(check_id(xd))a1.showgrade(xd);
                else
                {
                    cout<<"Error! ID not found.\n";
                }
            }
            else if(x==6)
            {
                string xd;
                cout<<endl<<"Enter Student ID  : ";
                cin>>xd;
                cout<<endl;
                if(check_id(xd)) a1.edit_marks(xd);
                else
                {
                    cout<<"Error! ID not found.\n";
                }
            }
            else if(x==7)
            {
                string x,y;

                cout<<"Enter Teacher ID      : ";
                cin>>x;
                cout<<endl;
                cout<<"Enter Assigned course : ";
                cin>>y;
                cout<<endl;
                if(check_id(x))a1.course_init(y,x);
                else
                {
                    cout<<"Error! Teacher ID not found.\n";
                }
            }
            else if(x==8)
            {
                string x,y;

                cout<<"Enter Teacher ID      : ";
                cin>>x;

                next();

                if(check_id(x))a1.courses_taken(x);
                else
                {
                    cout<<"Error! ID not found.\n";
                }
            }
            else if(x==9)
            {
                p1->edit_password(str);
            }
            else if(x==10)
            {
                string str,x;
                cout<<endl<<"Choose one of the following options "<<endl<<endl;
                cout<<" 1. Vacant seats \n 2. Hall Details \n 3. Room details\n\nEnter Your Choice: ";
                cin>>x;

                cout<<endl<<endl;
                next();

                if(x=="1")
                {
                    a1.vacant_seats("vacant");
                }
                else if(x=="2")
                {
                    a1.vacant_seats("full");
                }

                else if(x=="3")
                {
                    cout<<endl<<"Enter room no (ex 410N): ";

                    cin>>str;
                    a1.find_room(str);
                    cout<<endl<<endl;
                }

            }
            else if(x==11)
            {
                activity_log();
            }
            else if(x==12)
            {
                help();
            }
            else break;

            next();

        }
    }
}

int main()
{
    //system("Color 03");
    system("Color 0B");

    try
    {
        authorization();
        //PlaySound(TEXT("Music_For_Project.wav"),NULL,SND_SYNC);
        muchas_gracias();
    }
    catch(Person::genError)
    {
        cout<<"Invalid Input !!!"<<endl;
    }

    return 0;
}
