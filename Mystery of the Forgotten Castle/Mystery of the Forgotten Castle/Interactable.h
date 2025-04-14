#pragma once
#include <string_view>
struct IInteractable
{
    virtual ~IInteractable() = default;
    virtual std::string_view GetName() const = 0;
    virtual void Use() = 0;
};
