INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g
CXXFLAGS = -c -I./$(INC)
.PHONY: all clean mrproper




pilacola: $(BIN)/pruebacola documentacion

pilaVD: $(BIN)/pruebapilaVD documentacion


$(BIN)/pruebacola :  $(OBJ)/Pila_max_Cola.o $(OBJ)/mainpilamax.o
	$(CXX) -o $(BIN)/pruebacola $(OBJ)/Pila_max_Cola.o $(OBJ)/mainpilamax.o

$(BIN)/pruebapilaVD :  $(OBJ)/Pila_max_VD.o $(OBJ)/mainpilamax.o
	$(CXX) -o $(BIN)/pruebapilaVD $(OBJ)/Pila_max_VD.o  $(OBJ)/mainpilamax.o

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/Pila_max_Cola.o : $(INC)/Pila_max_Cola.h $(INC)/cola.h
$(OBJ)/cola.o :
$(OBJ)/Pila_max_VD.o : $(INC)/Pila_max_VD.h $(INC)/vectordin.h
$(OBJ)/mainpilamax.o : $(INC)/Pila_max.h

clean:
	@rm -fr $(OBJ)/*
	@echo "Limpiando obj..."

mrproper: clean
	@rm -fr $(BIN)/*
	@echo "Limpiando bin..."

documentacion:
	doxygen doc/doxys/Doxyfile
