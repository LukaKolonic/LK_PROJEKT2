#include "VideoGame.h"
#include <sstream>


VideoGame::VideoGame()
{
}

VideoGame::VideoGame(string naziv, int godina_izdanja)
{
	set_naziv(naziv);
	set_godina_izdanja(godina_izdanja);
}

VideoGame::VideoGame(int rank, string naziv, string platforma, int godina_izdanja, string zanr, string izdavac, double NA_Sales, double EU_Sales, double JP_Sales, double Other_Sales, double globalno_zaradeni_iznos)
{
	this->rank = rank;
	this->platforma = platforma;
	this->zanr = zanr;
	this->NA_Sales = NA_Sales;
	this->EU_Sales = EU_Sales;
	this->JP_Sales = JP_Sales;
	this->Other_Sales = Other_Sales;
	set_naziv(naziv);
	set_godina_izdanja(godina_izdanja);
	set_izdavac(izdavac);
	set_globalno_zaradeni_iznos(globalno_zaradeni_iznos);
}

void VideoGame::set_naziv(string naziv)
{
	this->naziv = naziv;
}

void VideoGame::set_izdavac(string izdavac)
{
	this->izdavac = izdavac;
}

void VideoGame::set_godina_izdanja(int godina_izdanja)
{
	this->godina_izdanja = godina_izdanja;
}

void VideoGame::set_globalno_zaradeni_iznos(double globalno_zaradeni_iznos)
{
	this->globalno_zaradeni_iznos = globalno_zaradeni_iznos;
}

string VideoGame::get_naziv() const
{
	return naziv;
}

string VideoGame::get_izdavac()
{
	return izdavac;
}

int VideoGame::get_godina_izdanja() const
{
	return godina_izdanja;
}

double VideoGame::get_globalno_zaradeni_iznos()
{
	return globalno_zaradeni_iznos;
}

double VideoGame::get_NA_Sales()
{
	return NA_Sales;
}

string VideoGame::get_zanr()
{
	return zanr;
}

int VideoGame::get_rank()
{
	return rank;
}

string VideoGame::get_plat()
{
	return platforma;
}

string VideoGame::to_string()
{
	stringstream ss;
	ss << "Naziv: " << naziv << endl;
	ss << "Izdavac: " << izdavac << endl;
	ss << "Godina izdanja: " << godina_izdanja << endl;
	ss << "Globalno zaradeni iznos: " << globalno_zaradeni_iznos << endl;
	return ss.str();
}

