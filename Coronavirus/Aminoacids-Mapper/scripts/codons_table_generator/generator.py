

file = open("table.txt")

for line in file:
    key, value = line.split()
    keys = key.split('/')
    long_name = keys[0]
    short_name = keys[1]

    bases = value.split(',')
    for base in bases:
        base = base.lower()
        print("this->codons_table[\"%s\"] = \"%s\";" % (base,long_name))
        if (base.find('t') != -1):
            base = base.replace('t','u')
            print("this->codons_table[\"%s\"] = \"%s\";" % (base,long_name))
    
file.close()

print("==============================================================================")

file = open("table.txt")

for line in file:
    key, value = line.split()
    keys = key.split('/')
    long_name = keys[0]
    short_name = keys[1]

    bases = value.split(',')
    for base in bases:
        base = base.lower()
        print("this->codons_table[\"%s\"] = \"%s\";" % (base,short_name))
        if (base.find('t') != -1):
            base = base.replace('t','u')
            print("this->codons_table[\"%s\"] = \"%s\";" % (base,short_name))
    
file.close()