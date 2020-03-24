

file = open("table.txt")

for line in file:
    key, value = line.split()
    bases = value.split(',')
    for base in bases:
        base = base.lower()
        print("this->codons_table[\"%s\"] = \"%s\";" % (base,key))
        if (base.find('t') != -1):
            base = base.replace('t','u')
            print("this->codons_table[\"%s\"] = \"%s\";" % (base,key))
    

file.close()