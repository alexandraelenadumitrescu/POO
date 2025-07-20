#include<iostream>
#include<vector>
using namespace std;


class Prajitura {
	const int id;
	string nume;
	int nrIngrediente;
	float* cantitati;
	int pret;
public:
	//ctr fara param
	Prajitura() :id(0) {
		this->nume = "N/A";
		this->nrIngrediente = 0;
		this->cantitati = nullptr;
		this->pret = 0;
	}
	//ctr cu toti param
	Prajitura(int _id, string _nume, int _nrIngrediente, float* _cantitati, int _pret) :id(_id) {
		this->nume = _nume;
		this->nrIngrediente = _nrIngrediente;
		if (_cantitati != nullptr && nrIngrediente > 0) {
			this->cantitati = new float[this->nrIngrediente];
			for (int i = 0;i < this->nrIngrediente;i++) {
				this->cantitati[i] = _cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;


		}
		this->pret = _pret;
	}
	//ctr de copiere
	Prajitura(const Prajitura& p) :id(p.id) {
		this->nume = p.nume;
		this->nrIngrediente = p.nrIngrediente;
		if (p.cantitati != nullptr && nrIngrediente > 0) {
			this->cantitati = new float[this->nrIngrediente];
			for (int i = 0;i < this->nrIngrediente;i++) {
				this->cantitati[i] = p.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;


		}
		this->pret = p.pret;
	}
	//op de atr
	Prajitura& operator=(const Prajitura& p) {
		if (this != &p) {
			if (this->cantitati != nullptr) {
				delete[] this->cantitati;
				this->cantitati = nullptr;
				this->nume = p.nume;
				this->nrIngrediente = p.nrIngrediente;
				if (p.cantitati != nullptr && nrIngrediente > 0) {
					this->cantitati = new float[this->nrIngrediente];
					for (int i = 0;i < this->nrIngrediente;i++) {
						this->cantitati[i] = p.cantitati[i];
					}
				}
				else {
					this->cantitati = nullptr;


				}
				this->pret = p.pret;
			}

		}return *this;
	}
	//destr
	~Prajitura() {
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
			this->cantitati = nullptr;
		}
	}
	//get si set pe pret
	int getPret() {
		return this->pret;
	}
	void setPret(int pretNou) {
		if (pretNou > 0) {
			this->pret = pretNou;
		}
	}
	void operator*=(float multiplier) {
		for (int i = 0;i < this->nrIngrediente;i++) {
			if (this->cantitati[i] < 1 && this->cantitati[i]>0) {
				this->cantitati[i] *= multiplier;
			}
		}
	}
	friend ostream& operator<<(ostream& out, const Prajitura& p) {
		out << p.id << endl;
		out << p.nume << endl;
		out << p.nrIngrediente << endl;
		for (int i = 0;i < p.nrIngrediente;i++) {
			out << p.cantitati[i]<< " ";
		}
		out << endl;
		out << p.pret << endl;


		return out;
	}
	friend istream& operator>>(istream& in, Prajitura& p) {
		cout << "nume" << endl;
		in >> p.nume;
		cout << "nr ing" << endl;
		in >> p.nrIngrediente;
		delete[] p.cantitati;
		p.cantitati = new float[p.nrIngrediente];
		for (int i = 0;i < p.nrIngrediente;i++) {
			cout << "cantitate" << endl;
			in >> p.cantitati[i];
		}
		cout << "pret" << endl;
		in >> p.pret;
		return in;

	}
};
int count(Prajitura* prajituri, int nrPrajituri, int prag) {
	int count = 0;
	for (int i = 0;i < nrPrajituri;i++) {
		if (prajituri[i].getPret() > prag) {
			count++;
		}
	}
	return count;
}
class Cofetarie {
	Prajitura* prajituri;
	int nrPrajituri;
public:
	//ctr cu toti param
	Cofetarie(Prajitura* _prajituri, int _nrPrajituri) {
		this->nrPrajituri = _nrPrajituri;
		if (this->nrPrajituri > 0) {
			this->prajituri = new Prajitura[this->nrPrajituri];
			for (int i = 0;i < this->nrPrajituri;i++) {
				this->prajituri[i] = _prajituri[i];
			}
		}
	}
	//ctr de copiere
	Cofetarie(const Cofetarie& c) {
		this->nrPrajituri = c.nrPrajituri;
		if (this->nrPrajituri > 0) {
			this->prajituri = new Prajitura[this->nrPrajituri];
			for (int i = 0;i < this->nrPrajituri;i++) {
				this->prajituri[i] = c.prajituri[i];
			}
		}
	}
	//op de atr
	Cofetarie& operator=(const Cofetarie& c) {
		if (this != &c) {
			if (this->prajituri != nullptr) {
				delete[] this->prajituri;
				this->prajituri = nullptr;
			}
			this->nrPrajituri = c.nrPrajituri;
			if (this->nrPrajituri > 0) {
				this->prajituri = new Prajitura[this->nrPrajituri];
				for (int i = 0;i < this->nrPrajituri;i++) {
					this->prajituri[i] = c.prajituri[i];
				}
			}
		}
		return *this;
		
	}
	//destr
	~Cofetarie() {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
			this->prajituri = nullptr;
		}
		
	}


};
class Cof {
	vector<Prajitura> v;
	//ctr 
	// 
public:
	Cof(vector<Prajitura> _v) {
		this->v = _v;
	}
	//ctr de cop
	Cof(const Cof& c) {
		this->v = c.v;
	}
	void adauga(Prajitura p) {
		this->v.push_back(p);
	}
	void afis() {
		for (auto& x : v) {
			cout << x;
		}
	}
};
int main() {
	Prajitura p;
	Prajitura p1(10, "prajitura1", 2, new float[2] {0.5, 200}, 10);
	Prajitura p2(p);
	cout << p1.getPret() << endl;
	p1.setPret(20);
	cout << p1.getPret()<<endl;
	p1 *= (10);
	cout << p1;
	Prajitura p3(10, "prajitura1", 2, new float[2] {0.5, 200}, 100);
	Prajitura* prajituri=new Prajitura[2]{ p1,p3 };
	//p = new Prajitura[2]{ p1,p3 };
	cout << count(prajituri, 2, 50);
	//cin >> p;
	cout << p;
	//cof.v.push_back(p);
	vector<Prajitura> v;
	Cof cof(v);
	cof.afis();
	cof.adauga(p1);
	cof.afis();
	return 0;
}