#include<iostream>
#include<map>
using namespace std;
class IE {
public:
	virtual void printInfo() = 0;
	virtual ~IE() {}
};
class Echipa: public IE{
	const string denumire;
	int nrjuc;
	string* numejuc;
	int buget;
	static int bugetmin;
public:
	virtual void metoda() {
		cout << 1;
	}
	void setBuget(int bugetNou) {
		if (bugetNou >= 0) {
			this->buget = bugetNou;
		}
		else {
			throw exception("ai eroare boss");
		}
	}
	//ctr fara param
	void printInfo() override {
		cout << *this << endl;
	}
	Echipa():denumire("N/A") {
		this->nrjuc = 0;
		this->numejuc = nullptr;
		this->buget = bugetmin;
	}
	//ctr cu toti param
	Echipa(string _denumire,int _nrjuc,string* _numejuc,int _buget) :denumire(_denumire) {
		this->nrjuc = _nrjuc;
		if (this->nrjuc > 0&&_numejuc!=nullptr) {
			this->numejuc = new string[this->nrjuc];
			for (int i = 0;i < this->nrjuc;i++) {
				this->numejuc[i] = _numejuc[i];
			}
		}
		if (_buget > bugetmin) {
			this->buget = _buget;
		}
		else {
			this->buget = bugetmin;

		}
	}
	//ctr de copiere
	Echipa(const Echipa& e):denumire(e.denumire) {
		this->numejuc = nullptr;
		this->nrjuc = e.nrjuc;
		if (this->nrjuc > 0 && e.numejuc != nullptr) {
			this->numejuc = new string[this->nrjuc];
			for (int i = 0;i < this->nrjuc;i++) {
				this->numejuc[i] = e.numejuc[i];
			}
		}
		if (e.buget > bugetmin) {
			this->buget = e.buget;
		}
		else {
			this->buget = bugetmin;

		}
	}
	//op de atr;
	Echipa& operator=(const Echipa& e) {
		if (this != &e) {
			delete[] this->numejuc;
			this->numejuc = nullptr;
			this->nrjuc = e.nrjuc;
			if (this->nrjuc > 0 && e.numejuc != nullptr) {
				this->numejuc = new string[this->nrjuc];
				for (int i = 0;i < this->nrjuc;i++) {
					this->numejuc[i] = e.numejuc[i];
				}
			}
			if (e.buget > bugetmin) {
				this->buget = e.buget;
			}
			else {
				this->buget = bugetmin;

			}
		}
		return *this;
	}
	//destructor
	virtual ~Echipa() {
		
		if (this->numejuc) {
			delete[] this->numejuc;
			this->numejuc = nullptr;
		}
	}
	//m=get si set pe buget
	/*void setBuget(int bugetNou) {
		if (bugetNou > bugetmin) {
			this->buget = bugetNou;
		}
	}*/
	int getBuget() {
		return this->buget;
	}
	void operator+=(int sumaBuget) {
		if (sumaBuget > 0) {
			this->buget += sumaBuget;
		}
	}
	explicit operator float() {
		return (this->buget>bugetmin);
	}
	friend ostream& operator<<(ostream& out, const Echipa& e) {
		out << e.denumire << endl;
		out << e.nrjuc << endl;
		for (int i = 0;i < e.nrjuc;i++) {
			out << e.numejuc[i] << " ";
		}
		out << endl;
		out << e.buget;
		return out;
	}
};
class EchipaPro :public Echipa {
	string denumireSponsor;
	//ctr fara param
public:
	void printInfo() override {
		cout << *this << endl;
	}
	EchipaPro() :Echipa() {
		this->denumireSponsor = "n/a";

	}
	//ctr cu param
	EchipaPro(string _denumire, int _nrjuc, string* _numejuc, int _buget,string _denumireSponsor) :Echipa(_denumire, _nrjuc, _numejuc, _buget) {
		this->denumireSponsor = _denumireSponsor;
	}
	//ctr de copiere
	EchipaPro(const EchipaPro& p):Echipa(p) {
		this->denumireSponsor = p.denumireSponsor;
	}
	//op de atr
	EchipaPro& operator=(const EchipaPro& p)  {
		Echipa::operator=(p);
		this->denumireSponsor = p.denumireSponsor;
		return *this;
	}
	//destructor
	~EchipaPro() {

	}
	friend ostream& operator<<(ostream& out, const EchipaPro& e) {
		cout << (Echipa)e;
		out << e.denumireSponsor<<endl;
		return out;
	}
};
int Echipa::bugetmin = 100;
int main() {
	Echipa e;
	try {
		e.setBuget(-200);
	}
	catch(exception ex){
		cout << ex.what();
	}
	/*Echipa e1("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	Echipa e2 = e1;
	e = e1;
	cout<<e.getBuget()<<endl;
	e.setBuget(500);
	cout << e.getBuget()<<endl;
	e += 200;
	cout << e.getBuget() << endl;
	cout << (float)e;
	EchipaPro p;
	cout << e1;
	cout << p;
	IE* i = new Echipa("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	i->printInfo();
	IE* i1 = new EchipaPro("echipa1", 2, new string[2]{ "juc1","juc2" }, 200,"sponsor");
	i1->printInfo();
	map<string, Echipa> m;
	m["echipa1"] = Echipa("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	m["echipa1"] = Echipa("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	m["echipa2"] = Echipa("echipa2", 2, new string[2]{ "juc1","juc2" }, 200);
	for (auto& p : m) {
		p.second.printInfo();
	}
	map<string, IE*> m1;
	m1["echipa1"] = new Echipa("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	m1["echipa1"] =new  Echipa("echipa1", 2, new string[2]{ "juc1","juc2" }, 200);
	m1["echipa2"] =new Echipa("echipa2", 2, new string[2]{ "juc1","juc2" }, 200);
	for (auto& p : m1) {
		p.second->printInfo();
	}*/


	return 0;
}