# ===============================================================================================================
# Author: Lucas Berg
# Program that reads the worldwide data from COVID-19 in .csv format and divide the information by country 
# =============================================================================================================== 

import sys
import pandas
import numpy as np
import matplotlib.pyplot as plt

def main():
	
    if len(sys.argv) != 2:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file> = Input file with the COVID-19 data")
        print("-------------------------------------------------------------------------")
        return 1

    input_file = sys.argv[1]
    df = pandas.read_csv(input_file)
    
    country_names = df['location'].unique()
    #print(country_names)

    for country_name in country_names:
	country_name_without_space = country_name.replace(' ','_')
        filename = "outputs/" + country_name_without_space.lower() + ".csv"
        
        country_data = df.loc[df['location'] == country_name]
        
        country_data.to_csv(filename)

if __name__ == "__main__":
    main()
