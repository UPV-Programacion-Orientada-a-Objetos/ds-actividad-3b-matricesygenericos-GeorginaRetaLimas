# 📝 Notas de Creación de clases
Recordatorios a mi misma y anotaciones durante la actividad

### ☀️ Clase normal:
| Archivo | Terminación | Notas                            |
|:--------|:-----------:|:---------------------------------|
| Clase   | .h          | Solo declaraciones               |
| Codigo  | .cpp        | Definiciones de implementaciones |

### ☀️ Clase template:
| Archivo       | Terminación | Notas                           |
|:--------------|:-----------:|:--------------------------------|
| Clase Templete| .h          | Declaraciones e Implementación  |

⚠️ En las clases no se se separan en dos, no tienen cpp por cuestiones de compilador

### 🎲 Conceptos aprendidos

#### 💣 Destructor
Un destructor es un método especial que se ejecuta **automáticamente** cuando un objeto se destruye. Su sintaxix es:

```cpp
~NombreClase(){
    // Acciones o cosas que se hagan cuando se destrye
}
```
    
### 🛠️ La regla de los tres:
En punteros la regla de tres es:

|:-----------------------|:----------------|
| Deestructor            | Liberar memoria |
| Constructor de copia   | Copiar datos    |
| Operador de asignación | Asignar datos   |

### 🚫 Regla Multiplicación de Matrices:
Para multiplicar una matriz A x B:
- El número de **Columnas de A** debe ser **igual** que el número de **Filas de B**.

Y el resultado seria el siguiente:
- A(m x **n**) x B(**n** x p) = C(m x p)

La **formula** es: Para cada elemento de C[i][j]
- C[i][j] = Σ(k=0 hasta n-1) A[i][k] × B[k][j]

#### 🌈 Ejemplo gráfico de multiplicación:
```
A (2×3):          B (3×2):          C (2×2):
[1, 2, 3]         [7,  8]           [?,  ?]
[4, 5, 6]         [9, 10]           [?,  ?]
                  [11,12]
```
**Para calcular C[0][0]:**

```
C[0][0] = A[0][0]×B[0][0] + A[0][1]×B[1][0] + A[0][2]×B[2][0]
        = 1×7             + 2×9             + 3×11
        = 7               + 18              + 33

C[0][0] = 58
```
**Para calcular C[0][1]:**
```
C[0][1] = A[0][0]×B[0][1] + A[0][1]×B[1][1] + A[0][2]×B[2][1]
        = 1×8             + 2×10            + 3×12
        = 8               + 20              + 36
        
C[0][1] = 64
```
**Resultado:**
```
C = [58,  64]
    [139,154]
```

### 🫂 Función Amiga:
Una función amiga es una funcion que **no es miembro de la clase**, pero tiene acceso especial a los atributos de la clase.

#### ¿Por qué en esta práctica es necesario?
Porque es necesario acceder a dos matrices y no debe pertenecer a ninguna, es independiente.

### 👨🏿‍🦼 Función Estática
Una función estática es un método que **pertenece a la clase** pero **no necesita un objeto** para ser llamado