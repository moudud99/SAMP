#include "Administrator.h"
#include "Teacher.h"
#include "Student.h"
#include "Person.h"
#include <bits/stdc++.h>

using namespace std;

extern dis(int n,int x = 40);
extern next();
extern check_id(string st_id);
extern string course_id[];
extern string course_fullname[];
extern double course_credits[];
extern authorization_setup(string ID);
extern add_id(string id);

Administrator::Administrator()
{
    //ctor
}

void make_empty_file(string st_id)
{
    float f=0.0;

    ifstream student_id("student_id.txt");
//    if(check_id(st_id))
//    {
//        cout<<"Already Exists"<<st_id<<endl;
//    }
//    else
//    {
    if(student_id)
    {
        student_id.close();
        ofstream student_id("student_id.txt",ios::app);
        for(int i=0; i<41; i++)
        {
            //cout<<st_id<<" "<<name<<" "<<course_id[i]<<" "<<course_fullname[i]<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<endl;
            student_id<<st_id<<" "<<course_id[i]<<" "<<course_fullname[i]<<" "<<course_credits[i]<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<endl;

        }
        student_id.close();
    }
    else
    {
        ofstream student_id("student_id.txt");
        for(int i=0; i<41; i++)
        {
            //cout<<st_id<<" "<<name<<" "<<course_id[i]<<" "<<course_fullname[i]<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<endl;
            student_id<<st_id<<" "<<course_id[i]<<" "<<course_fullname[i]<<" "<<course_credits[i]<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<" "<<f<<endl;

        }
        student_id.close();
    }
//    }
}

void assign_residence(string str,string input_ID)
{
    string hallno,side,A,B,C,D,hallSeat,hallnumber,hall,NS;
    int flag = 0;

    ifstream residence("Residence.txt");
    ofstream HallTempFile("HallTemp.txt");

    hall = str.substr(0,3);
    NS = str.substr(3,1);
    hallSeat = str.substr(5,1);


    if(!residence)
    {
        cout<<"Residence File not Found"<<endl;
    }
    else
    {

        while(residence>>hallno>>side>>A>>B>>C>>D)
        {
            if(hallno == hall && side==NS)
            {
                if(hallSeat=="A" && A=="A")
                {
                    A=input_ID;
                    flag = 1;
                }
                else if(hallSeat=="B" && B=="B")
                {
                    B=input_ID;
                    flag = 1;
                }
                else if(hallSeat=="C" && C=="C")
                {
                    C=input_ID;
                    flag = 1;
                }
                else if(hallSeat=="D" && D=="D")
                {
                    D=input_ID;
                    flag = 1;
                }
                else
                {
                    cout<<"Error !! Seat Already Taken"<<endl;
                }
            }


            HallTempFile<<hallno<<" "<<side<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
        }

        residence.close();
        HallTempFile.close();
        ofstream residence("Residence.txt");
        ifstream HallTempFile("HallTemp.txt");
        if(HallTempFile)
        {
            while(HallTempFile>>hallno>>side>>A>>B>>C>>D)
            {
                residence<<hallno<<" "<<side<<" "<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
            }
        }
        residence.close();
        HallTempFile.close();
        remove("HallTemp.txt");
    }
    next();
}



void Administrator::setStudent()
{
    system("PAUSE");
    system("CLS");

    ifstream student("student.txt");
    if(student)
    {
        student.close();
        ofstream student("student.txt",ios::app);
        cout<<endl<<"Please Enter Student Details: "<<endl;
        dis(3,35);
        cout<<"Student ID           : ";
        cin>>studentID;
        if(check_id(studentID))
        {
            cout<<"Already Exists 1"<<endl;
        }
        else
        {
            add_id(studentID);
            cout<<"Student Name         : ";
            getchar();
            getline(cin,name);
            //getchar();
            cout<<"Date of Birth        : ";
            cin>>dateOfBirth;
            cout<<"Gender               : ";
            cin>>gender;
            cout<<"Blood Group          : ";
            cin>>BloodGroup;
            cout<<"Contact No.          : ";
            cin>>contact_no;
            cout<<"Residence            : ";
            cin>>residence;
            cout<<"Vaccination Status   : ";
            cin>>vacc_status;
            cout<<endl;
            details();
            ageAndSem();
            student<<studentID<<" "<<name<<" "<<batch<<" "<<semester<<" "<<dept<<" "<<program<<" "<<section<<" "<<dateOfBirth<<" "<<age<<" "<<gender<<" "<<BloodGroup<<" "<<contact_no<<" "<<residence<<" "<<vacc_status<<endl;
            cout<<endl;

            //__hall = residence.substr(0,4);

            make_empty_file(studentID);
            authorization_setup(studentID);
            assign_residence(residence,studentID);
            student.close();
        }
    }
    if(!student)
    {
        student.close();
        ofstream student("student.txt");
        //student<<"Student_ID   Name  Date of Birth    Gender   Blood_Group    Mobile_Number  Residence  Vaccination_Status"<<endl;
        cout<<endl<<"Please Enter Student Details: "<<endl;
        dis(3,35);
        cout<<"Student ID           : ";
        cin>>studentID;
        if(check_id(studentID))
        {
            cout<<"Already Exists (Student ID already registered)"<<endl;
        }
        else
        {
            add_id(studentID);
            cout<<"Student Name         : ";
            getchar();
            getline(cin,name);
            //getchar();
            cout<<"Date of Birth        : ";
            cin>>dateOfBirth;
            cout<<"Gender               : ";
            cin>>gender;
            cout<<"Blood Group          : ";
            cin>>BloodGroup;
            cout<<"Contact No.          : ";
            cin>>contact_no;
            cout<<"Residence            : ";
            cin>>residence;
            cout<<"Vaccination Status   : ";
            cin>>vacc_status;
            cout<<endl;
            details();
            ageAndSem();
            student<<studentID<<" "<<name<<" "<<batch<<" "<<semester<<" "<<dept<<" "<<program<<" "<<section<<" "<<dateOfBirth<<" "<<age<<" "<<gender<<" "<<BloodGroup<<" "<<contact_no<<" "<<residence<<" "<<vacc_status<<endl;
            make_empty_file(studentID);
            assign_residence(residence,studentID);
            authorization_setup(studentID);
            student.close();

        }
    }
}

void Administrator::setData()
{
    system("PAUSE");
    system("CLS");

    ifstream teacher("teacher.txt");

    if(teacher)
    {
        teacher.close();
        ofstream teacher("teacher.txt",ios::app);
        cout<<endl<<"Enter Teacher Data"<<endl;
        dis(3,35);
            cout<<"Teacher ID                 : ";
        cin>>TID;
        if(check_id(TID))
        {
            cout<<"Teacher Already Exists"<<endl;
        }
        else
        {
            add_id(TID);
            Person::setData();
            cout<<"Join Date                  : ";
            cin>>JoinD;
            cout<<"Post                       : ";
            getchar();
            getline(cin,post);
            Teacher_Det(TID);
            //Age_calc(dateOfBirth);
            teacher<<TID<<" "<<Name_1<<" "<<Name_2<<" "<<dept1<<"  "<<dateOfBirth1<<"  "<<age1<<"  "<<gender1<<"  "<<BG<<" "<<contact<<" "<<Email<<" "<<JoinD<<" "<<post<<endl;
            teacher.close();
            authorization_setup(TID);
        }
    }
    if(!teacher)
    {
        teacher.close();
        ofstream teacher("teacher.txt");
        cout<<endl<<"Enter Teacher Data"<<endl;
        dis(3,35);
        cout<<"Teacher ID                 : ";
        cin>>TID;
        if(check_id(TID))
        {
            cout<<"Teacher Already Exists"<<endl;
        }
        else
        {
            add_id(TID);
            Person::setData();
            cout<<"Join Date                  : ";
            cin>>JoinD;
            cout<<"Post                       : ";
            getchar();
            getline(cin,post);
            Teacher_Det(TID);
            teacher<<TID<<" "<<Name_1<<" "<<Name_2<<" "<<dept1<<"  "<<dateOfBirth1<<"  "<<age1<<"  "<<gender1<<"  "<<BG<<" "<<contact<<" "<<Email<<" "<<JoinD<<" "<<post<<endl;
            //Age_calc(dateOfBirth);
            teacher.close();
            authorization_setup(TID);
        }
    }
}


void Administrator::edit_marks(string st_id)
{
    ofstream tempFile("temp.txt");
    string id,name,course_id,input_code,course_credit;
    string att,q1,q2,q3,q4,mid,sem_fin,marks;
    ifstream course_file("student_id.txt");
    if(!course_file)
    {
        cout<<"Course File not Found"<<endl;
    }
    else
    {
        int option;
        string strin,str,str_id,str_course,str_coursename;
        cout<<endl<<"Enter Course Code : ";
        cin>>input_code;

        next();

        cout<<"What do You Want to Update ?"<<endl;
        dis(3,40);

        cout<<"1.Attendance (10%)"<<endl;
        cout<<"2.Quiz 1     (15%)"<<endl;
        cout<<"3.Quiz 2     (15%)"<<endl;
        cout<<"4.Quiz 3     (15%)"<<endl;
        cout<<"5.Quiz 4     (15%)"<<endl;
        cout<<"6.Mid Semester Exam    (25%)"<<endl;
        cout<<"7.Semester Final Exam  (50%)"<<endl<<endl;

        cout<<"Enter your option: ";
        cin>>option;
        cout<<endl<<endl;
        cout<<"Enter updated marks: ";
        cin>>marks;

        while(course_file>>str_id>>str_course>>str_coursename>>course_credit>>att>>q1>>q2>>q3>>q4>>mid>>sem_fin)
        {
            if(str_id==st_id && input_code==str_course)
            {
                if(option == 1) att=marks;
                else if(option == 2) q1=marks;
                else if(option == 3) q2=marks;
                else if(option == 4) q3=marks;
                else if(option == 5) q4=marks;
                else if(option == 6) mid=marks;
                else if(option == 7) sem_fin=marks;
            }
            if(1)
            {
                tempFile<<str_id<<" "<<str_course<<" "<<str_coursename<<" "<<course_credit<<" "<<att<<" "<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<" "<<mid<<" "<<sem_fin<<endl;
            }
        }
        course_file.close();
        tempFile.close();
        ofstream course_file("student_id.txt");
        ifstream tempFile("temp.txt");

        if(tempFile)
        {
            while(tempFile>>str_id>>str_course>>str_coursename>>course_credit>>att>>q1>>q2>>q3>>q4>>mid>>sem_fin)
            {
                course_file<<str_id<<" "<<str_course<<" "<<str_coursename<<" "<<course_credit<<" "<<att<<" "<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<" "<<mid<<" "<<sem_fin<<endl;
            }
        }
        course_file.close();
        tempFile.close();
        remove("temp.txt");
        next();

    }
}

void Administrator::course_init(string c_name,string t_name)
{
    ofstream course_tempFile("course_temp.txt");
    ifstream courses("course_list.txt");
    if(!courses)
    {
        cout<<"File not found";
    }
    else
    {
        courses.close();
        string course_id,course_name,teacher_name;
        ifstream courses("course_list.txt");

        while(courses>>course_id>>course_name>>teacher_name)
        {
            if(course_id==c_name)
            {
                teacher_name=t_name;
            }
            course_tempFile<<course_id<<" "<<course_name<<" "<<teacher_name<<endl;
        }
        courses.close();
        course_tempFile.close();
        ofstream courses1("course_list.txt");
        ifstream course_tempFile("course_temp.txt");

        if(course_tempFile)
        {
            while(course_tempFile>>course_id>>course_name>>teacher_name)
            {
                courses1<<course_id<<" "<<course_name<<" "<<teacher_name<<endl;
            }
        }
        courses1.close();
        course_tempFile.close();
        remove("course_temp.txt");
    }

}

void Administrator::vacant_seats(string f)
{
    string hallno,side,A,B,C,D,hallSeat,hallnumber,w,x,y,z;
    int flag = 0;

    ifstream residence2("Residence.txt");
    ofstream HallTempFile("HallTemp.txt");

    cout<<"Room No      Side       Seat A         Seat B        Seat C         Seat D"<<endl;
    cout<<"*******     ******   ************   ***********   ************   ************"<<endl;

    if(!residence2)
    {
        cout<<"Residence File not Found"<<endl;
    }

    else
    {
        while(residence2>>hallno>>side>>A>>B>>C>>D)
        {

            if(A=="A" || B=="B" || C=="C" || D=="D")
            {
                flag = 1;

                //if(A=="A")
                {
                    if(A=="A") w = "vacant(A)";
                    else if (f=="full") w = "         ";
                    else w = A;

                }
                //if(B=="B")
                {
                    if(B=="B") x = "vacant(D)";
                    else if (f=="full") x = "         ";
                    else x = B;
                }
                //if(C=="C")
                {
                    if(C=="C") y = "vacant(C)";
                    else if (f=="full") y = "         ";
                    else y = C;
                }
                //if(D=="D")
                {
                    //if(hallno=="409") cout<<D<<endl;
                    if(D=="D") z = "vacant(D)";
                    else if (f=="full") z = "         ";
                    else z = D;
                }
            }
//            cout<<left<<hallno<<setw(15)<<side<<setw(8)<<w<<setw(14)<<x<<setw(14)<<y<<setw(14)<<z<<setw(14)<<endl;
            cout<<hallno<<setw(13)<<side<<setw(16)<<w<<setw(14)<<x<<setw(14)<<y<<setw(16)<<z<<endl;
        }

        if(!flag)
        {
            cout<<"No Vacant Seats"<<endl;
        }
    }

    residence2.close();
    HallTempFile.close();

    next();
}

void Administrator::find_room(string hall)
{
    string hallno,side,A,B,C,D,hallSeat,hallnumber,W,X,Y,Z,NS;
    int flag = 0;

    hallnumber = hall.substr(0,3);
    NS = hall.substr(3,1);

    //cout<<hall<<" "<<hallno<<" "<<NS<<endl;
    //hallSeat = hall.substr(5,1);

    ifstream residence("Residence.txt");
    ofstream HallTempFile("HallTemp.txt");

    next();

    if(!residence)
    {
        cout<<"Residence File not Found"<<endl;
    }
    else
    {
        while(residence>>hallno>>side>>A>>B>>C>>D)
        {
            //cout<<"HEllo"<<endl;
            if(hallno == hallnumber && side == NS)
            {

                W = A,X = B,Y = C, Z = D;
                //cout<<hallno<<" "<<side<<" ";
                flag = 1;

                if(A=="A")
                {
                    W = "vacant";
                }
                if(B=="B")
                {
                    X = "vacant";
                }
                if(C=="C")
                {
                    Y = "vacant";
                }
                if(D=="D")
                {
                    Z = "vacant";
                }

                cout<<"Room No "<<hallno<<" "<<NS<<endl;
                dis(2,15);
                cout<<"Bed A : "<<W<<endl;
                cout<<"Bed B : "<<X<<endl;
                cout<<"Bed C : "<<Y<<endl;
                cout<<"Bed D : "<<Z<<endl<<endl;

                cout<<endl;
            }
        }

        residence.close();
        HallTempFile.close();
    }

    next();
}

Administrator::~Administrator()
{}
