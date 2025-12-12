#ifndef VISUALIZACAO_H
#define VISUALIZACAO_H

#include <vector>
#include <iostream>

void exibirResultados(const std::vector<int>& frequencias, int numDados, int numFaces, int numLancamentos);
void exibirHistograma(const std::vector<int>& frequencias, int numDados, int numFaces, int numLancamentos);

#endif 