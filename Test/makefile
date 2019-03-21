CC = g++ -ansi -pedantic -Wall -Wconversion
CFLAGS = -Wall -ansi -O0 -pedantic -Werror -Wconversion -lgtest -lgtest_main -pthread 
# FlagsGTest = -lgtest -lgtest_main -pthread
# PathCommandFactory = ../Controller/ControllerCPP/CommandFactory.cpp 
PathNewCommand = ../Controller/ControllerCPP/NewCmd.cpp 
# PathLoadCommand = ../Controller/ControllerCPP/LoadCmd.cpp 
PathNucleotideModel = ../Models/ModelsCPP/Nucleotide.cpp 
PathModelDNA = ../Models/ModelsCPP/DNA.cpp 
PathModelDataStructure = ../Models/ModelsCPP/DataStructure.cpp
# PathSaveCommand = ../Controller/ControllerCPP/SaveCmd.cpp 
PathListCommand = ../Controller/ControllerCPP/ListCmd.cpp 
PathLenCommand = ../Controller/ControllerCPP/LenCmd.cpp 
PathTest = test.cpp
TEST:  
	$(CC) $(PathTest) $(PathNewCommand) $(PathModelDNA) $(PathNucleotideModel) $(PathModelDataStructure) $(PathListCommand) $(PathLenCommand) $(CFLAGS) -o test
clean:
	rm test