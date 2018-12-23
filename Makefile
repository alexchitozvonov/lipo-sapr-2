# Compiler
CC=g++
# Flags to compile an object file from source file
CFLAGS=-c
# C++ flags
CPPFLAGS=-std=c++11
# Flags to compile an executed file from object file
OFLAG=-o
# CppUnit library flags
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
# PCRE library flag
PCRE_FLAG=-lpcrecpp
# Object files folder
OBJ=obj
# Temp files folder
TEMP=temp
# Test file
TESTFILE=test/test.txt
# Output executed file name
OFILE=main

all: $(OFILE) test

$(OFILE): $(OBJ)/main.o $(OBJ)/UniqueC.o $(OBJ)/UniqueCTest.o
	$(CC) $(OBJ)/main.o $(OBJ)/UniqueC.o $(OBJ)/UniqueCTest.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(OFILE)
	
$(OBJ)/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/UniqueC.o: UniqueC/UniqueC.cpp
	$(CC) $(CFLAGS) UniqueC/UniqueC.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/UniqueC.o
	
$(OBJ)/UniqueCTest.o: UniqueCTest/UniqueCTest.cpp
	$(CC) $(CFLAGS) UniqueCTest/UniqueCTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/UniqueCTest.o

test: $(OFILE)
	./$(OFILE) < $(TESTFILE) --test

compare: $(OFILE)
	./$(OFILE) < $(TESTFILE) | sed '$$d' | sort > $(TEMP)/tmp1
	./main.sh < $(TESTFILE) > $(TEMP)/tmp2
	diff $(TEMP)/tmp1 $(TEMP)/tmp2

clean:
	rm -rf main *.o $(OBJ)/*.o $(TEMP)/*