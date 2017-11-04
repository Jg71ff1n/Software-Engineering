#
# Created  by rbh
# Modified by nas, 09/09/16
#

# Lines starting with the # symbol are comments.

# These are makefile variables:
INCLUDEDIR = ../headers/
CXXFLAGS   = -std=c++11 -I $(INCLUDEDIR) -Wall -Wfatal-errors
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
all: randomPrime checkPrime

# Building "randomPrime" depends on its cpp file, and the object and
# header files for "prime".
randomPrime: randomPrime.cpp prime.o
	g++ $(CXXFLAGS) randomPrime.cpp prime.o -o randomPrime
# -o <filename> : specify that the name of the output file should be <filename>

checkPrime: checkPrime.cpp prime.o
	g++ $(CXXFLAGS) checkPrime.cpp prime.o -o checkPrime

# The following rule builds object code (without linking into an executable).
prime.o : prime.cpp prime.h
	g++ $(CXXFLAGS) -c prime.cpp -o prime.o
# -c : compile only, no linking

# "clean" is a so-called "phoney target".  It doesn't correspond to a file.
# Rather than building anything, it instead performs some clean-up commands.
clean:
	rm -f prime.o randomPrime checkPrime
# -f : force (succeed even if the files to be deleted don't exist)
