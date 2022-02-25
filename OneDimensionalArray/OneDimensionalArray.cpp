#include <iostream>
#include "Vector.h"
#include "StaticArray.h"
#include "DynamicArray.h"

int main()
{
    
    std::cout << "======Static array\n";
    staticArray();

    std::cout << "\n======Dynamic array\n";
    dynamicArray();

    std::cout << "\n======Vector\n";
    vector();

    return 0;
}
