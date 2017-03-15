speller.out : mynew.o speller.o SpellRunner.o string.o
	g++ -ansi -Wall -g -o speller.out mynew.o speller.o SpellRunner.o string.o

string.o: 
	g++ -ansi -Wall -g -c string.cpp

mynew.o : mynew.cpp mynew.h
	g++ -ansi -Wall -g -c mynew.cpp

speller.o : speller.cpp speller.h QuadraticProbing.cpp QuadraticProbing.h
	g++ -ansi -Wall -g -c speller.cpp

SpellRunner.o : SpellRunner.cpp CPUTimer.h mynew.h speller.h
	g++ -ansi -Wall -g -c SpellRunner.cpp

clean :
	rm -f speller.out mynew.o  speller.o  SpellRunner.o string.o

