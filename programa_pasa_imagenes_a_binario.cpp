//*************************Función que me lo lee el patron, tiene como entrada el nombre del archivo

#include <iostream>
#include <vector>
#include <math.h> // Para usar la función sqrt
#include <algorithm> // Para usar la función min
#include <fstream> // Para usar la función ofstream
#include <string>
#include<chrono>
#include <random> 
using namespace std;

void guardar_patron_binario(const vector<vector<int>>& epsilon, int N);
vector<vector<int>> leer_patron_binario(const string& nombre_archivo, int N);

int main(){
    int N=30;
    //Leo el patron de la bola del mundo, cuya información lo introduzco en una matriz 
    //array.

    vector<vector<int>> epsilon = leer_patron_binario("2_final.txt", N);

    //Guardo el patrón inicial en un txt, de numeros separados
    guardar_patron_binario(epsilon, N);

    return 0;
}

vector<vector<int>> leer_patron_binario(const string& nombre_archivo, int N) { 

    //abro el archivo donde voy a leer el patrón binario
    ifstream archivo(nombre_archivo);
    

    //Genero un epsilon para guardar en él mi patrón
    vector<vector<int>> epsilon(N, vector<int>(N));

    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            archivo >> c;
            if(c == '0'){
                epsilon[i][j] = 0;
            } else {
                epsilon[i][j] = 1;
            }
        }
    }
    
    return epsilon;
}

//************Función que guardo el patrón incicial en un txt, de numeros separados

void guardar_patron_binario(const vector<vector<int>>& epsilon, int N) {
    
    // Abrir el archivo para escribir el patrón binario
    ofstream fich_patron("2_final.txt");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fich_patron << epsilon[i][j] << ' ';
                }
            
            fich_patron << '\n';
        }
}


