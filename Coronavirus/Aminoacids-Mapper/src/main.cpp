// =================================================================================================================
// Author: Lucas Berg
// Program that given an input DNA sequence transcribe it into a protein sequence.
// -----------------------------------------------------------------------------------------------------------------
// --> URL: https://www.ncbi.nlm.nih.gov/nuccore/NC_045512                                      
// Severe acute respiratory syndrome coronavirus 2 isolate Wuhan-Hu-1, complete genome
// --> URL: https://www.ncbi.nlm.nih.gov/nuccore/MT126808.1
// Severe acute respiratory syndrome coronavirus 2 isolate SARS-CoV-2/SP02/human/2020/BRA, complete genome
// =================================================================================================================

#include <iostream>
#include "solver/solver.h"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "================================================================================================================" << endl;
        cout << "Usage:> " << argv[0] << " <input_file>" << endl;
        cout << "================================================================================================================" << endl;
        cout << "<input_file> = Input file with the DNA sequence to be translated" << endl;
        cout << "================================================================================================================" << endl;
        cout << "Example:> ./bin/Aminoacids-Mapper inputs/wuhan-1/input.txt > outputs/wuhan-1/output.txt" << endl;
        cout << "          ./bin/Aminoacids-Mapper inputs/brazil/input.txt > outputs/brazil/output.txt" << endl;
        cout << "================================================================================================================" << endl;
        exit(EXIT_FAILURE);
    }

    char *input_filename = argv[1];

    Solver *the_solver = new Solver(input_filename);
    //the_solver->print();

    the_solver->translate_proteins();

    delete the_solver;

    return 0;
}