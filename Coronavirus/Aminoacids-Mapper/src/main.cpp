// =================================================================================================================
// Author: Lucas Berg
// Program that given an input DNA sequence transcribe it to RNAm and them translate into a set aminoacids.
// -----------------------------------------------------------------------------------------------------------------
// --> URL: https://www.ncbi.nlm.nih.gov/nuccore/NC_045512
// Severe acute respiratory syndrome coronavirus 2 isolate Wuhan-Hu-1, complete genome
// =================================================================================================================

#include <iostream>
#include "solver/solver.h"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        cout << "================================================================================================================" << endl;
        cout << "Usage:> " << argv[0] << " <dna_sequence>" << endl;
        cout << "================================================================================================================" << endl;
        cout << "<dna_sequence> = DNA sequence to be translated" << endl;
        cout << "================================================================================================================" << endl;
        cout << "Example:> ./bin/Aminoacids-Mapper inputs/coronavirus-dna-sequence.txt > outputs/aminoacids_sequence.txt" << endl;
        cout << "================================================================================================================" << endl;
        exit(EXIT_FAILURE);
    }

    char *dna_sequence_filename = argv[1];

    Solver *the_solver = new Solver(dna_sequence_filename);
    //the_solver->print();

    the_solver->translate_proteins();

    delete the_solver;

    return 0;
}