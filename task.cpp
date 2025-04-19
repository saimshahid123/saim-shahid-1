#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int stringToInt(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}



void addstudents() {
	int number;
	cout << "how manu student you want to enter ::::";
	cin >> number;
	for (int i = 0;i < number;i++) {
		int rollnumber;
		float gpa;
		char name[30], departement[30];
		cin.ignore();
		cout << "enter your name:::";
		cin.getline(name, 30);
		cout << endl;
		cin.ignore();

		cout << "enter your roll number:::";
		cin >> rollnumber;
		cout << endl;
		cin.ignore();
		cout << "enter your department:::";
		cin.getline(departement, 30);
		cout << endl;
		cin.ignore();
		cout << ":enter your gpa::::";
		cin >> gpa;
		cout << endl;

		ofstream writefile("student.txt",ios::app);
		writefile << "name is:::" << name << endl;
		writefile << "roll number is:::" << rollnumber << endl;
		writefile << "deoartment is:::" << departement << endl;
		writefile << "gpa is:::" << gpa << endl;
		writefile.close();
        cout << "Student's added successfully.\n";
	}
}

void viewStudents() {
    ifstream read("students.txt");
    string name, roll, dept, gpa;

    cout << "\nName\t\tRoll No\tDepartment\tGPA\n";
    cout << "---------------------------------------------\n";

    while (getline(read, name, ',') &&
        getline(read, roll, ',') &&
        getline(read, dept, ',') &&
        getline(read, gpa)) {
        cout << name << ":::" << roll << ":::" << dept << ":::" << gpa << endl;
    }

   read.close();
}


void searchStudent() {
    int searchRoll;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    ifstream search("students.txt");
    string name, rollStr, dept, gpa;
    bool found = false;

    while (getline(search, name, ',') &&
        getline(search, rollStr, ',') &&
        getline(search, dept, ',') &&
        getline(search, gpa)) {
        int roll = stringToInt(rollStr);
        if (roll == searchRoll) {
            cout << endl;
            cout << "Student Found:" << endl;
            cout << "Name: " << name << "\nRoll No: " << rollStr
                << "\nDepartment: " << dept << "\nGPA: " << gpa << endl;
            found = true;
        }
    }

    search.close();
    if (!found)
        cout << "Student not found. try again::" << endl;
}



void updateGPA() {
    int searchRoll;
    float newGPA;
    cout << "Enter roll number to update GPA: ";
    cin >> searchRoll;
    cout << "Enter new GPA: ";
    cin >> newGPA;

    ifstream update("students.txt");
    string name, rollStr, dept, gpa;
    string updatedData = "";
    bool updated = false;

    while (getline(update, name, ',') &&
        getline(update, rollStr, ',') &&
        getline(update, dept, ',') &&
        getline(update, gpa)) {
        int roll = stringToInt(rollStr);
        if (roll == searchRoll) {
            // to string function use to convsrt float into string to add in string declare in <string>
            updatedData = updatedData + name + "," + rollStr + "," + dept + "," + to_string(newGPA);
            updated = true;
            cout << endl;
        }
        else {
            updatedData += name + "," + rollStr + "," + dept + "," + gpa;
            cout << endl;
        }
    }

    update.close();

    ofstream writeinstudentfile("students.txt");
    writeinstudentfile << updatedData;
    writeinstudentfile.close();

    if (updated) {
        cout << "GPA updated successfully.";
    }
    else {
        cout << "Student not found."<<endl;
    }
}

void deleteStudent() {
    int searchRoll;
    cout << "Enter roll number to delete: ";
    cin >> searchRoll;

    ifstream deletestore("students.txt");
    string name, rollStr, dept, gpa;
    string finalData = "";
    bool deleted = false;

    while (getline(deletestore, name, ',') &&
        getline(deletestore, rollStr, ',') &&
        getline(deletestore, dept, ',') &&
        getline(deletestore, gpa)) {
        int roll = stringToInt(rollStr);
        if (roll != searchRoll) {
            finalData += name + "," + rollStr + "," + dept + "," + gpa ;
            cout << endl;
        }
        else {
            deleted = true;
        }
    }

    deletestore.close();

    ofstream updatestudentfile("students.txt"); 
    updatestudentfile<< finalData;
    updatestudentfile.close();

    if (deleted)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.try again::";
    cout<<endl;
}


int main() {
    int choice;
    do {

        cout << "===== Student Management System =====" << endl;
        cout << "1. Add Student Record" << endl;;
        cout << "2. View All Students" << endl;;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Update Student GPA" << endl;;
        cout << "5. Delete Student Record" << endl;
        cout << "6. Exit" << endl;;
        cout << "Choose an option: " << endl;;
        cin >> choice;

        switch (choice) {
        case 1: addstudents(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateGPA(); break;
        case 5: deleteStudent(); break;
        case 6: cout << "Exiting..."; break;
            cout << endl;
        default: cout << "Invalid option. Try again.";
            cout << endl;
        }

    } while (choice != 6);

    return 0;
}

