

CC = g++ -g
CFLAGS = -c -Wall -ansi -O0 -pedantic -Werror -Wconversion 

# FlagsGTest = -lgtest -lgtest_main -pthread
PathCommandFactory = ../Controller/ControllerCPP/CommandFactory.cpp 
PathNewCommand = ../Controller/ControllerCPP/NewCmd.cpp 
PathLoadCommand = ../Controller/ControllerCPP/LoadCmd.cpp 
PathNucleotideModel = ../Models/ModelsCPP/Nucleotide.cpp 
PathModelDNA = ../Models/ModelsCPP/DNA.cpp 
PathModelDataStructure = ../Models/ModelsCPP/DataStructure.cpp
PathSaveCommand = ../Controller/ControllerCPP/SaveCmd.cpp 
PathListCommand = ../Controller/ControllerCPP/ListCmd.cpp 
PathLenCommand = ../Controller/ControllerCPP/LenCmd.cpp
PathPairCommand = ../Controller/ControllerCPP/PairCmd.cpp
PathView = main.cpp
DNA:  
	$(CC) $(PathView) $(PathCommandFactory) $(PathNewCommand) $(PathLoadCommand) $(PathModelDNA) $(PathNucleotideModel) $(PathModelDataStructure) $(PathSaveCommand) $(PathListCommand) $(PathLenCommand) $(PathPairCommand) -o run
clean:
	rm run