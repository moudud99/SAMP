#include<bits/stdc++.h>
#include "Student.h"
#include <ctime>

using namespace std;

extern dis(int n,int x = 40);
extern next();
extern string access_ID;
string __hall;

time_t tttime = time(0);
tm *local_ttime = localtime(&tttime);

namespace shomoy
{
string routine_slot[15]= {"080000","090000","100000","110000","120000","125000","141000","151000","161500","170500","180500"};

int c_year = 1900 + local_ttime->tm_year;
int c_month = 1 + local_ttime->tm_mon;
int c_date = local_ttime->tm_mday;
int c_day = local_ttime->tm_wday;
int c_hour = local_ttime->tm_hour;
int c_min = local_ttime->tm_min;
int c_sec = local_ttime->tm_sec;

int tx = c_sec + c_min*100 + c_hour*10000;
string tmp_time = to_string(tx);
int n=6-tmp_time.length();
string xx(n,'0');
string curr_time=xx+tmp_time;
}

using namespace shomoy;

string course_id[] = {"CSE__4105","CSE__4101","MATH_4141","HUM__4145","HUM__4147","PHY__4141","HUM__4142","PHY__4142","CSE__4108","CSE__4104",
                      "CSE__4203","CSE__4205","CHEM_4241","HUM__4241","MATH_4241","PHY__4241","HUM__4242","PHY__4242","CHEM_4242","CSE__4204","CSE__4206",
                      "CSE__4301","CSE__4303","CSE__4305","CSE__4307","MATH_4341","EEE__4383","EEE__4384","CSE__4302","CSE__4304","CSE__4308",
                      "CSE__4403","CSE__4405","CSE__4407","EEE__4483","HUM__4441","MATH_4441","EEE__4484","CSE__4402","CSE__4404","CSE__4408"
                     };

string course_fullname[] =
{
    "Computing_for_Engineers","Structured_Programming_I","Geometry_and_Differential_Calculus","Islamiat","Technology,_Environment_and_Society","Physics_I","Arabic_I","Physics_I_Lab","Structured_Programming_I_Lab","Engineering_Drawing_Lab",
    "Discrete_Mathematics","Digital_Logic_Design","Chemistry","Islamic_History_Science_and_Culture","Integral_Calculus_and_Differential_Equations","Physics_II","Arabic_II","Physics_II_Lab","Chemistry_Lab","Structured_Programming_II_Lab","Digital_Logic_Design_Lab",
    "Object_Oriented_Programming","Data_Structures","Computer_Organization_and_Architecture","Database_Management_Systems","Linear_Algebra","Electronic_Devices_and_Circuits","Electronic_Devices_and_Circuits_Lab","Object_Oriented_Programming_Lab","Data_Structures_Lab","Database_Management_Systems_Lab",
    "Algorithms","Data_and_Telecommunications","System_Analysis_and_Design","Digital_Electronics_and_Pulse_Techniques","Engineering_Ethics", "Probability_and_Statistics","Digital_Electronics_and_Pulse_Techniques_Lab","Visual_Programming_Lab","Algorithms_Lab","System_Analysis_and_Design_Lab"
};

double course_credits[] =
{
    3,3,4,2,3,3,1,0.75,1.5,0.75,
    3,3,3,2,4,3,1,0.75,0.75,1.5,0.75,
    3,3,3,3,3,3,0.75,1.5,1.5,1,
    3,4,2,3,3,3,0.75,1.5,1,1
};

void Student::ageAndSem()
{
    string y = dateOfBirth.substr(6,4);
    string m = dateOfBirth.substr(3,2);
    string d = dateOfBirth.substr(0,2);
    string a = m + d;
    long long t1 = (y[0]-'0')*1000 + (y[1]-'0')*100 + (y[2]-'0')*10 + (y[3]-'0');
    long long t2 = 1900 + local_ttime->tm_year;
    long long t3 = (a[0]-'0')*1000 + (a[1]-'0')*100 + (a[2]-'0')*10 + (a[3]-'0') ;
    long long t4 = (1 + local_ttime->tm_mon)*100 + (local_ttime->tm_mday) ;
    age = t2-t1;
    if( t4 < t3 )
        age--;
    long long t5 = (batch[0]-'0')*10 +(batch[1]-'0');
    long long monthspassed =  (local_ttime->tm_year - 100 - t5 - 1)*12 + 1 + local_ttime->tm_mon;
    semester = ceil((double)monthspassed/6.00);
    if( (1 + local_ttime->tm_mon) < 9 )
        semester--;
}

void authorization_setup(string st_id)
{

    ifstream password("Password.txt");
//    if(check_id(st_id))
//    {
//        cout<<"Already Exists"<<st_id<<endl;
//    }
//    else
//    {
    if(password)
    {
        password.close();
        ofstream password("Password.txt",ios::app);
        password<<st_id<<" "<<st_id<<endl;
        password.close();
    }
    else
    {
        ofstream password("Password.txt");
        password<<st_id<<" "<<st_id<<endl;
        password.close();
    }
//    }
}

int check_id(string st_id)
{
    string id;
    int flag=0;
    ifstream all_id("All_ID.txt");
    if(all_id)
    {
        while(all_id>>id)
        {
            if(st_id==id)
            {
                flag=1;
                all_id.close();
                return 1;
            }
        }
    }
    if(flag==0)
    {
        all_id.close();
        return 0;
    }
}
void add_id(string id)
{
    ofstream all_id("All_ID.txt",ios::app);
    all_id<<id<<endl;
    all_id.close();
}

Student::Student(string a="",string b="",string c="",string d="",string e="",string f="",string x="",string y=""):studentID(a),name(b),dateOfBirth(c),gender(d),BloodGroup(e),contact_no(f),vacc_status(x),residence(y)
{
    if(a.size()>9)
        studentID="";
    details();
    ageAndSem();
    //residence_r();
}

Student::Student()
{}

Student::~Student()
{}

void Student::department()
{
    string x = studentID.substr(4,2);
    if(x=="11")
    {
        dept = "Mechanical";
        program = "Mechanical";
    }
    else if(x=="12")
    {
        dept = "Mechanical";
        program = "IPE";
    }
    else if(x=="21")
    {
        dept = "EEE";
        program = "EEE";
    }
    else if(x=="41")
    {
        dept = "CSE";
        program = "CSE";
    }
    else if(x=="42")
    {
        dept = "CSE";
        program = "SWE";
    }
    else if(x=="51")
    {
        dept = "CEE";
        program = "CEE";
    }
    else if(x=="61")
    {
        dept = "BTM";
        program = "BTM";
    }
}

void Student::details()
{
    batch = studentID.substr(0,2);
    department();
    section = studentID.substr(6,1);
}

//void Student::residence_r()
//{
//    string room_no = residence.substr(0,3),hall(3,1),bed(5,1);
//}



void Student::showStudent(string id)
{
    string studentID,name,name2,batch,semester,dept,program,section,dateOfBirth,age,gender,BloodGroup,contact_no,vac_sts,res;
    ifstream student("student.txt");

    if(student)
    {
        while(student>>studentID>>name>>name2>>batch>>semester>>dept>>program>>section>>dateOfBirth>>age>>gender>>BloodGroup>>contact_no>>res>>vac_sts)
        {
            if(id==studentID)
            {
                cout<<endl<<endl<<"Student Details"<<endl;
                dis(2,40);
                cout<<endl<<endl;
                cout<<"Student ID           : "<<studentID<<endl;
                cout<<"Student Name         : "<<name<<" "<<name2<<endl;
                cout<<"Batch                : "<<batch<<endl;
                //cout<<"Semester             : "<<semester<<endl;
                cout<<"Department           : "<<dept<<endl;
                cout<<"Program              : "<<program<<endl;
                cout<<"Section              : "<<section<<endl;
                cout<<"Date of Birth        : "<<dateOfBirth<<endl;
                cout<<"Age                  : "<<age<<endl;
                cout<<"Gender               : "<<gender<<endl;
                cout<<"Blood Group          : "<<BloodGroup<<endl;
                cout<<"Contact No.          : "<<contact_no<<endl;
                cout<<"Residence            : "<<res.substr(0,4)<<' '<<res.substr(5,1)<<endl;
                cout<<"Vaccination Status   : "<<vac_sts<<endl;
            }
        }
    }
    else
    {
        cout<<"Error Opening Student File"<<endl;
    }

    next();
}

void Student::schedule()
{
    int wday,flag=0;
    string ID,sem,id,slots[15],input;
    cout<<"Enter ID       : ";
    cin>>ID;
    cout<<"Enter semester : ";
    cin>>sem;
    ID = sem+ID.substr(4,3);
    ifstream routine("routine.txt");

    next();

    if(!routine)
    {
        cout<<"Routine File not Found"<<endl;
    }
    else
    {
        string strin,str,str_replace,new_str;
        /// 1412 1 CSE__4103 x x MATH_4141 CSE__4105 LUNCH_BREAK CSE__4104 CSE__4104 x x
        while(routine>>id>>wday>>slots[0]>>slots[1]>>slots[2]>>slots[3]>>slots[4]>>slots[5]>>slots[6]>>slots[7]>>slots[8]>>slots[9])
        {
            if(ID==id && c_day == wday)
            {
                for(int j=1; j<=10; j++)
                {

                    if(curr_time>=routine_slot[j-1] && curr_time<=routine_slot[j])
                    {
                        cout<<"Ongoing Class : "<<slots[j-1]<<endl;
                        cout<<"Remaining Classes : "<<endl;
                        for(int i=j; i<=9; i++)
                        {
                            if(slots[i]=="x")
                            {
                                cout<<"No Class"<<endl;
                            }
                            else
                            {
                                cout<<slots[i]<<endl;
                            }
                        }
                        flag = 2;
                    }
                }

            }
            flag = 1;
        }
        if(flag==0) cout<<endl<<"Holiday !!  No classes Today ."<<endl;
        if(flag==1) cout<<endl<<"No more classes today ."<<endl;
    }

    next();
}

double fin_quiz(vector<double>quiz)
{
    sort(quiz.begin(),quiz.end());
    double x=0;
    for(int i=quiz.size()-1,j=0; i>=0,j<3; i--,j++)
    {
        x+=quiz[i];
    }
    x=x/(double)min((int)quiz.size(),3);
    return x;
}

double fin_tot_marks(double quiz,double mid,double fin,double att,double cred)
{
    double ret=0;
    ret+=quiz;
    ret+=mid/cred;
    ret+=fin/cred;
    ret+=att;
    return ret;
}

string calc_grade(double gp)
{

    if(gp<40)
    {
        return "F";
    }
    else if(gp<50)
    {
        return "C";
    }
    else if(gp<60)
    {
        return "B";
    }
    else if(gp<70)
    {
        return "A-";
    }
    else if(gp<80)
    {
        return "A";
    }
    else
    {
        return "A+";
    }
}

void get_marks(string id,char cour_name)
{
    string st_id,name,course_id,course_credit,course_name;
    double att,q1,q2,q3,q4,mid,fin,marks,cred;
    ifstream course_file("student_id.txt");
    if(!course_file)
    {
        cout<<"Course File not Found"<<endl;
    }
    else
    {
        cout<<"ID "<<access_ID<<endl;
        dis(3,10);

        cout<<"Result of Semester "<<cour_name<<" "<<endl;
        dis(1,40);
        /// student_id student_name course_id course_name att q1 q2 q3 q4 mid fin course_credit
        cout<<"Course ID    Attendance (10%)    Quiz (10%)     Mid Term (25%)      Semester Final (50%)    Total Marks (100%)     Grade "<<endl;
        cout<<"*********    ****************    **********     **************      ********************    ******************     ******"<<endl;
        while(course_file>>st_id>>course_id>>course_name>>cred>>att>>q1>>q2>>q3>>q4>>mid>>fin)
        {
            if(id==st_id && course_id[6]==cour_name)
            {
                ///access variables-
                vector<double>quiz;
                quiz.push_back(q1);
                quiz.push_back(q2);
                quiz.push_back(q3);
                quiz.push_back(q4);

                double qquiz = fin_quiz(quiz);
                double marks=fin_tot_marks(qquiz,mid,fin,att,cred);

                /// couse_code attendance quiz_avg mid final grade
                cout<<setw(9)<<course_id<<setw(13)<<att<<setw(19)<<setprecision(4)<<qquiz<<setw(17)<<setprecision(4)<<mid<<setw(23)<<setprecision(4)<<fin<<setw(24)<<setprecision(4)<<marks<<setw(14)<<calc_grade(marks)<<endl;
                //cout<<course_id<<"  "<<att<<" "<<qquiz<<" "<<mid<<" "<<fin<<" "<<marks<<" "<<calc_grade(marks)<<endl;
                ///i++;
            }

        }
    }
}

void Student::find_course()
{
    char sem;
    string xd = "Theory";
    cout<<"Which Semester are you in ?"<<endl<<endl;
    cout<<"Semester : ";
    cin>>sem;

    next();

    cout<<"Courses of semester "<<sem<<endl;
    cout<<"************************"<<endl<<endl<<endl;

    cout<<"Course ID   Course Name                                Type          Course Credit  "<<endl;
    cout<<"*********   *************************                ********        **********     "<<endl;
    for(int i=0; i<41; i++)
    {
        if(course_id[i][6]==sem)
        {
            if(stoi(course_id[i].substr(8,1))%2 == 0) xd = "Lab";

            cout<<left<<setw(12)<<course_id[i]<<setw(42)<<course_fullname[i]<<setw(20)<<xd<<setw(5)<<course_credits[i]<<endl;
        }
    }
    next();
}


void Student::showgrade(string id)
{
    next();
    cout<<"Show Result of __________"<<endl;
    cout<<"1. 1st Semester\n2. 2nd Semester\n3. 3rd Semester\n4. 4th Semester\n5.Overall"<<endl;
    cout<<"Enter your choice : ";
    int x;
    cin>>x;

    next();
    cout<<endl;

    /// format course_code course_name Quiz_1 Quiz_2 Quiz_3 Quiz_4 Mid_Marks Final_Marks Quiz_Avg Attendance Total Grade

    if(x==1)
    {
        get_marks(id,'1');
    }
    else if(x==2)
    {
        get_marks(id,'2');
    }
    else if(x==3)
    {
        get_marks(id,'3');
    }
    else if(x==4)
    {
        get_marks(id,'5');
    }
    else if(x==5)
    {
        get_marks(id,'1');
        get_marks(id,'2');
        get_marks(id,'3');
        get_marks(id,'4');
    }
    next();
}
