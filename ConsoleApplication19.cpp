#include <iostream>
#include <fstream>
using namespace std;
const int MAX_LENGTH_NAME = 50;
const int MAX_LENGTH_GROUP = 10;
const int MAX_GRADES = 10;


struct Student {
    int id;
    char name[MAX_LENGTH_NAME];
    char group[MAX_LENGTH_GROUP];
    int year;
    int grades[MAX_GRADES];
};


void initStudent(Student & student) {
    student.id = 0;
    student.name[0] = '\0';
    student.group[0] = '\0';
    student.year = 0;
}


void printStudent(const Student & student) {
    cout << "ID: " << student.id << endl;
    cout << "FCs: " << student.name << endl;
    cout << "Group: " << student.group << endl;
    cout << "Year of admission: " << student.year << endl;
    cout << "Evaluations: ";
    for (int i = 0; i < student.numGrades; ++i) {
        cout << student.grades[i] << " ";
    }
    cout << endl;
}


const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int numStudents = 0;


int stringLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


void stringCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


int stringCompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


int main() {
    setlocale(LC_ALL, "ru");
    ofstream file ("journal.txt");
    if (file.is_open()) {
        string l, p;
        cout << "Логин: ";
        file << "Логин: ";
        cin >> l;
        file << l << endl;
        cout << "Пароль: ";
        file << "Пароль: ";
        cin >> p;
        file << p << endl;
        file.close();
    }
}
