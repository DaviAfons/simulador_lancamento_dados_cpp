#include "persistencia.h"
#include <fstream>      
#include <iostream>     
#include <iomanip>      

using namespace std;

void guardarResultadoCSV(const vector <int>& frequencias, int numDados, int numFaces, int numLancamentos, const string& nomeFicheiro) {
    ofstream ficheiroSaida(nomeFicheiro);

    if (!ficheiroSaida.is_open())
    {
        cerr << "ERRO: Nao foi possivel abrir o ficheiro de saida: " << nomeFicheiro << "\n";
        return;
    }
    
    const int somaMinima = numDados;

    // 1. Escreve o cabeçalho (metadados)
    ficheiroSaida << "Tipo_Dado,D" << numFaces << "\n";
    ficheiroSaida << "Num_Dados" << numDados << "\n";
    ficheiroSaida << "Num_Lancamentos" << numLancamentos << "\n";

    // 2. Escreve o cabeçalho da tabela CSV
    ficheiroSaida << "Soma,Frequencia,Porcentagem\n";

    // 3. Escreva os dados linha por linha
    for (size_t i = 0; i < frequencias.size(); ++i)
    {
        int somaAtual = somaMinima + i;
        int contagem = frequencias[i];

        double porcentagem = (static_cast<double>(contagem) / numLancamentos) * 100.0;

        // Escreve a linha no formato CSV: Soma,Frequencia,Porcentagem
        ficheiroSaida << somaAtual << ","
                      << contagem << ","
                      << fixed << setprecision(4) << porcentagem << "\n";
    }

    // Fecha o ficheiro 
    ficheiroSaida.close();
    cout << "\n Resultados guardados com sucesso em: " << nomeFicheiro << "\n";
}