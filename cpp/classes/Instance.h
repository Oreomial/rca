#pragma once

#include <string>
#include <iostream>
#include <memory>

struct Instance {
    std::string Name = "";
    std::string ClassName;

    virtual void Destroy() {
         std::cout << "Destroyed: " 
              << (Name.empty() ? "<unnamed>" : Name)
              << " (" << ClassName << ")\n";
    };
};