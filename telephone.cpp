#include <iostream>
#include <string>
using namespace std;

class Telephone {
private:
    int* mobno;
    string* name;
    int size;

public:
    Telephone() {
        cout << "Enter table size: ";
        cin >> size;

        mobno = new int[size];
        name = new string[size];

        for (int i = 0; i < size; i++) {
            mobno[i] = -1;
        }
    }

    ~Telephone() {
        delete[] mobno;
        delete[] name;
    }

    void insertRecord_LP() {
        cout << "Enter no of records: ";
        int x;
        cin >> x;

        for (int i = 0; i < x; i++) {
            cout << "Enter Telephone no: ";
            long int key;
            cin >> key;
            int hash_address = key % size;
            if (mobno[hash_address] == -1) {
                mobno[hash_address] = key;
                cout << "Enter name: ";
                cin >> name[hash_address];
            } else {
                int j = 1;
                while (mobno[(hash_address + j) % size] != -1 && j < size) {
                    j++;
                }
                if (j == size) {
                    cout << "Table is full, cannot insert more records." << endl;
                    break;
                }
                mobno[(hash_address + j) % size] = key;
                cout << "Enter name: ";
                cin >> name[(hash_address + j) % size];
            }
        }
    }

    void insertRecord_QP() {
        cout << "Enter no of records: ";
        int x;
        cin >> x;

        for (int i = 0; i < x; i++) {
            cout << "Enter Telephone no: ";
            long int key;
            cin >> key;
            int hash_address = key % size;
            if (mobno[hash_address] == -1) {
                mobno[hash_address] = key;
                cout << "Enter name: ";
                cin >> name[hash_address];
            } else {
                int j = 1;
                while (mobno[(hash_address + j * j) % size] != -1 && j < size) {
                    j++;
                }
                if (j == size) {
                    cout << "Table is full, cannot insert more records." << endl;
                    break;
                }
                mobno[(hash_address + j * j) % size] = key;
                cout << "Enter name: ";
                cin >> name[(hash_address + j * j) % size];
            }
        }
    }

    void display() {
        for (int address = 0; address < size; address++) {
            cout << address << " " << mobno[address] << " " << name[address] << endl;
        }
    }
};

int main() {
    Telephone t1;
    int ch;
    do {
        cout << "\n1.Insert Record(Linear Probing)";
        cout << "\n2.Insert Record(Quadratic Probing)";
        cout << "\n3.Display";
        cout << "\n4.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                t1.insertRecord_LP();
                break;
            case 2:
                t1.insertRecord_QP();
                break;
            case 3:
                t1.display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Wrong choice" << endl;
        }
    } while (ch != 4);
    return 0;
}