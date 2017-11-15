INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g
CXXFLAGS = -c -I./$(INC)

.PHONY: all clean mrproper


all:  $(OBJ)/FechaHistorica.o  $(OBJ)/Cronologia.o $(BIN)/prueba documentacion

#$(OBJ)/FechaHistorica.o : $(INC)/FechaHistorica.h  $(INC)/vectordin.h $(SRC)/FechaHistorica.cpp
#	$(CXX) $(CPPFLAGS) -I./$(INC) $(SRC)/FechaHistorica.cpp  -c -o $(OBJ)/FechaHistorica.o 
#$(OBJ)/vectordin.o : $(INC)/vectordin.h $(SRC)/vectordin.cpp
#	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/vectordin.o $(SRC)/vectordin.cpp


$(BIN)/prueba : $(OBJ)/pruebacronologia.o $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebacronologia.o $(OBJ)/FechaHistorica.o $(OBJ)/Cronologia.o

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/pruebacronologia.o : $(INC)/FechaHistorica.h
$(OBJ)/FechaHistorica.o : $(INC)/vectordin.h $(INC)/FechaHistorica.h
$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(INC)/FechaHistorica.h



clean:
	@rm -fr $(OBJ)/*
	@echo "Limpiando obj..."

mrproper: clean
	@rm -fr $(BIN)/*
	@echo "Limpiando bin..."

documentacion: 
	doxygen doc/doxys/Doxyfile



