#ifndef TEACHER_H
#define TEACHER_H
#include"Person.h"
#include <bits/stdc++.h>

using namespace std;

class Teacher : virtual public Person
{
protected:
    string TID;
    string JoinD;
    string post;

    vector<class Course*>courses;

    void Teacher_Det(string ss);

public:
    Teacher(string a,string x,string b,string c,string d,string e,string f,string w,string j,string p);
    Teacher();
    void showTeacher(string x);
    void courses_taken(string TID);
    virtual ~Teacher();
};

#endif // TEACHER_H
