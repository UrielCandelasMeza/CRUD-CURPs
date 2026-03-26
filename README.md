# CRUD de CURPs

Aplicacion de consola en C++ para gestionar CURPs (Clave Unica de Registro de Poblacion) mediante operaciones CRUD. Utiliza **QuickSort** para ordenamiento y **Binary Search** para consultas eficientes.

---

## Estructura del proyecto

```
.
├── curp/
│   ├── curp.hpp
│   └── curp.cpp
├── build/
│   ├── curp/
│   │   └── curp.o
│   └── main.o
├── main.cpp
├── main
├── Makefile
└── .gitignore
```

---

## Compilacion

### Compilar el proyecto

```bash
make
```

Genera el ejecutable `main` y los archivos objeto en `build/`.

### Limpiar archivos generados

```bash
make clean
```

Elimina el directorio `build/` y el ejecutable `main`.

---

## Uso

```bash
./main
```

Al iniciar, el programa solicita una cantidad de CURPs para registrar como carga inicial. Despues de eso, se accede al menu principal con las siguientes opciones:

```
  ----------------------------------------
  MENU PRINCIPAL
  ----------------------------------------
  1. Agregar CURP
  2. Consultar todos los CURPs
  3. Buscar un CURP especifico
  4. Modificar un CURP
  5. Eliminar un CURP
  6. Salir
  ----------------------------------------
```

---

## Validaciones

- El CURP debe tener exactamente **18 caracteres**.
- No se permiten CURPs duplicados.
- Al modificar, el CURP original debe existir y el nuevo no debe estar ya registrado.

---

## Implementacion

### Clase `CURP`

| Metodo                 | Descripcion                                                  |
| ---------------------- | ------------------------------------------------------------ |
| `addCurp(curp)`        | Agrega un CURP si no existe. Retorna `true` si fue exitoso.  |
| `findCurp(curp)`       | Busca y retorna el CURP. Retorna `"not_found"` si no existe. |
| `getCurps()`           | Retorna el vector con todos los CURPs registrados.           |
| `updateCurp(old, new)` | Reemplaza un CURP existente por uno nuevo.                   |
| `deleteCurp(curp)`     | Elimina un CURP del registro. Retorna `true` si fue exitoso. |

### Algoritmos

**QuickSort** — se aplica sobre el vector antes de cada busqueda para garantizar que el arreglo este ordenado.

**Binary Search** — permite localizar un CURP en `O(log n)` una vez ordenado el vector.

> Nota: dado que QuickSort se ejecuta antes de cada busqueda, el costo real por operacion es `O(n log n)`. Para colecciones grandes se recomienda mantener el vector ordenado de forma incremental.

---

## Requisitos

- Compilador **g++** con soporte C++17 o superior.
- **make**
- No requiere dependencias externas.
