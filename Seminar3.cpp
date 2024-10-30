#include <iostream>
using namespace std;



class Cofetarie {

private:
	string nume;//
	int nrAngajati;//
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA; //daca va trebui modificat ,vom avea acelasi spatiu de memorie rezervat pentru acesta 

public:
	Cofetarie(): 
	
		adaos(30),
		anDeschidere(2024)
	
	{
		
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
		
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :

		anDeschidere(an)
	
	{

		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		

	}

	string getNume()
	{
		return this->nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 2)
		{
			this->nume = nume;
		}
	}


	void Afisare()//primeste pointerul this, nu are nevoie de parametru
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Numar de anagajati: " << this->nrAngajati << endl;
		cout << "Este vegana? " << this->esteVegana << endl;
		////////cout << "Anul deschiderii: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << Cofetarie::TVA << endl;
	}


	static void modificaTVA(int noulTVA)// functia statica nu primeste this->, folosit doar in metode
	{
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}

	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
		{
			suma += vector[i].nrAngajati;
		}
		return suma;
	}


	Cofetarie operator=(const Cofetarie& c)
	{

	}

};

int Cofetarie::TVA = 9;

int main()
{
	//Cofetarie c1;
	//c1.Afisare();

	//Cofetarie::modificaTVA(19);

	//Cofetarie c2("Dolce Vita", 6,1,2019,10);
	//c2.Afisare();

	//Cofetarie* pointer;
	//pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
	////(*pointer).Afisare(); dereferentiere + accesare
	//pointer->Afisare();

	//delete pointer;

	//int nrCofetarii = 3;
	//Cofetarie* vector;
	//vector = new Cofetarie[nrCofetarii]; //declarare bloc de memorie cu paranteze patrate,
	//                                     //nu un singur obiect 
	////[] indexul -deplasare + dereferentiere 
	//for (int i = 0; i < nrCofetarii; i++)
	//{
	//	vector[i].Afisare();
	//}

	//cout << "Numar total angajati: " << Cofetarie::calculeazaNrTotalAngajati(nrCofetarii, vector);

	//delete[] vector;


	Cofetarie c;

	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;









	return 0;
}