#include "../classes/Instance.h"
#include "../classes/Part.h"
#include <sol/sol.hpp>
#include <memory>

void register_instance(sol::state& lua) {
    lua.new_usertype<Instance>("Instance",
        "Name",       &Instance::Name,
        "ClassName",  sol::readonly_property(&Instance::ClassName),
        "Destroy",    &Instance::Destroy
    );

    // Part
    lua.new_usertype<Part>("Part",
        sol::base_classes, sol::bases<Instance>(),
        "Position",   &Part::Position
    );

    // Fabryka jako statyczna metoda w klasie Instance
    lua["Instance"]["new"] = sol::overload(
        // Instance.new("Part") → zwraca Part
        [](const std::string& className) -> std::shared_ptr<Instance> {
            if (className == "Part") {
                auto p = std::make_shared<Part>();
                p->ClassName = "Part";
                return p;
            }
            // fallback na zwykły Instance
            auto inst = std::make_shared<Instance>();
            inst->ClassName = className;
            return inst;
        }
    );
}