#include "Teacher.h"
#include<bits/stdc++.h>
#include "Person.h"
#include "Student.h"

using namespace std;

extern dis(int n,int x = 40);
extern next();
extern check_id(string id);
extern authorization_setup(string ID);

void Teacher::Teacher_Det(string ss)
{
    string x = ss.substr(1,1);
    if(x=="1")
        dept1 = "Mechanical";
    else if(x=="2")
        dept1 = "EEE";
    else if(x=="4")
        dept1 = "CSE";
    else if(x=="5")
        dept1 = "CEE";
    else if(x=="6")
        dept1 = "BTM";
}

Teacher::Teacher()
{}

Teacher::Teacher(string a="",string x= "",string b="",string c="",string d="",string e="",string f="",string w="",string j="",string p=""):Person(a,x,b,c,d,e,f),TID(w),JoinD(j),post(p)
{}

void Teacher::showTeacher(string id)
{
    string TID,Name_1,Name_2,dept,dateOfBirth,gender,BG,contact,Email,JoinD,post;
    ifstream teacher("teacher.txt");

    if(teacher)
    {
        while(teacher>>TID>>Name_1>>Name_2>>dept>>dateOfBirth1>>age1>>gender>>BG>>contact>>Email>>JoinD>>post)
        {
            if(TID==id)
            {
                cout<<endl<<endl<<"Teacher Details"<<endl;
                dis(2,40);
                cout<<endl<<endl;
                cout<<"Teacher ID           : "<<TID<<endl;
                cout<<"Teacher Name         : "<<Name_1<<" "<<Name_2<<endl;
                cout<<"Department           : "<<dept<<endl;
                cout<<"Date of Birth        : "<<dateOfBirth1<<endl;
                cout<<"Age                  : "<<age1<<endl;
                cout<<"Gender               : "<<gender<<endl;
                cout<<"Blood Group          : "<<BG<<endl;
                cout<<"Contact No.          : "<<contact<<endl;
                cout<<"Email No.            : "<<Email<<endl;
                cout<<"Join Date            : "<<JoinD<<endl;
                cout<<"Post                 : "<<post<<endl;

            }
        }
    }
    else
    {
        cout<<"Error Opening Teacher File"<<endl;
    }

    next();
}

Teacher::~Teacher()
{}

//void Teacher::course_init(string c_name,string t_name)
//{
//    ofstream course_tempFile("course_temp.txt");
//    ifstream courses("course_list.txt");
//    if(!courses)
//    {
//        cout<<"File not found";
//    }
//    else
//    {
//        courses.close();
//        string course_id,course_name,teacher_name;
//        ifstream courses("course_list.txt");
//
//        while(courses>>course_id>>course_name>>teacher_name)
//        {
//            if(course_id==c_name)
//            {
//                teacher_name=t_name;
//            }
//            course_tempFile<<course_id<<" "<<course_name<<" "<<teacher_name<<endl;
//        }
//        courses.close();
//        course_tempFile.close();
//        ofstream courses1("course_list.txt");
//        ifstream course_tempFile("course_temp.txt");
//
//        if(course_tempFile)
//        {
//            while(course_tempFile>>course_id>>course_name>>teacher_name)
//            {
//                courses1<<course_id<<" "<<course_name<<" "<<teacher_name<<endl;
//            }
//        }
//        courses1.close();
//        course_tempFile.close();
//        remove("course_temp.txt");
//    }
//
//}

void Teacher::courses_taken(string TID)
{
    ifstream courses("course_list.txt");
    if(!courses)
    {
        cout<<"ERROR !!\n";
    }
    else
    {
        courses.close();
        ifstream courses("course_list.txt");
        string c_id,c_name,t_id;
        cout<<"Courses taken by Teacher ID: "<<TID<<endl;
        dis(2,30);
        int i=1;
        while(courses>>c_id>>c_name>>t_id)
        {
            if(t_id==TID)
            {
                cout<<i<<") "<<c_id<<" "<<c_name<<endl;
                i++;
            }
        }
        courses.close();
    }
}
