#Definitions

CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
CCLINK=g++ 
LIBS=
OBJS=polynom.o func.o main.o compfunc.o 
RM=rm -f
TARGET = WolfraMamat

$(TARGET): $(OBJS)
	  $(CCLINK) -o $(TARGET) $(OBJS) $(LIBS)

#Dependencies

polynom.o: polynom.cpp polynom.h
func.o: func.cpp func.h 
compfunc.o: compfunc.cpp compfunc.h 
main.o: main.cpp compfunc.h func.h polynom.h

#Clean

clean:
	  $(RM) WolfraMamat *.o *.bak *~ "#"* core
