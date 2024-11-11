#include<iostream>

//clasas cu atribute alocate dinamic => obligatoriu constr de copiere, operator egal si destructor

using namespace std;

class Cofetarie {
private:
	string nume;
	int nrAngajati;
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}


	// Cofetarie c3;
	// c3 = c2;
	// este sau nu obiectul deja in *this?
	Cofetarie operator=(const Cofetarie& c)
	{
		if (&c != this)// evitarea auto-atribuirii
		{
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++)
			{
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	//Cofetarie c3= c1+ c2;
	Cofetarie operator+(Cofetarie c) const //declarare metoda ca si const 
		                                   // => metoda nu poate modifica obiectul din *this 
	{
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++)
		{
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}


	// c4+=c2;
	Cofetarie& operator+=(Cofetarie c)
	//Cofetarie& pentru ca lucram direct pe obiect
	//si nu pe o copie a sa
	{
		*this = *this + c;
		return* this;
	}

	//adauga un nou salariu la lista de salarii
	//Cofetarie c4= c2+ 20;
	Cofetarie operator+(float salariu) const
	{   //de ce e const???
		Cofetarie temp = *this;
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	//Cofetarie c4= 20 + c2;
	friend Cofetarie operator+(float salariu, Cofetarie c)
	{
		Cofetarie temp = c;
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++)
		{
			temp.salarii[temp.nrAngajati] = salariu;
			temp.nrAngajati++; //de ce??
			return temp;
		}
	}

	// int nrAngajati = (int)c2; CAST

	friend ostream& operator<<(ostream& output, Cofetarie c)
	{
		output << "Nume: " << c.nume << endl;
		output << "Nr. angajati" << c.nrAngajati << endl;
		if (c.salarii != NULL)
		{
			for (int i = 0; i < c.nrAngajati; i++)
			{
				cout << c.salarii[i] << " ";
			}
		}
		
		output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
		output << "An deschidere:" << c.anDeschidere << endl;
		output << "Adaos:" << c.adaos << endl;
		output << "TVA:" << Cofetarie::TVA << endl;

		return output;
	}


	friend istream& operator>>(istream& input, Cofetarie& c)
	{// neaparat transmis prin referinta!
		cout << "Nume: ";
		input >> c.nume;
		cout << "Nr angajati: ";
		input >> c.nrAngajati;

		if (c.salarii != NULL)
		{
			delete[]c.salarii;
		}

		if (c.nrAngajati > 0) //validare pentru a aloca spatiu
		{
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++)
			{
				cout << "Salariul " << i + 1 << ":";
				input >> c.salarii[i];
			}
		}
		else
		{
			c.salarii = NULL; //altfel nu alocam spatiu
		}

		cout << "Are produse vegane in compozitie? 1-Da, 0-Nu" << endl;
		input >> c.esteVegana;
		cout << "Adaos comercial: ";
		input >> c.adaos;

		return input;
	}


};

	int main() {
		Cofetarie c;
		cout << c.getNume() << endl;
		c.setNume("");
		cout << c.getNume() << endl;
		c.setNume("Alt nume");
		cout << c.getNume() << endl;
		c.setNrAngajati(4, new float[4] {2, 6, 4, 9});

		Cofetarie c2("Minimal", 3, false, 2020, 10);


		//Cofetarie c3 = c2;
		Cofetarie c3;
		c3 = c2;

		Cofetarie c4 = c2 + 20;
		c4.afisare();

		c4 += c2;
		c4.afisare();


		cout << c2; //ostream << cofetarie
		cin >> c2;


		int nrAngajati = (int)c2;
		float salariuTotal = (float)c2;

		if (c < c2) //returns true or false (condition)
		{
			//c1.operator<(c2);
			cout << "C1 este mai mic decat C2";
		}

		try {
			cout << c2[1] << endl;
			cout << c2[-6] << endl;
			cout << c2[1] << endl; //daca avem exceptie nu mai executa si asta 
		}
		catch (int exceptie)
		{

		}
		catch (float exceptie)
		{

		}
		catch (const char* exceptie)
		{
			cout << endl << exceptie << endl;
		}
		catch (...) //capteaza orice
		{

		}

		//in interiorul clasei avem vector, obligatoriu prin metoda
		//cout << c2.getSalariu(1);

		c2[1] = 2000;
		cout << c2[1] << endl;

		return 0;

	}
