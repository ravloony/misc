#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <utility>

struct node
{
  char c;
  node* back;
  node* next;
};

typedef node* Tree;



int main (int argc, char** argv) {
  string singleline;
  string tok1, tok2, tok3;
  node* current;
  node* next;
  Tree tree;

  map<string,string> dictionary;
  bool dnaFound = false;
  string dna;

  //make cool mini parse tree hey hey
  node* firstNode = new node;
  firstNode->back = firstNode;
  firstNode->c = 'A';

  node* secondNode = new node;
  secondNode->back = firstNode;
  secondNode->c = 'T';
  firstNode->next = secondNode;

  thirdNode = new node;
  thirdNode->back = firstNode;
  thirdNode->c = 'G';
  secondNode->next = thirdNode;
  
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
      map.add(make_pair(tok1,tok2));
    } else {
      dna = singleline;
    }  
  }
  
} 
