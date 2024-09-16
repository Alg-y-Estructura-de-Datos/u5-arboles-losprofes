#include <iostream>
#include "Arbol/ArbolBinario.h"

int main() {
    // Crear el árbol binario
    ArbolBinario<int> biblioteca;

    // Insertar los libros en el sistema de gestión
    biblioteca.put(101);
    biblioteca.put(52);
    biblioteca.put(198);
    biblioteca.put(36);
    biblioteca.put(75);
    biblioteca.put(150);
    biblioteca.put(200);

    // Buscar el libro con ID 75
    try {
        int libro = biblioteca.search(75);
        std::cout << "El libro con ID 75 está en la biblioteca: " << libro << std::endl;
    } catch (int e) {
        if (e == 404) {
            std::cout << "El libro con ID 75 no está en la biblioteca." << std::endl;
        }
    }

    // Eliminar el libro con ID 52 (prestado)
    biblioteca.remove(52);
    std::cout << "El libro con ID 52 ha sido eliminado (prestado)." << std::endl;

    // Imprimir la estructura del árbol después de la eliminación
    std::cout << "Estructura del sistema de libros después de eliminar el ID 52:" << std::endl;
    biblioteca.print(); // Imprime el árbol en orden (en este caso, por IDs de libros)

    return 0;
}
