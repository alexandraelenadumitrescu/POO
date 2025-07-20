#include<iostream>
using namespace std;
class Student {
	string nume;
	int varsta;
	
public:
	static int nrStudenti;
	static float taxaRestanta;
	Student(string _nume,int _varsta) /*:(nrStudenti++)*/ {
		this->nume = _nume;
		this->varsta = _varsta;
		nrStudenti++;
	}
	static int getNrStudenti() {
		return nrStudenti;
	}
	static bool validare(string _nume,int _varsta) {
		if (_varsta < 17 || _varsta>99) {
			return false;
		}
		
		return true;
	}
	friend ostream& operator<<(ostream& out, const Student& s);
};
ostream& operator<<(ostream& out, const Student& s) {
	out << s.nume;
	out << s.varsta;
	return out;
}
class Masina {
	string model;
	int nrDeplasari;
	float* distantaDeplasari;
	float pret;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2100) {
		this->model = "N/A";
		this->nrDeplasari = 0;
		this->distantaDeplasari = nullptr;
		this->pret = 0;
		

	}
	Masina(string _model, int _nrDeplasari, float* _distantaDeplasari, float _pret, int _anFabricatie) :anFabricatie(_anFabricatie) {
		this->model = _model;
		this->nrDeplasari = _nrDeplasari;
		if (nrDeplasari > 0 && _distantaDeplasari != nullptr) {
			this->distantaDeplasari = new float[nrDeplasari];
			for (int i = 0;i < nrDeplasari;i++) {
				this->distantaDeplasari[i] = _distantaDeplasari[i];
			}
		}
		else {
			this->distantaDeplasari = nullptr;
		}
		this->pret = _pret;
	}
	Masina(const Masina& m):anFabricatie(m.anFabricatie) {
		this->model = m.model;
		this->nrDeplasari = m.nrDeplasari;
		if (nrDeplasari > 0 && m.distantaDeplasari != nullptr) {
			this->distantaDeplasari = new float[nrDeplasari];
			for (int i = 0;i < nrDeplasari;i++) {
				this->distantaDeplasari[i] = m.distantaDeplasari[i];
			}
		}
		else {
			this->distantaDeplasari = nullptr;
		}
		this->pret = m.pret;
	}
	Masina& operator =(const Masina& m) {
		this->model = m.model;
		this->nrDeplasari = m.nrDeplasari;
		if (nrDeplasari > 0 && m.distantaDeplasari != nullptr) {
			delete[] distantaDeplasari;
			this->distantaDeplasari = nullptr;
			this->distantaDeplasari = new float[nrDeplasari];
			for (int i = 0;i < nrDeplasari;i++) {
				this->distantaDeplasari[i] = m.distantaDeplasari[i];
			}
		}
		else {
			this->distantaDeplasari = nullptr;
		}
		this->pret = m.pret;

		return *this;
	}
	friend ostream& operator<<(ostream& out, const Masina& m);
	Masina& operator++() {
		this->pret++;
		return *this;
	}
	Masina& operator++(int x) {
		Masina m = *this;
		this->pret++;
		return m;
	}
	//operator index
	float operator[](int i) {
		return this->distantaDeplasari[i];
	}
	//operator de cast implicit la int
	 explicit operator int() {
		return this->nrDeplasari;
	}
	 explicit operator string() {
		 return this->model;
	 }

	 //operator functie
	 //1 cu 2 param calculeaza suma deplasarilor intre doi indici
	 float  operator()(int index1, int index2) {
		 float suma = 0;
		 for (int i = index1;i < index2;i++) {
			 suma += this->distantaDeplasari[i];
		 }
		 return suma;

	 }
	 int operator()() {
		 int count = 0;
		 for (int i = 0;i < this->nrDeplasari;i++) {
			 if (this->distantaDeplasari[i] > 100) {
				 count++;
			 }
		 }
		 return count;
	 }
	 //2 fara param numara deplasarile cu distanta>100
	 ~Masina() {
		 delete[] this->distantaDeplasari;
		 this->distantaDeplasari = nullptr;
	 }
	 
};
ostream& operator<<(ostream& out, const Masina& m) {
	
	out << m.model << endl;
	out << m.nrDeplasari << endl;
	if (m.nrDeplasari > 0 && m.distantaDeplasari != nullptr) {
		for (int i = 0;i < m.nrDeplasari;i++) {
			out << m.distantaDeplasari[i] << " ";
		}
		out << endl;
	}
	out << m.pret<<endl;
	out << m.anFabricatie<<endl;
	return out;
}
class Persoana {
public:
	string nume;
protected:
	string adresa;
private:
	string contBancar;
	Masina masina;
};

int Student::nrStudenti = 0;
float Student::taxaRestanta = 100;
int main() {
	Student s("alex", 20);
	cout << s;
	cout << s.nrStudenti;
	cout << endl;
	float* deplasari = new float[2] {100, 200};
	Masina m("dacia", 2, deplasari, 10000, 2007);
	Masina m1 = m;
	cout << m1<<endl;
	cout << m;
	cout << m[0];
	cout << (int)m;
	cout << endl;
	cout << (string)m;
	cout << m(0, 2);
	return 0;
}