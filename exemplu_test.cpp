//#include <iostream>
//using namespace std;
//
//
//class Prajitura
//{
//private:
//	char* denumire;
//	int nrCalorii;
//	int nrIngrediente;
//	float* gramajIngrediente;
//	bool esteVegana;
//	static string aroma;
//	bool cuNuci;
//
//public:
//
//	Prajitura()
//	{
//		this->denumire = new char[strlen("Boema" + 1)];
//		strcpy_s(this->denumire, strlen("Boema" + 1), "Boema");
//		this->nrCalorii = 200;
//		this->nrIngrediente = 4;
//		this->gramajIngrediente = new float[this->nrIngrediente];
//		for (int i = 0; i < this->nrIngrediente; i++)
//		{
//			this->gramajIngrediente[i] = i + 3;
//		}
//		
//		this->esteVegana = 1;
//		this->cuNuci = 0;
//	}
//
//
//	/*Prajitura(char* denumire, int nrCalorii, int nrIngrediente, float* gramajIngrediente, bool esteVegana, bool cuNuci)
//	{
//		if (this->denumire != NULL)
//		{
//			delete[]this->denumire;
//		}
//		this->denumire = new char(strlen("Amandina" + 1));
//		strcpy_s(this->denumire, strlen("Amandina" + 1), "Amandina");
//		this->nrCalorii = nrCalorii;
//		this->nrIngrediente = nrIngrediente;
//		//if( )...
//	}*/
//
//	~Prajitura()
//	{
//		if (this->denumire)
//		{
//			delete[]this->denumire;
//		}
//		if (this->gramajIngrediente)
//		{
//			delete[]this->gramajIngrediente;
//		}
//	}
//
//	char* getDenumire()
//	{
//		return this->denumire;
//	}
//
//	void setDenumire(char* nouaDenumire)
//	{
//		if (this->denumire != NULL)
//		{
//			delete[]this->denumire;
//		}
//		this->denumire = new char[strlen(nouaDenumire) + 1];
//		strcpy_s(this->denumire, strlen(nouaDenumire) + 1, nouaDenumire);
//	}
//
//	int getNrCalorii()
//	{
//		return this->nrCalorii;
//	}
//
//	void setNrCalorii(int Nou)
//	{
//		this->nrCalorii = Nou;
//	}
//
//	int getNrIngrediente()
//	{
//		return this->nrIngrediente;
//
//	}
//
//	void setNrIngrediente(int Nou, float* gramajIngredienteNou)
//	{
//		if (Nou > 1)
//		{
//			this->nrIngrediente = Nou;
//			if (this->gramajIngrediente != NULL)
//			{
//				delete[]this->gramajIngrediente;
//			}
//			this->gramajIngrediente = new float[this->nrIngrediente];
//			for (int i = 0; i < this->nrIngrediente; i++)
//			{
//				this->gramajIngrediente[i] = gramajIngredienteNou[i];
//			}
//		}
//		else {
//			throw "Prea putine ingrediente. ";
//		}
//	}
//
//
//	//p1= p2 * 2;
//	Prajitura operator*(int numar)
//	{
//		Prajitura temp = *this;
//		if (temp.gramajIngrediente != NULL)
//		{
//			delete[]temp.gramajIngrediente;
//		}
//		temp.gramajIngrediente = new float[this->nrIngrediente];
//		for (int i = 0; i < this->nrIngrediente; i++)
//		{
//			temp.gramajIngrediente[i] = this->gramajIngrediente[i] * numar;
//		}
//		return temp;
//	}
//
//
//};
//
//string Prajitura::aroma = "ciocolata";
//
//int main()
//{
//
//	Prajitura p1;
//	Prajitura p2;
//
//	p1 = p2 * 2;
//
//	return 0;
//}