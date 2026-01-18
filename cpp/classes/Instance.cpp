#include "Instance.h"
#include <iostream>

void Instance::Destroy() {
    std::cout << "Destroyed: " 
              << (Name.empty() ? "<unnamed>" : Name)
              << " (" << ClassName << ")\n";
}