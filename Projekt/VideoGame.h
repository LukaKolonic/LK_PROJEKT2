#pragma once

#include <string>

using namespace std;

class VideoGame
{
public:

	VideoGame();
	VideoGame(string naziv, int godina_izdanja);
	VideoGame(int rank, string naziv, string platforma, int godina_izdanja, string zanr, string izdavac,
		double NA_Sales, double EU_Sales, double JP_Sales, double Other_Sales, double globalno_zaradeni_iznos);
	void set_naziv(string naziv);
	void set_izdavac(string izdavac);
	void set_godina_izdanja(int godina_izdanja);
	void set_globalno_zaradeni_iznos(double globalno_zaradeni_iznos);

	string get_naziv() const;
	string get_izdavac();
	int get_godina_izdanja() const;
	double get_globalno_zaradeni_iznos();
	double get_NA_Sales();
	string get_zanr();
	int get_rank();
	string get_plat();
	string to_string();

private:
	int rank;
	string naziv;
	string platforma;
	int godina_izdanja;
	string zanr;
	string izdavac;
	double NA_Sales;
	double EU_Sales;
	double JP_Sales;
	double Other_Sales;
	double globalno_zaradeni_iznos;

};

//FUNKCIONALNOST 35
struct comp {

	bool operator() (const VideoGame& vg1, const VideoGame& vg2) const {

		return vg1.get_godina_izdanja() > vg2.get_godina_izdanja();
	}
};



