#include "biblio.h"

using namespace std;

Biblio::Biblio()
{

}

// Getters
int Biblio::GetNum()
{
    return _num;
}

string Biblio::GetNom()
{
    return _nom;
}

double Biblio::GetCout()
{
    return _cout;
}

string Biblio::GetAccr()
{
    return _accr;
}

string Biblio::GetSource()
{
    return _source;
}

string Biblio::GetCont()
{
    return _cont;
}

double Biblio::GetPoids()
{
    return _poids;
}

// Setters
void Biblio::SetNum(int num)
{
    _num=num;
}

void Biblio::SetNom(string nom)
{
    _nom=nom;
}

void Biblio::SetCout(double cout)
{
    _cout=cout;
}

void Biblio::SetAccr(string accr)
{
    _accr=accr;
}

void Biblio::SetSource(string source)
{
    _source=source;
}

void Biblio::SetCont(string cont)
{
    _cont=cont;
}

void Biblio::SetPoids(double poids)
{
    _poids = poids;
}

Biblio::Biblio(int num, string nom, double cout, double poids, string cont, string accr, string source)
{

    _num = num;
    _nom = nom;
    _cout = cout;
    _poids = poids;
    _cont = cont;
    _accr = accr;
    _source = source;

}
