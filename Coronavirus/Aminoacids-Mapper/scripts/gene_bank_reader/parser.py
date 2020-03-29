import sys

def read_dna_sequence_from_file (filename):
    file = open(filename,"r")

    dna_sequence = []
    counter = 0
    for line in file:
        if (counter != 0):
            for letter in line:
                if (letter != "\n"):
                    dna_sequence.append(letter.lower())
        counter = counter + 1

    file.close()

    return dna_sequence

def read_gene_sequence_from_file (filename):
    file = open(filename,"r")
    buffer = file.read()

    start_protein_index = 0
    gene_sequence = []
    while (start_protein_index != -1):
        start_protein_index = buffer.find("lcl",start_protein_index+1)
        
        end_protein_index = buffer.find("\n",start_protein_index)

        protein_info = buffer[start_protein_index:end_protein_index]
        protein_attrib = protein_info.split(" ")
        
        if (len(protein_info) > 0):
            for k in range(1,len(protein_attrib)):
                
                info = protein_attrib[k]
                for s in "[]": 
                    info = info.replace(s,"")
                tokens = info.split("=")
                key, name = tokens[0], tokens[1]

                if (key == "gene"):
                    gene_name = name
                
                if (key == "location"):
                    tokens = info.split("=")
                    tokens2 = tokens[1].split("..")
                    location_start, location_end = tokens2[0], tokens2[1]
            
            
            i = end_protein_index
            code_sequence = []
            while (i < len(buffer) and buffer[i] != ">"):
                if (buffer[i] != "\n"):
                    code_sequence.append(buffer[i].lower())
                i = i + 1

            gene_sequence.append([gene_name,location_start,location_end,code_sequence])

    file.close()

    return gene_sequence

def read_protein_sequence_from_file (filename):
    file = open(filename,"r")
    buffer = file.read()

    start_protein_index = 0
    proteins = []
    while (start_protein_index != -1):

        start_protein_index = buffer.find("lcl",start_protein_index+1)
        end_protein_index = buffer.find("\n",start_protein_index)
        
        i = end_protein_index
        protein_sequence = []
        while (i < len(buffer) and buffer[i] != ">"):
            if (buffer[i] != "\n"):
                protein_sequence.append(buffer[i])
            i = i + 1
    
        if (len(protein_sequence) > 0):
            proteins.append(protein_sequence)

    file.close()

    return proteins

def write_input_file_for_mapper (dna_sequence,gene_sequence):
    file = open("inputs/input.txt","w")

    file.write("%d\n" % (len(dna_sequence)))
    for letter in dna_sequence:
        file.write("%s" % (letter))
    file.write("\n")

    file.write("%d\n" % (len(gene_sequence)))
    for i in range(len(gene_sequence)):
        file.write("%s %s\n" % (gene_sequence[i][1],gene_sequence[i][2]))    

    file.close()

def write_output_file_for_mapper (proteins_sequence):
    file = open("outputs/output.txt","w")

    file.write("%d\n" % (len(proteins_sequence)))
    for i in range(len(proteins_sequence)):               # Avoid the first protein ()
        for letter in proteins_sequence[i]:
            file.write("%s" % (letter))
        file.write("\n")

    file.close()

def main():
	
    if len(sys.argv) != 4:
        print("----------------------------------------------------------------------------------------------------------------")
        print("Usage:> python %s <dna_sequence> <gene_sequence> <protein_sequence>" % sys.argv[0])
        print("----------------------------------------------------------------------------------------------------------------")
        return 1

    dna_filename = sys.argv[1]
    gene_filename = sys.argv[2]
    protein_filename = sys.argv[3]

    dna_sequence = read_dna_sequence_from_file(dna_filename)
    #print(dna_sequence)

    gene_sequence = read_gene_sequence_from_file(gene_filename)
    #print(gene_sequence)

    proteins_sequence = read_protein_sequence_from_file(protein_filename)
    #print(proteins_sequence)

    write_input_file_for_mapper(dna_sequence,gene_sequence)
    write_output_file_for_mapper(proteins_sequence)    



if __name__ == "__main__":
	main()
