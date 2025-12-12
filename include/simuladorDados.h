#ifndef SIMULADORDADOS_H
#define SIMULADORDADOS_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Recebe o número de dados e o número de lançamentos
vector<int> realizarSimulacao(int numDados, int numFaces, int numLancamentos);

// Recebe o vetor de frequencias, o número de dados e o número de lançamentos totais
void exibirResultados(const vector<int>& frequencias, int numDados, int numFaces, int numLancamentos);

void exibirHistograma(const vector<int>& frequencias, int numDados, int Faces, int numLancamentos);

void guardarResultadoCSV(const vector <int>& frequencias, int numDados, int numFaces, int numLancamentos, const string& nomeFicheiro);
#endif