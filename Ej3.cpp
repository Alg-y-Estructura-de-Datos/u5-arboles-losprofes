#include <iostream>
#include "Arbol/ArbolBinario.h"

int main()
{
    // Crear el árbol binario para almacenar los números de socio
    ArbolBinario<int> gimnasio;

    // Inscribir a los socios
    gimnasio.put(500);
    gimnasio.put(250);
    gimnasio.put(750);
    gimnasio.put(100);
    gimnasio.put(300);
    gimnasio.put(600);
    gimnasio.put(800);

    std::cout << "Lista de socios antes de las modificaciones:" << std::endl;
    gimnasio.print(); // Imprimir lista de socios

    // Eliminar el socio con número 250 (se dio de baja)
    gimnasio.remove(250);

    // Verificar si el socio con número 300 está activo
    try
    {
        int socio300 = gimnasio.search(300);
        std::cout << "El socio con número 300 está activo." << std::endl;
    }
    catch (int e)
    {
        std::cout << "El socio con número 300 no está en el sistema." << std::endl;
    }

    // Verificar si el socio con número 750 está activo
    try
    {
        int socio750 = gimnasio.search(750);
        std::cout << "El socio con número 750 está activo." << std::endl;
    }
    catch (int e)
    {
        std::cout << "El socio con número 750 no está en el sistema." << std::endl;
    }

    // Imprimir la lista de socios actualizada
    std::cout << "Lista de socios después de las modificaciones:" << std::endl;
    gimnasio.print();

    return 0;
}
