#include <iostream>
#include "Stack.hpp"

int main()
{
    try
    {
        Stack<int> s(2);

        std::cout << "Stack creado con capacidad inicial 2\n";

        std::cout << "\nPush 10\n";
        s.push(10);

        std::cout << "Push 20\n";
        s.push(20);

        std::cout << "Estado del stack:\n";
        s.show();

        std::cout << "\nPush 30 (deberia hacer resize)\n";
        s.push(30);

        std::cout << "Estado del stack tras resize:\n";
        s.show();

        std::cout << "\nElemento en el tope (peek): "
                  << s.peek() << "\n";

        std::cout << "\nPop\n";
        s.pop();

        std::cout << "Estado del stack:\n";
        s.show();

        std::cout << "\nPop\n";
        s.pop();

        std::cout << "Estado del stack:\n";
        s.show();

        std::cout << "\nPop\n";
        s.pop();

        std::cout << "Estado del stack:\n";
        s.show();

        std::cout << "\nIntentando pop en stack vacio:\n";
        s.pop();  // debería lanzar excepción
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "\nExcepcion capturada: " << e.what() << "\n";
    }

    return 0;
}
