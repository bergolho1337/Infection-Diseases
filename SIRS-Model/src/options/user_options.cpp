#include "user_options.h"

struct user_options* new_user_options (int argc, char *argv[])
{
    struct user_options *result = (struct user_options*)malloc(sizeof(struct user_options));

    // Default parameters are based on the paper: 
    // --> Forecasting seasonal influenza with a state-space SIR model,Osthus, Dave and Hickmann, Kyle S and Caragea, Petru{\c{t}}a C and Higdon, Dave and Del Valle, Sara Y (2017)
	result->dt_ode = 0.1;
    result->simulation_time = 50.0;
    result->print_rate = 1;
    result->output_dir = NULL;
    result->S0 = 0.9;
    result->I0 = 0.0002;
    result->R0 = 0.0998;
    result->beta = 2.0;
    result->gamma = 1.4;
    result->epsilon = 1.0;
    result->rho = 0.0;
    result->eta = 0.0;

    read_config_file(result,argv[1]);
    
    return result;
}

void free_user_options (struct user_options *options)
{   
    if (options->output_dir)
        free(options->output_dir);

    free(options);
}

void read_config_file (struct user_options *options, const char filename[])
{
    printf("%s\n","=============================================================================");
    printf("[user_options] Reading configuration file:> \"%s\"\n",filename);

    // Open the config file for reading
    FILE *file = fopen(filename,"r");
    if (!file)
    {
        fprintf(stderr,"[-] Error reading configuration file '%s'\n",filename);
        exit(EXIT_FAILURE);
    }
    
    // Here we parse the config file
    if(ini_parse(filename, parse_config_file, options) < 0) 
    {
        fprintf(stderr, "Error: Can't load the config file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("%s\n","=============================================================================");

    fclose(file);

	// DEBUG
    print_user_options(options);
}

int parse_config_file(void *user, const char *section, const char *name, const char *value) 
{
    struct user_options *pconfig = (struct user_options *)user;

    if (SECTION_STARTS_WITH(MAIN_SECTION))
    {
        if (MATCH_NAME("dt_ode"))
        {
            pconfig->dt_ode = strtof(value, NULL);
        }
        else if (MATCH_NAME("simulation_time"))
        {
            pconfig->simulation_time = strtof(value, NULL);
        }
    }
    else if (SECTION_STARTS_WITH(MODEL_SECTION))
    {
        if (MATCH_NAME("beta"))
        {
            pconfig->beta = strtof(value, NULL);
        }
        else if (MATCH_NAME("gamma"))
        {
            pconfig->gamma = strtof(value, NULL);
        }
        else if (MATCH_NAME("epsilon"))
        {
            pconfig->epsilon = strtof(value, NULL);
        }
        else if (MATCH_NAME("rho"))
        {
            pconfig->rho = strtof(value, NULL);
        }
        else if (MATCH_NAME("eta"))
        {
            pconfig->eta = strtof(value, NULL);
        }
        else if (MATCH_NAME("S0"))
        {
            pconfig->S0 = strtof(value, NULL);
        }
        else if (MATCH_NAME("I0"))
        {
            pconfig->I0 = strtof(value, NULL);
        }
        else if (MATCH_NAME("R0"))
        {
            pconfig->R0 = strtof(value, NULL);
        }
    }
    else if (SECTION_STARTS_WITH(SAVE_RESULT_SECTION))
    {

        if (MATCH_NAME("output_dir"))
        {
            pconfig->output_dir = strdup(value);
        }   
        else if (MATCH_NAME("print_rate"))
        {
            pconfig->print_rate = strtol(value,NULL,10);
        }
    }

    return 1;
}

void print_user_options (struct user_options *options)
{
    printf("********************* user_options *********************\n");
    printf("dt_ode = %g\n",options->dt_ode);
    printf("simulation_time = %g\n",options->simulation_time);
    printf("--------------------------------------------------------\n");
    printf("print_rate = %u\n",options->print_rate);
    printf("output_dir = %s\n",options->output_dir);
    printf("--------------------------------------------------------\n");
    printf("beta = %lf\n",options->beta);
    printf("gamma = %lf\n",options->gamma);
    printf("epsilon = %lf\n",options->epsilon);
    printf("rho = %lf\n",options->rho);
    printf("eta = %lf\n",options->eta);
    printf("--------------------------------------------------------\n");
    printf("Initial conditions:\n");
    printf("\tS0 = %lf (Susceptibles)\n",options->S0);
    printf("\tI0 = %lf (Infected)\n",options->I0);
    printf("\tR0 = %lf (Recovered)\n",options->R0);
    printf("********************************************************\n");
}
