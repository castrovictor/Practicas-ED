INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g -O2 -std=c++11
CXXFLAGS = -c -I./$(INC)

.PHONY: all clean mrproper

all: $(BIN)/filtradoPorClave $(BIN)/unionCronologia $(BIN)/recuento_eventos


$(BIN)/recuento_eventos : $(OBJ)/recuento_eventos.o $(OBJ)/FechaHistorica.o $(OBJ)/cronologia.o
		$(CXX) -o $@ $<
$(BIN)/unionCronologia : $(OBJ)/unionCronologia.o $(OBJ)/FechaHistorica.o $(OBJ)/cronologia.o
	$(CXX) -o $@ $<
$(BIN)/filtradoPorClave : $(OBJ)/filtradoPorClave.o $(OBJ)/FechaHistorica.o $(OBJ)/cronologia.o
	$(CXX) -o $@ $<

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/recuento_eventos.o : $(INC)/cronologia.h
$(OBJ)/unionCronologia.o : $(INC)/cronologia.h
$(OBJ)/filtradoPorClave.o : $(INC)/cronologia.h
$(OBJ)/FechaHistorica.o : $(INC)/FechaHistorica.h
$(OBJ)/cronologia.o : $(INC)/cronologia.h $(INC)/FechaHistorica.h



