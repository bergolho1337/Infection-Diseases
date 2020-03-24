# Data taken from:
# ----------------------------------------------------------------------------------------------
# URL: https://www.ncbi.nlm.nih.gov/nuccore/NC_045512
# Severe acute respiratory syndrome coronavirus 2 isolate Wuhan-Hu-1, complete genome
# ----------------------------------------------------------------------------------------------

import sys

def main():
	
    if len(sys.argv) != 1:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        return 1

    input_file = open("coronavirus-sequence.txt","r")
    output_file = open("coronavirus-dna-sequence.txt","w")

    buffer = input_file.read()

    for s in " \n0123456789":
        buffer = buffer.replace(s,"")

    output_file.write(buffer)

    input_file.close()
    output_file.close()


if __name__ == "__main__":
	main()
