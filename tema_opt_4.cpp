#include <iostream> 
using namespace std;


//3 obiecte apartinand aceluiasi domeniu
//cate 3 clase cu atribute normale, statice si constante
//atribute definite in zona publica a clasei
//in fiecare clasa -> cel putin un pointer pentru care vom aloca spatiu in HEAP
//cate trei constructori pentru fiecare clasa cu numar diferit de parametri
//in cadrul constructorilor initializati toate atributele claselor
//in fiecare clasa cate o functie statica 
//...



//Gradinarit

class Ghiveci {

private:
	string material;
	bool esteCilindric;
	static string culoare;
	const int volum;

public:

	Ghiveci() :
		volum(5)
	{
		this->material = "terracota";
		this->esteCilindric = false;

	}

	Ghiveci(string Material, bool cilindric, int Volum) :
		volum(2)
	{
		this->material = "plastic";
		this->esteCilindric = true;
	}

	Ghiveci(string Material, int Volum) :
		volum(6)
	{
		this->material = "piatra";
		this->esteCilindric = false;
	}

	Ghiveci(const Ghiveci& g) :volum(g.volum)
	{
		this->material = g.material;
		this->esteCilindric = g.esteCilindric;
	}


	void static AfisareG(const Ghiveci& ghiveci)
	{
		cout << "Materialul: " << ghiveci.culoare << endl;
		cout << "Este ghiveciul cilindric?( 1-DA, 0-NU): " << ghiveci.esteCilindric << endl;
		cout << "Culoarea: " << Ghiveci::culoare << endl; //static
		cout << "Volum ghiveci( in litri): " << ghiveci.volum << endl;
	}

	static void modificaCuloare(string nouaCuloare, const Ghiveci& ghiveci)
	{
		if (nouaCuloare != "")
			Ghiveci::culoare = nouaCuloare;
		cout << "Rezultatul modificarii culorii: " << endl;
		Ghiveci::AfisareG(ghiveci);
	}


	string getMaterial()
	{
		return this->material;
	}

	void setMaterial(string material)
	{
		if (material.length() > 1)
		{
			this->material = material;
		}
	}

	friend ostream& operator<<(ostream& output, Ghiveci g)
	{
		/*string material;
		bool esteCilindric;
		static string culoare;
		const int volum;*/

		output << "Material: " << g.material << endl;
		output << "Este cilindric? 1-DA, 0-NU" << g.esteCilindric << endl;
		output << "Culoarea: " << Ghiveci::culoare << endl;
		output << "Volumul: " << g.volum << endl;

		return output;

	}

	//neaparat transmis prin referinta pentru a putea modifica Ghiveci
	//(date de la tastatura)
	friend istream& operator>>(istream& input, Ghiveci& g)
	{
		cout << "Material: ";
		input >> g.material;
		cout << "Este cilindric? 1-DA, 0-NU";
		input >> g.esteCilindric;
		cout << "Culoarea: ";
		input >> g.culoare;
		cout << "Volumul: ";
		
		return input;
	}

	

};


class Fertilizant {

private:
	bool esteOrganic;
	static float concentratiePotasiu;
	const int anulExpirarii;
	int* pret;

public:

	Fertilizant() :
		anulExpirarii(2027)
	{
		this->esteOrganic = true;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = i + i * 2;
		}

	}

	Fertilizant(bool organic, int expirare) :
		anulExpirarii(2025)
	{
		this->esteOrganic = false;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = i + i * 3;
		}
	}

	Fertilizant(bool organic, int expirare, int Pret) :
		anulExpirarii(2026)
	{
		this->esteOrganic = false;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = i + 3;
		}
	}

	Fertilizant(const Fertilizant& f) :
		anulExpirarii(f.anulExpirarii)
	{
		this->esteOrganic = f.esteOrganic;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = f.pret[i];
		}

	}


	~Fertilizant() {
		if (this->pret)
			delete[]this->pret;
	}

	static float getConcentratiePNoua()
	{
		return concentratiePotasiu;
	}

	static void setConcentratiePNoua(float cpnoua)
	{
		if (concentratiePotasiu > 0)
		{
			concentratiePotasiu = cpnoua;
		}
		else
		{
			cout << "Concentratia de potasiu nu poate fi negativa." << endl;
		}
	}


	void AfisareF()
	{
		cout << "Este fertilizantul organic? ( 1-DA, 0-NU): " << this->esteOrganic << endl;
		cout << "Care este concentratia de sodiu?( in %): " << Fertilizant::concentratiePotasiu << endl;
		cout << "Cand expira?: " << this->anulExpirarii << endl;
		cout << "Pret: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << pret[i] << " ";
		}
	}

	static bool potrivitPentruOrhidei()
	{
		if (Fertilizant::concentratiePotasiu > 2)
		{
			return 1;
		}
		else
			return 0;

	}

	int getPret()
	{
		for (int i = 0; i < 3; i++)
		{
			return this->pret[i];
		}
	}

	void setPret(int* pret)
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = pret[i];
		}
	}

	friend int PretMediu(const Fertilizant& f);


	//f3=f1+f2;
	//concatenam vectorul pret din f1 cu vectorul pret din f2
	Fertilizant operator+(Fertilizant f) const //a.i nu modifica *this
	{
		//f3, adica rezultatul, il vom stoca in temp
		Fertilizant temp = *this; //de ce ne trebuie temp si aux??
		int* aux = new int[3];
		for (int i = 0; i < 3; i++)
		{
			aux[i] = this->pret[i];
		}

		for (int i = 0; i < 3; i++)
		{
			aux[i + 3] = f.pret[i];
		}
		//concatenare de vectori!!!!
		
		temp.pret = aux;
		return temp;
	}
	//cum stim ce e in *this?
	//f1=f2;    e const pentru ca f2 nu il modificam
	Fertilizant operator=(const Fertilizant& f)
	{

		//ce e const si static nu se modifica la operatori

		/*bool esteOrganic;
		static float concentratiePotasiu;
		const int anulExpirarii;
		int* pret;*/

		if (&f != this) //de ce facem verificarea asta?
		{
			this->esteOrganic = f.esteOrganic;
			if (this->pret != NULL)
			{
				delete[]this->pret;
			}
			this->pret = new int[3];
			for (int i = 0; i < 3; i++)
			{
				this->pret[i] = f.pret[i];
			}

		}
		return *this;
	}

	//adaugare pret la vectorul de preturi
	//f2= 20+ f1;

	friend Fertilizant operator+(int pret, const Fertilizant& f)
	{
		//nu mai avem this
		Fertilizant temp = f;
		if (temp.pret != NULL)
		{
			delete[]temp.pret;
		}
		temp.pret = new int[4]; //3+1
		for (int i = 0; i < 3; i++)
		{
			temp.pret[i] = f.pret[i];
		}
		temp.pret[4] = pret;
		//indexul trebuie incrementat daca este un atribut
		return temp;

	}

	//f2 += f1;
	Fertilizant& operator+=(Fertilizant f)
	{
		*this = *this + f;
		return *this;
	}



};

class Seminte {

private:
	string speciePlanta;
	static int cantitate;
	const int timpPanaLaRasadire;
	float* dimensiune;

public:

	Seminte() :
		timpPanaLaRasadire(15)
	{
		this->speciePlanta = "anthurium";
		this->dimensiune = new float(0.1f);

	}

	Seminte(string specie, int rasadire) :
		timpPanaLaRasadire(7)
	{
		this->speciePlanta = "monstera";
		this->dimensiune = new float(0.4f);
	}

	Seminte(string specie, int rasadire, float dimens) :
		timpPanaLaRasadire(7)
	{
		this->speciePlanta = "syngonium";
		this->dimensiune = new float(dimens);
	}

	Seminte(const Seminte& s) :
		timpPanaLaRasadire(s.timpPanaLaRasadire)
	{
		this->speciePlanta = s.speciePlanta;
		this->dimensiune = new float(0.05f);
	}


	~Seminte()
	{
		if (this->dimensiune)
			delete[]this->dimensiune;
	}


	void AfisareS()
	{
		cout << "Specia plantei: " << this->speciePlanta << endl;
		cout << "Cantitate pachet( cate seminte contine un pliculet): " << Seminte::cantitate << endl;
		cout << "Timp pana rasade( in zile): " << this->timpPanaLaRasadire << endl;
		cout << "Dimensiune seminte( in milimetri): " << *dimensiune << endl;

	}



	static int catePliculete1(int nrSeminteCeruteSpreVanzare)
	{
		return nrSeminteCeruteSpreVanzare / Seminte::cantitate;
	}

	friend int catePliculete2(int nrSeminteCeruteSpreVanzare);



	/*string speciePlanta;
	static int cantitate;
	const int timpPanaLaRasadire;
	float* dimensiune;*/


	//cout << s[1];
	float& operator[](int index)
	{
		//am pus un singur element in vector, deci 1
		if (index >= 0 && index < 1)
		{
			return this->dimensiune[index];
		}

		else
		{
			throw "INDEX INAFARA LIMITELOR";
		}
	}





};

int catePliculete2(int nrSeminteCeruteSpreVanzare)
{
	return nrSeminteCeruteSpreVanzare / Seminte::cantitate;
}

string Ghiveci::culoare = "maro";
float Fertilizant::concentratiePotasiu = 2.4f;
int Seminte::cantitate = 100;

int PretMediu(const Fertilizant& f)
{
	int sumaPreturi = 0;
	for (int i = 0; i < 3; i++)
	{
		sumaPreturi += f.pret[i];
	}
	return sumaPreturi / 3;
}


int main()
{
	int nrSeminteCeruteSpreVanzare = 600;

	//cate un pointer la fiecare clasa

	Ghiveci* pointerG;
	pointerG = new Ghiveci("lemn", false, 4);
	pointerG->AfisareG(*pointerG);
	cout << endl;

	Fertilizant* pointerF;
	pointerF = new Fertilizant(true, 2028);
	pointerF->AfisareF();
	cout << endl;

	Seminte* pointerS;
	pointerS = new Seminte("scadens micans", 20, 0.2);
	pointerS->AfisareS();
	cout << endl;

	delete pointerG;
	delete pointerF;
	delete pointerS;

	//exemplu apelare constructor 1 fara parametri

	Ghiveci g1;
	g1.AfisareG(g1);
	cout << endl;
	g1.modificaCuloare("alb", g1);

	Fertilizant f1;
	f1.AfisareF();
	cout << endl;
	(f1.potrivitPentruOrhidei() ? cout << " Este potrivit pentru orhidei." << endl : cout << "Nu este potrivit pentru orhidei." << endl);

	Seminte s1;
	s1.AfisareS();
	cout << endl;
	cout << "Numarul necesar de pliculete pentru " << nrSeminteCeruteSpreVanzare << " seminte este de:  " << s1.catePliculete1(nrSeminteCeruteSpreVanzare) << endl;

	//apelare functie prietena

	cout << " Functie prietena: " << catePliculete2(nrSeminteCeruteSpreVanzare) << endl;

	//exemplu apelare constructor 2 cu 2 parametri

	Ghiveci g2("plastic", 15);
	g2.AfisareG(g2);
	cout << endl;

	Fertilizant f2(false, 2028);
	f2.AfisareF();
	cout << endl;

	Seminte s2("phalaenopsis", 20);
	s2.AfisareS();
	cout << endl;

	//exemplu apelare constructor 3 cu 3 parametri


	Ghiveci g3("rasina", true, 35);
	g3.AfisareG(g3);
	cout << endl;
	cout << "Materialul este: " << g3.getMaterial() << endl;
	g3.setMaterial("portelan");
	cout << "Noul material este: " << g3.getMaterial() << endl;


	Fertilizant f3(true, 2024, 45);
	f3.AfisareF();
	cout << endl;
	cout << "Preturile sunt: " << f3.getPret() << endl;
	int pretNou[3] = { 17,19,34 };
	f3.setPret(pretNou);
	cout << "Preturile noi sunt: " << f3.getPret() << endl;


	Seminte s3("scindapsus pictus", 5, 0.25);
	s3.AfisareS();
	cout << endl;



	f1 = f2 + f3;

	try
	{
		cout << s1[-4] << endl;

	}
	catch(const char* exceptie) {
		cout << exceptie << endl;
	}
	


	return 0;
}
