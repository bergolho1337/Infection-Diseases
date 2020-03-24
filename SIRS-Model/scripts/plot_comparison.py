# This script can be use to compared two different simulations

import sys
import numpy as np
import matplotlib.pyplot as plt

def read_results(input_file):
    data = np.genfromtxt(input_file)
    n = len(data)

    t = data[:,0]
    s = data[:,1]
    i = data[:,2]
    r = data[:,3]

    return t, s, i, r


def plot_results(t, s1, i1, r1, s2, i2, r2):
    plt.clf()
    plt.title("Susceptible",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, s1, label="No control", linewidth=3.0)
    plt.plot(t, s2, label="With control", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig("s-comparison.png")
    print("[+] Output figure saved at 'scripts/s-comparison.png'")

    plt.clf()
    plt.title("Infectious",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, i1, label="No control", linewidth=3.0)
    plt.plot(t, i2, label="With control", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig("i-comparison.png")
    print("[+] Output figure saved at 'scripts/i-comparison.png'")

    plt.clf()
    plt.title("Recovered",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, r1, label="No control", linewidth=3.0)
    plt.plot(t, r2, label="With control", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    plt.savefig("r-comparison.png")
    print("[+] Output figure saved at 'scripts/r-comparison.png'")

def main():
    if len(sys.argv) != 3:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file_1> <input_file_2>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file_1> = Input file with the results from Simulation 1")
        print("<input_file_2> = Input file with the results from Simulation 2")
        print("-------------------------------------------------------------------------")
        return 1

    input_file_1 = sys.argv[1]
    input_file_2 = sys.argv[2]

    t, s1, i1, r1 = read_results(input_file_1)
    t, s2, i2, r2 = read_results(input_file_2)

    plot_results(t,s1,i1,r1,s2,i2,r2)


if __name__ == "__main__":
	main()
