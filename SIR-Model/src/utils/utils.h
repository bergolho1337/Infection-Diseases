//
// Created by bergolho on 19/02/19.
//

#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <cmath>

void usage (const char pname[]);

char* set_output_filename (const char output_dir[]);

void write_solution_to_file (FILE *file, const double cur_time, const double y[]);

#endif
