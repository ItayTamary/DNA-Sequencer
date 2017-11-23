/*************************************
 ** File:    DNA.cpp
 ** Project: DNA Sequencer
 ** Author:  Itay Tamary
 ** Date:    3/20/17
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to create a strand of DNA, insert and link 
 ** together individual nucleotides, displays, counts, and identifies the
 ** amino acids within the strand.
 **
 **
 **************************************/

#include "DNA.h"
#include "Sequencer.h"
#include <string>
using namespace std;

// DNA 
// Constructs the specifications to create a strand of DNA (linked list)
DNA::DNA() {
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

// ~DNA
// Destructor calls clear at the end of program to clear out dynamically
// allocated memory
DNA::~DNA() {
  Clear();
}

// InsertEnd
// Takes in individual nucleotide (char) and links it to the end of 
// the list / DNA strand
void DNA::InsertEnd(char payload) {
  Nucleotide* newNucl = new Nucleotide(); //creates new Nucleotide
  newNucl -> m_payload = payload;
  bool emptyHead = IsEmpty();
  if (emptyHead == 1) { //if this is the first nucleotide in the strand
    m_head = newNucl;   //then this nucleotide will be the head of the list
    m_tail = newNucl;
    m_size = 0;
  }	
  else {
    m_tail -> m_next = newNucl; //assigns the the new nucleotide to the end
    m_tail = newNucl;           //of the list
    newNucl -> m_next = NULL;
  }
}

// Display
// Takes in users choice of display, and will display each individual
// nucleotide by itself, or each nucleotide along with its base pair
void DNA::Display(int numStrand) {
  Nucleotide* CURR;
  CURR = m_head;
  int choice = numStrand;
  if (choice == 1) {
    for (int j = 0; j < m_size; j++) {  //simply prints out each nucleotide
      cout << CURR -> m_payload << endl;//and then the one linked to it
      CURR = CURR -> m_next;
    }
    cout << "END" << endl;
    cout << m_size << " nucleotides listed." << endl;
  }
  else if (choice == 2) { //prints out each nucleotide and its base pair
    for (int i = 0; i < m_size; i++) {
      char pair;
      if (CURR -> m_payload == 'A') { //if statements to determine base pair
	pair = 'T';
      }
      else if (CURR -> m_payload == 'T') {
	pair = 'A';
      }
      else if (CURR -> m_payload == 'G') {
	pair = 'C';
      }
      else if (CURR -> m_payload == 'C') {
	pair = 'G';
      }
      cout << CURR -> m_payload << "-" << pair << endl;
      CURR = CURR -> m_next;
    }
    cout << "END" << endl;
    cout << m_size << " base pairs listed." << endl;
  }
  cout << m_size / TRINUCLEOTIDE_SIZE << " trinucleotides listed." << endl;
}

// NumAmino
// Takes in a desired amino acid name and codon and counts how many
// times that specific codon appears in the strand
void DNA::NumAmino(string name, string trinucleotide) {
  Nucleotide* CURR;
  Nucleotide* secondNucl;
  Nucleotide* thirdNucl;
  CURR = m_head;
  int skipper = 3; //to only consider every third nucleotide
  int counter = 0; //to count how many times codon appears
  char first, second, third;
  string stringFirst, stringSecond, stringThird;
  for (int i = 0; i < m_size; i++) {
    secondNucl = CURR -> m_next;
    thirdNucl = secondNucl -> m_next;
    first = CURR -> m_payload;
    second = secondNucl -> m_payload;
    third = thirdNucl -> m_payload;
    if (first == 'A') { //if statements convert char to string 
      stringFirst = "A";
    }
    else if (first == 'T') {
      stringFirst = "T";
    }
    else if (first == 'C') {
      stringFirst = "C";
    }
    else if (first == 'G') {
      stringFirst = "G";
    }
    if (second == 'A') {
      stringSecond = "A";
    }
    else if (second == 'T') {
      stringSecond = "T";
    }
    else if (second == 'C') {
      stringSecond = "C";
    }
    else if (second == 'G') {
      stringSecond = "G";
    }
    if (third == 'A') {
      stringThird = "A";
    }
    else if (third == 'T') {
      stringThird = "T";
    }
    else if (third == 'C') {
      stringThird = "C";
    }
    else if (third == 'G') {
      stringThird = "G";
    }
    string threeString;
    threeString = stringFirst + stringSecond + stringThird; //codon string
    if ((skipper % 3) == 0 && (threeString == trinucleotide)) {
      counter = counter + 1; //only considers every third nucleotide
    }
    skipper = skipper + 1;
    if (i <= m_size - 3) { //to stay in range
      CURR = CURR -> m_next;
    }
  }
  cout << name << ": " << counter << " identified" << endl;
}

// Sequence
// Identifies and prints all the amino acids in the strand (linked list)
void DNA::Sequence() {
  Nucleotide* CURR;
  Nucleotide* secondNucl;
  Nucleotide* thirdNucl;
  CURR = m_head;
  int skipper = 3;
  char first, second, third;
  string stringFirst, stringSecond, stringThird;
  string *nuclArray;
  nuclArray = new string[m_size]; //dynamically store all the amino acids
  int index = 0;
  for (int j = 0; j <= m_size - TRINUCLEOTIDE_SIZE; j++) {
    secondNucl = CURR -> m_next;
    thirdNucl = secondNucl -> m_next;
    first = CURR -> m_payload;
    second = secondNucl -> m_payload;
    third = thirdNucl -> m_payload;
    if (first == 'A') { //if statements to convert char to string
      stringFirst = "A";
    }
    else if (first == 'T') {
      stringFirst = "T";
    }
    else if (first == 'C') {
      stringFirst = "C";
    }
    else if (first == 'G') {
      stringFirst = "G";
    }
    if (second == 'A') {
      stringSecond = "A";
    }
    else if (second == 'T') {
      stringSecond = "T";
    }
    else if (second == 'C') {
      stringSecond = "C";
    }
    else if (second == 'G') {
      stringSecond = "G";
    }
    if (third == 'A') {
      stringThird = "A";
    }
    else if (third == 'T') {
      stringThird = "T";
    }
    else if (third == 'C') {
      stringThird = "C";
    }
    else if (third == 'G') {
      stringThird = "G";
    }
    string threeString;
    threeString = stringFirst + stringSecond + stringThird;
    string checkedString = Translate(threeString); //calls translate to 
    if (skipper % 3 == 0) {                        //identify amino acids
      nuclArray[index] = checkedString;
      index = index + 1;
    }
    skipper = skipper + 1;
    CURR = CURR -> m_next;
  } 
  int sizeArray = (m_size / TRINUCLEOTIDE_SIZE); 
  cout << "Amino Acid List:" << endl; //prints out list of amino acids
  for (int p = 0; p < index; p++) {   //from dynamic array
    cout << nuclArray[p] << endl;
  }
  cout << "Total Amino Acids Identified: " << sizeArray << endl;
  delete [] nuclArray; //deletes dynamically allocated memory
}

// Translate
// Takes in a string of codon and identifies its coorresponsing amino acid
string DNA::Translate(const string trinucleotide) {
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||(trinucleotide=="CTA")||
	  (trinucleotide=="CTG")|| (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
	  (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
	  (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
	  (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
	  (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
	  (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
	  (trinucleotide=="TCA")||(trinucleotide=="TCG")||
	  (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
	  (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||(trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}

// IsEmpty
// Checks and returns if the linked list is empty
bool DNA::IsEmpty() {
  bool empty;
  if (m_head == NULL && m_tail == NULL) {
    empty = 1;
  }
  else {
    empty = 0; 
  }
  return empty;
}

// SizeOf
// Used to count and produce the size of the linked list
void DNA::SizeOf() {
  m_size = m_size + 1;
}

// Clear
// Used in the destructor to clear the linked list and the dynamically
// allocated memory the linked list occupied
void DNA::Clear() {
  Nucleotide* nuclClear;
  nuclClear = m_head;
  while (nuclClear != NULL) { //traverses through each node
    m_head = m_head -> m_next; 
    delete nuclClear; //deletes it
    nuclClear = m_head;
  }
  m_tail = NULL; //sets to null
  m_head = NULL;
}



