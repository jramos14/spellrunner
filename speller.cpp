#include "speller.h"

#include<cstring>

#include<iostream>


//class Word {
//	public:
//		char* Ar[21];

//};




Speller::Speller(char *dictionary[], int dictSize) : not_found(NULL), quadHash(not_found, dictSize * 2 )

{
    //dictName = new QuadraticHashTable<char*>(NULL, dictSize * 2);
    //char* dictName = new char[dictSize];
    //char *char_array[dictSize];
    //cout << "running" << endl;
    //Word* dictName = new Word[dictSize]; 
    for (int i = 0; i < dictSize; i++)
    {
    //cout << "segfaults here" << endl;
    //Word* dictName = new Word[dictSize];   
    // char* dictName = new char[strlen(dictionary[i]) + 1];
    //char_array[i] = dictionary[i];
    //
       // if ((strlen(dictionary[i])>11))

    int bitPos = 0;
    int bitLen = 0;
     
     
	{
	    strcpy(dictName[i].Ar, dictionary[i]);
     	    quadHash.insert(dictName[i].Ar);
	}
/*	else
       	{
             strcpy(dictName[i].Br, dictionary[i]);
	     quadHash.insert(dictName[i].Br);
        }
*/	     //delete dictName;

    }
      //delete dictName;

  
// Dict is what you insert

// Doc is the words that you are asked to find in hash table

}  // Speller()





Speller::~Speller()

{


 
//quadHash.makeEmpty();
/*  
  for (int i = 0; i < dictSize; i++)
  {
       delete dictName[i];
  }
  // helps fix your memory leaks
       delete dictName;
*/ 
} // ~Speller()



  // try to find your misspelled words

void Speller::check(char *document[], int docSize, int misspelled[], int *misspelledCount)
  {



    char* not_found = NULL;

    *misspelledCount = 0;

    for (int i = 0; i < docSize; i++)
    {
      if (quadHash.find(document[i]))
      {
//	cout << "it was found" << endl;      
        continue;
    } else {

  //    cout << "Misspelled count has been incremented " << endl;
      misspelled[(*misspelledCount)++] = i;

    }



  } // end for




}  // check()


