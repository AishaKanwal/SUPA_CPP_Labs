CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
# TARGET=FiniteFunctions
# OBJECTS=FiniteFunctions.o 
TARGET=Test #Executable name
OBJECTS=Test.o FiniteFunctions.o readmystery.o CustomFunctions.o # Added readmystery.o  and CustomFunctions.o to OBJECTS
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

Test.o : Test.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c Test.cxx

FiniteFunctions.o : FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

readmystery.o : readmystery.cpp readmystery.h #added target for readmystery.o
	${CC} ${FLAGS} ${LIBS} -c readmystery.cpp 

CustomFunctions.o : CustomFunctions.cxx CustomFunctions.h FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c CustomFunctions.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
