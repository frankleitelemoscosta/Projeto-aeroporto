all:
	echo "make aleatorio-> para compilar o programa com input aleatorio"
	echo "make arquivo-> para compilar o programa com input de um arquivo"
	
aleatorio:
	g++ ./Entrada_Aleatoria/cpp/Aeroporto.cpp ./Entrada_Aleatoria/cpp/Aviao.cpp ./Entrada_Aleatoria/cpp/Fila_Aerea.cpp ./Entrada_Aleatoria/cpp/Fila_Aterrissagem_P3.cpp ./Entrada_Aleatoria/cpp/Fila_Decolagem.cpp ./Entrada_Aleatoria/cpp/pista_emergencia.cpp ./Entrada_Aleatoria/cpp/pista.cpp  ./Entrada_Aleatoria/hpp/pista.hpp  ./Entrada_Aleatoria/hpp/pista_emergencia.hpp ./Entrada_Aleatoria/hpp/Fila_Decolagem.hpp  ./Entrada_Aleatoria/hpp/Fila_Aerea.hpp ./Entrada_Aleatoria/hpp/Fila_Aterrissagem_P3.hpp ./Entrada_Aleatoria/hpp/Aviao.hpp ./Entrada_Aleatoria/hpp/Aeroporto.hpp ./Entrada_Aleatoria/cpp/main.cpp -o executavel

arquivo:
	g++ ./Entrada_com_arquivo/cpp/Aeroporto.cpp ./Entrada_com_arquivo/cpp/Aviao.cpp ./Entrada_com_arquivo/cpp/Fila_Aerea.cpp ./Entrada_com_arquivo/cpp/Fila_Aterrissagem_P3.cpp ./Entrada_com_arquivo/cpp/Fila_Decolagem.cpp ./Entrada_com_arquivo/cpp/pista_emergencia.cpp ./Entrada_com_arquivo/cpp/pista.cpp  ./Entrada_com_arquivo/hpp/pista.hpp  ./Entrada_com_arquivo/hpp/pista_emergencia.hpp ./Entrada_com_arquivo/hpp/Fila_Decolagem.hpp  ./Entrada_com_arquivo/hpp/Fila_Aerea.hpp ./Entrada_com_arquivo/hpp/Fila_Aterrissagem_P3.hpp ./Entrada_com_arquivo/hpp/Aviao.hpp ./Entrada_com_arquivo/hpp/Aeroporto.hpp ./Entrada_com_arquivo/cpp/main.cpp -o executavel_arquivo

clean:
	rm -rf executavel
	rm -rf executavel_arquivo

run_aleatorio:
	./executavel

run_arquivo:
	./executavel_arquivo