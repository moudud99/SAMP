#ifndef STUDENT_H
#define STUDENT_H
#include"Person.h"
#include <bits/stdc++.h>

using namespace std;

class Student:virtual public Person
{
protected:
    string studentID;
    string name;
    string batch;
    string dept;
    string program;
    string section;
    int semester;
    string dateOfBirth;
    int age;
    string gender;
    string residence;
    string BloodGroup;
    //double CG;
    string contact_no;
    string vacc_status;
public:

    void department();
    void ageAndSem();
    void details();
    Student(string a,string b,string c,string d,string e,string f,string x,string y);
    Student();
    void showStudent(string id);
    void schedule();
    void showgrade(string id);
    void find_course();
    //void residence_r();
    virtual ~Student();
};
#endif // STUDENT_H
