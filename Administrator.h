#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include"Person.h"
#include"Teacher.h"
#include"Student.h"
#include <bits/stdc++.h>

using namespace std;


class Administrator : public Teacher, public Student
{
private:

public:
    Administrator();
    void setStudent();
    void setData();
    void edit_marks(string id);
    void course_init(string c_name,string t_name);
    void vacant_seats(string str);
    void find_room(string hall);
    ~Administrator();

};

#endif // ADMINISTRATOR_H
