#include "table.h"
struct str {
	string name;
	string surname;
};
void work_1()
{
	str work;
	work.name;
	work.surname;
	cout << "Фамилия: ";
	cin >> work.surname;
	cout << "Имя: ";
	cin >> work.name;
}