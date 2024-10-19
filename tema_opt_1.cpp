//
//
//#include <iostream>
//using namespace std;
//
//struct Bloc
//{
//	string strada;
//	int nrEtaje;
//	int nrAp;
//	int anConstructie;
//	bool areRiscSeismic;
//};
//
//
//void citireBloc(Bloc& bloc)
//{
//	cout << "Introduceti strada: ";
//	cin >> bloc.strada;
//
//	cout << "Introduceti numarul de etaje: ";
//	cin >> bloc.nrEtaje;
//
//	cout << "Introduceti numarul de apartamente: ";
//	cin >> bloc.nrAp;
//
//	cout << "Introduceti anul constructiei: ";
//	cin >> bloc.anConstructie;
//
//	cout << "Are risc seismic? (1/0) ";
//	cin >> bloc.areRiscSeismic;
//
//}
//
//
//void afisareBloc(const Bloc& bloc)
//{
//	cout << "Blocul de pe strada " << bloc.strada
//		<< " are " << bloc.nrEtaje << " etaje, "
//		<< bloc.nrAp << " apartamente, "
//		<< "a fost construit in anul " << bloc.anConstructie
//		<< " si" << (bloc.areRiscSeismic ? " are risc seismic" : " nu are risc seismic") << "." << endl;
//
//}
//
//int main()
//{
//	const int nrBlocuri = 1;
//	Bloc* Blocuri[nrBlocuri];
//
//	for (int i = 0; i < nrBlocuri; ++i)
//	{
//		Blocuri[i] = new Bloc();
//		cout << "Blocul " << i + 1 << ":\n";
//
//		citireBloc(*Blocuri[i]);
//		cout << endl;
//	}
//
//	for (int i = 0; i < nrBlocuri; ++i)
//	{
//		afisareBloc(*Blocuri[i]);
//		cout << endl;
//	}
//
//
//	for (int i = 0; i < nrBlocuri; ++i)
//	{
//		delete Blocuri[i];
//	}
//
//
//	return 0;
//}