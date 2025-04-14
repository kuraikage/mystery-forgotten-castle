#pragma once
#include <string_view> 
#include <map>
#include <memory>
#include <vector>
#include "Item.h"
class Room
{
private:
	std::string m_name;
	std::string m_description;
	std::map<std::string_view, std::weak_ptr<Room>> m_exits; // Using weak_ptr to prevent circular references
	std::vector<std::unique_ptr<Item>> m_items;
public:
	Room(std::string name, std::string description);

	// Deleted copy and move constructors and assignment operators
	Room(const Room&) = delete;
	Room& operator=(const Room&) = delete;
	Room(Room&&) = delete;
	Room& operator=(Room&&) = delete;

	void Connect(const std::string_view& direction, const std::shared_ptr<Room>& room);
	std::shared_ptr<Room> GetExit(const std::string_view& direction) const;

	[[nodiscard]] inline const std::vector<std::unique_ptr<Item>>& GetItems() const { return m_items; }
	inline void AddItem(std::unique_ptr<Item> item) { m_items.push_back(std::move(item)); }
	std::unique_ptr<Item> TakeItem(const std::string& itemName);

    [[nodiscard]] inline std::string_view GetName() const { return m_name; }
	[[nodiscard]] inline std::string_view GetDescription() const { return m_description; }
};
