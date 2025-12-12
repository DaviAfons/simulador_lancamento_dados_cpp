#include "visualizacao.h"
#include <iomanip>    // setw, setprecision
#include <algorithm>  // max_element
#include <cmath>      // round

using namespace std;


void exibirResultados(const vector<int>& frequencias, int numDados, int numFaces, int numLancamentos) {
    const int somaMinima = numDados;

    cout << "\n--- Resultados da Frequencia (" << numDados << " Dados de D" << numFaces << ") ---\n";
    cout << "Soma | Frequencia | Porcentagem\n";
    cout << "--------------------------------\n";

    for (size_t i = 0; i < frequencias.size(); ++i)
    {
        int somaAtual = somaMinima + i;
        int contagem = frequencias[i];

        double porcentagem = (static_cast<double>(contagem) / numLancamentos) * 100.0;

        // Imprime a linha formatada com largura fixa e 2 casas decimais
        cout << setw(4) << somaAtual << " | "
             << setw(10) << contagem << " | "
             << setw(11) << fixed << setprecision(2) << porcentagem << "%\n";
    }

    cout << "--------------------------------\n";
    cout << "Simulacao concluida\n";
}

// Implementacao da funcao exibirHistograma (Eixo e Barras)
void exibirHistograma(const std::vector<int>& frequencias, int numDados, int numFaces, int numLancamentos) {
    
    // Define a largura maxima da barra do histograma na consola
    const int LARGURA_MAXIMA = 50; 
    
    // 1. Encontrar a Frequencia Maxima (Igual a antes)
    if (frequencias.empty()) return;
    
    auto max_it = std::max_element(frequencias.begin(), frequencias.end());
    int freq_maxima = *max_it;

    if (freq_maxima == 0) {
        std::cout << "Nao houve resultados de frequencia maior que zero.\n";
        return;
    }

    double escala = static_cast<double>(freq_maxima) / LARGURA_MAXIMA;
    
    const int somaMinima = numDados;

    std::cout << "\n--- Histograma de Frequencia (" << numDados << " Dados de D" << numFaces << ") ---\n";
    std::cout << "(Comprimento maximo: " << LARGURA_MAXIMA << " caracteres)\n";
    
    // 2. Desenhar as Barras (O Eixo Y)
    std::cout << "\n";
    for (size_t i = 0; i < frequencias.size(); ++i) {
        int somaAtual = somaMinima + i;
        int contagem = frequencias[i];
        
        int comprimento_barra = static_cast<int>(std::round(contagem / escala));
        
        std::cout << std::setw(3) << somaAtual << " |";
        
        for (int j = 0; j < comprimento_barra; ++j) {
            std::cout << "*";
        }
        
        std::cout << " (" << contagem << ")\n";
    }

    // 3. Desenhar a Escala e o Eixo X
    std::cout << std::setw(4) << "---+"; 
    for (int j = 0; j < LARGURA_MAXIMA; ++j) {
        std::cout << "-";
    }
    std::cout << "\n";

    std::cout << std::setw(4) << "   |";
    for (int j = 0; j <= LARGURA_MAXIMA; j += 10) {
        int valorFrequencia = static_cast<int>(std::round(j * escala));
        
        if (j == 0) {
            std::cout << "0";
        } else if (j > 0) {
            int espacos = (j > 10) ? 9 : j - 1; // Espaços para alinhar o marcador 
            for (int k = 0; k < espacos; ++k) {
                std::cout << " ";
            }
            std::cout << valorFrequencia; 
        }
    }
    std::cout << "\n";
    std::cout << std::setw(4 + LARGURA_MAXIMA / 2) << "Frequencia\n"; // Label do Eixo X

    std::cout << "------------------------------------------------------\n";
}