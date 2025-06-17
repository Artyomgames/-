#include "Work.h"

int Work(string filename)
{
    int choice = 0;
    cout << "Выберите операцию:" << endl
        << "1. Просмотр таблицы" << endl
        << "2. Добавить студента" << endl
        << "3. Удалить студента" << endl
        << "4. Поиск студента" << endl
        << "5. Экспорт данных" << endl
        << "6. Импорт данных" << endl
        << "7. Выход" << endl
        << "Внимание, работайте с английским языком!!!" << endl;
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
    }
    else if (choice == 2) {
        while (choice == 2) {
            cout << "1. Выйти" << endl << "2. Добавить";
            cin >> choice;
            if (choice == 2) {
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
            }
            else {
                return 0;
            }
        }
    }
    else if (choice == 3) {
        ifstream file(filename, ios::app);
        if (file.is_open()) {
            cout << "Введите номер строки для удаления: " << endl;
            int i_number_line_delete = 0;
            cin >> i_number_line_delete;
            int i_number_line_now = 0;
            string line;
            string line_file_text;
            while (getline(file, line)) {
                i_number_line_now++;
                if (i_number_line_now != i_number_line_delete) {
                    line_file_text.insert(line_file_text.size(), line);
                }
                file.close();
                ofstream file_out;
                file_out.open(filename, ios::trunc | ios::binary);
                file_out.write(line_file_text.c_str(), line_file_text.size());
                file_out.clear();
            }
            file.close();
        }
    }
    return 0;
}
