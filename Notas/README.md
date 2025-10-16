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

**Nota:** Si la clase que estamos desarrollando necesita **uno** de estos tres, probablemente necesita los **tres**. Por teoría básica de punteros, como vemos arriba.

**¿Por qué es importante el constructor copia?** Puede pasar que a B se le asigna el objeto B:

```cpp
MatrizDinamica<int> A(2, 2);
A.setValor(0, 0, 5);

MatrizDinamica<int> B = A;
```

Lo que esta pasando es que **los datos de A no se pasan a B**, si no que **B apunta a la dirección de A**, entonces si en el futuro A cambia de valor B tambien lo hara.

Es por eso que se necesita hacer un constructor copia, aún mas cuando el programa termine y el destructor se ejecute, porque:

```cpp

A -> Se va a liberar

B -> Apunta a A pero A ya esta limpio, causando Error
```

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