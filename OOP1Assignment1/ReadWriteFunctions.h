#pragma once
#ifndef READWRITE_FUNCTIONS_FILE
#define READWRITE_FUNCTIONS_FILE
#include <string>
#include <vector>

using namespace std;

double* read_text(const std::string& fileName, int sizeR, int sizeC);
void write_pgm(const std::string& filename, double *data, int sizeR, int sizeC, int Q);

#endif