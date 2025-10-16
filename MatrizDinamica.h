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
        
    }

    void mostrar(){
        for(int i = 0; i < filas; i++){

        }
    }

    // Metodos de Gestión

    // Operaciones
};