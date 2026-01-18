#pragma once

#include <string>
#include <memory>

struct Instance {
    std::string Name = "";
    std::string ClassName;

    virtual ~Instance() = default;

    virtual void Destroy();
};