#include<iostream>
using namespace std;
class Masina {
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int tva;
	const int anFabricatie;
	
public:
	 static void met1() {
		cout << "aceasta este metoda din clasa de baza"<<endl;
	}
	//ctr fara param
	Masina():anFabricatie(9999) {
		this->nrRoti = 0;
		this->producatori = nullptr;
		this->marca = "";
		this->pret = 0;
	
	}
	//ctr cu param
	Masina(int _nrRoti,string* _producatori,string _marca,float _pret,int _anFabricatie):anFabricatie(_anFabricatie) {
	this->nrRoti = _nrRoti;
	if (this->nrRoti > 0) {
		this->producatori = new string[nrRoti];
		for (int i = 0;i < this->nrRoti;i++) {
			this->producatori[i] = _producatori[i];
		}
	}
	
	this->marca = _marca;
	this->pret = _pret;

}
	// ctr de copiere
	Masina(const Masina& m):anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		if (this->nrRoti > 0) {
			this->producatori = new string[nrRoti];
			for (int i = 0;i < this->nrRoti;i++) {
				this->producatori[i] = m.producatori[i];
			}
		}

		this->marca = m.marca;
		this->pret = m.pret;
	}
	//op de atribuire
	Masina& operator=(const Masina& m) {
		if (this != &m) {
			this->nrRoti = m.nrRoti;

			if (this->nrRoti > 0) {
				delete[] this->producatori;
				this->producatori = nullptr;
				this->producatori = new string[this->nrRoti];
				for (int i = 0;i < this->nrRoti;i++) {
					this->producatori[i] = m.producatori[i];
					
				}
			}

			this->marca = m.marca;
			this->pret = m.pret;
		}
		return *this;
	}
	~Masina() {
		delete[] this->producatori;
		this->producatori = nullptr;
	}
	friend ostream& operator<<(ostream& out, const Masina& m) {
		out << m.nrRoti << endl;
		for (int i = 0;i < m.nrRoti;i++) {
			out << m.producatori[i] << " ";
			
		}
		out << endl;
		out << m.marca << endl;
		out << m.pret << endl;
		out << m.anFabricatie << endl;
		


		return out;
	}
	
};

int Masina::tva = 0.21;
class Tir :public Masina {
	float tonaj;
	char* tara;
public:
	Tir() :Masina() {
		this->tonaj = 0;
		//this->tara = nullptr;
		this->tara = new char[2];
		strcpy_s(this->tara, 2, "-");
	}
	Tir(int _nrRoti, string* _producatori, string _marca, float _pret, int _anFabricatie, float _tonaj, char* _tara) :Masina(_nrRoti, _producatori, _marca, _pret, _anFabricatie) {
		this->tonaj = _tonaj;
		this->tara = new char[strlen(_tara) + 1];
		strcpy_s(this->tara, strlen(_tara) + 1, _tara);
	}
	friend ostream& operator<<(ostream& out, const Tir& m) {
		/*out << m.nrRoti << endl;
		for (int i = 0;i < m.nrRoti;i++) {
			out << m.producatori[i] << " ";

		}
		out << endl;
		out << m.marca << endl;
		out << m.pret << endl;
		out << m.anFabricatie << endl;*/
		out << (Masina)m;
		out << m.tonaj << endl;
		out << m.tara << endl;


		return out;
	}
	/*override Masina::met1() {
		cout << "aceasta este metoda din clasa copil" << endl;
	}*/
	static void met1() override {
		cout << "aceasta este metoda din clasa copil" << endl;
	}
};
int main() {
	Masina m;
	string* prodroti = new string[4]{ "michelin","pirelli","yamaha","yokohama" };
	Masina m1(4, prodroti, "vw", 15000, 2010);
	Masina m2 = m1;
	Masina m3;
	cout << m3;
	m3 = m1;
	cout << m << m1 << m2 << m3;
	Tir t1;
	cout << t1;
	m1.met1();
	t1.met1();
	
	return 0;
}