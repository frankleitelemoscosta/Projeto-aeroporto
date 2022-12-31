all:
	g++ ./Entrada_Aleatoria/cpp/Aeroporto.cpp ./Entrada_Aleatoria/cpp/Aviao.cpp ./Entrada_Aleatoria/cpp/Fila_Aerea.cpp ./Entrada_Aleatoria/cpp/Fila_Aterrissagem_P3.cpp ./Entrada_Aleatoria/cpp/Fila_Decolagem.cpp ./Entrada_Aleatoria/cpp/pista_emergencia.cpp ./Entrada_Aleatoria/cpp/pista.cpp  ./Entrada_Aleatoria/hpp/pista.hpp  ./Entrada_Aleatoria/hpp/pista_emergencia.hpp ./Entrada_Aleatoria/hpp/Fila_Decolagem.hpp  ./Entrada_Aleatoria/hpp/Fila_Aerea.hpp ./Entrada_Aleatoria/hpp/Fila_Aterrissagem_P3.hpp ./Entrada_Aleatoria/hpp/Aviao.hpp ./Entrada_Aleatoria/hpp/Aeroporto.hpp ./Entrada_Aleatoria/cpp/main.cpp -o executavel

clean:
	rm -rf executavel

run:
	./executavel