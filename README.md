# DNA-Sequencer
DNA Sequencer - Takes in sequence of nucleotides, convert to DNA, outputs Amino Acid and DNA strand

March 2017

Grade: A+ 100% (80/80)

To run:

  To compile: Using makefile: "make"
  
  To exectute: There are four differents strands (CSV), "make run1", "make run2", "make run3", "make run4"
  
  Rules:
  
 There are four test files available. They are dnaseq_numSize.csv. For example, dnaseq_60.csv has 60 nucleotides. dnaseq_15000.csv has 15,000 nucleotides. We should be able to test a file of any size (within reason). We provided test files with 9, 60, 3000, and 15000 nucleotides.

•	You need to write the functions for the class (DNA.cpp) based on the header file (DNA.h). The nucleotides (i.e. Nodes) for the linked list that you are implementing are structs that hold two pieces of information – a char and a pointer to the next node. Do not use the STL for this project.

o	DNA() – The constructor creates a new empty linked list. m_head and m_tail are always NULL and m_size is zero.

o	~DNA() – The destructor de-allocates any dynamically allocated memory. (May call clear)

o	Clear() – Clears the linked list.

o	InsertEnd() – Always inserts new nucleotides at the end of the linked list.

o	Display() – Takes in a variable to know how many strands you want to display. 1 shows just the nucleotides that were loaded. 2 shows the nucleotides and their complements (G-C), (C-G), (T-A), or (T-A).

o	IsEmpty() – Returns if the linked list is empty.

o	SizeOf() – Populates m_size of sequencer with how many nucleotides were loaded.

o	NumAmino() – Takes in the name and trinucleotide codon. Counts the number of instances of that trinucleotide codon in just the provided strand. For example, it could take Tryptophan and TGG or Phenylalanine and TTT. It then iterates over the structure to count how many instances of those amino acids exist in the DNA. Additionally, if we had the sequence T-T-T-T-G-G, we would have exactly 2 codons (TTT) and (TGG). The same if we had a sequence that was 15,000 nucleotides long. We would have exactly 5,000 trinucleotide codons. We never count overlapping codons. Run numAmino on at least Tryptophan (TGG) and Phenylalanine (TTT).

o	Sequence() – Iterates over entire structure and converts trinucleotides to amino acids for all nucleotides in the file. Stores the amino acid name in a dynamic array. Displays amino acid list.

o	Translate() – Converts a trinucleotide string to an amino acid name. 

o	Sequencer() – The constructor builds the DNA (linked list), reads the file, and calls mainMenu.

o	~Sequencer() – The destructor de-allocates any dynamically allocated memory. 

o	ReadFile()– The ReadFile function loads a file of nucleotides into the DNA (linked list). The file itself is passed to the ReadFile function from the command line (in driver.cpp which is provided). Also, calls SizeOf to populate m_size.

o	MainMenu() – Calls the various functions in the DNA (linked list).

	Choices (1 and 2) – calls the DNA function Display. 

	Choice 3 – calls the DNA function NumAmino.

	Choice 4 - calls the DNA function Sequence. 

	Choice 5 - Exits.
