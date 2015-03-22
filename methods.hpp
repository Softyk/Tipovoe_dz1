//methods.hpp содержит описания функций классов

Sotrudnik::Sotrudnik()
{
	f = "";
	i = "";
	o = "";
	salary = 0;
}

Sotrudnik::Sotrudnik(string a, string b, string c, int s)
{
	f = a;
	i = b;
	o = c;
	salary = s;
}

Sotrudnik::~Sotrudnik()
{
	f = "";
	i = "";
	o = "";
	salary = 0;
}

void Sotrudnik::setSalary(int s)
{
	salary = s;
}

void Sotrudnik::setF(string s)
{
	f = s;
}

void Sotrudnik::setI(string s)
{
	i = s;
}

void Sotrudnik::setO(string s)
{
	o = s;
}

int Sotrudnik::getSalary()
{
	return salary;
}

void Sotrudnik::print()
{
	cout << "\nФамилия: " << f;
	cout << "\nИмя: " << i;
	cout << "\nОтчество: " << o;
	cout << "\nОбъем зарплаты: " << salary;
}

void Sotrudnik::clear()
{
	f = "";
	i = "";
	o = "";
	salary = 0;
}

Otdel::Otdel()
{
	this->resize(0);
	quantity = 0;
	name = "";
}

Otdel::Otdel(string s)
{
	this->resize(0);
	quantity = 0;
	name = s;
}

void Otdel::addSotr(Sotrudnik &sotr)
{
	this->push_back(sotr);
	quantity++;
}

void Otdel::addSotr(string a, string b, string c, int s)
{
	Sotrudnik sotr = Sotrudnik(a, b, c, s);
	this->push_back(sotr);
	quantity++;
}

void Otdel::accruals()
{
	int sum = 0;
	vector <Sotrudnik>::iterator it = this->begin();
	for (; it != this->end(); ++it)
		sum += it->getSalary();
	cout << "\nНачисления зарплат по отделу: " << sum;
}

void Otdel::print()
{
	cout << "\nНазвание отдела: " << name;
	cout << "\nКоличество сотрудников: " << quantity;
	vector<Sotrudnik>::iterator it = this->begin();
	for (int i = 0; it != this->end(); ++it, ++i)
	{
		cout << "\nСотрудник " << (i + 1);
		it->print();
	}
}

void Otdel::clear()
{
	name = "";
	resize(0);
	quantity = 0;
}

Otdel::~Otdel()
{
	name = "";
	quantity = 0;
	resize(0);
}

Sotrudnik & Otdel::operator[](int n)
{
	if ((n <= quantity)&(n >= 0))
	{
		Otdel::iterator it = this->begin();
		for (int i = 0; i < n; i++)	{ ++it; }
		return(*it);
	}
	else {
		cout << "\nError";
		system("pause");
		exit(-1);
	}
}

Otdel & Otdel:: operator =(Otdel& ot)
{
	this->clear();
	this->quantity = ot.quantity;
	this->name = ot.name;
	Otdel::iterator it = ot.begin();
	for (; it != ot.end(); ++it){ this->addSotr(*it); }

	return *this;
}

Otdel operator +(Otdel& ot1, Otdel& ot2)
{
	Otdel ot = ot1;
	Otdel::iterator it = ot2.begin();
	for (; it != ot2.end(); ++it){ ot.addSotr(*it); }
	ot.quantity += ot2.quantity;

	return ot;
}
