import sys
import pandas
import numpy as np
import matplotlib.pyplot as plt

def plot_comparison_total_cases(country_name_1,days_1,total_cases_1,country_name_2,days_2,total_cases_2):
    t_1 = np.arange(len(days_1))
    t_2 = np.arange(len(days_2))
    
    filename = "outputs/comparisons/" + country_name_1.lower() + "_" + country_name_2.lower() + "_total_cases.png"
    plt.grid()
    #plt.plot(days_1, total_cases_1, label="%s" % (country_name_1), c="orange", linewidth=3.0)
    #plt.plot(days_2, total_cases_2, label="%s" % (country_name_2), c="blue", linewidth=3.0)
    plt.plot(t_1, total_cases_1, label="%s" % (country_name_1), c="orange", linewidth=3.0)
    plt.plot(t_2, total_cases_2, label="%s" % (country_name_2), c="blue", linewidth=3.0)
    plt.xlabel("days",fontsize=15)
    plt.ylabel("Cases",fontsize=15)
    plt.title("COVID-19 - %s x %s - Total cases" % (country_name_1,country_name_2),fontsize=14)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig(filename)

def plot_comparison_total_deaths(country_name_1,days_1,total_deaths_1,country_name_2,days_2,total_deaths_2):
    t_1 = np.arange(len(days_1))
    t_2 = np.arange(len(days_2))

    filename = "outputs/comparisons/" + country_name_1.lower() + "_" + country_name_2.lower() + "_total_deaths.png"
    plt.grid()
    #plt.plot(days_1, total_deaths_1, label="%s" % (country_name_1), c="orange", linewidth=3.0)
    #plt.plot(days_2, total_deaths_2, label="%s" % (country_name_2), c="blue", linewidth=3.0)
    plt.plot(t_1, total_deaths_1, label="%s" % (country_name_1), c="orange", linewidth=3.0)
    plt.plot(t_2, total_deaths_2, label="%s" % (country_name_2), c="blue", linewidth=3.0)
    plt.xlabel("days",fontsize=15)
    plt.ylabel("Deaths",fontsize=15)
    plt.title("COVID-19 - %s x %s - Total deaths" % (country_name_1,country_name_2),fontsize=14)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig(filename)

def get_country_name (filename):
    tokens = filename.split('/')

    country_name = tokens[1][0:-4]

    return country_name.capitalize()

def main():
	
    if len(sys.argv) != 3:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file_1> <input_file_2>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file_1> = Input file with the first country data")
        print("<input_file_2> = Input file with the second country data")
        print("-------------------------------------------------------------------------")
        return 1

    input_file_1 = sys.argv[1]
    input_file_2 = sys.argv[2]
    
    df_1 = pandas.read_csv(input_file_1)
    df_2 = pandas.read_csv(input_file_2)

    country_name_1 = get_country_name(input_file_1)
    country_name_2 = get_country_name(input_file_2)
    #print(country_name)

    days_1, total_cases_1, total_deaths_1 = df_1[df_1.columns[0]].to_numpy(), df_1["total_cases"].to_numpy(), df_1["total_deaths"].to_numpy()
    days_2, total_cases_2, total_deaths_2 = df_2[df_2.columns[0]].to_numpy(), df_2["total_cases"].to_numpy(), df_2["total_deaths"].to_numpy()
    
    plot_comparison_total_cases(country_name_1,days_1,total_cases_1,country_name_2,days_2,total_cases_2)
    plt.clf()
    plot_comparison_total_deaths(country_name_1,days_1,total_deaths_1,country_name_2,days_2,total_deaths_2)    

if __name__ == "__main__":
    main()
