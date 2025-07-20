/*
Enunt examen POO 30 iunie 2020 ora 8.00
Să se scrie o aplicație orientată obiect pentru evidenta activitatilor zilnice 
ale unei persoane; este necesară cunoașterea activitatii, a orei de desfasurare și a duratei estimate.
Pentru domeniul dat, să se definească o clasă cu membri de tip public, private,  protected, const, static, care să conțină:
(1p) definirea corectă a clasei;
(2p) constructor cu parametri, default constructor, constructor de copiere, destructor și operator<< 
pentru afișare (0.5 puncte/funcție/operator) ;
(2p) operator=, un operator pentru compararea între obiecte și încă doi operatori adecvați domeniului 
(aritmetici sau cast sau indexare sau de alt tip) (0.5 puncte/funcție/operator) ;
(1p) două funcții de tip accesor și două metode proprii clasei (0.25 puncte/funcție/operator);
 (1p) funcții sau operatori pentru salvarea și restaurarea obiectelor în/din fișiere binare, permanente.
 (2p) Definiți încă o clasă, capabilă să gestioneze o colecție de obiecte din prima clasă; operatorii += și -= 
 vor asigura adăugarea / scoaterea obiectelor din colecție.
(1p) Transformați una din clase într-o clasă template sau instanțiați o clasă template STL, pentru domeniul dat.
Elementele definite vor fi punctate doar dacă sunt complete și au fost testate în main().

*/
#include <iostream>
using namespace std;
#include <map>
#include<vector>
class Activitate {
	string nume;
	int ora;
	int durata;
protected:
	const int cod;
public:
	int cost() {
		return this->durata * 500;
	}
	int sumaTva() {
		return this->cost() * 0.21;
	}
	static int counter;
	Activitate():cod(0) {
		this->nume = "N/A";
		this->ora = 0;
		this->durata = 0;
		counter++;
		
	}
	Activitate(string _nume, int _ora, int _durata, int _cod) :cod(_cod) {
		this->nume = _nume;
		this->ora = _ora;
		this->durata = _durata;
		counter++;
	}
	Activitate(const Activitate& a):cod(a.cod) {
		this->nume = a.nume;
		this->ora = a.ora;
		this->durata = a.durata;
		counter++;
	}

	Activitate& operator =(const Activitate& a) {
		if (this != &a) {
			this->nume = a.nume;
			this->ora = a.ora;
			this->durata = a.durata;
		}
		return *this;
	}
	~Activitate() {

	}
	friend ostream& operator<<(ostream& out, const Activitate& a);

	bool operator>(const Activitate& a1) {
		if (this->durata > a1.durata) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!() {
		if (this->durata > 5) {
			return true;
		}
		else {
			return false;
		}
	}
	explicit operator int() {
		return this->durata;
	}
};
ostream& operator<<(ostream& out, const Activitate& a) {
	out << a.nume << endl;
	out << a.ora << endl;
	out << a.durata << endl;
	out << a.cod << endl;
	return out;
}
int Activitate::counter = 0;
class Lista {
	Activitate* activitati;
	int nr;
public:
	Lista() {
		this->nr = 0;
		this->activitati = nullptr;

	}
	Lista(Activitate* _activitati, int _nr) {
		this->nr = _nr;
		if (nr > 0 && _activitati != nullptr) {
			this->activitati = new Activitate[nr];
			for (int i = 0;i < nr;i++) {
				this->activitati[i] = _activitati[i];
			}
		}
	}
	void operator+=(const Activitate& a) {
		nr++;
		Activitate* activitatiCopie;
		activitatiCopie = new Activitate[nr - 1];
		for (int i = 0;i < this->nr - 1;i++) {
			activitatiCopie[i] = this->activitati[i];
		}
		delete[] this->activitati;
		this->activitati = new Activitate[nr];
		for (int i = 0;i < this->nr;i++) {
			this->activitati[i] = activitatiCopie[i];
		}


	}
	friend ostream& operator<<(ostream& out, const Lista& a);
};
ostream& operator<<(ostream& out, const Lista& a) {
	for (int i = 0;i < a.nr;i++) {
		out << a.activitati[i] << " ";
	}
	return out;
}
int main() {
	//cout << "aaaaaa";
	Activitate a;
	cout << a;
	Activitate a1("activitate 1", 10, 10, 10);
	cout << a1;
	Activitate a2 =a1;
	cout << a2;
	Activitate a3("activitate 3", 10, 20, 10);
	a2 = a3;
	cout << a2;
	cout << (a1 > a2);
	cout<< !a2;
	cout << (int)a2 << endl;
	cout << a2.cost() << endl;
	cout << a2.sumaTva() << endl;
	Lista l;
	cout << l;
	Lista l1( new Activitate[2]{ a2,a3 },2);
	cout << l1;
	map<int, float> elemente;
	
	
	
		elemente.insert(pair<int, float>(6, 4.6));
	
		elemente.insert(pair<int, float>(5, 6.6));
		elemente.insert(pair<int, float>(8, 3.8));
		elemente.insert(pair<int, float>(6, 7.6));
	
		elemente[6] = 9.3;
		elemente[2] = 10;
		elemente[0] = 1;
		//afisare
		map<int, float>::iterator it = elemente.begin();
		while (it != elemente.end()) {
			cout << it->first<<" ";
			cout << it->second<<endl;
			it++;
		}
		vector<Activitate> v;
		v.push_back(a);
		v.push_back(a1);
		v.push_back(a2);
		v.push_back(a3);
		cout << endl << "===================" << endl;
		for (int i = 0;i < v.size();i++) {
			cout << v[i]<<" ";
		}
	return 0;
}