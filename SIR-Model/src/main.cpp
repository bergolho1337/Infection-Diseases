// Author: Lucas Berg
// Simple program that solves the SIR model for infection diseases

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "utils/utils.h"
#include "options/user_options.h"
#include "ode_solver/ode_solver.h"

void configure_solver_from_options (struct ode_solver *the_solver, struct user_options *the_options)
{
    // Configure ODE solver
    the_solver->dt = the_options->dt_ode;
    the_solver->simulation_time = the_options->simulation_time;
    the_solver->num_timesteps = nearbyint(the_options->simulation_time/the_options->dt_ode);
    
    the_solver->num_equations = 3;
    the_solver->y_old = new double[the_solver->num_equations]();
    the_solver->y_new = new double[the_solver->num_equations]();

    set_initial_conditions(the_solver->y_old,the_options->S0,the_options->I0,the_options->R0);

    // DEBUG
    //print_ode_solver(the_solver);
}

void solve_problem (struct ode_solver *the_solver, struct user_options *the_options)
{
    char *output_dir = the_options->output_dir;
    char *output_filename = set_output_filename(output_dir);
    FILE *file = fopen(output_filename,"w+");
    
    uint32_t nt = the_solver->num_timesteps;
    uint32_t print_rate = the_options->print_rate;
    double dt = the_solver->dt;

    double beta = the_options->beta;
    double gamma = the_options->gamma;
    double rho = the_options->rho;
    double eta = the_options->eta;

    double *y_old = the_solver->y_old;
    double *y_new = the_solver->y_new;

    for (uint32_t k = 0; k < nt; k++)
    {
        double t = k*dt;
        
        if (k % print_rate == 0)
        {
            write_solution_to_file(file,t,y_old);
        }

        // Solve the ODE system using Explicit Euler
        y_new[0] = y_old[0] + dSdt(y_old,beta,rho,eta)*dt;
        y_new[1] = y_old[1] + dIdt(y_old,beta,gamma,eta)*dt;
        y_new[2] = y_old[2] + dRdt(y_old,gamma,eta)*dt;        

        // Swap pointers
        swap(y_old,y_new);
    }

    delete [] output_filename;
    fclose(file);
}

int main (int argc, char *argv[])
{
    if (argc-1 != 1)
    {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    struct user_options *the_options = new_user_options(argc,argv);
    struct ode_solver *the_solver = new_ode_solver();
    
    configure_solver_from_options(the_solver,the_options);
    
    solve_problem(the_solver,the_options);

    free_ode_solver(the_solver);
    free_user_options(the_options);

    return 0;
}
