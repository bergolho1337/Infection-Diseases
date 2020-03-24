//
// Created by bergolho on 24/03/20.
//

#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cmath>

class Solver
{
public:
    std::vector<char> the_dna;
    std::vector<char> the_rna_m;

    std::map<std::string,std::string> codons_table;
public:
    Solver (const char filename[]);
    void read_dna_sequence_from_file (const char filename[]);
    void transcribe_dna_to_rna_m ();
    void translate_proteins ();
    void build_codons_table ();
    void print ();

};

char convert_nitrogenous_base (const char base);

#endif
