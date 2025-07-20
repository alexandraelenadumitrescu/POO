#include<iostream>
#include<vector>
using namespace std;
class Comanda {
	string client;
	int prod;
	float* pret;
	bool achitat;
	static int max;
	//ctr fara param
public:
	void operator++() {
		for (int i = 0;i < this->prod;i++) {
			if (this->pret[i] < 3) {
				this->pret[i]++;
			}
		}
	}
	Comanda() {
		this->client = "N/A";
		this->prod = 0;
		this->pret = nullptr;
		this->achitat = false;
	}
	//ctr cu toti param
	Comanda(string _client, int _prod, float* _pret, bool _achitat) {
		this->client = _client;
		if (_prod > max) {
			this->prod = max;
			this->pret = new float[max];
			for (int i = 0;i < this->prod;i++) {
				this->pret[i] = _pret[i];
			}

		}
		else if
			(_prod <= max) {
			this->prod = _prod;
			this->pret = new float[this->prod];
			for (int i = 0;i < this->prod;i++) {
				this->pret[i] = _pret[i];
			}
		}
		
		this->achitat = _achitat;

	}
	//ctr de copiere
	Comanda(const Comanda& c) {
		this->client = c.client;
		if (c.prod > max) {
			this->prod = max;
			this->pret = new float[max];
			for (int i = 0;i < this->prod;i++) {
				this->pret[i] = c.pret[i];
			}

		}
		else if
			(c.prod <= max) {
			this->prod = c.prod;
			this->pret = new float[this->prod];
			for (int i = 0;i < this->prod;i++) {
				this->pret[i] = c.pret[i];
			}
		}

		this->achitat = c.achitat;
	}
	//destructor
	~Comanda() {
		delete[] this->pret;
		this->pret = nullptr;
		cout << "apel destructor"<<endl;
	}
	//operatorul de atribuire
	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			delete[] this->pret;
			this->pret = nullptr;
			this->client = c.client;
			if (c.prod > max) {
				this->prod = max;
				this->pret = new float[max];
				for (int i = 0;i < this->prod;i++) {
					this->pret[i] = c.pret[i];
				}

			}
			else if
				(c.prod <= max) {
				this->prod = c.prod;
				this->pret = new float[this->prod];
				for (int i = 0;i < this->prod;i++) {
					this->pret[i] = c.pret[i];
				}
			}

			this->achitat = c.achitat;
		}
			return *this;
	}
	/*bool operator>(float comp) {
		bool val = true;
		int suma = 0;
		for (int i = 0;i < prod;i++) {
			suma+= pret[i];
		}
		if (suma < comp) {
			val = false;
		}
		return val;
	}*/
	friend bool operator>(float comp, const Comanda& c);
	int operator()(Comanda com[3]) {
		int sumaComanda = 0;
		for (int i = 0;i < prod;i++) {
			sumaComanda += pret[i];
		}
		int nrcom = 0;
		for (int i = 0;i < 3;i++) {
			int suma = 0;
			for (int j = 0;j < com[i].prod;i++) {
				suma += com[i].pret[j];
			}
			if (suma > sumaComanda) {
				nrcom++;
			}
		}
		return nrcom;
	}
	friend ostream& operator<<(ostream& out, const Comanda& c) {
		out << c.client << endl;
		out << c.prod << endl;
		for (int i = 0;i < c.prod;i++) {
			out << c.pret[i]<<" ";
		}
		out << endl;
		if (c.achitat == true) {
			out << "este achitat" << endl;
		}
		else {
			out << "nu este achitat" << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Comanda& c) {
		cout << "nume client" << endl;
		in >> c.client;
		cout << "nr produse: " << endl;
		in >> c.prod;
		delete[] c.pret;
		c.pret = nullptr;
		c.pret = new float[c.prod];
		for (int i = 0;i < c.prod; i++) {
			cout << "pret produs";
			in >> c.pret[i];

		}
		cout << "achitat";
		in >> c.achitat;
		return in;
	}
};
class Restaurant {
	string nume;
	Comanda* comenzi;
	int nrcom;
public:
	void adaugare(const Comanda& c) {
		this->nrcom++;
		Comanda* aux = new Comanda[this->nrcom];
		for (int i = 0;i <this-> nrcom;i++) {
			aux[i] = this->comenzi[i];
		}
		delete[] this->comenzi;
		this->comenzi = new Comanda[this->nrcom];
		for (int i = 0;i < this->nrcom;i++) {
			this->comenzi[i]=aux[i] ;
		}
		delete[] aux;
		aux = nullptr;
	}
	//ctr fara param
	Restaurant() {
		this->nume = "N/A";
		this->comenzi = nullptr;
		this->nrcom = 0;
	}
	//ctr cu un param
	Restaurant(string _nume) {
		this->nume = _nume;
		this->comenzi = nullptr;
		this->nrcom = 0;
	}
	//ctr cu toti param
	Restaurant(string _nume, Comanda* _comenzi, int _nrcom) {
		this->nume = _nume;
		this->nrcom = _nrcom;
		if (this->nrcom > 0) {
			this->comenzi = new Comanda[this->nrcom];
			for (int i = 0;i < this->nrcom;i++) {
				this->comenzi[i] = _comenzi[i];
			}
		}
	}
	//ctr de copiere
	Restaurant(const Restaurant& r) {
		this->nume = r.nume;
		this->nrcom = r.nrcom;
		if (this->nrcom > 0) {
			this->comenzi = new Comanda[this->nrcom];
			for (int i = 0;i < this->nrcom;i++) {
				this->comenzi[i] = r.comenzi[i];
			}
		}
	}
	// //destructor
	~Restaurant() {
		delete[] this->comenzi;
		this->comenzi = nullptr;
	}
	//op de atr
	Restaurant& operator=(const Restaurant& r) {
		if(this!=&r){
			delete[] this->comenzi;
			this->comenzi = nullptr;
			this->nume = r.nume;
			this->nrcom = r.nrcom;
			if (this->nrcom > 0) {
				this->comenzi = new Comanda[this->nrcom];
				for (int i = 0;i < this->nrcom;i++) {
					this->comenzi[i] = r.comenzi[i];
				}
			}
		}
		return *this;
		
	}
	friend ostream& operator<<(ostream& out, const Restaurant& r) {
		out << r.nume;
		out << r.nrcom;
		for (int i = 0;i < r.nrcom;i++) {
			out << r.comenzi[i] << " ";
		}

		return out;
	}
	friend istream& operator>>(istream& in, Restaurant& r) {
		cout << "nume: ";
		in >> r.nume;
		cout << "nr com";
		in >> r.nrcom;
		delete[] r.comenzi;
		r.comenzi = new Comanda[r.nrcom];
		for (int i = 0;i < r.nrcom;i++) {
			cout << " comanda";
			in >> r.comenzi[i];
		}
			return in;
	}
	
};
bool operator>(float comp,const Comanda& c) {
	bool val = true;
	int suma = 0;
	for (int i = 0;i < c.prod;i++) {
		suma += c.pret[i];
	}
	if (suma < comp) {
		val = false;
	}
	return val;
}
int Comanda::max = 10;
int main() {
	Comanda c;
	Comanda c1("client 1", 3, new float[3] {1, 2, 12}, 1);
	Comanda c2 = c1;
	Comanda c3;
	c3 = c2;
	//cout << (c3 > 20);
	//cout << (20 > c3);
	Comanda com[3] = { c,c,c };
	cout << "===================" << endl;
	//cout<<c1(com);
	//cout << c1;
	cout << endl;
	Restaurant r;
	//cout << r;
	Comanda* comenzi = new Comanda[3]{ c,c1,c2 };

	Restaurant r1("restaurant 1", comenzi, 3);
	cout << endl;
	//cout << r1;
	//cin >> c2;
	//cout << c2 << endl;

	cout << "=======================" << endl;

	/*cout << r1;
	cin >> r1;
	cout << r1;
	cout << c1;*/

	/*++c1;
	cout << c1;*/
	vector<Restaurant> v;
	v.push_back(r1);
	v.push_back(r1);
	v.push_back(r1);
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << endl;
	}

	

	return 0;
}