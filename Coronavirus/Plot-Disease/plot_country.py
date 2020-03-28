import sys
import pandas
import numpy as np
import matplotlib.pyplot as plt

def plot_total_cases(country_name, days, total_cases):
    t = np.arange(len(days))

    filename = "outputs/" + country_name.lower() + "_total_cases.png"
    plt.grid()
    #plt.plot(days, total_cases, label="Total cases", c="orange", linewidth=3.0)
    plt.plot(t, total_cases, label="Total cases", c="orange", linewidth=3.0)
    plt.xlabel("days",fontsize=15)
    plt.ylabel("Cases",fontsize=15)
    plt.title("COVID-19 - %s - Total cases" % (country_name),fontsize=14)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig(filename)

def plot_total_deaths(country_name, days, total_deaths):
    t = np.arange(len(days))

    filename = "outputs/" + country_name.lower() + "_total_deaths.png"
    plt.clf()
    plt.grid()
    #plt.plot(days, total_deaths, label="Total deaths", c="red", linewidth=3.0)
    plt.plot(t, total_deaths, label="Total deaths", c="red", linewidth=3.0)
    plt.xlabel("days",fontsize=15)
    plt.ylabel("Deaths",fontsize=15)
    plt.title("COVID-19 - %s - Total deaths" % (country_name),fontsize=14)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig(filename)

def get_country_name (filename):
    tokens = filename.split('/')

    country_name = tokens[1][0:-4]

    return country_name.capitalize()

def main():
	
    if len(sys.argv) != 2:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file> = Input file with the country data")
        print("-------------------------------------------------------------------------")
        return 1

    input_file = sys.argv[1]
    df = pandas.read_csv(input_file)

    country_name = get_country_name(input_file)
    #print(country_name)

    days, total_cases, total_deaths = df[df.columns[0]].to_numpy(), df["total_cases"].to_numpy(), df["total_deaths"].to_numpy()
    
    plot_total_cases(country_name,days,total_cases)
    plot_total_deaths(country_name,days,total_deaths)
    

if __name__ == "__main__":
    main()
