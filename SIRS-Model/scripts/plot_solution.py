# This script is for plotting the results from the 'solution.dat' file

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


def plot_results(t, s, i, r):
    plt.clf()
    plt.title("Susceptible",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, s, label="S", c="black", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    #plt.savefig("s.pdf")
    plt.savefig("s.png")
    print("[+] Output figure saved at 'scripts/s.png'")

    plt.clf()
    plt.title("Infectious",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, i, label="I", c="black", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    #plt.savefig("i.pdf")
    plt.savefig("i.png")
    print("[+] Output figure saved at 'scripts/i.png'")

    plt.clf()
    plt.title("Recovered",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, r, label="R", c="black", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    #plt.savefig("r.pdf")
    plt.savefig("r.png")
    print("[+] Output figure saved at 'scripts/r.png'")

    plt.clf()
    plt.title("SIRS Model",fontsize=14)
    plt.xlabel("Time",fontsize=15)
    plt.ylabel("%",fontsize=15)
    plt.plot(t, s, label="S", c="blue", linewidth=3.0)
    plt.plot(t, i, label="I", c="red", linewidth=3.0)
    plt.plot(t, r, label="R", c="green", linewidth=3.0)
    plt.legend(loc=0,fontsize=14)
    #plt.show()
    #plt.savefig("sirs.pdf")
    plt.savefig("sirs.png")
    print("[+] Output figure saved at 'scripts/sirs.png'")

def main():
	
	if len(sys.argv) != 2:
		print("-------------------------------------------------------------------------")
		print("Usage:> python %s <input_file>" % sys.argv[0])
		print("-------------------------------------------------------------------------")
		print("<input_file> = Input file with the simulation results")
		print("-------------------------------------------------------------------------")
		return 1

	input_file = sys.argv[1]

	t, s, i, r = read_results(input_file)

	plot_results(t,s,i,r)


if __name__ == "__main__":
	main()
