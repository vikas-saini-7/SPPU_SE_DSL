/*
Problem Statement:12

Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular students. If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details.

*/

// 1. Class definition
// 	Define data members : roll no, name, div, address
// 	Member function definition: createdata(), display(), delete()
// 2. File handling operations
// 	File object: ifstream obj for read(), ofstream obj write()

// 3. main()
// 	Create the menu: 1. add, 2. delete info of student...
// 	take choice of user
// 	based on choice run switch case
// 		case 1: createdata()
// 		case 2: delete()
// 		case 3: display()

#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class Studnet
{
public:
    int rollno;
    char name[50];
    char addr[50];

    void setData()
    {
        cout << "\nEnter Roll NO : . ";
        cin >> rollno;
        cout << "Enter name ";
        cin >> name;
        cout << "enter the address of the student";
        cin >> addr;
    }

    void showData()
    {
        cout << "\n*Student Roll No  : " << rollno;
        cout << "\n*Student Name : " << name;
        cout << "\n*Address: " << addr;
    }

    int retrollno()
    {
        return rollno;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("Studnet.dat", ios::binary | ios::app);

    Studnet obj;
    obj.setData();

    outFile.write((char *)&obj, sizeof(obj)); // obj is sender

    outFile.close();
}

void display() // display of complete file
{
    ifstream inFile;
    inFile.open("Studnet.dat", ios::binary);

    Studnet obj;

    while (inFile.read((char *)&obj, sizeof(obj))) // obj is receiver
    {
        obj.showData();
    }

    inFile.close();
}

int search(int n) // with respect to roll no
{
    ifstream inFile;
    bool flag = false;
    inFile.open("Studnet.dat", ios::binary);

    Studnet obj;

    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.rollno == n)
        {
            flag = true;
            obj.showData();
            return 1;
            break;
        }
    }
    if (flag == false)
    {
        cout << " Record for roll no." << n << " not found in file";
        return 0;
    }

    inFile.close();
}

void delete_record(int n)
{
    Studnet obj;
    //  bool flag= true;
    ifstream inFile;
    inFile.open("Studnet.dat", ios::binary); // original/ before

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary); // new/after

    int a = search(n);
    if (a == 1)
    {

        while (inFile.read((char *)&obj, sizeof(obj)))
        {
            if (obj.retrollno() != n)
            {
                //	 flag= false;
                outFile.write((char *)&obj, sizeof(obj));
            }
        }
        inFile.close();
        outFile.close();
        remove("Studnet.dat"); // to delete student file
        rename("temp.dat", "Studnet.dat");
    }
    else
    {
        cout << "' This roll no data is not present in the file so cant apply delete operation";
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n\n\n***********File operations*************** \n1. Add record \n2. Display records \n3.  Search a particular record \n4. Delete a particular record  ";

        cout << "\nEnter your choice";
        cin >> ch;
        switch (ch)
        {

        case 1:
            cout << "Enter number of records: ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                write_record();
            break;

        case 2:

            cout << "\nList of records";
            display();
            break;

        case 3:
            cout << "Enter Student Roll No : ";
            int s;
            cin >> s;
            search(s);
            break;
        case 4:
            cout << "enter no to be deleted";
            int d;
            cin >> d;

            delete_record(d);
            cout << "\nRecord Deleted";
            break;

        case 5:

            return 0;
        }

    } while (ch != 6);
}
