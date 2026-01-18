#include "../classes/Vector3.h"
#include <sol/sol.hpp>

void register_vector3(sol::state& lua) {
    lua.new_usertype<Vector3>("Vector3",

        sol::constructors<Vector3(), Vector3(float, float, float)>(),

        "new", sol::factories(
            []()                  { return Vector3{}; },
            [](float x, float y, float z) { return Vector3{x, y, z}; }
        ),

         "X", sol::property(&Vector3::get_x, &Vector3::set_x),
        "Y", sol::property(&Vector3::get_y, &Vector3::set_y),
        "Z", sol::property(&Vector3::get_z, &Vector3::set_z),

        "__tostring", [](const Vector3& v) -> std::string {
        return "Vector3(" + std::to_string(v.get_x()) + ", " + std::to_string(v.get_y()) + ", " + std::to_string(v.get_z()) + ")";
        }
    );
}