//main.cpp 

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

#include "Classes.h";
#include "Methods.hpp";

void pause()
{
	cout << "\n";
	system("pause");
	cout << "\n";
}

//фирма-вектор отделов
typedef vector<Otdel> Firm;

int main()
{
	setlocale(LC_ALL, "rus");

	//создаем фирму и добавляем в нее отдел
	Firm firm;
	Otdel ot1("Отдел кадров");
	firm.push_back(ot1);

	//добавляем сотрудников в отдел
	firm[0].addSotr("Иванов", "Иван", "Иванович", 40000);
	firm[0].addSotr("Грозный", "Иван", "Васильевич", 50000);


	//выводим на печать инфо о первом отделе и начислениях зарплат
	firm[0].print();

	//добавляем еще один отдел
	Otdel ot2("Отдел маркетинга");
	firm.push_back(ot2);
	Sotrudnik sotr("Чайковский", "Петр", "Ильич", 45000);
	firm[1].addSotr(sotr);

	//выводим
	firm[1].print();

	pause();

	//складываем отделы:
	Otdel ot3 = firm[0] + firm[1];
	firm.push_back(ot3);

	//выводим
	firm[2].print();
	firm[2].accruals();

	pause();

	//удалим отдел№3
	firm[2].clear();

	//выведем данные 2го работника 1го отдела
	firm[0][1].print();

	pause();

	//очистим его данные
	firm[0][1].clear();

	//поменяем некоторые поля
	firm[0][0].setI("Василий");
	firm[1][0].setSalary(100000);
	
	//выведем что получилось
	for (int i = 0; i < 2; i++)
	{
		firm[i].print();
		firm[i].accruals();
	}

	pause();

	return 0;
}
