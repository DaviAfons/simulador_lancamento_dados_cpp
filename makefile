# Variaveis de Configuracao
COMPILADOR = g++
CFLAGS = -Wall -std=c++17
INCLUDE_FLAGS = -Iinclude/

# Ficheiros para o Executavel PRINCIPAL
TARGET = simulador_dados

SOURCES_PROD = main.cpp src/simulacao.cpp src/visualizacao.cpp src/persistencia.cpp
OBJECTS_PROD = $(SOURCES_PROD:.cpp=.o)

# Regra Principal (Executavel de Producao)
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS_PROD)
	$(COMPILADOR) $(CFLAGS) $^ -o $(TARGET)

# Regras de Compilacao de Objetos
%.o: %.cpp
	$(COMPILADOR) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

src/%.o: src/%.cpp
	$(COMPILADOR) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) *.o src/*.o