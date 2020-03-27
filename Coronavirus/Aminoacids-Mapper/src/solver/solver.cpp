#include "solver.h"

Solver::Solver (const char filename[])
{
    // Read the DNA sequence
    read_dna_sequence_from_file(filename);

    // Transcribe the DNA into RNAm
    transcribe_dna_to_rna_m();

    // Build the codons table for protein synthesis
    build_codons_table();
    
}

void Solver::read_dna_sequence_from_file (const char filename[])
{
    FILE *file = fopen(filename,"r");
    if (!file)
    {
        std::cerr << "[-] ERROR! Cannot open file '" << filename << "' !" << std::endl;
        exit(EXIT_FAILURE);
    }

    char letter;
    while (fscanf(file,"%c",&letter) != EOF)
    {
        this->the_dna.push_back(letter);
    }

    fclose(file);
}

void Solver::transcribe_dna_to_rna_m ()
{
    for (uint32_t i = 0; i < this->the_dna.size(); i++)
    {
        char base = convert_nitrogenous_base(this->the_dna[i]);

        this->the_rna_m.push_back(base);
    }
}

void Solver::translate_proteins ()
{ 
    // Flag to start the aminoacids sequence
    bool is_generating = false;
 
    // Let the RNAt pass through the RNAm
    std::string code_sequence;
    uint32_t counter = 0;
    uint32_t dna_size = this->the_dna.size();

    uint32_t i = 0;
    while (i < dna_size)
    {
        // TODO: Improve this .... kkkkk
        char base[4];
        base[0] = this->the_dna[i];
        base[1] = this->the_dna[i+1];
        base[2] = this->the_dna[i+2];
        base[3] = '\0';

        std::string key(base);
        std::string value = this->codons_table[key];

        // Find the initialization codon
        if (!is_generating)
        {
            // If the codon is Methionine then start encoding ...
            if (value == "M")
            {
                is_generating = true;
                code_sequence = "M";

                i += 3;

                //std::cout << "Start = " << i << std::endl;
            }
            else
            {
                // We pass through one nitrogen base at the time
                i++;
            }
            
        }
        // Reading codons ...
        else
        {
            // If the codon is a termination one then stop encoding
            if (value == "#")
            {
                is_generating = false;
                counter++;

                //std::cout << "End = " << i << std::endl;

                std::cout << "Protein " << counter << " = " << code_sequence << std::endl;
            }

            code_sequence += value;

            i += 3;
        }

        // DEBUG
        //std::cout << i << ": " << base << " --> " << value << std::endl;
    }


/*
    std::cout << "================================ DNA ===========================================" << std::endl;
    for (uint32_t i = 0; i < this->the_dna.size(); i += 3)
    {

        // TODO: Improve this .... kkkkk
        char base[4];
        base[0] = this->the_dna[i];
        base[1] = this->the_dna[i+1];
        base[2] = this->the_dna[i+2];
        base[3] = '\0';

        std::string key(base);
        std::string value = this->codons_table[key];

        // If the codon is Methionine then start encoding ...
        if (value == "M")
        {
            is_generating = true;
            code_sequence = "";
        }
        // If the codon is a termination one then stop encoding
        else if (value == "#")
        {
            is_generating = false;
            counter++;

            //std::cout << "Protein " << counter << " = " << code_sequence << std::endl;
        }
            
        if (is_generating)
            code_sequence += value;
        
        // DEBUG
        std::cout << i << ": " << base << " --> " << value << std::endl;
    }
    std::cout << "================================ DNA ===========================================" << std::endl;
*/
}

void Solver::build_codons_table ()
{
    // Long name codons table
/*
this->codons_table["gct"] = "Ala";
this->codons_table["gcu"] = "Ala";
this->codons_table["gcc"] = "Ala";
this->codons_table["gca"] = "Ala";
this->codons_table["gcg"] = "Ala";
this->codons_table["att"] = "Ile";
this->codons_table["auu"] = "Ile";
this->codons_table["atc"] = "Ile";
this->codons_table["auc"] = "Ile";
this->codons_table["ata"] = "Ile";
this->codons_table["aua"] = "Ile";
this->codons_table["cgt"] = "Arg";
this->codons_table["cgu"] = "Arg";
this->codons_table["cgc"] = "Arg";
this->codons_table["cga"] = "Arg";
this->codons_table["cgg"] = "Arg";
this->codons_table["aga"] = "Arg";
this->codons_table["agg"] = "Arg";
this->codons_table["ctt"] = "Leu";
this->codons_table["cuu"] = "Leu";
this->codons_table["ctc"] = "Leu";
this->codons_table["cuc"] = "Leu";
this->codons_table["cta"] = "Leu";
this->codons_table["cua"] = "Leu";
this->codons_table["ctg"] = "Leu";
this->codons_table["cug"] = "Leu";
this->codons_table["tta"] = "Leu";
this->codons_table["uua"] = "Leu";
this->codons_table["ttg"] = "Leu";
this->codons_table["uug"] = "Leu";
this->codons_table["aat"] = "Asn";
this->codons_table["aau"] = "Asn";
this->codons_table["aac"] = "Asn";
this->codons_table["aaa"] = "Lys";
this->codons_table["aag"] = "Lys";
this->codons_table["gat"] = "Asp";
this->codons_table["gau"] = "Asp";
this->codons_table["gac"] = "Asp";
this->codons_table["atg"] = "Met";
this->codons_table["aug"] = "Met";
this->codons_table["ttt"] = "Phe";
this->codons_table["uuu"] = "Phe";
this->codons_table["ttc"] = "Phe";
this->codons_table["uuc"] = "Phe";
this->codons_table["tgt"] = "Cys";
this->codons_table["ugu"] = "Cys";
this->codons_table["tgc"] = "Cys";
this->codons_table["ugc"] = "Cys";
this->codons_table["cct"] = "Pro";
this->codons_table["ccu"] = "Pro";
this->codons_table["ccc"] = "Pro";
this->codons_table["cca"] = "Pro";
this->codons_table["ccg"] = "Pro";
this->codons_table["caa"] = "Gln";
this->codons_table["cag"] = "Gln";
this->codons_table["tct"] = "Ser";
this->codons_table["ucu"] = "Ser";
this->codons_table["tcc"] = "Ser";
this->codons_table["ucc"] = "Ser";
this->codons_table["tca"] = "Ser";
this->codons_table["uca"] = "Ser";
this->codons_table["tcg"] = "Ser";
this->codons_table["ucg"] = "Ser";
this->codons_table["agt"] = "Ser";
this->codons_table["agu"] = "Ser";
this->codons_table["agc"] = "Ser";
this->codons_table["gaa"] = "Glu";
this->codons_table["gag"] = "Glu";
this->codons_table["act"] = "Thr";
this->codons_table["acu"] = "Thr";
this->codons_table["acc"] = "Thr";
this->codons_table["aca"] = "Thr";
this->codons_table["acg"] = "Thr";
this->codons_table["tgg"] = "Trp";
this->codons_table["ugg"] = "Trp";
this->codons_table["ggt"] = "Gly";
this->codons_table["ggu"] = "Gly";
this->codons_table["ggc"] = "Gly";
this->codons_table["gga"] = "Gly";
this->codons_table["ggg"] = "Gly";
this->codons_table["tat"] = "Tyr";
this->codons_table["uau"] = "Tyr";
this->codons_table["tac"] = "Tyr";
this->codons_table["uac"] = "Tyr";
this->codons_table["cat"] = "His";
this->codons_table["cau"] = "His";
this->codons_table["cac"] = "His";
this->codons_table["gtt"] = "Val";
this->codons_table["guu"] = "Val";
this->codons_table["gtc"] = "Val";
this->codons_table["guc"] = "Val";
this->codons_table["gta"] = "Val";
this->codons_table["gua"] = "Val";
this->codons_table["gtg"] = "Val";
this->codons_table["gug"] = "Val";
this->codons_table["taa"] = "STOP";
this->codons_table["uaa"] = "STOP";
this->codons_table["tga"] = "STOP";
this->codons_table["uga"] = "STOP";
this->codons_table["tag"] = "STOP";
this->codons_table["uag"] = "STOP";
*/

  // Short name codons table
this->codons_table["gct"] = "A";
this->codons_table["gcu"] = "A";
this->codons_table["gcc"] = "A";
this->codons_table["gca"] = "A";
this->codons_table["gcg"] = "A";
this->codons_table["att"] = "I";
this->codons_table["auu"] = "I";
this->codons_table["atc"] = "I";
this->codons_table["auc"] = "I";
this->codons_table["ata"] = "I";
this->codons_table["aua"] = "I";
this->codons_table["cgt"] = "R";
this->codons_table["cgu"] = "R";
this->codons_table["cgc"] = "R";
this->codons_table["cga"] = "R";
this->codons_table["cgg"] = "R";
this->codons_table["aga"] = "R";
this->codons_table["agg"] = "R";
this->codons_table["ctt"] = "L";
this->codons_table["cuu"] = "L";
this->codons_table["ctc"] = "L";
this->codons_table["cuc"] = "L";
this->codons_table["cta"] = "L";
this->codons_table["cua"] = "L";
this->codons_table["ctg"] = "L";
this->codons_table["cug"] = "L";
this->codons_table["tta"] = "L";
this->codons_table["uua"] = "L";
this->codons_table["ttg"] = "L";
this->codons_table["uug"] = "L";
this->codons_table["aat"] = "N";
this->codons_table["aau"] = "N";
this->codons_table["aac"] = "N";
this->codons_table["aaa"] = "K";
this->codons_table["aag"] = "K";
this->codons_table["gat"] = "D";
this->codons_table["gau"] = "D";
this->codons_table["gac"] = "D";
this->codons_table["atg"] = "M";
this->codons_table["aug"] = "M";
this->codons_table["ttt"] = "F";
this->codons_table["uuu"] = "F";
this->codons_table["ttc"] = "F";
this->codons_table["uuc"] = "F";
this->codons_table["tgt"] = "C";
this->codons_table["ugu"] = "C";
this->codons_table["tgc"] = "C";
this->codons_table["ugc"] = "C";
this->codons_table["cct"] = "P";
this->codons_table["ccu"] = "P";
this->codons_table["ccc"] = "P";
this->codons_table["cca"] = "P";
this->codons_table["ccg"] = "P";
this->codons_table["caa"] = "Q";
this->codons_table["cag"] = "Q";
this->codons_table["tct"] = "S";
this->codons_table["ucu"] = "S";
this->codons_table["tcc"] = "S";
this->codons_table["ucc"] = "S";
this->codons_table["tca"] = "S";
this->codons_table["uca"] = "S";
this->codons_table["tcg"] = "S";
this->codons_table["ucg"] = "S";
this->codons_table["agt"] = "S";
this->codons_table["agu"] = "S";
this->codons_table["agc"] = "S";
this->codons_table["gaa"] = "E";
this->codons_table["gag"] = "E";
this->codons_table["act"] = "T";
this->codons_table["acu"] = "T";
this->codons_table["acc"] = "T";
this->codons_table["aca"] = "T";
this->codons_table["acg"] = "T";
this->codons_table["tgg"] = "W";
this->codons_table["ugg"] = "W";
this->codons_table["ggt"] = "G";
this->codons_table["ggu"] = "G";
this->codons_table["ggc"] = "G";
this->codons_table["gga"] = "G";
this->codons_table["ggg"] = "G";
this->codons_table["tat"] = "Y";
this->codons_table["uau"] = "Y";
this->codons_table["tac"] = "Y";
this->codons_table["uac"] = "Y";
this->codons_table["cat"] = "H";
this->codons_table["cau"] = "H";
this->codons_table["cac"] = "H";
this->codons_table["gtt"] = "V";
this->codons_table["guu"] = "V";
this->codons_table["gtc"] = "V";
this->codons_table["guc"] = "V";
this->codons_table["gta"] = "V";
this->codons_table["gua"] = "V";
this->codons_table["gtg"] = "V";
this->codons_table["gug"] = "V";
this->codons_table["taa"] = "#";
this->codons_table["uaa"] = "#";
this->codons_table["tga"] = "#";
this->codons_table["uga"] = "#";
this->codons_table["tag"] = "#";
this->codons_table["uag"] = "#";
  
}

void Solver::print ()
{
    std::cout << "================== DNA ==============================" << std::endl;
    for (uint32_t i = 0; i < this->the_dna.size(); i++)
        std::cout << this->the_dna[i];
    std::cout << std::endl;
    std::cout << "================== DNA ==============================" << std::endl;

    std::cout << "================== RNAm ==============================" << std::endl;
    for (uint32_t i = 0; i < this->the_rna_m.size(); i++)
        std::cout << this->the_rna_m[i];
    std::cout << std::endl;
    std::cout << "================== RNAm ==============================" << std::endl;

}

char convert_nitrogenous_base (const char base)
{
    switch (base)
    {
        case 'a': return 'u';
        case 'u': return 'a';
        case 't': return 'a';
        case 'c': return 'g';
        case 'g': return 'c';

        default:
        {
            std::cerr << "[-] ERROR! Invalid nitrogenous_base '" << base << "' !" << std::endl;
            exit(EXIT_FAILURE);
        }
    } 
}