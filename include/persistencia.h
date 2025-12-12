#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>

void guardarResultadosCSV(const std::vector<int>& frequencias, int numDados, int numFaces, int numLancamentos, const std::string& nomeFicheiro);

#endif 