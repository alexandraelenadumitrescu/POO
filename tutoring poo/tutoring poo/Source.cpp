#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
class CameraHotel {
	string numarCamera;
	int numarFacilitati;
	float pretPeNoapte;
public:
	string* facilitatiCamera;
	CameraHotel() {
		this->facilitatiCamera = nullptr;
		this->numarCamera = "";
		this->numarFacilitati = 0;
		this->pretPeNoapte = 0;
	}
	float getPretPeNoapte() {
		return this->pretPeNoapte;
	}
	void setPretPeNoapte(float nou) {
		this->pretPeNoapte = nou;
	}
	CameraHotel(string* facilitatiCamera,int numarFacilitati,float pretPeNoapte) {//chiar si val care nu apar ca param se init
		this->numarFacilitati = numarFacilitati;
		this->facilitatiCamera = new string[this->numarFacilitati];
		for (int i = 0;i < this->numarFacilitati;i++) {
			this->facilitatiCamera[i] = facilitatiCamera[i];
		}
		this->numarCamera = "";
		
		this->pretPeNoapte = pretPeNoapte;
	}
	CameraHotel(const CameraHotel& c) {
		this->numarFacilitati = c.numarFacilitati;
		this->facilitatiCamera = new string[this->numarFacilitati];
		for (int i = 0;i < this->numarFacilitati;i++) {
			this->facilitatiCamera[i] = facilitatiCamera[i];
		}
		this->numarCamera = c.numarCamera;
		
		this->pretPeNoapte = c.pretPeNoapte;
	}
	~CameraHotel() {
		delete this->facilitatiCamera[];
		this->facilitatiCamera = nullptr;
	}
};
int main() {
	//cout << "aaa" << endl;
	CameraHotel c;
	cout << c.getPretPeNoapte() << endl;
	c.setPretPeNoapte(150.15);
	cout << c.getPretPeNoapte() << endl;
	string* facilitati = new string[3]{ "wifi","minibar","ac" };
	CameraHotel c1();


	return 0;
}