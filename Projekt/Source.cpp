#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "VideoGame.h"
#include <map>
#include <queue>
#include <chrono>
#include <ctime>
#include <list>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include <unordered_map>



using namespace std;
using namespace chrono;


//FUNKCIONALNOST 32
template<typename T>
T convert(string& s)
{
	stringstream st(s);
	T t;
	st >> t;
	return t;
}

//FUNKCIONALNOST 32
void load(ifstream& citanje, vector<VideoGame>& vg) {
	string line;
	getline(citanje, line);
	while (getline(citanje, line))
	{
		stringstream ss(line);
		string vrijednost;

		getline(ss, vrijednost, ',');
		int rank = convert<int>(vrijednost);
		getline(ss, vrijednost, ',');
		string name = vrijednost;
		getline(ss, vrijednost, ',');
		string platforma = vrijednost;
		getline(ss, vrijednost, ',');
		int godina_izdanja = convert <int>(vrijednost);
		getline(ss, vrijednost, ',');
		string zanr = vrijednost;
		getline(ss, vrijednost, ',');
		string izdavac = vrijednost;
		getline(ss, vrijednost, ',');
		double NA_Sales = convert<double>(vrijednost);
		getline(ss, vrijednost, ',');
		double EU_Sales = convert<double>(vrijednost);
		getline(ss, vrijednost, ',');
		double JP_Sales = convert<double>(vrijednost);
		getline(ss, vrijednost, ',');
		double Other_Sales = convert<double>(vrijednost);
		getline(ss, vrijednost);
		double globalno_zaradeni_iznos = convert<double>(vrijednost);

		vg.emplace_back(rank, name, platforma, godina_izdanja, zanr, izdavac, NA_Sales, EU_Sales, JP_Sales, Other_Sales, globalno_zaradeni_iznos);

	}
}
//FUNKCIONALNOST 32
void ispisi(VideoGame& game) {


	cout << game.to_string();
}

//FUNKCIONALNOST 33 i 34
void pretraga(multimap<string, string>& pretraga_zanr, vector<VideoGame>& vecv, list<VideoGame>& listv)
{
	bool dalje;
	do
	{
		string zanr;
		cout << "Unesite zanr: ";
		cin >> zanr;

		auto begin1 = high_resolution_clock::now();
		auto found = pretraga_zanr.equal_range(zanr);
		auto end1 = high_resolution_clock::now();


		if (found.first != found.second)
		{
			cout << "Pronadjene igre:" << endl;
			for (auto it = found.first; it != found.second; ++it)
			{
				cout << it->second << endl;

			}
			cout << endl;
		}
		else
		{
			cout << "Ne postoji " << endl;
		}

		auto begin2 = high_resolution_clock::now();
		for (auto it = vecv.begin(); it != vecv.end(); ++it)
		{
			if (it->get_zanr() == zanr)
			{
				break;
			}
		}
		auto end2 = high_resolution_clock::now();

		auto begin3 = high_resolution_clock::now();
		for (auto it = listv.begin(); it != listv.end(); ++it)
		{
			if (it->get_zanr() == zanr)
			{
				break;
			}
		}
		auto end3 = high_resolution_clock::now();


		cout << "Multimapa vrijeme: " << duration_cast<nanoseconds>(end1 - begin1).count() << " ns" << endl;
		cout << "Vektor vrijeme: " << duration_cast<nanoseconds>(end2 - begin2).count() << " ns" << endl;
		cout << "Lista vrijeme: " << duration_cast<nanoseconds>(end3 - begin3).count() << " ns" << endl;






		cout << "Dalje (1, 0)? ";
		cin >> dalje;
	} while (dalje);
}


//FUNKCIONALNOST 36
void pretraga2(multimap<string, string>& pretraga_zanr, vector<string> v)
{
	bool dalje;
	do
	{
		string zanr;
		cout << "Unesite zanr: ";
		cin >> zanr;

		auto found = pretraga_zanr.equal_range(zanr);

		if (found.first != found.second)
		{
			cout << "Pronadjene igre:" << endl;
			for (auto it = found.first; it != found.second; ++it)
			{
				v.push_back(it->second);

			}
			cout << endl;
		}
		else
		{
			cout << "Ne postoji " << endl;
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << endl;
		}

		cout << "Dalje (1, 0)? ";
		cin >> dalje;
	} while (dalje);
}

//FUNKCIONALNOST 45
bool rastuce(vector<string>& v3)
{
	for (unsigned i = 0; i < v3.size() - 1; i++)
	{
		if (v3[i] > v3[i + 1])
		{
			return false;
		}
	}
	return true;
}

//FUNKCIONALNOST 44

int generiranje_random(int min, int max) {

	return rand() % (max - min + 1) + min;
}

void pogodi_trajanje(vector<int>& v4, int korisnik_vrijeme) {
	auto begin = high_resolution_clock::now();
	random_shuffle(v4.begin(), v4.end());
	sort(v4.begin(), v4.end());
	binary_search(v4.begin(), v4.end(), 7);
	auto end = high_resolution_clock::now();

	int pravo_trajanje = duration_cast<milliseconds>(end - begin).count();
	cout << "Razlika u trajanju : " << pravo_trajanje - korisnik_vrijeme << " milisekunde " << endl;


}

//FUNKCIONALNOST 46

void quick_sort_2(vector<string>& v5, int pocetak, int kraj) {

	int brojac = 0;

	if (kraj <= pocetak)
	{
		return;
	}


	string& pivot = v5[pocetak];
	int i = pocetak + 1;
	int j = kraj;

	while (i <= j && i <= kraj && j > pocetak)
	{
		while (v5[i] <= pivot && i <= kraj)
		{
			i++;
		}
		while (v5[j] > pivot && j > pocetak)
		{
			j--;
		}
		if (i < j)
		{
			swap(v5[i], v5[j]);
			brojac--;
		}
	}
	swap(pivot, v5[j]);
	quick_sort_2(v5, pocetak, j - 1);
	brojac++;
	quick_sort_2(v5, j + 1, kraj);
	brojac++;

}

void quick_sort(vector<string>& v5, int n) {
	quick_sort_2(v5, 0, n - 1);
}

//FUNKCIONALNOST 52 i 53

void pretraga2(unordered_multimap<string, string>& pretraga_plat, vector<VideoGame>& vv, list<VideoGame>& lv)
{


	cin.ignore();
	string platforma;
	cout << "Unesite platformu: ";
	getline(cin, platforma);

	auto begin1 = high_resolution_clock::now();
	auto found = pretraga_plat.equal_range(platforma);
	auto end1 = high_resolution_clock::now();

	if (found.first != found.second)
	{
		cout << "Pronadjene igre:" << endl;
		for (auto it = found.first; it != found.second; ++it)
		{
			cout << it->second << endl;

		}
		cout << endl;
	}
	else
	{
		cout << "Ne postoji " << endl;
	}


	auto begin2 = high_resolution_clock::now();
	for (auto it = vv.begin(); it != vv.end(); ++it)
	{
		if (it->get_plat() == platforma)
		{
			break;
		}
	}
	auto end2 = high_resolution_clock::now();

	auto begin3 = high_resolution_clock::now();
	for (auto it = lv.begin(); it != lv.end(); ++it)
	{
		if (it->get_plat() == platforma)
		{
			break;
		}
	}
	auto end3 = high_resolution_clock::now();


	cout << "Unordered_multimapa vrijeme: " << duration_cast<nanoseconds>(end1 - begin1).count() << " ns" << endl;
	cout << "Vektor vrijeme: " << duration_cast<nanoseconds>(end2 - begin2).count() << " ns" << endl;
	cout << "Lista vrijeme: " << duration_cast<nanoseconds>(end3 - begin3).count() << " ns" << endl;

}



int main() {

	//FUNKCIONALNOST 31 + NADODACI 

	cout << "GAME SALE" << endl;
	cout << "Pretraga po zanru -> Z" << endl;
	cout << "Prikaz po godini -> G" << endl;
	cout << "Kopiranje u novi vektor -> V" << endl;
	cout << "Prikaz po globalnoj prodaji -> P" << endl;
	cout << endl;
	cout << "Bubble vs Insertion -> A  " << endl;
	cout << "Pogodi trajanje -> B  " << endl;
	cout << "Lets Bogo! -> C " << endl;
	cout << " Quick quick -> D " << endl;
	cout << endl;
	cout << "Pretraga po platformi -> Q " << endl;
	cout << "Vizualiziraj -> W  " << endl;
	cout << " Izrada imena iz imena ->  E " << endl;
	cout << endl;
	cout << "Za izbor pretrage koristiti iskljucivo velika slova !!" << endl;
	cout << "Izaberite slovo ovisno o izboru (Z,G,V,P, A, B, C, D,  Q,  W,  E) : " << endl;


	char slovo;
	cin >> slovo;

	srand(time(nullptr));

	//FUNKCIONALNOST 32
	ifstream citanje("SPA_PROJ_006_GAME_SALES_data.csv");
	if (!citanje)
	{
		cout << "Eror" << endl;
		return 1;
	}

	vector <VideoGame> vg;
	load(citanje, vg);
	citanje.close();

	VideoGame game;

	// FUNKCIONALNOST 32
	//AKO KORISNIK ZELI OSNOVNE PODATKE O IGRAMA POTREBNO JE ODKOMENTIRATI LINIJU KODA ISPOD
	//for_each(vg.begin(), vg.end(), ispisi);

	//FUNKCIONALNOST 33 i 34

	multimap<string, string> pretraga_zanr;

	if (slovo == 'Z')
	{
		vector<VideoGame> vecv;
		list<VideoGame> listv;

		for (int i = 0; i < vg.size(); i++)
		{
			pretraga_zanr.insert(pair<string, string>(vg[i].get_zanr(), vg[i].to_string()));
			vecv.push_back(vg[i]);
			listv.push_back(vg[i]);
		}
		pretraga(pretraga_zanr, vecv, listv);



	}

	//FUNKCIONALNOST 36
	if (slovo == 'V')
	{
		vector<string> v;

		for (int i = 0; i < vg.size(); i++)
		{
			pretraga_zanr.insert(pair<string, string>(vg[i].get_zanr(), vg[i].to_string()));
		}
		pretraga2(pretraga_zanr, v);
	}


	//FUNKCIONALNOST 35
	if (slovo == 'G')
	{
		priority_queue<VideoGame, vector<VideoGame>, comp> prioritetni_red;
		for (int i = 0; i < vg.size(); i++)
		{
			prioritetni_red.emplace(vg[i].get_naziv(), vg[i].get_godina_izdanja());
		}
		while (!prioritetni_red.empty()) {

			cout << prioritetni_red.top().get_naziv() << " -> " << prioritetni_red.top().get_godina_izdanja() << endl;
			prioritetni_red.pop();
		}
	}

	//FUNKCIONALNOST 42 I 43

	if (slovo == 'A')
	{
		vector<string> v1;
		vector<string> v2;

		for (int i = 0; i < vg.size(); i++)
		{
			v1.push_back(vg[i].get_naziv());
			v2.push_back(vg[i].get_naziv());
		}
		auto begin_bubble = high_resolution_clock::now();


		cout << "Swap: " << bubble_sort(v1) << endl;

		auto end_bubble = high_resolution_clock::now();


		cout << "Bubble: " << duration_cast<milliseconds>(end_bubble - begin_bubble).count() << " ms" << endl; //potrebno je pricekati malo jer se dugo ucitava

		auto begin_ins = high_resolution_clock::now();

		cout << "Swap: " << insertion_sort(v2) << " ms "<< endl;

		auto end_ins = high_resolution_clock::now();


		cout << "Insertion: " << duration_cast<milliseconds>(end_ins - begin_ins).count() << " ms" << endl; //potrebno je pricekati malo jer se dugo ucitava

	}

	//FUKCIONALNOST 45

	if (slovo == 'C')
	{

		vector<string> v3;
		int n = 5;

		random_shuffle(vg.begin(), vg.end());



		for (int i = 0; i < n; i++) {
			v3.push_back(vg[i].get_naziv());

		}


		for (auto& i : v3)
		{
			cout << i << endl;
		}

		while (!rastuce(v3)) {

			next_permutation(v3.begin(), v3.end());

		}



	}


	//FUNKCIONALNOST 44

	if (slovo == 'B')
	{
		int broj = generiranje_random(1, 100000000);
		int korisnik_vrijeme;
		cout << "Koliko mislite da ce trajati : ";
		cin >> korisnik_vrijeme;
		vector<int> v4;

		for (int i = 1; i < broj + 1; i++)
		{
			v4.push_back(i);
		}
		pogodi_trajanje(v4, korisnik_vrijeme);


	}


	//FUNKCIONALNOST 46

	if (slovo == 'D')
	{


		int n;
		cout << "Unesite  neki veci broj: ";
		cin >> n;

		vector<string> v5;

		random_shuffle(vg.begin(), vg.end());

		for (int i = 0; i < n; i++)
		{
			v5.push_back(vg[i].get_naziv());
		}


		quick_sort(v5, n);

		for (auto& i : v5)
		{
			cout << i << endl;
		}
	}

	//FUNKCIONALNOST 52 I 53
	if (slovo == 'Q')
	{
		unordered_multimap<string, string> pretraga_plat;

		vector<VideoGame> vv;
		list<VideoGame> lv;

		for (int i = 0; i < vg.size(); i++)
		{
			pretraga_plat.insert(pair<string, string>(vg[i].get_plat(), vg[i].to_string()));
			vv.push_back(vg[i]);
			lv.push_back(vg[i]);
		}
		pretraga2(pretraga_plat, vv, lv);

	}

	//FUNKCIONALNOST 54

	if (slovo == 'W')
	{
		unordered_map<int, string> vizualiziraj;
		for (int i = 0; i < vg.size(); i++)
		{
			vizualiziraj.insert(pair<int, string>(vg[i].get_rank(), vg[i].get_naziv()));
		}

		for (unsigned i = 0; i < vizualiziraj.bucket_count(); i++)
		{
			cout << "BUCKET	" << i << " -> ";

			for (auto it = vizualiziraj.begin(i); it != vizualiziraj.end(i); ++it)
			{
				cout << it->second << "      ";

			}


			cout << endl;

		}


	}

	//FUNKCIONALNOST 55
	if (slovo == 'E')
	{
		cout << "Unesite prvu igru: ";
		string igra1;
		getline(cin, igra1);

		cout << "Unesite drugu igru: ";
		string igra2;
		getline(cin, igra2);

		unordered_map<string, string> izrada_imena;
		for (int i = 0; i < vg.size(); i++)
		{
			izrada_imena.insert(pair<string, string>(vg[i].get_naziv(), vg[i].get_naziv()));
		}
	}


	return 0;
}