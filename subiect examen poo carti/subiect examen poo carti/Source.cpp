#include<iostream>
enum TipCarte{tip1,tip2};
using namespace std;
class Carte {
	string autor;
	char* titluCarte;
	TipCarte tip;
	int nrExemplareDisponibile;
public:
	Carte(string _autor,char* _titluCarte,TipCarte _tip, int _nrExemplareDisponibile) {
		this->autor = _autor;
		if (_titluCarte != nullptr) {
			this->titluCarte = new char[strlen(_titluCarte) + 1];
			strcpy_s(this->titluCarte, strlen(_titluCarte) + 1, _titluCarte);
		}
		this->tip = _tip;
		this->nrExemplareDisponibile = _nrExemplareDisponibile;
	}
	//ctr de copiere
	Carte(const Carte& c) {
		this->autor = c.autor;
		if (c.titluCarte != nullptr) {
			this->titluCarte = new char[strlen(c.titluCarte) + 1];
			strcpy_s(this->titluCarte, strlen(c.titluCarte) + 1, c.titluCarte);
		}
		this->tip = c.tip;
		this->nrExemplareDisponibile = c.nrExemplareDisponibile;
	}
	//operator de atribuire
	Carte& operator=(const Carte& c) {
		this->autor = c.autor;
		if (c.titluCarte != nullptr) {
			delete[] this->titluCarte;
			this->titluCarte = nullptr;
			this->titluCarte = new char[strlen(c.titluCarte) + 1];
			strcpy_s(this->titluCarte, strlen(c.titluCarte) + 1, c.titluCarte);
		}
		this->tip = c.tip;
		this->nrExemplareDisponibile = c.nrExemplareDisponibile;
		return *this;
	}
	~Carte(){
		delete[] this->titluCarte;
		this->titluCarte = nullptr;	
	}
		//get si set pentru numarul de exemplare
		int getNrExemplare() {
		return this->nrExemplareDisponibile;
	}
	void setNrExemplare(int nouNrExemplare) {
		this->nrExemplareDisponibile = nouNrExemplare;
	}
	//virtual void functie()=0;
	explicit operator int() {
		return this->nrExemplareDisponibile;
	}
	//sa se implementeze o metoda statica care primeste un vector 
	// de obiecte de tip carte si returneaza cartea cu cele mai multe
	//exemplare disponibile
	static Carte maxim(Carte* lista, int nr) {
		int maxim = 0;
		for (int i = 0;i < nr;i++) {
			if (lista[i].getNrExemplare() > maxim) {
				maxim = i;
			}
		}
		return lista[maxim];
	}
	friend ostream& operator <<(ostream& out, const Carte& c);
	friend istream& operator>>(istream& in, Carte& c);
};
ostream& operator <<(ostream& out, const Carte& c) {
	out << c.autor << endl;
	out << c.titluCarte << endl;
	out << c.tip << endl;
	out << c.nrExemplareDisponibile << endl;
	return out;
}
istream& operator>>(istream& in, Carte& c) {
	cout << "nume autor: \n";
	in >> c.autor;
	cout << "titlu carte: \n";
	/*int dim = 100;
	char* aux = new char[dim];
	cin.getline(aux, dim);
	delete[] c.titluCarte;
	c.titluCarte = nullptr;
	c.titluCarte = new char[strlen(aux) + 1];
	strcpy_s(c.titluCarte, strlen(aux) + 1, aux);*/
	string aux;
	in >> aux;
	delete[] c.titluCarte;
	c.titluCarte = new char[aux.length() + 1];
	strcpy_s(c.titluCarte, aux.length()+1,aux.data() );


	cout << "tip: \n";
	int tipTemp;
	in >> tipTemp;
	c.tip = static_cast<TipCarte>(tipTemp);
	
	cout << "exemplare disponibile: \n";
	in >> c.nrExemplareDisponibile;

	


		return in;

}
//class CarteElectronica :Carte {
//	string format;
//	override functie() {
//		cout << "s a inchiriat cartea";
//	}
//	
//};
int main() {
	char* nume = new char[5] {"meta"};
	Carte c1("alex", nume, tip1, 10);
	cout << c1;
	cin >> c1;
	cout << c1;
	return 0;
}