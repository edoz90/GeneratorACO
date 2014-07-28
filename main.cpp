#include "ACO.h"

using namespace std;

int main(int argc, char** argv) {    
    // inizializzo il generatore di numeri pseduo-random
    srand(time(NULL));
    std::string word = "";
    // leggo la stringa in input
    if (argv[1]) {
        word = argv[1];
		ACO g(word);
		g.execute();
    }else {
		// Eseguo il test su 10 stringhe
		std::ofstream outfile;
  		outfile.open("log.txt", std::ios_base::app);
		int iteration = 10;

		double somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g1("bbbb");
    		somma += g1.execute();
		}
		outfile << "4 - bbbb " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g2("ciao");
    		somma += g2.execute();
		}
		outfile << "4 - ciao " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g3("pioggia");
    		somma += g3.execute();
		}
		outfile << "7 - pioggia " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g4("genetico");
    		somma += g4.execute();
		}
		outfile << "8 - genetico " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++){
			ACO g5("artificiale");
    		somma += g5.execute();
		}
		outfile << "11 - artificiale " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g6("hello world");
    		somma += g6.execute();
		}
		outfile << "11 - hello world " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g7("intelligenza");
    		somma += g7.execute();
		}
		outfile << "12 - intelligenza " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g8("illimitatamente");
    		somma += g8.execute();
		}
		outfile << "15 - illimitatamente " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g9("intelligenza artificiale");
    		somma += g9.execute();
		}
		outfile << "24 - intelligenza artificiale " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g10("precipitevolissimevolmente");
    		somma += g10.execute();
		}
		outfile << "26 - precipitevolissimevolmente " << somma/iteration << endl;

		somma = 0.0;
    	// inizializzo la classe
		for (int i = 0; i < iteration; i++) {
			ACO g11("propongo di considerare questa domanda le macchine sono in grado di pensare");
    		somma += g11.execute();
		}
		outfile << "75 - propongo di considerare questa domanda le macchine sono in grado di pensare " << somma/iteration << endl;
	}
    return 0;
}
