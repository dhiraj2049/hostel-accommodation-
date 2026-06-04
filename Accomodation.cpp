#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Hostel {
private:
    string Name;
    int Rent;
    int Bed;
public:
    Hostel(string name, int rent, int bed) {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    string getName() { return Name; }
    int getRent() { return Rent; }
    int getBed() { return Bed; }

    void reserve(string host) {
        ifstream in("Hostels.txt");
        ofstream out("Hostel_temp.txt");

        string line;
        while (getline(in, line)) { 
            int position = line.find(host); 
            if (position != string::npos) { 
                Bed--; 

                stringstream ss; 
                ss << Bed;
                string strBed = ss.str(); 

                int bedPos = line.find_last_of(':'); 
                line.replace(bedPos + 1, string::npos, strBed); 
            }
            out << line << endl;
        }

        out.close();
        in.close();

        remove("Hostels.txt");
        rename("Hostel_temp.txt", "Hostels.txt");
        cout << "\tBed Reserved Successfully!" << endl;
        Sleep(3000);
    }
};

class Student {
private:
    string Name;
    string RollNo;
    string Address;
public:
    Student() : Name(""), RollNo(""), Address("") {} 

    void setName(string name) { Name = name; }
    void setRollNo(string rollno) { RollNo = rollno; }
    void setAddress(string address) { Address = address; }

    string getName() { return Name; }
    string getRollNo() { return RollNo; }
    string getAddress() { return Address; }
};
    void reserveBed(Hostel &h, string hostelName, Student &s) {
    system("cls");
    string name, rollno, address;

    cout << "\tEnter name of Student: ";
    cin >> name;
    s.setName(name);

    cout << "\tEnter RollNo of " << name << ": ";
    cin >> rollno;
    s.setRollNo(rollno);

    cout << "\tEnter Address of " << name << ": ";
    cin >> address;
    s.setAddress(address);

    h.reserve(hostelName); // reserve bed in file

    ofstream outFile("Student.txt", ios::app); // append to student file
    outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
    outFile.close();
}

int main() {
    Hostel Dhansiri("Dhansiri", 5000, 3);
    Hostel Disang("Disang", 5000, 4);
    Hostel Lohit("Lohit", 5000, 3);
    Hostel Kapili("Kapili", 5000, 2);

    ofstream out("Hostels.txt");
    out << "\t" << Dhansiri.getName() << " : " << Dhansiri.getRent() << " : " << Dhansiri.getBed() << endl << endl;
    out << "\t" << Disang.getName() << " : " << Disang.getRent() << " : " << Disang.getBed() << endl << endl;
    out << "\t" << Lohit.getName() << " : " << Lohit.getRent() << " : " << Lohit.getBed() << endl << endl;
    out << "\t" << Kapili.getName() << " : " << Kapili.getRent() << " : " << Kapili.getBed() << endl << endl;
    cout << "Hostel Data Saved!" << endl;
    out.close();

    Student s;
    bool exit = false;

    while (!exit) {
        system("cls"); 
        int val;
        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed" << endl;
        cout << "\t2. Exit" << endl;
        cout << "\tEnter your choice:";
        cin >> val;

        if (val == 2) {
            system("cls");
            cout << "\tThank You!" << endl;
            exit = true;
            Sleep(3000);
            break;
        }

        cout << "\tWhich Hostel Do you want to Choose?" << endl;
        cout << "\t1.Dhansiri (" << Dhansiri.getBed() << " rooms available)" << endl;
        cout << "\t2.Disang   (" << Disang.getBed() << " rooms available)" << endl;
        cout << "\t3.Lohit    (" << Lohit.getBed() << " rooms available)" << endl;
        cout << "\t4.Kapili   (" << Kapili.getBed() << " rooms available)" << endl;

        int opt;
        cin >> opt;
        switch (opt) {
    case 1:
        system("cls");
        cout<<"DHANSIRI RESERVATION!"<<endl;
        if (Dhansiri.getBed() > 0) {
            reserveBed(Dhansiri, "Dhansiri", s);
        } else {
            cout << "\tSorry, No Bed Available!" << endl;
            Sleep(5000);
        }
        break;

    case 2:
        system("cls");
        cout<<"DISANG RESERVATION!"<<endl;
        if (Disang.getBed() > 0) {
            reserveBed(Disang, "Disang", s);
        } else {
            cout << "\tSorry, No Bed Available!" << endl;
            Sleep(5000);
        }
        break;

    case 3:
        system("cls");
        cout<<"LOHIT RESERVATION!"<<endl;
        if (Lohit.getBed() > 0) {
            reserveBed(Lohit, "Lohit", s);
        } else {
            cout << "\tSorry, No Bed Available!" << endl;
            Sleep(5000);
        }
        break;

    case 4:
        system("cls");
        cout<<"KAPILI RESERVATION!"<<endl;
        if (Kapili.getBed() > 0) {
            reserveBed(Kapili, "Kapili", s);
        } else {
            cout << "\tSorry, No Bed Available!" << endl;
            Sleep(5000);
        }
        break;

    default:
        cout << "\tThank You!" << endl;
        Sleep(3000);
        exit = true;
        }
    }
    return 0;
}
