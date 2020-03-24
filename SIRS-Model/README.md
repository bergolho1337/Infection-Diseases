# SIRS Model

The SIR model assumes people carry lifelong immunity to a disease upon recovery, this is the case for a variety of diseases. 

For another class of airborne diseases, for example seasonal influenza, an individual’s immunity may wane over time. In this case, the SIRS model is used to allow recovered individuals to return to a susceptible state. This behaviour is controlled by the wane rate parameter.

![sirmodel](https://bergolho.github.io/assets/sirs-model.png)

where *N = S + I + R = 1* is the total population.

![sirparameters](https://bergolho.github.io/assets/sirs-parameters.png)

# Pre-Requisites
  - Linux-based operating system
  - CMake
  - Python
  - Matplotlib

# Running examples

## Example 1) Influenza spread without control
----

First compile the source code by running the script:

```sh
$ ./recompile_project.sh 
```

Next, execute the program by passing the configuration file with the Simple Infection parameters.

```sh
$ bin/SIRS inputs/influenza-no-control.ini 
```

Plot the results by running the Python script located inside the *scripts/* folder.

```sh
$ python plot_solution.py ../outputs/influenza-no-control/solution.dat
```

## Parameters
```ini
# =================================================================
# Simple SIRS model with vital dynamics for an influenza infection
# =================================================================
[main]
dt_ode = 0.1
simulation_time = 50.0

[model]
beta = 3.0          
gamma = 1.5
epsilon = 0.005
rho = 0.0
eta = 0.002
S0 = 0.9
I0 = 0.0002
R0 = 0.0998

[save_result]
print_rate = 1
output_dir = outputs/influenza-no-control

```

## Output 
![sir](https://bergolho.github.io/assets/s-no-control.png)

![sir](https://bergolho.github.io/assets/i-no-control.png)

![sir](https://bergolho.github.io/assets/r-no-control.png)

![sir](https://bergolho.github.io/assets/sirs-no-control.png)


## Example 2) Influenza spread with control

If some medical actions are taken into account, like for example social distance between the individuals, the infection rate can be drastically reduced. 

Leading to a reduction in the number of infectious and far more easy infection to be dealt with by the health departments.

```sh
$ bin/SIRS inputs/influenza-control.ini 
```

## Parameters
```ini
# =================================================================
# Simple SIRS model with vital dynamics for an influenza infection
# =================================================================
[main]
dt_ode = 0.1
simulation_time = 50.0

[model]
beta = 2.0
gamma = 1.5
epsilon = 0.005
rho = 0.0
eta = 0.002
S0 = 0.9
I0 = 0.0002
R0 = 0.0998

[save_result]
print_rate = 1
output_dir = outputs/influenza-control

```

## Output 
![sir](https://bergolho.github.io/assets/s-control.png)

![sir](https://bergolho.github.io/assets/i-control.png)

![sir](https://bergolho.github.io/assets/r-control.png)

![sir](https://bergolho.github.io/assets/sirs-control.png)

## No control x Control

![sir](https://bergolho.github.io/assets/s-comparison.png)

![sir](https://bergolho.github.io/assets/i-comparison.png)

![sir](https://bergolho.github.io/assets/r-comparison.png)


