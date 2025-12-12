#include "simulacao.h"
#include <cstdlib> 
using namespace std;


vector<int> realizarSimulacao(int numDados, int numFaces, int numLancamentos) {

    const int somaMinima = numDados;
    const int somaMaxima = numDados * numFaces;

    vector<int> frequencias(somaMaxima - somaMinima + 1, 0);

    for (int i = 0; i < numLancamentos; i++)
    {
        int somaLancamento = 0;

        for (int j = 0; j < numDados; ++j)
        {
            int resultadoDado = (rand() % numFaces) + 1;
            somaLancamento += resultadoDado;
        }

        frequencias[somaLancamento - somaMinima]++;
    }

    return frequencias;
}