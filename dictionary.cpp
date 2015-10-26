/*
Made By Andrew Hingst (5043535)
This is a program designed to take a text file and feed the output of how frequent
words appear, as well as in alphabetical order. It breaks between white space.
this file only holds the FUNCTIONS and VARIABLES for main.cpp.
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

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);


DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies


BOOL InsertWord(DICT dict, WORD word)
{

	//cout << "Begining to Insert Word" << endl;
	if(!FullDictionary(dict)){					//Makes sure the dictionary isn't full
		for(int i = 0; i < MAX; i++){				
			if(dict[i].compare("") == 0) {			//If you reach the empty spot, proceed to insert the word
				//cout << "Word Inserted" << endl;
				dict[i] = word;
				count[i]++;
				//cout << "Word at : " << i << " is " << dict[i] << endl;
				return 1;															//Word properly inserted
			}
		}
	} else return 0;
}

void DumpDictionary(DICT dict, int count[]) {

	int tmp = 0;
	string tmp2;				
	for (int i = 0; i < MAX; i++){			//commence sorting (bubble sort... I'm lazy)
		if (count[i] == 0) break;			//break if at the end
		for (int j = i+1; j < MAX; j++){
			if (count[j]==0) break;
			if(dict[i].compare(dict[j]) > 0){
				tmp = count[j];				//sort both count and value
				count[j] = count[i];
				count[i] = tmp;
				tmp2 = dict[j];
				dict[j] = dict[i];
				dict[i] = tmp2;
			}
		}
	}
				
			
	
	//cout << "Beginning Output" << endl;						//Output info
	cout << "Word:               Frequency: \n";
	cout << "-------------------------------\n";
	for(int i = 0; i < MAX; i++){
		//cout << "Reading at : " << i << endl;
		if(count[i] > 0){
			cout << dict[i] << "       " << count[i] << endl;
		} else {
			//cout << "Done Output" << endl;			
			break;											//Break if No More Words
		}
	}
}

WORD GetNextWord(void){

	//cout << "Getting Next Word" << endl;
	WORD tmp = "";										//Initializes tmp with a null string
	cin >> tmp;
	//cout << "Word Acquired : " << tmp << endl;
	if (tmp.compare("") == 0) {							//If tmp is still null, return an empty string
		//cout << "Returning Bad" << endl;
		return "";
	} else {
		//cout << "Returning : " << tmp << endl;
		return tmp;										//return the input if valid
	}
}

BOOL FullDictionary(DICT dict) {

	
	//cout << "Checking if Dictionary is Full" << endl;		
	if(dict[MAX-1].compare("") == 0) {	//Compare the final spot, if it's empty then there is still at least 1 spot
		//cout << "dictionary not full" << endl;
		return 0;
	} else return 1;


}

int LocateWord(DICT dict, WORD word) {

	//cout << "Starting Locate Word" << endl;
	for(int i = 0; i < MAX; i++){										//Don't go past edge of dictionary
		if(dict[i].compare(word) == 0) {								//If it's the word, return location
			//cout << "Word Located at : " << i << endl;			
			return i;
		} else if (dict[i].empty()) {									//If empty, return a false value
			//cout << "Word not Found. Stopped at location : " << i << endl;
			return -1;
		}
	}
	cout << "ERROR. YOU BORKED IT!" << endl;							//If this goes off... what did you do?
	return -1;
	
}

