#
# Created  by rbh
# Modified by nas, 09/09/16
#

# Lines starting with the # symbol are comments.

# These are makefile variables:
INCLUDEDIR     = ../headers/
CXXFLAGS       = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors
PRIMEVAR       = randomPrime checkPrime listPrimes
FACTORIALVAR   = oneFactorial listFactorial
OBJECTS        = prime.o calcFactorial.o
HEADERS        = prime.h factorial.h

# "$(X)" is replaced with the value of the variable "X".
# These are flags for the C++ compiler:
#   -std=c++11     : Use the C++11 language standard
#   -I <dir>       : include files in directory <dir>
#   -Wall          : turn on all warnings
#   -Wfatal-errors : stop compilation after detecting the first error


# vpath is used to add search paths for (source) files.
# Here we add the directory stored in the $(INCLUDEDIR) variable when
# searching for files with a ".h" suffix.
vpath %.h $(INCLUDEDIR)


# "all" is the first target in the file, so "make" and "make all"
# will have the same effect.
all: $(OBJECTS) $(PRIMEVAR) $(FACTORIALVAR)

# Building "randomPrime" depends on its cpp file, and the object and
# header files for "prime".

$(PRIMEVAR): %: %.cpp prime.o
	g++ $(CXXFLAGS) $^ -o $@

$(FACTORIALVAR): %: %.cpp calcFactorial.o
	g++ $(CXXFLAGS) $^ -o $@

$(OBJECTS): %.o: %.cpp $(HEADERS)
	g++ $(CXXFLAGS) -c $< -o $@

# The following rule builds object code (without linking into an executable).
#prime.o : prime.cpp prime.h
#	g++ $(CXXFLAGS) -c prime.cpp -o prime.o
# -c : compile only, no linking
#calcFactorial.o : calcFactorial.cpp factorial.h
#	g++ $(CXXFLAGS) -c calcFactorial.cpp -o calcFactorial.o

# "clean" is a so-called "phoney target".  It doesn't correspond to a file.
# Rather than building anything, it instead performs some clean-up commands.
clean:
	rm -f $(PRIMEVAR) $(FACTORIALVAR) $(OBJECTS)
# -f : force (succeed even if the files to be deleted don't exist)
