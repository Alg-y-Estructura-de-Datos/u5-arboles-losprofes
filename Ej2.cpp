#include <iostream>
#include "Arbol/ArbolBinario.h"  // Incluir la librería del árbol binario

int main()
{
    // Crear el árbol binario de productos
    ArbolBinario<int> inventario;

    // Paso 1: Insertar los productos en el árbol
    inventario.put(4001);
    inventario.put(2002);
    inventario.put(6003);
    inventario.put(1500);
    inventario.put(3500);
    inventario.put(5000);
    inventario.put(7000);

    // Mostrar el inventario inicial en inorden
    std::cout << "Inventario inicial (inorden): ";
    inventario.print();

    // Paso 2: Eliminar los productos comprados
    inventario.remove(2002);
    inventario.remove(6003);

    // Mostrar el inventario después de las eliminaciones
    std::cout << "Inventario después de eliminar los productos 2002 y 6003 (inorden): ";
    inventario.print();

    // Paso 3: Agregar el nuevo producto al inventario
    inventario.put(2500);

    // Mostrar el inventario actualizado
    std::cout << "Inventario actualizado después de agregar el producto 2500 (inorden): ";
    inventario.print();

    // Paso 4: Verificar si el código 4001 está en el sistema
    try
    {
        int resultado = inventario.search(4001);
        std::cout << "El producto con el código 4001 está en el inventario.\n";
    }
    catch (int e)
    {
        std::cout << "El producto con el código 4001 no está en el inventario.\n";
    }

    return 0;
}
