#include "Work.h"

int Work(string filename)
{
    int choice = 0;
    cout << "�������� ��������:" << endl
        << "1. �������� �������" << endl
        << "2. �������� ��������" << endl
        << "3. ������� ��������" << endl
        << "4. ����� ��������" << endl
        << "5. ������� ������" << endl
        << "6. ������ ������" << endl
        << "7. �����" << endl
        << "��������, ��������� � ���������� ������!!!" << endl;
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
            cout << "1. �����" << endl << "2. ��������";
            cin >> choice;
            if (choice == 2) {
                ofstream file(filename, ios::app);
                if (file.is_open()) {
                    string studentData;
                    cout << "������� ������ ��������: ";
                    cin.ignore();
                    getline(cin, studentData);
                    file << studentData << endl;
                    file.close();
                    cout << "������� ��������." << endl;
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
            cout << "������� ����� ������ ��� ��������: " << endl;
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
