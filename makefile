# simple makefile
#
# macro definitions
# $@ 	= the target
# $?	= all pre-requisites newer than the target
# #^	= all pre-requisites (dependencies)
#

CXXFLAGS = -std=c++11 -Wall -O3 -g 
LDFLAGS = 

# by default, the first target is the default target
#
# build the executable from the binary objects

test: array_copy.o
	$(CXX) $^ -o $@ $(LDFLAGS)
# g++ -o test array_copy.o 
#
# build all binary objects 

array_copy.o: array_copy.cpp
# use make's default rule for building cpp into o
#	 $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@


clean:
	rm -f *.o test

