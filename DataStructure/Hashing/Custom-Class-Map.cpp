#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string fname;
    string lname;
    string roll;

    Student(string f, string l, string no)
    {
        fname = f;
        lname = l;
        roll = no;
    }

    bool operator==(const Student &s) const
    {
        return roll == s.roll ? true : false;
    }
};

class Hashfn
{
public:
    size_t operator()(const Student &s) const
    {
        return s.fname.length() + s.lname.length();
    }
};

int main()
{
    unordered_map<Student, int, Hashfn> student_map;

    Student s1("Abhishek", "Kumar", "043");
    Student s2("Abhishek", "Kumar", "001");
    Student s3("Akash", "Kotnala", "030");

    student_map[s1] = 100;
    student_map[s2] = 98;
    student_map[s3] = 70;

    for (auto x : student_map)
        cout << x.first.fname << " " << x.first.roll << " -> " << x.second << endl;
}
