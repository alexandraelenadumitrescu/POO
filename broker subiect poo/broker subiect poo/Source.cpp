#include<iostream>
using namespace std;
class Asigurare {
	char* nume;
	float suma;
	string tip;
	int durata;
	static int nrAsigurati;
	const int cod;
public:
	Asigurare():cod(nrAsigurati++) {
		this->nume = new char[2];
		strcpy_s(nume, 2, "-");
		this->suma = 0;
		this->tip = "indisponibil";
		this->durata = 0;
		
	}
	Asigurare(char* _nume, float _suma, string _tip, int _durata) :cod(nrAsigurati++) {
		if (_nume != nullptr && strlen(_nume) > 3) {
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(nume, strlen(_nume) + 1, _nume);
		}
		this->suma = _suma;
		this->tip = _tip;
		this->durata = _durata;

	}
	Asigurare(const Asigurare& a):cod(nrAsigurati++) {
		if (a.nume != nullptr && strlen(a.nume) > 3) {
			this->nume = new char[strlen(a.nume) + 1];
			strcpy_s(nume, strlen(a.nume) + 1, a.nume);
		}
		this->suma = a.suma;
		this->tip = a.tip;
		this->durata = a.durata;

	}
	Asigurare& operator=(const Asigurare& a) {
		if (this != &a) {
			if (a.nume != nullptr && strlen(a.nume) > 3) {
				delete[] this->nume;
				this->nume = nullptr;
				this->nume = new char[strlen(a.nume) + 1];
				strcpy_s(nume, strlen(a.nume) + 1, a.nume);
			}
			this->suma = a.suma;
			this->tip = a.tip;
			this->durata = a.durata;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Asigurare& a);
};
ostream& operator<<(ostream&  out, const Asigurare& a) {
	out << a.nume<<endl;
	out << a.suma<<endl;
	out << a.tip<<endl;
	out << a.durata<<endl;
	return out;
}
int Asigurare::nrAsigurati = 0;
int main() {
	Asigurare a;
	cout << a;
	Asigurare a1(new char[5]{"alex"},200,"rca",20);
	cout << a1;
	return 0;
}