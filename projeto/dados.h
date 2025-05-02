    #include <iostream>
    #include <ctime>
    #include <cstdlib>

    using namespace std;

    void nomes(){

        srand(time(0));

        string nome[] =  {"João", "Francisco", "Vasco", "André", "Rodrigo", "Guilherme", "Henrique", "Tadeu" };
        int tamanho = sizeof(nome) / sizeof(nome[0]);
        
        int indice = rand() % tamanho;
        string nomegerado = nome[indice];

        cout << nomegerado;
    }

    