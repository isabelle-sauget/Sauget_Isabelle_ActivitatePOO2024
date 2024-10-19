#include <iostream> 
using namespace std;


//3 obiecte apartinand aceluiasi domeniu
//cate 3 clase cu atribute normale, statice si constante
//atribute definite in zona publica a clasei
//in fiecare clasa -> cel putin un pointer pentru care vom aloca spatiu in HEAP
//cate trei constructori pentru fiecare clasa cu numar diferit de parametri
//in cadrul constructorilor initializati toate atributele claselor
//in fiecare clasa cate o functie statica 
//

string Ghiveci::culoare = "maro";
float Fertilizant::concentratiePotasiu = 2.4f;
int Seminte::cantitate = 100;

//Gradinarit

class Ghiveci {

public:
	string material;
	bool esteCilindric;
	static string culoare;
	const int volum;

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


	void AfisareG()
	{
		cout << "Materialul: " << this->material << endl;
		cout << "Este ghiveciul cilindric?( 1-DA, 0-NU): " << this->esteCilindric << endl;
		cout << "Culoarea: " << Ghiveci::culoare << endl; //static
		cout << "Volum ghiveci( in litri): " << this->volum << endl;
	}

	static void modificaCuloare(string nouaCuloare)
	{
		if (nouaCuloare != "")
			Ghiveci::culoare = nouaCuloare;
		cout << "Rezultatul modificarii culorii: " << endl;
		Ghiveci::AfisareG();
	}

};


class Fertilizant {

public:
	bool esteOrganic;
	static float concentratiePotasiu;
	const int anulExpirarii;
	int pret;

	Fertilizant() :
		anulExpirarii(2027)
	{
		this->esteOrganic = true;

	}

	Fertilizant(bool organic, int expirare) :
		anulExpirarii(2025)
	{
		this->esteOrganic = false;
		this->pret = 20;
	}

	Fertilizant(bool organic, int expirare, int Pret) :
		anulExpirarii(2026)
	{
		this->esteOrganic = false;
		this->pret = 35;
	}


	void AfisareF()
	{
		cout << "Este fertilizantul organic?: " << this->esteOrganic << endl;
		cout << "Care este concentratia de sodiu?( in %): " << Fertilizant::concentratieSodiu << endl;
		cout << "Cand expira?: " << this->anulExpirarii << endl;
		cout << "Pret: " << this->pret << endl;
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

};

class Seminte {

public:
	string speciePlanta;
	static int cantitate;
	const int timpPanaLaRasadire;
	float dimensiune;

	Seminte() :
		timpPanaLaRasadire(15)
	{
		this->speciePlanta = "anthurium";

	}

	Seminte(string specie, int rasadire) :
		timpPanaLaRasadire(7)
	{
		this->speciePlanta = "monstera";
		this->dimensiune = 0.4f;
	}

	Seminte(string specie, int rasadire, float dimens) :
		timpPanaLaRasadire(7)
	{
		this->speciePlanta = "syngonium";
		this->dimensiune = 0.9f;
	}

	AfisareS()
	{
		cout << "Specia plantei: " << this->speciePlanta << endl;
		cout << "Cantitate pachet( cate seminte contine un pliculet): " << Seminte::cantitate << endl;
		cout << "Timp pana rasade( in zile): " << this->timpPanaLaRasadire << endl;
		cout << "Dimensiune seminte( in milimetri): " << this->dimensiune << endl;

	}

	static int catePliculete(int nrSeminteCeruteSpreVanzare)
	{
		return nrseminteCeruteSpreVanzare / Seminte::cantitate;
	}

};



int main()
{
	int nrseminteCeruteSpreVanzare = 600;

	Ghiveci* pointerG;
	pointerG = new Ghiveci("lemn", false, 4);
	pointerG->AfisareG;

	Fertilizant* pointerF;
	pointerF = new Fertilizant(true, 2028);
	pointerF->AfisareF;

	Seminte* pointerS;
	pointerS = new Seminte("scadens micans", 20, 0.2);
	pointerS->AfisareS;

	delete pointerG;
	delete pointerF;
	delete pointerS;


	Ghiveci g1;
	g1.AfisareG();
	g1.modificaCuloare("alb");

	Fertilizant f1;
	f1.AfisareF();
	(f1.potrivitPentruOrhidei() ? cout << " Este potrivit pentru orhidei." : cout << "Nu este potrivit pentru orhidei.")

		Seminte s1;
	s1.AfisareS();
	//s1.catePliculete()




	return 0;
}
