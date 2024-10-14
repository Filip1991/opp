#include<iostream>
//#include<string.h>
using namespace std;

class Student {
private:
	//atribute
	string nume;
	char* facultate;
	//char nume2[50]; variabila statica val in C
	char serie;
	int anStudiu;
	int nrNote;
	int* note;//vector alocat dinamic




public: 
	//metode
	
	//metode tip constructor
	Student(string nume, char* facultate, char serie, int anStudiu, int nrNote, int* note) {
		//pointer this, this->adresa obj apelator
		this->nume=nume;
		this->serie = serie;
		this->anStudiu = anStudiu;
		if (facultate != nullptr) {
			this->facultate = new char[strlen(facultate) + 1];
			strcpy_s(this->facultate, strlen(facultate) + 1, facultate);
		}
		else {
			this->facultate = nullptr;
		}

		if (note != nullptr && nrNote > 0) {
			this->nrNote = nrNote;
			//this->note=note; shallow copy
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = note[i];
		}

	}
	//metode tip accesor (get si set)

	int getAnStudiu() {
		return anStudiu;
	}

	void setAnStudiu(int anStudiuNou) {  //anStudiuNou=>ce setam noi
		if (anStudiuNou >= 1 && anStudiuNou <= 5) {
			anStudiu = anStudiuNou;
		}
		else {
			cout << "\nAn studiu nu este conform";
		}

	}

	void setFacultate(const char* facultateNoua) {
		if (facultateNoua != nullptr && strlen(facultateNoua) >= 3) {
			if (facultate != nullptr) {
				delete[]facultate;
				facultate = nullptr;
			}
			facultate = new char[strlen(facultateNoua) + 1];
			strcpy_s(facultate, strlen(facultateNoua) + 1, facultateNoua);
		}

	}

	const char* getFacultate() {
		return facultate;
	}

	/*	 char* getFacultate2() {
		 char* copieFacultate = nullptr;
		 if (facultate != nullptr) {
			 copieFacultate = new char[strlen(facultate) + 1];
			 strcpy_s(copieFacultate, strlen(facultate) + 1, facultate);
				
		 }
		return copieFacultate;
	}
	*/
};




int main() {

	Student s;
	cout<< s.getAnStudiu();//s e obj apelator
	s.setAnStudiu(3);
	cout << endl << s.getAnStudiu();
    s.setFacultate("CSIE"); //eroare fara const la setter
	char facultate[] = "FABIZ";
	s.setFacultate(facultate);
	//cout <<endl<< s.getFacultate();
//	s.getFacultate()[0] = 'M';
	cout << endl << s.getFacultate();

	//cout << endl << s.getFacultate2();//memory leaks
	//remediere
	//char* facultateCopie = s.getFacultate2();
//	delete[] facultateCopie;
//	facultateCopie = nullptr;

	return 0;

}

