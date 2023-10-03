//
//  main.cpp
//  03.10.23 Пара Наследование
//
//  Created by Michalis on 03.10.2023.
//

#include <iostream>
#include <string.h>
using namespace std;
class Person
{
protected:
    char* name;
    int age;
public:
    Person()=default;
    Person(const char* n,  int a):age(a)
    {
        name=new char[strlen(n)+1];
        strcpy(name, n);
    }
    void Print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    void Input()
    {
        char buff[50];
        cout<<"Input name: ";

        cin>>buff;
        name=new char[strlen(buff)+1];
        strcpy(name, buff);
        cout<<endl;
        cout<<"Input age: ";
        cin>>age;
    }
    ~Person()
    {
        delete[]name;
        cout<<"Person destructor!"<<endl;
    }
};

class Student: public Person
{
    char* university;
public:
   Student(const char* n,  int a, const char* un):Person(n,a)
    {
        university=new char[strlen(un)+1];
        strcpy(university, un);
    }
    ~Student()
    {
        delete[]university;
        cout<<"Student destructor!"<<endl;
    }
    void Print()
    {
//        cout<<"Name: "<<name<<endl;
//        cout<<"Age: "<<age<<endl;
        Person::Print();//вызов принта родительского класса
        cout<<"University: "<<university<<endl;
    }
    void Input(const char* un)
    {
        if (university!=nullptr)
        {
            delete[]university;
    }
        university=new char[strlen(un)+1];
        strcpy(university, un);
        Person::Input();
    }
    };
class Teacher: public Person
{
    char* school;
    char** subjects;
    int salary;
    int size;
public:
    Teacher(const char* n,  int a, const char* schl, int sal, int s, char** sub):Person(n,a)
    {
        school=new char[strlen(schl)+1];
        strcpy(school, schl);
        salary=sal;
        size=s;
        subjects = new char* [size];

        for (int i = 0; i < size; i++) 
        {
            subjects[i] = new char[strlen(sub[i]) + 1];
                strcpy(subjects[i], sub[i]);
            }
    }
    ~Teacher()
    {
        delete[]school;
        delete[]subjects;

        cout<<"Student destructor!"<<endl;
    }
    void Print()
    {
//        cout<<"Name: "<<name<<endl;
//        cout<<"Age: "<<age<<endl;
        Person::Print();//вызов принта родительского класса
        cout<<"School: "<<school<<endl;
        cout<<"Salary: "<<salary<<endl;
        for (int i=0;i<size;i++)
        {
            cout<<subjects[i]<<endl;
        }
    }
    void Input(const char* schl, int sal, int s)
    {
        if (school!=nullptr)
        {
            delete[]school;
        }
        school=new char[strlen(schl)+1];
        strcpy(school, schl);
        salary=sal;
        size=s;
        Person::Input();
//        for (int i = 0; i < size; i++)
//        {
//            if (subjects[i] != nullptr)
//                delete[] subjects[i];
//        }
        char temp[200];
        subjects=new char*[size];
        
        for (int i = 0; i < size; i++)
        {
            cout << "Введите предмет: ";
            cin >> temp;
            
            subjects[i] = new char[strlen(temp) + 1];
            strcpy(subjects[i], temp);
        }
    }
    };
class Driver: public Person
{
    char* autoNumber;
    char* driverLicense;
public:
    Driver(const char* n,  int a, const char* autoN, const char* driverL):Person(n,a)
    {
        autoNumber=new char[strlen(autoN)+1];
        strcpy(autoNumber, autoN);
        driverLicense=new char[strlen(driverL)+1];
        strcpy(driverLicense, driverL);
    }
    ~Driver()
    {
        delete[]autoNumber;
        delete[]driverLicense;

        cout<<"Student destructor!"<<endl;
    }
    void Print()
    {
//        cout<<"Name: "<<name<<endl;
//        cout<<"Age: "<<age<<endl;
        Person::Print();//вызов принта родительского класса
        cout<<"Auto Number: "<<autoNumber<<endl;
        cout<<"Driver License: "<<driverLicense<<endl;

    }
    void Input(const char* autoN , const char* driverL)
    {
        if (autoNumber!=nullptr)
        {
            delete[]autoNumber;
    }
        if (driverLicense!=nullptr)
        {
            delete[]driverLicense;
    }
        autoNumber=new char[strlen(autoN)+1];
        strcpy(autoNumber, autoN);
        driverLicense=new char[strlen(driverL)+1];
        strcpy(driverLicense, driverL);
        Person::Input();
    }
    };
class Doctor: public Person
{
    char* speciality;
    int experience;
    bool isFamily;
public:
    Doctor(const char* n,  int a, const char* sp, int exp, int fam):Person(n,a)
    {
        speciality=new char[strlen(sp)+1];
        strcpy(speciality, sp);
        experience=exp;
        int family=fam;
        if (family==1)
        {
            isFamily=true;
        }
        else if (family==2)
        {
            isFamily=false;
        }
        else
        {
            cout<<"You can input only 1(family) or 2(unfamily)!"<<endl;
        }
    }
    ~Doctor()
    {
        delete[]speciality;
        cout<<"Student destructor!"<<endl;
    }
    void Print()
    {
//        cout<<"Name: "<<name<<endl;
//        cout<<"Age: "<<age<<endl;
        Person::Print();//вызов принта родительского класса
        cout<<"Speciality: "<<speciality<<endl;
        cout<<"Experience: "<<experience<<endl;
if (isFamily)
{
    cout<<"It's family doctor!"<<endl;
}
        else
        {
            cout<<"It's not family doctor!"<<endl;
        }
    }
    void Input(const char* sp, int exp, int fam)
    {
        if (speciality!=nullptr)
        {
            delete[]speciality;
    }
        speciality=new char[strlen(sp)+1];
        strcpy(speciality, sp);
        experience=exp;
        int family=fam;
        if (family==1)
        {
            isFamily=true;
        }
        else if (family==2)
        {
            isFamily=false;
        }
        else
        {
            cout<<"You can input only 1(family) or 2(unfamily)!"<<endl;
        }
        Person::Input();
    }
    };
int main() {
    int size;
        char** subjects;
        char temp[50];

        cout << "Введите кол-во предметов: ";
        cin >> size;

    subjects = new char* [size];

        for (int i = 0; i < size; i++) 
        {
            cout << "Введите предмет: ";
            cin >> temp;

            subjects[i] = new char[strlen(temp) + 1];
            strcpy(subjects[i], temp);
        }    
    Student obj("Irina", 18, "IT STEP");
    obj.Print();
    Teacher t_obj("Irina", 123, "OOSH#18", 15000, size, subjects);
    t_obj.Input("OOSH#23", 23000, 1);
    t_obj.Print();
    Driver d_obj("Irina", 123, "BH0786BH", "FY334J7");
    d_obj.Print();
    Doctor doc_obj("Irina", 123, "Terapevt", 32, 1);
    doc_obj.Print();
    

    return 0;
}
