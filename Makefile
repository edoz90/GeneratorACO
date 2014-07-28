./decoder_ga:
	g++ -O2 -std=gnu++11 *.cpp -o generator_aco

debug:
	g++ -g *.cpp -o generator_aco

clean:
	rm -f *.o generator_aco log.txt
