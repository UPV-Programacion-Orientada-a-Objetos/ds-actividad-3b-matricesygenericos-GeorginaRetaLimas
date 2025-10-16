#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <iostream>

template <typename T>
class MatrizDinamica {
private:
    T **datos;
    int filas;
    int columnas;

public:
    // Constructor
    MatrizDinamica(int f, int c){
        filas = f;
        columnas = c;

        // Arreglo de punteros que son las filas
        datos = new T*[filas];

        for(int i = 0; i < filas ; i ++){
            // Pedimos el espacio para la columna de cada fila
            datos[i] = new T[columnas];

            // Inicialización
            for(int j = 0; j < columnas; j ++){
                datos[i][j] = 0;
            }
        }
    }

    // Destructor
    ~MatrizDinamica(){
        // Primero debemos liberar la memoria de cada fila
        for(int i = 0; i < filas; i++){
            delete[] datos[i];
        }

        // Luego limpiamos el arreglo de punteros
        delete[] datos;
    }

    // Setters 
    void setValor(int i, int j, T valor){
        // Primero validamos que los indices sean validos
        if ( i >= 0 && i < filas && j >= 0 && j < columnas){
            datos[i][j] = valor;
            // Mostramos en consola para que sea bonito
            std::cout << "[" << i << "]" << "[" << j << "] = " << valor <<std::endl;
        } else {
            std::cout << "Error: Indice invalido";
        }
    }

    // Getters
    T getValor(int i, int j) const {
        if ( i >= 0 && i < filas && j >= 0 && j < columnas){
            return datos[i][j];
        }

        return 0;
    }

    int getFilas() const {
        return filas;
    }

    int getColumnas() const {
        return columnas;
    }

    // Mostrar
    void mostrar(){

        for(int i = 0; i < filas; i++){
            std::cout << "  | ";
            for(int j = 0; j < columnas; j++){
                std::cout << datos[i][j] << " | ";
            }
            std::cout << std::endl;
        }
    }

    // Metodos de Gestión
    void redimensionar(int nuevasF, int nuevasC){
        // Primero Validamos que los índices sean validos
        if (nuevasF < 0 || nuevasC < 0){
            std::cout << "Error: Un índice no puede ser menor a 0";
            return;
        }

        std::cout << "Redimensionando de " << filas << "x" << columnas 
              << " a " << nuevasF << "x" << nuevasC << "..." << std::endl;

        // Creamos una nueva matriz temporal
        T **nuevosDatos = new T*[nuevasF];
        for(int i = 0; i < nuevasF; i++){
            nuevosDatos[i] = new T[nuevasC];

            for(int j = 0; j < nuevasC; j ++){
                nuevosDatos[i][j] = 0;
            }
        }

        // Copiamos los datos, buscamos el indice menor para copiar
        int filasCopiar = (filas < nuevasF) ? filas : nuevasF;
        int columnasCopiar = (columnas < nuevasC) ? columnas : nuevasC;

        for(int i = 0; i < filasCopiar; i++){
            for(int j = 0; j < columnasCopiar; j ++){
                nuevosDatos[i][j] = datos[i][j];
            }
        }

        // Liberamos la memoria
        for(int i = 0; i < filas; i++){
            delete[] datos[i];
        }

        delete[] datos;

        datos = nuevosDatos;
        filas = nuevasF;
        columnas = nuevasC;

        mostrar();
    }

    // Operaciones
    static MatrizDinamica<T> multiplicar(const MatrizDinamica<T>& A,  const MatrizDinamica<T>& B) {
        // Validamos las dimensiones
        if(A.columnas != B.filas){
            std::cout << "Error: Matrices incompatibles" << std::endl;
            return MatrizDinamica<T>(1,1);
        }

        // Definimos la matriz del resultado
        MatrizDinamica<T> C(A.filas, B.columnas);

        // Multiplicación
        for(int i = 0; i < A.filas ; i++){
            for(j = 0; j < B.columnas; j++){
                T suma = 0;

                for(int k = 0; k < A.columnas; k++){
                    suma += A.datos[i][k] * B.datos[k][j];
                }

                C.datos[i][j] = suma;
            }
        }

        return C;
    }
};

/*
// Implementación de función amiga fuera de clase
template <typename T>
MatrizDinamica<T> multiplicar(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B) {
    // Validamos las dimensiones
    if(A.columnas != B.filas){
        std::cout << "Error: Matrices incompatibles" << std::endl;
        return MatrizDinamica<T>(1,1);
    }

    // Definimos la matriz del resultado
    MatrizDinamica<T> C(A.filas, B.columnas);

    // Multiplicación
    for(int i = 0; i < A.filas ; i++){
        for(j = 0; j < B.columnas; j++){
            T suma = 0;

            for(int k = 0; k < A.columnas; k){
                suma += A.datos[i][k] * B.datos[k][j];
            }

            C.datos[i][j] = suma;
        }
    }

    return C;
}
*/
#endif