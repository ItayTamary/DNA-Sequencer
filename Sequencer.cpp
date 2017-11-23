/*************************************
 ** File:    Sequencer.cpp
 ** Project: DNA Sequencer
 ** Author:  Itay Tamary
 ** Date:    3/20/17
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code that initates a program that takes in a
 ** a "csv" file of nucleotides and calls functions to manipulate, display,
 ** and translate the file into amino acids.
 ** 
 **
 **************************************/

#include "Sequencer.h"
#include "stdlib.h"
#include <fstream>
#include <iomanip>
using namespace std;

// Sequencer
// Runs the program, sets the file name, calls to read the file, and runs
// the menu and prompts
Sequencer::Sequencer(string fileName) {
  m_fileName = fileName;
  readFile();
  mainMenu();
  cout << "DNA removed from memory" << endl;
}

// ~Sequencer
// Destructor that is never called since there is no dynamically allocated
// memory being created in this function
Sequencer::~Sequencer() {
  //No nodes to clear
}

// mainMenu
// Displays and prompts the users with the functionality of the program
// and calls each corresponding function
void Sequencer::mainMenu() {
  cout << "New Sequencer loaded" << endl;
  int choice = 0;
  while (choice != 5) { //input validation loop
    while (choice < 1 || choice > 5) {
      cout << "What would you like to do?:" << endl;
      cout << "1. Display Sequencer (Leading Strand)" << endl;
      cout << "2. Display Sequencer (Base Pairs)" << endl;
      cout << "3. Inventory Basic Amino Acids" << endl;
      cout << "4. Sequence Entire DNA Strand" << endl;
      cout << "5. Exit" << endl;
      cin >> choice;
    }
    switch (choice) { //switch function to call for desired function
    case 1:
      cout << "Leading Strand: " << endl;
      m_dna.Display(choice);
      choice = 0; //to reprompt the menu after the function is displayed
      break;
    case 2:
      cout << "Base Pairs: " << endl;
      m_dna.Display(choice); 
      choice = 0;
      break;
    case 3:
      m_dna.NumAmino("Tryptophan", "TGG"); //translates two basic amino acid
      m_dna.NumAmino("Phenylalanine", "TTT");
      choice = 0;
      break;
    case 4:
      m_dna.Sequence();
      choice = 0;
      break;
    case 5:
      break;
    }
  }
}

// readFile
// Reads in the desired "csv" file, converts each nucleotide to a char,
// adds it to the end of list, and counts the length of the strand
void Sequencer::readFile() {
  string *line; 
  string stringBlock;
  line = new string[1]; //dynamic array of strings
  int counter = 0;
  char block;
  fstream inputStream;
  inputStream.open(m_fileName.c_str()); //opens fileName with c-string
  while (inputStream) {
    getline(inputStream, line[0]);
    stringBlock = line[0]; //string of nucleotide
    block = stringBlock.c_str()[0]; //converts string to char nucleotide
    m_dna.InsertEnd(block); //adds it to the end of the linked list
    counter = counter + 1; //counts how many times a nucleotide is added
    
  }
  for (int i = 1; i < counter; i++) {
    m_dna.SizeOf(); //runs a for loop to remove any white space
  }                 //to correctly determine the size of the linked list
  delete [] line; //deletes dynamically allocated array
}

