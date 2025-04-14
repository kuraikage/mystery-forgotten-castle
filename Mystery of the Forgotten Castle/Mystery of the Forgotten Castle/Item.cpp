#include "Item.h"

inline Item::Item(std::string name, std::string description)
	: m_name(std::move(name)), m_description(std::move(description))
{
}
