#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp>
#include <engine/mainEngine.h>
#include <iostream>
#include <memory>

void register_instance(sol::state& lua);
void register_vector3(sol::state& lua);

int main() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    register_vector3(lua);
    register_instance(lua);

    lua.script_file("../luau/main.luau");
    Engine::Init();

    return 0;
}