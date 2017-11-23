CXX = g++
CXXFLAGS = -Wall

dnaseq: DNA.o Sequencer.o driver.cpp
	$(CXX) $(CXXFLAGS) DNA.o Sequencer.o driver.cpp -o dnaseq

Sequencer.o: DNA.cpp DNA.h Sequencer.cpp Sequencer.h
	$(CXX) $(CXXFLAGS) -c Sequencer.cpp

DNA.o: DNA.cpp DNA.h
	$(CXX) $(CXXFLAGS) -c DNA.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./dnaseq

run1:
	./dnaseq dnaseq_9.csv

run2:
	./dnaseq dnaseq_60.csv

run3:
	./dnaseq dnaseq_3000.csv

run4:
	./dnaseq dnaseq_15000.csv
