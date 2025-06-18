#include "Work.h"

int Work(string filename)
{
    int choice = 0;
cout << "Выберите функцию:" << endl
    << "1. Просмотр списка студентов" << endl
    << "2. Добавить студента" << endl
    << "3. Удалить студента   " << endl
    << "4. Поиск студента " << endl
    << "5. Экспорт данных " << endl
    << "6. Импорт данных " << endl
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
        cout << "1. Выход" << endl << "2. Добавить" << endl;
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
        ofstream outfile("temp.txt");

        if (!outfile.is_open()) {
            cerr << "Ошибка создания временного файла!" << endl;
            file.close();
            return 1;
        }

        string line;
        int current_line = 1;

        while (getline(file, line)) {
            if (current_line != i_number_line_delete) {
                outfile << line << endl;
            }
            current_line++;
        }

        file.close();
        outfile.close();
        if (remove(filename.c_str()) != 0) {
            cerr << "Ошибка удаления исходного файла!" << endl;
            return 1;
        }

        if (rename("temp.txt", filename.c_str()) != 0) {
            cerr << "Ошибка переименования временного файла!" << endl;
            return 1;
        }

        cout << "Строка успешно удалена." << endl;

        return 0;
    }
}

else if (choice == 4) {
    ifstream file("file.txt");
    if (file.is_open()) {
        string word, vvod;
        int line = 0;
        cout << "Введите студента, которого хотите найти: ";
        cin >> vvod;
        while (file >> word) {
            if (word == vvod) {
                cout << "Result: " << word << endl << "String: " << line;
                break;
            }
            else {
                continue;
            }
        }
    }
    return 0;
}
else if (choice == 5) {
    string outputFilename = "output.txt";
    ifstream file(filename);
    ofstream outputFile(outputFilename);
    if (file.is_open()) {


        string line;

        while (getline(file, line)) {

            for (auto& c : line) {
                c = toupper(c);
            }

            outputFile << line << endl;
        }


        file.close();
        outputFile.close();

        cout << "Экспорт завершен. Данные записаны в " << outputFilename << endl;
        return 0;
    }

}
else if (choice == 6) {
    ifstream file(filename);
    if (file.is_open()) {
        string data;
        while (getline(file, data)) { 
            cout << "Прочитанная строка: " << data << endl;
        }
        file.close();
        return 0;
    }
}
else if (choice == 7) {
    return 0;
}
    }
