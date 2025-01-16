#include <iostream>
using namespace std;
#include<map>
#include<list>

class Aliment
{
private:
	string nume;
	float pret;

public:
	Aliment()
	{
		this->nume = "Aliment";
		this->pret = 0;
	}

	Aliment(string nume, float pret)
	{
		this->nume = nume;
		this->pret = pret;
	}

	Aliment(const Aliment& a)
	{
		this->nume = a.nume;
		this->pret = a.pret;

	}

	void  afisareDescriere()
	{
		cout << nume << "=>" << pret << endl;
	}



};


int main()
{
	//pair este tot o clasa
	map<string, float> preturi;
	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("Paine", 7));
	preturi.insert(pair<string, float>("Oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35));
	//ultimul lapte nu va fi adaugat pentru ca deja ezista o valoare Lapte

	preturi["Lapte"] = 67;
	//iteratorul este imbricat in fiecare clasa de containere
	map<string, float> ::iterator it;

	//.end() este sfarsitul intregului obiect!!!

	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end())
	{
		suma += it->second;
		//accesarea unui pointer este cu ->
		it++; //este deja supraincarcat
	}

	it = preturi.begin();
	while (it != preturi.end())
	{
		cout << it->first << " => " << it->second << endl;
		it++;
	}

	cout << "Suma: " << suma << endl;


	list<Aliment> alimente;
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("Lapte",20));
	alimente.push_front(Aliment("Paine",10));
	alimente.push_front(Aliment("Oua",16));
	cout << "Lista: "<< endl;

	list<Aliment>::iterator iter = alimente.begin();
	while (iter != alimente.end())
	{
		iter->afisareDescriere();
		iter++;
	}


	return 1;
}