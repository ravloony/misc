/*
 * This is a solution to an interviewstreet problem I was asked to solve as part of the Facebook engineer application process. 
 * I actually was not capable of finding a good solution in the 60 minutes allotted time, mostly due to my coding skillz being so fucking rusty, 
 * but I was intrigued by the problem. So I solved it anyway.
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <utility>
#include <string>

using namespace std;
struct node
{
  char c;
  node* back;
  node* next;
};


int main (int argc, char** argv) {
  string singleline;
  string tok1, tok2, tok3;
  node* current;

  map<string,string> dictionary;
  bool dnaFound = false;
  string dna;

  //make cool mini parse state machine
  node firstNode;
  firstNode.back = &firstNode;
  firstNode.c = 'A';

  node secondNode;
  secondNode.back = &firstNode;
  secondNode.c = 'T';
  firstNode.next = &secondNode;

  node thirdNode;
  thirdNode.back = &firstNode;
  thirdNode.c = 'G';
  secondNode.next = &thirdNode;
  thirdNode.next = 0;

  getline(cin, singleline); // jump the first comment
  while (getline(cin, singleline)) {
    if (singleline[0] == '/') {
      dnaFound = true;
      continue;
    }
    if (!dnaFound) {
      istringstream is(singleline);
      is >> tok1;
      is >> tok2;
      is >> tok3;
      // add codon to dictionary
      dictionary.insert(make_pair(tok1,tok2));
    } else {
      dna = singleline;
    }  
  }

  std::map<std::string, std::string>::iterator iter;

  /*for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
    cout << iter->first << '=' << iter->second << endl;
  }
  cout << "dna : " << dna << endl;
  */
  node* currentNode = &firstNode;
  char currentProtChar;
  string currentCodon("   ");
  bool protein = false;

  int i=0;
  while (i < dna.size()) {
    // Find the protein start
    while (!protein) {
      if (currentNode) {
	if (currentNode->c == dna[i]) {
	  currentNode = currentNode->next;
	} else {
	  currentNode = currentNode->back;
	}
	i++; // keep moving, as riddick would say
      } else {
	protein = true;
	currentNode = &firstNode;
      }
      //      i++;
    }
    //cout << "found a protein at " << i << endl;
    cout << 'M';
    //start reading the protein
    while (protein) {
      for (int j=0; j<3; j++)
	currentCodon[j] = dna[i+j];
      //cout << currentCodon << endl;
      currentProtChar = dictionary[currentCodon][0];
      //cout << dictionary[currentCodon] << endl;
      if (currentProtChar == 'X') {
	protein = false; //out of protein
      } else {
	cout << currentProtChar; //output the translation of the current codon
      }
      i += 3;
    }
    cout << endl;
    }
}

