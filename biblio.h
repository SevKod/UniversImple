#ifndef BIBLIO_H
#define BIBLIO_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

//using namespace std;

class Biblio
{
private:

    int _num;
    std::string _nom;
    double  _cout;
    double _poids;
    std::string _cont;
    std::string _accr;
    std::string _source;

public:

    // Constructeurs
    Biblio();
    Biblio(int num, std::string nom, double cout, double poids, std::string cont, std::string accr, std::string source);

    // Getters
    int GetNum();
    std::string GetNom();
    double GetCout();
    double GetPoids();
    std::string GetCont();
    std::string GetAccr();
    std::string GetSource();

    // Setters
    void SetNum(int num);
    void SetNom(std::string nom);
    void SetCout(double cout);
    void SetPoids(double poids);
    void SetCont(std::string cont);
    void SetAccr(std::string accr);
    void SetSource(std::string source);
};

#endif // BIBLIO_H
