INCLUDEDIR    		 = ../headers/
CXXFLAGS       		= -m64 -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors -O3
PRIMEBEST      		= primeFactors-BestStudent_2016-2017.o
PRIMEOPTIMISED 		= primeFactors-Optimised.o
PRIMEFACTORS   		= primeFactors.o
PRIMEFACTORSMULTI 	= primeFactorsMulti.o
ALLTESTS       		= correctnessTestBest timingTestsBest correctnessTestOptimised timingTestsOptimised timingTestsPrimes correctnessTestPrimes primeFactorMain timingTestsMulti correctnessTestMulti


vpath %.h $(INCLUDEDIR)

all: $(ALLTESTS)

correctnessTestBest: $(PRIMEBEST) correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@

timingTestsBest: $(PRIMEBEST) timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@

correctnessTestOptimised: $(PRIMEOPTIMISED) correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@

timingTestsOptimised: $(PRIMEOPTIMISED) timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@

correctnessTestPrimes: $(PRIMEFACTORS) correctnessTests.cpp
	g++ $(CXXFLAGS) $^ -lboost_unit_test_framework -o $@

timingTestsPrimes: $(PRIMEFACTORS) timingTests.cpp
	g++ $(CXXFLAGS) $^ -o $@
	
timingTestsMulti: $(PRIMEFACTORSMULTI) timingTests.cpp
	g++ $(CXXFLAGS) -pthread $^ -o $@
	
correctnessTestMulti: $(PRIMEFACTORSMULTI) correctnessTests.cpp
	g++ $(CXXFLAGS) -pthread $^ -lboost_unit_test_framework -o $@
	
primeFactorMain: $(PRIMEFACTORS) main.cpp
	g++ $(CXXFLAGS) $^ -o $@

primeFactors.o: primeFactors.cpp
	g++ $(CXXFLAGS) -c $^ -o $@

primeFactorsMulti.o: primeFactorsMulti.cpp
	g++ $(CXXFLAGS) -c -pthread $^ -o $@

clean:
	rm -f $(ALLTESTS) $(PRIMEFACTORS) 
