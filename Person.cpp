#include<ctime>
#include "Person.h"
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

extern int check_id(string sid);

time_t ttime = time(0);
tm *local_time = localtime(&ttime);

void time()
{
    int c_year = 1900 + local_time->tm_year;
    int c_month = 1 + local_time->tm_mon;
    int c_date = local_time->tm_mday;
    int c_day = local_time->tm_wday;
    int c_hour = local_time->tm_hour;
    int c_min = local_time->tm_min;
    int c_sec = local_time->tm_sec;

    string day;

    if(c_day==1) day = "Monday";
    if(c_day==2) day = "Tuesday";
    if(c_day==3) day = "Wednesday";
    if(c_day==4) day = "Thursday";
    if(c_day==5) day = "Friday";
    if(c_day==6) day = "Saturday";
    if(c_day==7) day = "Sunday";

    cout<<endl<<c_hour<<":"<<c_min<<":"<<c_sec<<"  "<<day<<"  "<<c_date<<"/"<<c_month<<"/"<<c_year<<endl;
}

void dis(int n,int x = 40)
{
    for(int i=0; i<x; i++)
    {
        if(n==1) cout<<"-";
        else if(n==2) cout<<"<>";
        else if(n==3) cout<<"*";
        else if(n==4) cout<<"+";
    }
    cout<<endl<<endl;
}

void next()
{
    cout<<endl<<endl;
    system("PAUSE");
    system("CLS");
}


Person::Person()
{}

Person::Person(string a,string x,string b,string c,string d,string e,string f)
{
    Name_1=a;
    Name_2=x;
    Email=b;
    dateOfBirth1=c;
    gender1=d;
    BG=e;
    contact=f;
}
void Person::Age_calc(string s)
{
    string y = s.substr(6,4);
    string m = s.substr(3,2);
    string d = s.substr(0,2);
    long long t1 = (y[0]-'0')*1000 + (y[1]-'0')*100 + (y[2]-'0')*10 + (y[3]-'0');
    long long t2 = 1900 + local_time->tm_year;
    age1 = t2-t1;
}

void Person::setData()
{
    cout<<"Name                       : ";
    cin>>Name_1>>Name_2;
    cout<<"Date of Birth (DD/MM/YYYY) : ";
    cin>>dateOfBirth1;
    cout<<"Gender                     : ";
    cin>>gender1;
    cout<<"Blood Group                : ";
    cin>>BG;
    cout<<"Contact No                 : ";
    cin>>contact;
    cout<<"Email                      : ";
    cin>>Email;

    string xd = gender1;
    transform(xd.begin(), xd.end(), xd.begin(), ::toupper);

    if(xd!="MALE" || xd!="FEMALE")
    {
        gender1 = "Unavailable";
        throw genError();
    }

    Age_calc(dateOfBirth1);
}

void Person::getData() {};

//    cout<<"Name           : "<< Name_1 <<" "<< Name_2 <<endl;
//    cout<<"Date of Birth  : "<< dateOfBirth1 <<endl;
//    cout<<"Age            : "<< age1 <<endl;
//    cout<<"Gender         : "<<gender1 <<endl;
//    cout<<"Blood Group    : "<<BG <<endl;
//    cout<<"Contact No     : "<<contact <<endl;
//    cout<<"Email          : "<<Email <<endl;




void Person::edit_password(string st_id)
{
    int flag=0;
    ofstream passTempFile("PassTemp.txt");
    string id,pass,replaced_pass,traverse,oldpass;
    ifstream password("Password.txt");
    if(check_id(st_id))
    {
        cout<<"Enter Old Password: ";
        cin>>oldpass;
        cout<<"Enter The Password You want : ";
        cin>>replaced_pass;
        while(password>>id>>pass)
        {
            if(pass==oldpass && st_id==id)
            {
                pass=replaced_pass;
                flag=1;
            }
            if(1)
            {
                passTempFile<<id<<" "<<pass<<endl;
            }
        }
        if(!flag)
        {
            cout<<"Wrong Password"<<endl;
        }
        password.close();
        passTempFile.close();
        ofstream password("Password.txt");
        ifstream passTempFile("PassTemp.txt");
        if(passTempFile)
        {
            while(passTempFile>>id>>pass)
            {
                password<<id<<" "<<pass<<endl;
            }
        }
        password.close();
        passTempFile.close();
        remove("PassTemp.txt");


    }
    else
    {
        cout<<"ID not Found"<<endl;
    }

    next();

}


void help()
{
    cout<<endl<<"Solutions to some frequently faced problems"<<endl;
    dis(1,40);
    cout<<"Examples of input format\n";
    cout<<"-------------------------------"<<endl<<endl;
    cout<<"Name               : Firstname Lastname\n\n";
    cout<<"Date               : 01/01/2000   (Date/Month/)\n\n";
    cout<<"residence          : 401N_A  (Room no Side _ Bed)\n\n";
    cout<<"vaccination status : Vaccinated / Not_vaccinated\n\n\n\n";

    cout<<"User Input Format\n";
    cout<<"-------------------------------"<<endl<<endl;
    cout<<"Administrator             'A' followed by unique ID \n\n";
    cout<<"Teacher                   'T' followed by unique ID \n\n";
    cout<<"Administrator              9 Digit Unique ID \n\n";

    next();

}

void muchas_gracias()
{
    char str;
    ifstream whatever("muchas_gracias.TXT"); //create file for output
    while( !whatever.get(str).eof() )  //for each character,
    {
        cout << str;
    }
    time();
    next();
}

