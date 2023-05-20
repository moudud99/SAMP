#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Person
{
protected:
    string Name_1,Name_2,dept1,dateOfBirth1,gender1,BG,contact,Email;
    int age1;
    void Age_calc(string s);
public:
    Person();
    Person(string a,string x,string b,string c,string d,string e,string f);
    class genError {};
    virtual void setData();
    virtual void getData();
    virtual void edit_password(string st_id);
    virtual ~Person()
    {}
};

#endif // PERSON_H
