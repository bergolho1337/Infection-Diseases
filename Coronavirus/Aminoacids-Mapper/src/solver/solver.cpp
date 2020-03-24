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
    // Let the RNAt pass through the RNAm 
    for (uint32_t i = 0; i < this->the_rna_m.size(); i += 3)
    {
        // TODO: Improve this .... kkkkk
        char base[4];
        base[0] = this->the_rna_m[i];
        base[1] = this->the_rna_m[i+1];
        base[2] = this->the_rna_m[i+2];
        base[3] = '\0';

        std::string key(base);
        std::string value = this->codons_table[key];

        std::cout << base << " --> " << value << std::endl;
    }
}

void Solver::build_codons_table ()
{
    this->codons_table["gct"] = "Ala/A";
    this->codons_table["gcu"] = "Ala/A";
    this->codons_table["gcc"] = "Ala/A";
    this->codons_table["gca"] = "Ala/A";
    this->codons_table["gcg"] = "Ala/A";
    this->codons_table["att"] = "Ile/I";
    this->codons_table["auu"] = "Ile/I";
    this->codons_table["atc"] = "Ile/I";
    this->codons_table["auc"] = "Ile/I";
    this->codons_table["ata"] = "Ile/I";
    this->codons_table["aua"] = "Ile/I";
    this->codons_table["cgt"] = "Arg/R";
    this->codons_table["cgu"] = "Arg/R";
    this->codons_table["cgc"] = "Arg/R";
    this->codons_table["cga"] = "Arg/R";
    this->codons_table["cgg"] = "Arg/R";
    this->codons_table["aga"] = "Arg/R";
    this->codons_table["agg"] = "Arg/R";
    this->codons_table["ctt"] = "Leu/L";
    this->codons_table["cuu"] = "Leu/L";
    this->codons_table["ctc"] = "Leu/L";
    this->codons_table["cuc"] = "Leu/L";
    this->codons_table["cta"] = "Leu/L";
    this->codons_table["cua"] = "Leu/L";
    this->codons_table["ctg"] = "Leu/L";
    this->codons_table["cug"] = "Leu/L";
    this->codons_table["tta"] = "Leu/L";
    this->codons_table["uua"] = "Leu/L";
    this->codons_table["ttg"] = "Leu/L";
    this->codons_table["uug"] = "Leu/L";
    this->codons_table["aat"] = "Asn/N";
    this->codons_table["aau"] = "Asn/N";
    this->codons_table["aac"] = "Asn/N";
    this->codons_table["aaa"] = "Lys/K";
    this->codons_table["aag"] = "Lys/K";
    this->codons_table["gat"] = "Asp/D";
    this->codons_table["gau"] = "Asp/D";
    this->codons_table["gac"] = "Asp/D";
    this->codons_table["atg"] = "Met/M";
    this->codons_table["aug"] = "Met/M";
    this->codons_table["aat"] = "Asn:Asp/B";
    this->codons_table["aau"] = "Asn:Asp/B";
    this->codons_table["aac"] = "Asn:Asp/B";
    this->codons_table["gat"] = "Asn:Asp/B";
    this->codons_table["gau"] = "Asn:Asp/B";
    this->codons_table["gac"] = "Asn:Asp/B";
    this->codons_table["ttt"] = "Phe/F";
    this->codons_table["uuu"] = "Phe/F";
    this->codons_table["ttc"] = "Phe/F";
    this->codons_table["uuc"] = "Phe/F";
    this->codons_table["tgt"] = "Cys/C";
    this->codons_table["ugu"] = "Cys/C";
    this->codons_table["tgc"] = "Cys/C";
    this->codons_table["ugc"] = "Cys/C";
    this->codons_table["cct"] = "Pro/P";
    this->codons_table["ccu"] = "Pro/P";
    this->codons_table["ccc"] = "Pro/P";
    this->codons_table["cca"] = "Pro/P";
    this->codons_table["ccg"] = "Pro/P";
    this->codons_table["caa"] = "Gln/Q";
    this->codons_table["cag"] = "Gln/Q";
    this->codons_table["tct"] = "Ser/S";
    this->codons_table["ucu"] = "Ser/S";
    this->codons_table["tcc"] = "Ser/S";
    this->codons_table["ucc"] = "Ser/S";
    this->codons_table["tca"] = "Ser/S";
    this->codons_table["uca"] = "Ser/S";
    this->codons_table["tcg"] = "Ser/S";
    this->codons_table["ucg"] = "Ser/S";
    this->codons_table["agt"] = "Ser/S";
    this->codons_table["agu"] = "Ser/S";
    this->codons_table["agc"] = "Ser/S";
    this->codons_table["gaa"] = "Glu/E";
    this->codons_table["gag"] = "Glu/E";
    this->codons_table["act"] = "Thr/T";
    this->codons_table["acu"] = "Thr/T";
    this->codons_table["acc"] = "Thr/T";
    this->codons_table["aca"] = "Thr/T";
    this->codons_table["acg"] = "Thr/T";
    this->codons_table["caa"] = "Gln:Glu/Z";
    this->codons_table["cag"] = "Gln:Glu/Z";
    this->codons_table["gaa"] = "Gln:Glu/Z";
    this->codons_table["gag"] = "Gln:Glu/Z";
    this->codons_table["tgg"] = "Trp/W";
    this->codons_table["ugg"] = "Trp/W";
    this->codons_table["ggt"] = "Gly/G";
    this->codons_table["ggu"] = "Gly/G";
    this->codons_table["ggc"] = "Gly/G";
    this->codons_table["gga"] = "Gly/G";
    this->codons_table["ggg"] = "Gly/G";
    this->codons_table["tat"] = "Tyr/Y";
    this->codons_table["uau"] = "Tyr/Y";
    this->codons_table["tac"] = "Tyr/Y";
    this->codons_table["uac"] = "Tyr/Y";
    this->codons_table["cat"] = "His/H";
    this->codons_table["cau"] = "His/H";
    this->codons_table["cac"] = "His/H";
    this->codons_table["gtt"] = "Val/V";
    this->codons_table["guu"] = "Val/V";
    this->codons_table["gtc"] = "Val/V";
    this->codons_table["guc"] = "Val/V";
    this->codons_table["gta"] = "Val/V";
    this->codons_table["gua"] = "Val/V";
    this->codons_table["gtg"] = "Val/V";
    this->codons_table["gug"] = "Val/V";
    this->codons_table["atg"] = "START";
    this->codons_table["aug"] = "START";
    this->codons_table["taa"] = "STOP";
    this->codons_table["uaa"] = "STOP";
    this->codons_table["tga"] = "STOP";
    this->codons_table["uga"] = "STOP";
    this->codons_table["tag"] = "STOP";
    this->codons_table["uag"] = "STOP";
    
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