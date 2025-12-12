# 🎲 Simulador de Lançamento de Dados (N Faces)

Um simulador estatístico interativo desenvolvido em C++ que permite ao usuário lançar qualquer número de dados com N faces (por exemplo, 3x D10, 5x D20) um número configurável de vezes. O projeto está organizado modularmente para alta manutenibilidade.

---

## 🌟 Funcionalidades

* **Dados Personalizáveis:** Suporta dados de N faces (D4, D6, D10, D20, D100, etc.).
* **Resultados Detalhados:** Apresenta tabela com Frequência e Porcentagem.
* **Visualização Avançada:** Exibe um histograma na consola com **eixo de escala** para facilitar a leitura da distribuição estatística.
* **Persistência de Dados:** Guarda os resultados completos da simulação num ficheiro **CSV** (Comma Separated Values) para análise posterior (Excel, Google Sheets).

---

## ⚙️ Estrutura do Projeto

O projeto segue uma estrutura modular padrão para C++:

| Diretório/Ficheiro | Conteúdo 
| :--- | :--- |
| **`main.cpp`** | Lógica de entrada/saída do usuário e orquestração das chamadas. |
| **`include/`** | Contém todos os ficheiros de cabeçalho (`.h`) para declaração de funções. |
| **`src/`** | Contém todos os ficheiros de implementação (`.cpp`). |
| `src/simulacao.cpp` | Lógica central de geração de números aleatórios e contagem de frequência. |
| `src/visualizacao.cpp` | Lógica de exibição de tabela e histograma. |
| `src/persistencia.cpp` | Lógica de gravação de resultados no ficheiro CSV. |
| **`makefile`** | Automatiza a compilação, ligando os módulos da pasta `src/` e `include/`. |

---

## 🛠️ Como Compilar e Executar

### Requisitos

* Compilador C++ (g++ recomendado)
* Programa `make`

### Compilação

Navegue até o diretório raiz e utilize o `Makefile`. O `-Iinclude/` é tratado automaticamente pela configuração:

```
make all

```
### Execução

Execute o programa e siga as instruções no console:

```
./simulador_dados

```
## 🧑‍💻 Autor
Davi Afonso
