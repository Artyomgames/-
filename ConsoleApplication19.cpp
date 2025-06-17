#include <iostream>
#include <fstream>
#include <string>
#include "Work.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    string login, password, filename;
    cout << "Логин: ";
    cin >> login;
    cout << endl << "Пароль: ";
    cin >> password;
    filename = login + password + ".txt";
    cout << "Добро пожаловать в систему. " << filename << endl;

    Work(filename);

    return 0;
}