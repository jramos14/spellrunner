// Author: Sean Davis

#ifndef SPELLER_H

#define SPELLER_H

#include <iostream>

#include "QuadraticProbing.h"

class Word{
	public:
		char Ar[21];
               
	
};

class Speller

{

public:

  Word dictName[100000];
  //
  //Word dictName[200001];

  QuadraticHashTable <char*> quadHash;

  char* not_found = NULL;

  //void insert(char *dictionary[]);

  ~Speller();

  Speller(char *dictionary[], int dictSize);

  void check(char *document[], int docSize, int misspelled[], int *misspelledCount);

// char *dictName;

 //int dictSize;
  //char **fileName;

  //int dictionary;

}; // class Speller





#endif


