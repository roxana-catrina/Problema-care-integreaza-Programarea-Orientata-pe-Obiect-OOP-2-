#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <typeinfo>
#include <exception>
using namespace std;
float total;
class produs {
private:
	string nume, cod;
	int nrbucati;
	float pret;
public:
	produs(string nume, string cod, float pret, int nrbuc) {
		this->nume = nume;
		this->cod = cod;
		this->pret = pret;
		this->nrbucati = nrbuc;
	}
	virtual void afisare_produs() {
		cout << "NUME: " << nume << endl;
		cout << "COD: " << cod << endl;
		cout << "PRET: " << pret << endl;
		cout << "NUMAR BUCATI: " << nrbucati << endl;
	}
	virtual string get_culoare() {
		return "necunoscuta";
	}
	string get_cod() {
		return cod;
	}
	float get_pret() {
		return pret;
	}
	int get_nr_bucati() {
		return nrbucati;
	}

	string get_nume() {
		return nume;
	}
	void modificare_bucati(int cumparate) {

		nrbucati = nrbucati - cumparate;

	}
	bool operator==(const produs p) {
		return this->pret == p.pret;
	}
	virtual string get_expirare() {
		return "necunoscut";
	}
	virtual int get_putere() {
		return 0;
	}
	int  getGen() {
		return -1;
	}

};
class produse_alimentare : produs {
private:
	string termen_expirare;
public:
	produse_alimentare(string nume, string cod, float pret, int nrbuc, string termen_expirare) : produs(nume, cod, pret, nrbuc) {
		this->termen_expirare = termen_expirare;
	}
	void afisare_produs()override {
		produs::afisare_produs();
		cout << "DATA EXPIRARE: " << termen_expirare << endl;
	}
	string get_expirare()override {
		return termen_expirare;
	}
};
class electrocasnicmare :produs {
private:
	string culoare;
public:
	electrocasnicmare(string nume, string cod, float pret, int nrbuc, string culoare) :produs(nume, cod, pret, nrbuc) {
		this->culoare = culoare;

	}
	void afisare_produs()override {
		produs::afisare_produs();
		cout << "CULOARE: " << culoare << endl;
	}
	string get_culoare()override {
		return culoare;
	}

};
class electrocasnicmic :produs {
private:
	int putere;
public:
	electrocasnicmic(string nume, string cod, float pret, int nrbuc, int putere) :produs(nume, cod, pret, nrbuc) {
		this->putere = putere;

	}
	void afisare_produs()override {
		produs::afisare_produs();
		cout << "PUTERE: " << putere << endl;
	}
	int get_putere()override {
		return putere;
	}

};
enum class GenJucarie {
	Baieti,
	Fete
};
class jucarie :produs {
private:
	GenJucarie gen;
public:
	jucarie(string nume, string cod, float pret, int nrbuc, GenJucarie gen) :produs(nume, cod, pret, nrbuc) {
		this->gen = gen;

	}

	void afisare_produs()override {
		produs::afisare_produs();
		std::cout << "Gen: " << (gen == GenJucarie::Baieti ? "Baieti" : "Fete") << endl;
	}
	int  getGen() {
		if (gen == GenJucarie::Baieti)
			return 0;
		else return 1;
	}

};

class magazin {
private:
	string nume, adresa;
	list <produs*> produse;

public:
	magazin(string nume, string adresa) {
		this->nume = nume;
		this->adresa = adresa;
	}


	void afiseazaDetalii() {
		cout << "Despre  magazin: " << endl;
		cout << "Nume: " << nume << endl;
		cout << "Adresa: " << adresa << endl;
	}
	void citire_globala_fisier(ifstream& in) {
		electrocasnicmare* ema;
		electrocasnicmic* emi;
		jucarie* j;
		produse_alimentare* pa;
		produs* p;
		string nume, cod;
		int nrbucati;
		float pret;
		string termen_expirare;
		int putere;
		string culoare, tip_produs;
		int gen;
		while (in >> nume >> cod >> nrbucati >> pret >> tip_produs) {
			if (tip_produs == "ema") {
				in >> culoare;
				ema = new electrocasnicmare(nume, cod, pret, nrbucati, culoare);
				p = (produs*)ema;
			}
			else if (tip_produs == "emi") {
				in >> putere;
				emi = new electrocasnicmic(nume, cod, pret, nrbucati, putere);
				p = (produs*)emi;
			}
			else if (tip_produs == "j") {
				in >> gen;
				GenJucarie genCitit = static_cast<GenJucarie>(gen);
				j = new jucarie(nume, cod, pret, nrbucati, genCitit);
				p = (produs*)j;
			}
			else if (tip_produs == "pa") {
				in >> termen_expirare;
				pa = new produse_alimentare(nume, cod, pret, nrbucati, termen_expirare);
				p = (produs*)pa;
			}
			produse.push_back(p);

		}
	}
	void afisare_produse() {
		for (produs* x : produse) {
			x->afisare_produs();
			cout << endl;
		}
	}
	void afisare_produse_alimentare() {
		for (produs* x : produse) {
			if (typeid(*x) == typeid(produse_alimentare)) {
				x->afisare_produs();
				cout << endl;
			}
		}
	}
	void afisare_produse_jucarii() {
		for (produs* x : produse) {
			if (typeid(*x) == typeid(jucarie)) {
				x->afisare_produs();
				cout << endl;
			}
		}
	}
	void afisare_produse_electrocasnice() {
		for (produs* x : produse) {
			if (typeid(*x) == typeid(electrocasnicmare) || typeid(*x) == typeid(electrocasnicmic)) {
				x->afisare_produs();
				cout << endl;
			}
		}
	}
	void cautare_electrocasnic_mare_culoare(string culoare) {
		int k = 0;
		for (produs* x : produse) {
			if (typeid(*x) == typeid(electrocasnicmare) && x->get_culoare() == culoare)
			{
				x->afisare_produs();
				cout << endl;
				k = 1;
			}
		}
		if (k == 0)
			cout << "Electrocasnicul mare n a fost gasit!" << endl;


	}
	void stergere_cod(string cod) {
		produse.remove_if([cod](produs* p) {return p->get_cod() == cod; });
	}
	void ardonare_crescatoare() {
		produse.sort([](produs* stanga, produs* dreapta) {return stanga->get_pret() < dreapta->get_pret(); });
	}
	void ardonare_descrescatoare() {
		produse.sort([](produs* stanga, produs* dreapta) {return stanga->get_pret() > dreapta->get_pret(); });
	}
	void vanzare_un_produs() {
		bool optiune;
		int buc;
		ofstream exceptii;
		exceptii.open("log.txt", ios::app);
		ofstream vanzare;
		vanzare.open("produse_vandute.txt", ios::app);
		string nume_c, telefon, adresa, produs_dorit;
		try {
			cout << "NUME:";
			cin >> nume_c;
			cout << "TELEFON: ";
			cin >> telefon;
			if (telefon.length() != 10) {
				throw runtime_error("numarul de telefon nu este corect!");
			}
			cout << "ADRESA LIVRARE: ";
			cin >> adresa;
			optiune = 1;


			do
			{
				for (produs* x : produse)
				{
					cout << x->get_nume(); cout << " ";
				}
				cout << endl << "Introduceti produlul dorit: ";
				cin >> produs_dorit;
				cout << "Introdu numarul de bucati: ";
				cin >> buc;

				for (produs* x : produse) {
					if (x->get_nume() == produs_dorit) {
						if (x->get_nr_bucati() == 0)
							cout << "Nu mai avem aces produs in stoc!";
						else {
							if (x->get_nr_bucati() >= buc)
							{
								vanzare << nume_c << " " << telefon << " " << adresa << " " << x->get_nume() << " " << buc << endl;
								x->modificare_bucati(buc);
								total = total + buc * x->get_pret();
							}

							else cout << "Avem doar " << x->get_nr_bucati() << "produse dorite de tine" << endl;
						}
					}
				}
				cout << "Mai doriti si altceva? da(1)/nu(0)";
				cin >> optiune;
			}


			while (optiune);
		}
		catch (const runtime_error& e) {
			exceptii << "Eroare: " << e.what() << endl;

		}
		vanzare.close();
		exceptii.close();
	}
	void comparare() {
		produs* ultimul = produse.back();
		produs* max = nullptr;
		float maxim = 0;
		for (produs* p : produse) {
			if (p->get_pret() > maxim)
			{
				maxim = p->get_pret();
				max = p;
			}
		}
		if (*max == *ultimul) {
			cout << "Ultimul produs corespunde cu cel care are cel mai mare pret";

		}
		else cout << "Nu corespunde";
	}
	void afisare_in_fisier(ofstream& out) {

		for (produs* p : produse) {
			if (p->get_nr_bucati() != 0) {
				if (typeid(*p) == typeid(produse_alimentare)) {

					out << p->get_nume() << " " << p->get_cod() << " " << p->get_nr_bucati() << " " << p->get_pret() << " " << " pa " << p->get_expirare() << endl;
				}
				else if (typeid(*p) == typeid(electrocasnicmare)) {

					out << p->get_nume() << " " << p->get_cod() << " " << p->get_nr_bucati() << " " << p->get_pret() << " " << "ema  " << p->get_culoare() << endl;
				}
				else if (typeid(*p) == typeid(electrocasnicmic)) {

					out << p->get_nume() << " " << p->get_cod() << " " << p->get_nr_bucati() << " " << p->get_pret() << " " << " emi " << p->get_putere() << endl;

				}
				else if (typeid(*p) == typeid(jucarie)) {

					out << p->get_nume() << " " << p->get_cod() << " " << p->get_nr_bucati() << " " << p->get_pret() << " " << "j " << p->getGen() << endl;
				}
			}
		}
	}
};
ofstream& operator<<(ofstream& out, magazin* m) {
	m->afisare_in_fisier(out);
	return out;
}
ifstream& operator>>(ifstream& in, magazin* m) {
	m->citire_globala_fisier(in);
	return in;
}
int main() {
	int opt, opt1;
	magazin* mag;
	mag = new magazin("Magazinul", "Timsioara");
	string culoare, cod;
	ifstream in;
	in.open("produse.txt");
	ofstream out;

	do
	{
		cout << "1) Afișare detalii magazin " << endl;
		cout << "2) Inițializare produse magazin din fișierul „produse.txt” " << endl;
		cout << "3) Afișarea tuturor produselor, sau la alegerea utilizatorului, afișarea filtrată: " << endl;
		cout << "4) Căutarea unui electrocasnic mare, după culoare " << endl;
		cout << "5)  Ștergerea unui produs după cod produs " << endl;
		cout << "6)  Sortarea produselor după preț crescător, respectiv descrescător " << endl;
		cout << "7) Vânzarea unui produs prin salvarea lui într-un fișier produse_vândute.txt, împreună cu numele cumpărătorului, telefonul și adresa de livrare. Dacă stocul este 0, să se afișeze un mesaj corespunzător " << endl;
		cout << "8) Calcularea și afișarea totalului pentru produsele vândute. " << endl;
		cout << "9) Compararea celui mai scump produs cu ultimul produs din listă prin supraîncărcarea operatorului == " << endl;
		cout << "10)  Salvarea tuturor produselor disponibile din magazin în fișierul „produse.txt”" << endl;
		cout << "Alegeti o optiune:  ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1: mag->afiseazaDetalii();
			break;
		case 2:
			in >> mag;

			in.close();
			break;
		case 3:
			cout << "1.Afisare tot" << endl;
			cout << "2. Produse alimentare" << endl;
			cout << "3.Electrocasnice" << endl;
			cout << "4.Jucarii" << endl;
			cout << "Optiunea aleasa" << endl;
			cin >> opt1;
			switch (opt1)
			{
			case 1:
				mag->afisare_produse();
				break;
			case 2:
				mag->afisare_produse_alimentare();

				break;
			case 3: mag->afisare_produse_electrocasnice();
				break;
			case 4: mag->afisare_produse_jucarii();
				break;
			default:  cout << "Optiune invalida!" << endl;
				break;
			}
			break;
		case 4:
			cout << "Dati culoarea :";
			cin >> culoare;
			mag->cautare_electrocasnic_mare_culoare(culoare);
			break;
		case 5:
			cout << "Introduceti cod: ";
			cin >> cod;
			mag->stergere_cod(cod);
			mag->afisare_produse();
			break;
		case 6:
			cout << "CRESCATOR: " << endl << endl;
			mag->ardonare_crescatoare();
			mag->afisare_produse();
			cout << "DESCRESCATOR: " << endl << endl;
			mag->ardonare_descrescatoare();
			mag->afisare_produse();
			break;
		case 7:
			mag->vanzare_un_produs();
			break;
		case 8:
			cout << total;
			break;
		case 9:

			mag->comparare();
			break;
		case 10:

			out.open("produse.txt");

			out << mag;
			out.close();
			break;
		default: cout << "OPTIUNE INVALIDA " << endl;
			break;
		}
		cout << " " << endl;
	} while (1);

	return 0;
}