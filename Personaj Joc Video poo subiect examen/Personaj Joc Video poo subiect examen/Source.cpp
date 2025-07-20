#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

enum Tip {tip1,tip2};
class Rucsac {
	int capacitate;
public:
	Rucsac() {
		this->capacitate = 0;
	}
	Rucsac(int _capacitate) {
		this->capacitate = _capacitate;
	}
	int getCapacitate () const {
		return this->capacitate;
	}
	void setCapacitate(int capacitateNoua) {
		this->capacitate = capacitateNoua;
	}
};

class Personaj {
	string nume;
	char* prenume;
	Tip tip;
	float* greutati;
	int nrBagaje;
	static int nrPersonaje;
	const int cod;
	
	
public:
	Rucsac rucsac;
	//cod rosu
	void codRosu() {
		
		if (this->nrBagaje > 0 && this->greutati != nullptr) {
			float maxim = this->greutati[0];
			for (int i = 0;i < this->nrBagaje;i++) {
				if (this->greutati[i] > maxim) {
					maxim = this->greutati[i];
				}
			}
			delete[] this->greutati;
			this->greutati = nullptr;
			this->greutati = new float[1] {maxim};
			this->nrBagaje = 1;
		}
	}
	//constr fara param
	Personaj() :cod(nrPersonaje++),rucsac(){
		this->nume = "-";
		this->tip = tip1;//Tip::tip1?
		this->nrBagaje = 0;
		this->greutati = nullptr;
		this->prenume = new char[2];
		strcpy_s(this->prenume, 2, "-");
		//this->rucsac = Rucsac(0);
	}
	//constr cu toti param
	Personaj(string _nume,Tip _tip,int _nrBagaje,float* _greutati,char* _prenume,int _capacitate) :cod(nrPersonaje++),rucsac( _capacitate) {
		this->nume = _nume;
		this->tip = _tip;
		this->nrBagaje = _nrBagaje;
		if (this->nrBagaje > 0 && _greutati != nullptr) {
			this->greutati = new float[this->nrBagaje];
			for (int i = 0;i < this->nrBagaje;i++) {
				this->greutati[i] = _greutati[i];
			}
		}
		if (strlen(_prenume) > 3 && _prenume != nullptr) {
			this->prenume = new char[strlen(_prenume)+1];
			strcpy_s(this->prenume, strlen(_prenume) + 1, _prenume);
		}
		
	}
	//constructor de copiere
	Personaj(const Personaj& p):cod(nrPersonaje++),rucsac(p.rucsac.getCapacitate()) {
		this->nume = p.nume;
		this->tip = p.tip;
		this->nrBagaje = p.nrBagaje;
		if (this->nrBagaje > 0 && p.greutati != nullptr) {
			this->greutati = new float[this->nrBagaje];
			for (int i = 0;i < this->nrBagaje;i++) {
				this->greutati[i] = p.greutati[i];
			}
		}
		if (strlen(p.prenume) > 3 && p.prenume != nullptr) {
			this->prenume = new char[strlen(p.prenume) + 1];
			strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
		}
		//rucsac.setCapacitate(p.rucsac.getCapacitate());
	}
	//operator de atribuire(operator =)
	Personaj& operator=(const Personaj& p) {
		if (this != &p) {
			this->nume = p.nume;
			this->tip = p.tip;
			this->nrBagaje = p.nrBagaje;
			delete[] this->greutati;
			this->greutati = nullptr;
			if (this->nrBagaje > 0 && p.greutati != nullptr) {
				this->greutati = new float[this->nrBagaje];
				for (int i = 0;i < this->nrBagaje;i++) {
					this->greutati[i] = p.greutati[i];
				}
			}
			delete[] this->prenume;
			this->prenume = nullptr;
			if (strlen(p.prenume) > 3 && p.prenume != nullptr) {
				this->prenume = new char[strlen(p.prenume) + 1];
				strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
			}
			this->rucsac.setCapacitate(p.rucsac.getCapacitate());
		}
		return *this;
	}
	//destructor
	~Personaj() {
		delete[] this->greutati;
		this->greutati = nullptr;
		delete[] this->prenume;
		this->prenume = nullptr;
		cout << "apel destructor" << endl;
	}
	//getter si setter pe tipul personajului
	Tip getTip() {
		return this->tip;
	}
	void setTip(Tip tipNou) {
		this->tip = tipNou;
	}
	friend ostream& operator<<(ostream& out, const Personaj& p);
	
};
int Personaj::nrPersonaje = 0;
ostream& operator<<(ostream& out, const Personaj& p) {
	out << p.cod << endl;
	out << p.nume<<endl;
	if (p.prenume != nullptr&&strlen(p.prenume) > 0) {
		out << p.prenume << endl;
	}
	out << p.tip << endl;
	out << p.nrBagaje<<endl;
	for (int i = 0;i < p.nrBagaje;i++) {
		out<<p.greutati[i]<<endl;
	}
	out << p.rucsac.getCapacitate() << endl;
	return out;
}
int main() {
	Personaj p;
	string s1 = "alex";
	Personaj p1("alex", tip1,4, new float[4] {10, 20, 30, 40}, new char[2] {"d"},50);

	cout << p<<endl;
	cout << p1<<endl;
	p1.codRosu();
	cout << p1;

	return 0;
}