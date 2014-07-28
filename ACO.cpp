#include "ACO.h"

ACO::~ACO() {
}

ACO::ACO(string s) {
	this->iteration = 0;
	// Inizialmente la probabilità totale in ogni colonna sarà 1
	this->total = 1;
	this->passed = false;
	this->text = s;
	this->lenght = this->text.size();
	// Inizializzo la matrice come array di array
	this->trail.resize(ACO::LETTERS.size());
	this->colony.resize(ACO::ants);
	for (int i = 0; i < ACO::LETTERS.size(); i++) {
		this->trail[i].resize(this->lenght);
	}
	// Controllo che il numero dei best sia adeguato
	if (ACO::best > ACO::ants) ACO::best = ACO::ants/3;
}

// Imposta la popolazione e avvia l'evoluzione
double ACO::execute() {
	// Salvo il tempo iniziale
	this->init = clock();
	// Inizializzazione
	this->initialization();
	cout << "STARTING THE EVOLUTION" << endl;
	// Evoluzione del sistema
	this->findString();
	this->final = difftime(clock(), this->init)/CLOCKS_PER_SEC;
	cout << "Execution time: " << this->final << "s" << endl;
	return this->final;
}

// Inizializzazione del sistema
void ACO::initialization() {
	this->iteration++;
	// Inizializzo i valori delle tracce
	for (int k = 0; k < this->lenght; k++) {
		for (int i = 0; i < ACO::LETTERS.size(); i++) {
			this->trail[i][k] = 1.0/ACO::LETTERS.size();
		}
	}
	string word;
	// Genero le prime stringhe a random
	for (int i = 0; i < this->colony.size(); i++) {
		word = "";
		this->colony[i].code.resize(this->lenght);
		for (int k = 0; k < this->lenght; k++) {
			// le probabilità sono tutte uguali
			int letter = rand() % ACO::LETTERS.size();
			this->colony[i].code[k] = letter;
			this->colony[i].word += ACO::LETTERS[letter];
		}
		// Calcolo la bontà della stringa
		this->colony[i].rate = this->evaluate(this->colony[i].word);
	}
}


// Ricerca la stringa, algoritmo centrale
void ACO::findString() {
	// Finchè non trova la parola
	while(!this->passed) {
		// Aumento il contatore delle iterazioni
		this->iteration++;
		// Costruisco la parola, per ogni formica
		for (int i = 0; i < this->ants; i++) {
			string word = "";
			Ant new_ant;
			new_ant.code.resize(this->lenght);
			// Per la lunghezza della stringa
			for (int k = 0; k < this->lenght; k++) {
				// Genero un numero double random da 0 a this->total
				double ran = 0 + (rand() / (RAND_MAX / this->total));
				int j = 0;
				double somma = this->trail[j][k];
				// Recupero la lettere corrispondente al numero generato
				while (ran > somma) {
					j++;
					somma += this->trail[j][k];
				}
				// Costruisco la parola
				word += ACO::LETTERS[j];
				new_ant.code[k] = j;
			}
			// Aggiorno la colonia delle formiche
			new_ant.word = word;
			new_ant.rate = this->evaluate(word);
			this->colony[i] = new_ant;
		}
		// Aggiorno le tracce
		this->evaporation_update();			
	}
    // Ho trovato la parola
	cout << endl << "WORD FOUND AFTER: " << this->iteration  << " ITERATION" << endl;
}


// Aggiorna le tracce
void ACO::evaporation_update() {
	// Aggiorno le tracce con i risultati migliori
	std::sort(this->colony.begin(), this->colony.end(), this->sortByRate);
	cout << "BEST IS: " << this->colony[0].word << endl;
	// Per ogni formica che considero migliore aggiorno la matrice delle tracce
	for (int i = 0; i < ACO::best; i++) {
		for (int k = 0; k < this->lenght; k++) {
			this->trail[this->colony[i].code[k]][k] += this->colony[i].rate;
		}
	}

	// Simulo l'evaporazione delle tracce
	for (int k = 0; k < this->lenght; k++) {
		for (int i = 0; i < ACO::LETTERS.size(); i++) {
			this->trail[i][k] *= this->rho;
		}
	}
	// Ricalcolo il totale
	this->total = 0;
	for (int i = 0; i < ACO::LETTERS.size(); i++) {
		// Il totale delle colonne è uguale
		this->total += this->trail[i][0];	
	}
}


// Valutazione della bontà della soluzione trovata
double ACO::evaluate(std::string word) {
    double rate = 0.0;
    // Se ho trovato la parola fermo l'evoluzione
    if (this->text == word) {
		this->passed = true;
	}else {
    	// Controllo carattere per carattere se ci sono lettere uguali
    	for (int i = 0; i < this->lenght; i++) {
        	if (this->text.at(i) == word.at(i)) {
        	    rate++;
        	}
    	}
		rate = rate/this->lenght;
	}
    return rate;
}

// Funzione di ordinamento dei geni per rate
bool ACO::sortByRate(const ACO::Ant &lhs, const ACO::Ant &rhs) {
    return lhs.rate > rhs.rate;
}
