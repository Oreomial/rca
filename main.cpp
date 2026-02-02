#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp>
#include <windows.h>
#include <iostream>
#include <memory>

void register_instance(sol::state& lua);
void register_vector3(sol::state& lua);

int main() {
    SetConsoleOutputCP(65001);

    sol::state lua;
    lua.open_libraries(sol::lib::base);

    register_vector3(lua);
    register_instance(lua);

   lua.script_file("../luau/main.luau");
  

    std::cout << "\nNaciśnij Enter aby zakończyć...\n";
    std::cin.get();
    return 0;
}