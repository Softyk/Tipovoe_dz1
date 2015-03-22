#ifndef __CLASSES_H
#define __CLASSES_H
//classes.h содержит описания классов

//класс сотрудников
class Sotrudnik
{
	string f;//фамилия
	string i;//имя 
	string o;//отчество
	int salary;//размер зарплаты
public:
	Sotrudnik();
	Sotrudnik(string, string, string, int);
	~Sotrudnik();

	//функции для изменения полей
	void setSalary(int);
	void setF(string);
	void setI(string);
	void setO(string);

	//функции для получения зарплаты
	int getSalary();

	//печать информации о сотруднике
	void print();

	//очистка данных о сотруднике
	void clear();
};

//класс отделов

class Otdel :public vector <Sotrudnik>
{
private:
	string name;
	int quantity = 0;
public:
	Otdel();
	Otdel(string);

	//функции добавления сотрудников
	void addSotr(string, string, string, int);
	void addSotr(Sotrudnik&);

	//функция печати начислений зарплаты по отделу
	void accruals();

	//функция печати
	void print();

	//функция очистки данных
	void clear();

	//перегрузка операции +(объединение двух отделов)
	friend Otdel operator+(Otdel&, Otdel&);

	//перегрузка оператора обращения по адресу
	Sotrudnik &operator[](int n);

	//перегрузка оператора =(копирование отдела)
	Otdel & operator =(Otdel&);

	~Otdel();
};

//фирма-вектор отделов
typedef vector<Otdel> Firm;

#endif
