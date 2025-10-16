#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

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
        for(int = 0; i < filas; i++){
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

    // Operaciones
};

#endif