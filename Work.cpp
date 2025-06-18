#include "Work.h"

int Work(string filename)
{
    int choice = 0;
    cout << "Âûáåðèòå îïåðàöèþ:" << endl
        << "1. Ïðîñìîòð òàáëèöû" << endl
        << "2. Äîáàâèòü ñòóäåíòà" << endl
        << "3. Óäàëèòü ñòóäåíòà" << endl
        << "4. Ïîèñê ñòóäåíòà" << endl
        << "5. Ýêñïîðò äàííûõ" << endl
        << "6. Èìïîðò äàííûõ" << endl
        << "7. Âûõîä" << endl
        << "Âíèìàíèå, ðàáîòàéòå ñ àíãëèéñêèì ÿçûêîì!!!" << endl;
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
            cout << "1. Âûéòè" << endl << "2. Äîáàâèòü";
            cin >> choice;
            if (choice == 2) {
                ofstream file(filename, ios::app);
                if (file.is_open()) {
                    string studentData;
                    cout << "Ââåäèòå äàííûå ñòóäåíòà: ";
                    cin.ignore();
                    getline(cin, studentData);
                    file << studentData << endl;
                    file.close();
                    cout << "Ñòóäåíò äîáàâëåí." << endl;
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
            cout << "Ââåäèòå íîìåð ñòðîêè äëÿ óäàëåíèÿ: " << endl;
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
        return 0;
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
    }
}
