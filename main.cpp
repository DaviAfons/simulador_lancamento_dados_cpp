#include "simuladorDados.h" 
#include <iostream>         
#include <cstdlib>          
#include <ctime>            
#include <string>           

using namespace std; 

// Funcao para obter entrada positiva do usuario
int obterEntradaPositiva(const string& mensagem) {
    int valor;
    cout << mensagem;
    
    // Leitura e tratamento de erro
    while (!(cin >> valor) || valor < 1)
    {
        cout << "Entrada inválida. Por favor, insira um valor positivo: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    return valor;
}

int main() {
    // Configuracao da Aleatoriedade 
    srand(time(0));

    cout << "--- Simulador de Lancamento de Dados ---\n";

    int numFaces = obterEntradaPositiva("Quantas faces tem cada dado? (Ex: 6, 10, 20): ");
    int numDados = obterEntradaPositiva("Quantos dados de " + to_string(numFaces) + " faces deseja lancar de uma vez? (Ex: 2): ");
    int numLancamentos = obterEntradaPositiva("Quantas vezes deseja repetir o lancamento? (Ex: 10000): ");

    // Processamento 
    vector<int> resultados = realizarSimulacao(numDados, numFaces, numLancamentos);

    // Saída  
    exibirResultados(resultados, numDados, numFaces, numLancamentos);
    exibirHistograma(resultados, numDados, numFaces, numLancamentos);

    string nomeFicheiro = "Sim_D" + to_string(numFaces) + "X" + to_string(numDados) + "_" + to_string(numLancamentos) + ".csv";
    guardarResultadoCSV(resultados, numDados, numFaces, numLancamentos, nomeFicheiro);

    return 0;
}