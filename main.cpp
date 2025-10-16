#include <iostream>
#include <string>

#include "MatrizDinamica.h"

void mostrarMenu();

int main() {

    std::cout<<"--- Sistema de Análisis de Transformaciones Lineales ---"<<std::endl;

    // Creamos la matriz de eneteros 2x3
    std::cout<<">> Prueba de Matriz ENTERA (Matriz A) <<"<<std::endl;
    std::cout<<"Creando Matriz A (Tipo INT) de 2x3\n"<<std::endl;

    MatrizDinamica<int> A(2, 3);

    // Inicializamos matriz A
    std::cout<<"Ingresar valores para para Matriz A (2x3)"<<std::endl;
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 3; j ++){
            int valor;
            std::cout<<"A ["<<i<<"][ "<<j<< " ]: "<std::endl;
            std::cin >> valor;
            A.setValor(i, j, valor);
        }
    }

    std::cout<<"\nMatriz A creada:"<<std::endl;
    A.mostrar();

    // Redimencionamos
    std::cout << "\n>> Redimensionando Matriz A <<\n";
    A.redimensionar(3, 3);
    A.mostrar();
    std::cout<<"\nNuevos valores inicializados en 0"<<std::endl;

    // Matriz B como Float
    std::cout<<"\n>> Prueba de Multiplicacion (Tipo FLOAT) <<"<<std::endl;
    std::cout<<"Creando Matriz B (Tipo FLOAT) de 3x2..."<<std::endl;

    // Inicializamos matriz B
    std::cout<<"Ingresar valores para B (3x2): "<<std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            float valor;
            std::cout<<"B["<<i<<"]["<<j<<"]: ";
            std::cin>>valor;
            B.setValor(i, j, valor);
        }
    }
    
    // Multiplicamos
    std::cout<<"\n>> Convirtiendo Matriz A a tipo FLOAT <<"<<std::endl;
    
    MatrizDinamica<float> A_float(3, 3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            A_float.setValor(i, j, static_cast<float>(A.getValor(i, j)));
        }
    }
    A.mostrar();

    std::cout<<"\n>> Multiplicando A(3x3) x B(3x2) <<"<<std::endl;
    MatrizDinamica<float> C = MatrizDinamica<float>::multiplicar(A_float, B);

    std::cout<<"\nMatriz C (Resultado 3x2, Tipo FLOAT):"<<std::endl;
    C.mostrar();

    std::cout<<"\nLiberando memoria de todas las matrices :D"<<std::endl;

    return 0;
}