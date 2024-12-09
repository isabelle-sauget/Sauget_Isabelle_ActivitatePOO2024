#include <iostream> 
using namespace std;



//clasa care mosteneste 2 clase de baza mai jos, dupa Ghiveci si dupa Seminte
//clasa KitGradinarit cu relatii de "has a"
//vectori de obiecte


class KitGradinarit
{
private:
	Ghiveci *ghiveci; //vector de obiecte de tip Ghiveci
	Fertilizant fzant; //un singur obiect Fertilizant
	Seminte **pachet; //vector de pointeri la obiecte de tip Seminte
	float pret;
public:
	KitGradinarit()
	{
		this->ghiveci = new Ghiveci[2];
		this->pachet = new Seminte*[2];
		for (int i = 0; i < 3; i++)
		{
			pachet[i] = new Seminte();
		}
		this->pret = 29.99;

	}

	KitGradinarit(const KitGradinarit& k)
	{
		this->ghiveci = new Ghiveci[2];
		for (int i = 0; i < 2; i++)
		{
			this->ghiveci[i] = k.ghiveci[i];
		}
		this->fzant = k.fzant;
		this->pachet = new Seminte * [2];
		for (int i = 0; i < 2; i++)
		{
			this->pachet[i] = new Seminte(*k.pachet[i]);
		}
		this->pret = k.pret;
	}


	~KitGradinarit()
	{
		delete[] this->ghiveci;
		for (int i = 0; i < 2; i++)
		{
			delete this->pachet[i];
		}
		delete[]pachet;

	}

	Ghiveci& getGhiveci(int index) const
	{
		if (index >= 0 && index < 2)
		{
			return this->ghiveci[index];
		}
	}

	void setGhiveci(const Ghiveci* ghiveciNou)
	{
		
		if (this->ghiveci)
		{
			delete[] this->ghiveci;
		}
		this->ghiveci = new Ghiveci[2];
		for (int i = 0; i < 2; i++)
		{
			this->ghiveci[i] = ghiveciNou[i];
		}
	}

	const Seminte& getPachet(int index)
	{
		if (index >= 0 && index < 2)
		{
			return *(this->pachet[index]);
		}
	}

	void setPachet(const Seminte** pachetnou)
	{
		for (int i = 0; i < 2; i++)
		{
			if (this->pachet[i])
			{
				delete[]this->pachet[i];
			}
			delete[]this->pachet;
		}
	}
	

	//k1++;
	//++k1;
	KitGradinarit& operator++()
	{
		Ghiveci* aux1 = new Ghiveci[3];
		for (int i = 0; i < 2; i++)
		{
			aux1[i] = this->ghiveci[i];
		}
		aux1[2] = Ghiveci();

		delete[]this -> ghiveci;
		this->ghiveci = aux1;

		Seminte** aux2 = new Seminte * [3];
		for(int i = 0; i < 2; i++)
		{
			aux2[i] = this->pachet[i];
		}
		aux2[2] = new Seminte();

		for (int i = 0; i < 2; i++)
		{
			delete[]this->pachet[i];
		}
		delete[]this->pachet;

		this->pachet = aux2;
		return *this;

	}


	//k1++;
	KitGradinarit& operator++()
	{
		KitGradinarit temp = *this;
		++(*this);
		return temp;
		//returnam copia veche
	}

	
	friend ostream& operator<<(ostream& o, const KitGradinarit& k)
	{
		/*Ghiveci* ghiveci; //vector de obiecte de tip Ghiveci
		Fertilizant fzant; //un singur obiect Fertilizant
		Seminte** pachet; //vector de pointeri la obiecte de tip Seminte
		float pret;*/

		o << "Ghivecele sunt: "<< endl;
		if (k.ghiveci)
		{
			for (int i = 0; i < 2; i++)
			{
				o << k.ghiveci[i] << ", ";
			}
			cout << endl;
		}
		o << "Fertilizantul este :" << k.fzant << endl;

		//afisare pentru un vector de pointeri
		o << "Semintele sunt: " << endl;
		if (k.pachet)
		{
			for (int i = 0; i < 2; i++)
			{
				if (k.pachet[i])
				{
					o << *(k.pachet[i]);
				}
			}
		}

	
		o << "Pretul este: " << k.pret << endl;


	}




};




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

	Ghiveci(string material, bool cilindric, int Volum) :
		volum(Volum)
	{
		this->material = material;
		this->esteCilindric = cilindric;
	}

	Ghiveci(string Material, int Volum) :
		volum(Volum)
	{
		this->material = Material;
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
		cout << "Este cilindric? (1-DA, 0-NU): ";
		input >> g.esteCilindric;
		cout << "Culoarea: ";
		input >> g.culoare;
		
		return input;
	}

	// (g1 < g2? cout<<" G2 este clindric.":cout<<" G2 nu este cilindric.");
	bool operator<(const Ghiveci& g) const
	{
		return this->esteCilindric < g.esteCilindric;
	}

	// !g1
	bool operator!() const
	{
		return !esteCilindric;
	}


	Ghiveci& operator=(const Ghiveci& g)
	{
		if (this != &g)
		{

			/*string material;
			bool esteCilindric;
			static string culoare;
			const int volum;*/

			this->material = g.material;
			this->esteCilindric = g.esteCilindric;
		}
		return *this;
	}



};


class Fertilizant {

protected:
	bool esteOrganic;
private:
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
		anulExpirarii(expirare)
	{
		this->esteOrganic = organic;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = i + i * 3;
		}
	}


	/*Fertilizant(bool organic, int expirare, int Pret) :
		anulExpirarii(2026)
	{
		this->esteOrganic = false;
		this->pret = new int[3];
		for (int i = 0; i < 3; i++)
		{
			this->pret[i] = i + 3;
		}
	}*/

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
		if (cpnoua > 0)
		{
			concentratiePotasiu = cpnoua;
		}
		else
		{
			throw "Concentratia de potasiu nu poate fi negativa.";
		}
	}


	const void AfisareF()
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

	int* getPret()
	{
		/*for (int i = 0; i < 3; i++)
		{
			return this->pret[i];
		}*/

		return this->pret;
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

	//pret mediu
	int operator()() //primeste *this
	{
		int s = 0;
		for (int i = 0; i < 3; i++)
		{
			s += this->pret[i];
		}
		return s / 3;
	}


	//f3=f1+f2;
	//concatenam vectorul pret din f1 cu vectorul pret din f2
	Fertilizant operator+(Fertilizant f) const //a.i nu modifica *this
	{
		//f3, adica rezultatul, il vom stoca in temp
		Fertilizant temp = *this; //de ce ne trebuie temp si aux??
		int* aux = new int[6];
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
		temp.pret[3] = pret;
		//indexul trebuie incrementat daca este un atribut
		return temp;

	}

	//f2 += f1;
	Fertilizant& operator+=(Fertilizant f)
	{
		*this = *this + f;
		return *this;
	}

	explicit operator bool()
	{
		return this->esteOrganic;
	}

	friend ostream& operator<<(ostream& o, Fertilizant f)
	{
		/*bool esteOrganic;
		static float concentratiePotasiu;
		const int anulExpirarii;
		int* pret;*/

		o << "Este organic? " << (f.esteOrganic ? "DA" : "NU") << endl;
		o << "Concentratie potasiu: " << Fertilizant::concentratiePotasiu << endl;
		o << "Anul expirarii: " << f.anulExpirarii <<endl;
		if (f.pret)
		{
			for (int i = 0; i < 3; i++)
				o << f.pret[i] << ", ";
		}
		o << endl;
		return o;
	}

};


//clasa care mosteneste clasa Fertilizant, FertilizantLichid este un Fertilizant
class FertilizantLichid : public Fertilizant
{
private:
	int vascozitate;
	string culoare;

public:
	FertilizantLichid(): Fertilizant()
	{
		this->vascozitate = 3;
		this->culoare = "transparent";
	}

	FertilizantLichid(int vasc, string cul) : Fertilizant(1, 2029)
	{
		this->vascozitate = vasc;
		this->culoare = cul;
	}

	FertilizantLichid(const FertilizantLichid& fl) :
		Fertilizant(fl)
	{
		this->vascozitate = fl.vascozitate;
		this->culoare = fl.culoare;
	}

	FertilizantLichid operator=(const FertilizantLichid& fl)
	{
		if (&fl != this)
		{
			(Fertilizant)*this = (Fertilizant)fl; //upcasting la clasa de baza
			this->vascozitate = fl.vascozitate;
			this->culoare = fl.culoare;
		}
		return *this;
	}

	string getCuloare()
	{
		return this->culoare;
	}

	bool getOrganic()
	{
		return this->esteOrganic; //atribut protected din clasa de baza
	}

	friend ostream& operator<<(ostream& o, const FertilizantLichid& fl)
	{
		o << (Fertilizant)fl << endl;
		o << "Vascozitate: " << fl.vascozitate << endl;
		o << "Culoarea: " << fl.culoare << endl;

		return o;
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
		timpPanaLaRasadire(rasadire)
	{
		this->speciePlanta = specie;
		this->dimensiune = new float(0.4f);
	}

	Seminte(string specie, int rasadire, float dimens) :
		timpPanaLaRasadire(rasadire)
	{
		this->speciePlanta = specie;
		this->dimensiune = new float(dimens);
	}

	Seminte(const Seminte& s) :
		timpPanaLaRasadire(s.timpPanaLaRasadire)
	{
		this->speciePlanta = s.speciePlanta;
		this->dimensiune = new float(*(s.dimensiune));
	}


	~Seminte()
	{
		if (this->dimensiune)
			delete this->dimensiune;
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
		if (index >= 0 && index < 1) //index =0;
		{
			return this->dimensiune[index];
		}

		else
		{
			throw "INDEX INAFARA LIMITELOR";
		}
	}

	explicit operator string()
	{
		return this->speciePlanta;
	}


	//s1= s2 + 2;

	Seminte operator+(float dimensiune)
	{
		Seminte temp = *this;
		if (temp.dimensiune != NULL)
		{
			delete[]temp.dimensiune;
		}
		temp.dimensiune = new float[2];
		temp.dimensiune[0] = this->dimensiune[0];
		temp.dimensiune[1] = dimensiune;

		return temp;
	}


	// s1 = s2 - 2;
	Seminte operator-(float dimensiune)
	{
		Seminte temp = *this; //copie a obiectului curent
		if (temp.dimensiune != NULL)
		{
			delete temp.dimensiune;
		}
		temp.dimensiune = new float(this->dimensiune[0] - dimensiune);
		return temp;
	}
	

	//s1= s2 - s3;
	Seminte operator-(const Seminte &s)
	{
		Seminte temp = *this; //copie a obiectului curent
		if (temp.dimensiune != NULL)
		{
			delete temp.dimensiune;
		}
		temp.dimensiune = new float(this->dimensiune[0] - s.dimensiune[0]);
		return temp;
	}

	//s1 -= s2;
	Seminte& operator-=(const Seminte &s)
	{
		*this = *this - s;
		return *this;
	}

	/*string speciePlanta;
	static int cantitate;
	const int timpPanaLaRasadire;
	float* dimensiune;*/

 // s1 = s3;
	Seminte operator=(const Seminte &s)
	{
		if (&s != this)
		{
			this->speciePlanta = s.speciePlanta;
			if (this->dimensiune != NULL)
			{
				delete this->dimensiune;
			}
			this->dimensiune = new float(s.dimensiune[0]);
		}
		return *this;
	}

	//returns a Seminte object
	//++s1;
	Seminte operator++()
	{
		this->dimensiune[0] = this->dimensiune[0] + 1;
		return *this;
	}


	//s1++;
	Seminte operator++(int) //int este fictiv si doar ajuta compilatorul sa diferentieze cei doi operatori intre ei
	{
		Seminte aux = *this;
		this->dimensiune[0] = this->dimensiune[0] + 1;
		return aux;
	}


	friend ostream& operator<<(ostream& o, Seminte s)
	{
		o << s.speciePlanta << endl;
		o << Seminte::cantitate << endl;
		o << s.timpPanaLaRasadire << endl;
		if (s.dimensiune)
		{
			o << *(s.dimensiune) << endl; //un singur pointer
		}

		return o;
	}



};


class PachetPromotional : public Ghiveci, public Seminte
{
private:
	float* reducere;
	int varianteReducere; //count ul reducerilor
public:

	PachetPromotional() : Ghiveci(), Seminte()
	{
		this->varianteReducere = 3;
		this->reducere = new float[varianteReducere];
		for (int i = 0; i < varianteReducere; i++)
		{
			this->reducere[i] = 0.15f + (float)i / 5;
		}
	}

	PachetPromotional(const PachetPromotional& p) :
		Ghiveci(p), Seminte(p)
	{
		this->varianteReducere = p.varianteReducere;
		if (this->reducere)
		{
			delete[] this->reducere;
		}
		this->reducere = new float[p.varianteReducere];
		for (int i = 0; i < p.varianteReducere; i++)
		{
			this->reducere[i] = p.reducere[i];
		}

	}

	~PachetPromotional()
	{
		delete[] this->reducere;
	}

	PachetPromotional operator=(const PachetPromotional& p)
	{
		if (&p != this)
		{
			(Ghiveci)*this = (Ghiveci)p;
			(Seminte)*this = (Seminte)p;
			if (this->reducere)
			{
				delete[] this->reducere;
			}
			this->reducere = new float[p.varianteReducere];
			for (int i = 0; i < p.varianteReducere; i++)
			{
				this->reducere[i] = p.reducere[i];
			}

		}
		return *this;
	}

	void setReducere(float* reducere, int varianteReducere)
	{
		this->varianteReducere = varianteReducere;
		if (this->reducere)
		{
			delete[] this->reducere;
		}
		this->reducere = new float[varianteReducere];
		for (int i = 0; i < varianteReducere; i++)
		{
			this->reducere[i] = reducere[i];
		}
	}

	friend istream& operator>>(istream& in, PachetPromotional& p)
	{
		in >> static_cast<Ghiveci&>(p);
		//nu am implementat operatorul>> pentru clasa Seminte
		cout << "Cate variante de reducere?" << endl;
		in >> p.varianteReducere;
		cout << "Reducerile: " << endl;
		for (int i = 0; i < p.varianteReducere; i++)
		{
			cout << "Reducerea " << i + 1 << ": ";
			in >> p.reducere[i];
			cout << endl;
		}

		return in;

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
	(f1.potrivitPentruOrhidei() ? cout << "Este potrivit pentru orhidei." << endl : cout << "Nu este potrivit pentru orhidei." << endl);

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


	Fertilizant f3(true,2030);
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
	f1 = 20 + f2;
	s1 = s2;
	s1 -= s2;
	s2 = s3 - 1;
	s2 = s1 - s3;

	try
	{
		cout << s1[-4] << endl;

	}
	catch(const char* exceptie) {
		cout << exceptie << endl;
	}

	(g1 < g2 ? cout << " G2 este clindric." : cout << " G2 nu este cilindric.");
	
	cout << endl;
	if (!g1)
		cout << " G1 nu este cilindric." << endl;


	//operator functie
	cout << f1() << endl;

	
	string speciePlanta = (string)s1;
	bool esteOrganic = (bool)f1;

	cout << g1;
	cin >> g2;



	PachetPromotional pachet1;
	FertilizantLichid fl1;

	//upcasting

	cout << (Ghiveci)pachet1 << endl;
	cout << (Seminte)pachet1 << endl;

	cout << (Fertilizant)fl1;

	return 0;
}
