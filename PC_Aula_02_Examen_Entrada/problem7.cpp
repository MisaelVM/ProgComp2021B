#include <iostream>

// La funcion utiliza manipulacion de bits para determinar
// si un numero es potencia de 2:
// La representacion en binario de una potencia de 2 tiene
// siempre la forma de un 1 seguido de una secuencia de n 0's:
// 1000000...0000
// Y el numero anterior a una potencia de 2 tiene la forma
// de una secuencia de n-1 1's:
// 0111111...1111
// Por lo que al aplicar un operador AND cada uno de estos bits
// se anula y resulta en exactamente 0, cumpliendose esta
// propiedad unicamente en potencias de 2
bool func(int n) {
    return ((n & (n - 1)) == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < (1 << 6); ++i)
        std::cout << i << " " << func(i) << "\n";

    return 0;
}
