#pragma once
#include <string>

class Item
{
private:
	std::string m_name;
	std::string m_description;
public:
	Item(std::string name, std::string description);

	// Deleted copy and move constructors and assignment operators
	Item(const Item&) = delete;
	Item& operator=(const Item&) = delete;
	Item(Item&&) = delete;
	Item& operator=(Item&&) = delete;

	[[nodiscard]] inline std::string_view GetName() const { return m_name; }
	[[nodiscard]] inline std::string_view GetDescription() const { return m_description; }

	virtual void Use() = 0;
};

