#ifndef ACO_H
#define	ACO_H

#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class ACO {
public:
    // costruttore
    ACO(std::string);
	~ACO();
    double execute();

private:
    // struct dei geni
    struct Ant {
        // la parola generata
        std::string word;
        // la bontà della parola
        double rate;
		// la stringa in formato numerico
        std::vector<int> code;
    };
	// Numero di formiche
	static const int ants = 300000;
	// Numero delle formiche migliori da considerare
	int best = 1000;
	// L'alfabeto
    const std::string LETTERS = "abcdefghijklmnopqrstuvwxyz ";
	// Costante di evaporazione
	const double rho = 0.5;
	// Matrice delle tracce
    vector< vector<double> > trail;
	// Variabile di supporto per la generazione delle stringhe
	double total;
	// Vettore delle formiche
	vector<Ant> colony;
	// Contatore delle iterazioni
	int iteration;
    // La parola da cercare
    string text;
    // La lunghezza della parola
    int lenght;
    // Miglior valutazione, tempo finale d'esecuzione
    double max_rate, final;
    // Flag di fine esecuzione
    bool passed;
    // Tempo iniziale
    clock_t init;

	void initialization();
	void findString();
	void evaporation_update();
	double evaluate(string);
	void printm();
	static bool sortByRate( const Ant&, const Ant&);
};

#endif	/* ACO_H */

