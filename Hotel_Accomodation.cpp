#include <bits/stdc++.h>
#include <fstream>    // For ifstream and ofstream
#include <sstream>    // For stringstream
#include <windows.h>

using namespace std;

class Hostel_Accomodation
{
private:
    string Name;
    int Rent, Bed;

public:
    Hostel_Accomodation(string name, int rent, int bed)
    {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    // creating member function
    string getName()
    {
        return Name;
    }

    int getRent()
    {
        return Rent;
    }

    int getBed()
    {
        return Bed;
    }

    void reserve(){
        ifstream in("D:/hostel managment/Hostel.txt");
        ofstream out("D:/hostel managment/Hostel_temp.txt");

        string line;

        while (getline(in, line))
        {
            int pos = line.find("3star");

            if(pos != string::npos){
                int bed = Bed-1;
                Bed = bed;

                stringstream ss;
                ss<<bed;

                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos+1, string::npos, strBed);
            }

            out<<line<<endl;
        }

        out.close();
        in.close();

        remove("D:/hostel managment/Hostel.txt");
        rename("D:/hostel managment/Hostel_temp.txt", "D:/hostel managment/Hostel.txt");
        cout<<"\tBed Reserved Successfully";

    }
};

class Student
{
private:
    string Name, RollNo, Address;

public:
    Student() : Name(""), RollNo(""), Address("") {}

    void setName(string name)
    {
        Name = name;
    };

    void setRollNo(string roll)
    {
        RollNo = roll;
    };
    void setAddress(string address)
    {
        Address = address;
    };

    string getName()
    {
        return Name;
    }

    string getRollNo()
    {
        return RollNo;
    }

    string getAddress()
    {
        return Address;
    }
};

int main()
{

    Hostel_Accomodation h("3star", 5000, 2);

    ofstream out("D:/hostel managment/Hostel.txt");
    cout << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl
         << endl;
    cout << "Hostel data saved" << endl;
    out.close();

    Student s;

    bool shouldExit = false;

    while (!shouldExit)
    {
        system("cls");
        int val;

        cout << "\tWelcome to hostel accommodation system" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1> Reserve a bed" << endl;
        cout << "\t2> Exit" << endl;
        cout << "\tChoose one of the two options : ";
        cin >> val;

        if (val == 1)
        {
            system("cls");
            string name, rollNo, address;
            cout << "\tEnter your name : ";
            cin >> name;
            s.setName(name);

            cout << "\tEnter your roll number : ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter your address : ";
            cin >> address;
            s.setAddress(address);

            if(h.getBed() > 0){
                h.reserve();
            }
            else if(h.getBed() == 0){
                cout<<"\tSorry no bed available"<<endl;
            }

            ofstream out("D:/hostel managment/Student.txt", ios::app);
            out<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
            Sleep(5000);
        }

        else if(val == 2){
            system("cls");
            shouldExit = true;
            cout<<"Good Luck!";
            Sleep(3000);
        }
    }

    return 0;
}
