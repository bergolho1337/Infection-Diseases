# SIR Model

The first well-know mathematical model for modelling diseases was the SIR model, which was first used by Kermack and McKendrick in 1927 and has subsequently been applied to a variety of diseases, especially airborne childhood diseases with lifelong immunity upon recovery, such as measles, mumps, rubella, and pertussis. 

The model is given by a set of ordinary differential equations (ODE's) and can supply two types of behaviours, with and without vital dynamics.

![sirmodel](https://bergolho.github.io/assets/sir-model.png)

where *N = S + I + R = 1* is the total population.

![sirparameters](https://bergolho.github.io/assets/sir-parameters.png)

# Pre-Requisites
  - Linux-based operating system
  - CMake
  - Python
  - Matplotlib

# Running examples

## Example 1) A simple infection
----

First compile the source code by running the script:

```sh
$ ./recompile_project.sh 
```

Next, execute the program by passing the configuration file with the Simple Infection parameters.

```sh
$ bin/SIR inputs/simple-infection.ini 
```

Plot the results by running the Python script located inside the *scripts/* folder.

```sh
$ python plot_solution.py ../outputs/simple_infection/solution.dat
```

## Parameters
```ini
# Simple SIR model
[main]
dt_ode = 0.1
simulation_time = 40.0

[model]
beta = 2.0
gamma = 1.4
rho = 0.0
eta = 0.0
S0 = 0.9
I0 = 0.0002
R0 = 0.0998

[save_result]
print_rate = 1
output_dir = outputs/simple_infection

```

## Output 
![sir](https://bergolho.github.io/assets/s-example-1.png)

![sir](https://bergolho.github.io/assets/i-example-1.png)

![sir](https://bergolho.github.io/assets/r-example-1.png)

![sir](https://bergolho.github.io/assets/sir-example-1.png)


## Example 2) An endemic disease with vital dynamics

It is also possible to simulate an endemic disease using the SIR model. In this scenario, peaks of infection will happen over time.

```sh
$ bin/SIR inputs/infection-vital-dynamics.ini 
```

## Parameters
```ini
# =================================================================
# Simple SIR model with vital dynamics and a constant population
# This simulation reproduces an endemic disease to a region
# =================================================================
[main]
dt_ode = 0.1
simulation_time = 200.0

[model]
beta = 3.0
gamma = 1.4
rho = 0.02
eta = 0.02
S0 = 0.9
I0 = 0.0002
R0 = 0.0998

[save_result]
print_rate = 1
output_dir = outputs/vital_dynamics

```

## Output 
![sir](https://bergolho.github.io/assets/s-example-2.png)

![sir](https://bergolho.github.io/assets/i-example-2.png)

![sir](https://bergolho.github.io/assets/r-example-2.png)

![sir](https://bergolho.github.io/assets/sir-example-2.png)



