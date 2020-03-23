#include "ode_solver.h"

struct ode_solver* new_ode_solver()
{
	struct ode_solver *ode_data = (struct ode_solver*)malloc(sizeof(struct ode_solver));

    ode_data->y_old = NULL;
    ode_data->y_new = NULL;
	
	return ode_data;
}

void free_ode_solver (struct ode_solver *s)
{
    if (s->y_old)
        delete [] s->y_old;

    if (s->y_new)
        delete [] s->y_new;
    
    free(s);
}

void set_initial_conditions (double *y, const double S0, const double I0, const double R0)
{
    y[0] = S0;
    y[1] = I0;
    y[2] = R0;
}

double dSdt (const double y[], const double beta, const double rho, const double eta)
{
    return rho - beta*y[0]*y[1] - eta*y[0];
}

double dIdt (const double y[], const double beta, const double gamma, const double eta)
{
    return beta*y[0]*y[1] - gamma*y[1] - eta*y[1];
}

double dRdt (const double y[], const double gamma, const double eta)
{
    return gamma*y[1] - eta*y[2];
}

void print_ode_solver (struct ode_solver *s)
{
    printf("********************* ode_solver *********************\n");
    printf("dt = %g\n",s->dt);
    printf("simulation_time = %g\n",s->simulation_time);
    printf("number_timesteps = %u\n",s->num_timesteps);
    printf("--------------------------------------------------------\n");
    printf("Number of equations ODE system = %u\n",s->num_equations);
    printf("Initial conditions:\n");
    for (uint32_t i = 0; i < s->num_equations; i++)
        printf("\ty[%u] = %lf\n",i,s->y_old[i]);
    printf("********************************************************\n");
}