#include <iostream>
#include <fstream>
#include <string>
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


void initStudent(Student& student) {
    student.id = 0;
    student.name[0] = '\0';
    student.group[0] = '\0';
    student.year = 0;
    for (int i = 0; i < MAX_GRADES; ++i) {
        student.grades[i] = 0;
    }
}


void printStudent(const Student& student) {
    cout << "ID: " << student.id << endl;
    cout << "FCs: " << student.name << endl;
    cout << "Group: " << student.group << endl;
    cout << "Year of admission: " << student.year << endl;
    cout << "Evaluations: " << endl;                          
}


int main() {
    setlocale(LC_ALL, "ru");

    
    string login, password, filename;
    cout << "Логин: ";
    cin >> login;
    cout << endl << "Пароль: ";
    cin >> password;
    filename = login + password + ".txt";
    cout << "Добро пожаловать в систему. " << filename << endl;

    
    int choice = 0;
    cout << "Выберите операцию:" << endl
        << "1. Просмотр таблицы" << endl
        << "2. Добавить студента" << endl
        << "3. Удалить студента" << endl
        << "4. Поиск студента" << endl
        << "5. Экспорт данных" << endl
        << "6. Импорт данных" << endl
        << "7. Выход" << endl
        << "Внимание, работайте с английским языком";
    cin >> choice;

    
    if (choice == 1) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cout << "Не удалось открыть файл." << endl;
        }
    }
    else if (choice == 2) { 
        ofstream file(filename, ios::app); 
        if (file.is_open()) {
            string studentData;
            cout << "Введите данные студента: ";
            cin.ignore();                      
            getline(cin, studentData);        
            file << studentData << endl;       
            file.close();                      
            cout << "Студент добавлен." << endl;
        }
        else {
            cout << "Не удалось открыть файл для записи." << endl;
        }
    }
    else {
        cout << "Функционал в разработке." << endl;
    }

    return 0;
}
