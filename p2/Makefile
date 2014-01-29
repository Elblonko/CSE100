# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -std=c++11 -g -Wall

#include debugging symbols in executable
LDFLAGS= -g	

benchtree: benchtree.o countint.o
	g++ -o benchtree -g benchtree.o countint.o

countint.o: countint.hpp

benchtree.o: BST.hpp BSTNode.hpp BSTIterator.hpp RST.hpp


