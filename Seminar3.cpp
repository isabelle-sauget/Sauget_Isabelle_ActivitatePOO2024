#include <iostream>
using namespace std;



class Cofetarie {

private:
	string nume;
	int nrAngajati;
	float* salarii;
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
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
		
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :

		anDeschidere(an)
	
	{

		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
		{
			this->salarii[i] = 1000 + 100 * i;
		}
		

	}

	Cofetarie(const Cofetarie& c): anDeschidere(c.anDeschidere)
	{
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++)
		{
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}


	~Cofetarie() {

		//se sterge ce alocam in heap!
		if (this->salarii != NULL)
		{
			delete[]this->salarii;

		}

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

	int getNrAngajati()
	{
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float *salarii)
	{
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;

			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++)
			{
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii()
	{
		return this->salarii;
	}

	float getSalariu(int index)
	{
		if (index >= 0 && index < this->nrAngajati)
		{
			return this->salarii[index];
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

	

};

void f(Cofetarie c) {

}

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
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;
	c.setNrAngajati(4, new float[4] {2, 6, 4, 9});// de ce nu e recomandata initializarea inline?

	Cofetarie c2("Minimal", 3, false, 2020, 10);
	cout << c2.getSalarii()[1] << endl;
	cout << c2.getSalariu(1) << endl;


	c.setNrAngajati(5, new float[5] {1,2,3,4,5});
	cout << c2.getSalariu(4);


	//apelare constructor de copiere

	Cofetarie c3(c2);
	Cofetarie c4 = c2;

	f(c4); //daca punem breakpoint observam ca este intai si intai apelat de constructorul de copiere



	return 0;
}