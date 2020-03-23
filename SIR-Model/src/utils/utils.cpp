#include "utils.h"

void usage (const char pname[])
{
	printf("%s\n","=============================================================================");
	printf("Usage:> %s <configuration_file>\n",pname);
	printf("%s\n","=============================================================================");
	printf("\t<configuration_file> = Configuration file with the parameter values of the simulation\n");
	printf("%s\n","=============================================================================");
	printf("Example:\n");
	printf("\t%s inputs/simple-infection.ini\n",pname);
	printf("%s\n","=============================================================================");
}

char* set_output_filename (const char output_dir[])
{
	char *filename = new char[FILENAME_MAX]();
	sprintf(filename,"%s/solution.dat",output_dir);

	return filename;
}

void write_solution_to_file (FILE *file, const double cur_time, const double y[])
{
	fprintf(file,"%g %g %g %g\n",cur_time,y[0],y[1],y[2]);
}
