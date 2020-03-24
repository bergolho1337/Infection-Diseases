
#ifndef ODE_SOLVER_H
#define ODE_SOLVER_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cstring>

struct ode_solver
{
	uint32_t num_timesteps;
	double dt;
	double simulation_time;

	uint32_t num_equations;
	double *y_old;
	double *y_new;
};

struct ode_solver* new_ode_solver();

void free_ode_solver (struct ode_solver *s);

void set_initial_conditions (double *y, const double S0, const double I0, const double R0);

double dSdt (const double y[], const double beta, const double rho, const double eta, const double epsilon);
double dIdt (const double y[], const double beta, const double gamma, const double eta);
double dRdt (const double y[], const double gamma, const double eta, const double epsilon);

void print_ode_solver (struct ode_solver *s);

#endif
