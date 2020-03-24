//
// Created by bergolho on 22/03/20.
//

#ifndef USER_OPTIONS_H
#define USER_OPTIONS_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cstring>

#include "../ini_parser/ini.h"
#include "../ini_parser/ini_file_sections.h"

static const uint32_t MAX_FILENAME_SIZE = 200;

struct user_options
{
	// ODE solver parameters
    double dt_ode;
    double simulation_time;
    
	// Output parameters
	uint32_t print_rate;
	char *output_dir;
	
	// Initial conditions
	double S0;
	double I0;
	double R0;

	// Model parameters
	double beta;			// Disease transmission rate
	double gamma;			// Recovery rate
	double rho;				// Birth rate
	double eta;				// Death rate
	double epsilon;			// Wane rate
};

struct user_options* new_user_options (int argc, char *argv[]);
void free_user_options (struct user_options *options);

void read_config_file (struct user_options *options, const char filename[]);

int parse_config_file(void *user, const char *section, const char *name, const char *value);

void print_user_options (struct user_options *options);

#endif
