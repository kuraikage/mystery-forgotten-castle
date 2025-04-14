#include "Room.h"
#include "StringUtils.hpp"

Room::Room(std::string name, std::string description)
	: m_name(std::move(name)), m_description(std::move(description)) {}

void Room::Connect(const std::string_view& direction, const std::shared_ptr<Room>& room) {
	m_exits[direction] = room;
}

std::shared_ptr<Room> Room::GetExit(const std::string_view& direction) const {
	auto it = m_exits.find(direction);
	if (it != m_exits.end()) {
		return it->second.lock();
	}
	return nullptr;
}

std::unique_ptr<Item> Room::TakeItem(const std::string& itemName)
{
	if(itemName.empty())
		return nullptr;

	if(m_items.empty())
		return nullptr;

	const std::string& lowerItemName = ToLower(itemName);

	auto it = std::find_if(m_items.begin(), m_items.end(),
		[&lowerItemName](const std::unique_ptr<Item>& item)
	{
		return ToLower(item->GetName()) == lowerItemName;
	});

	if(it == m_items.end())
		return nullptr;

	std::unique_ptr<Item> removedItem = std::move(*it);
	m_items.erase(it);
	return removedItem;
}