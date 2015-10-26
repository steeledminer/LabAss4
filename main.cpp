/*
Made By Andrew Hingst (5043535)
This is a program designed to take a text file and feed the output of how frequent
words appear, as well as in alphabetical order. It breaks between white space. This is
the MAIN program. All fucntions are in dictionary.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];


//variables in dictionary.cpp
extern int LocateWord(DICT, WORD);
extern BOOL FullDictionary(DICT);
extern BOOL InsertWord(DICT,WORD);
extern WORD GetNextWord(void);
extern void DumpDictionary(DICT ,int[]);


extern DICT dictionary;  //your dictionary 
extern WORD word;        // 
extern int count[MAX];   //tracks word frequencies

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
