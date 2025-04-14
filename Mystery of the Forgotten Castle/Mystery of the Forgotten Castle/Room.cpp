#include "Room.h"

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

std::string_view Room::GetName() const {
	return m_name;
}

std::string_view Room::GetDescription() const {
	return m_description;
}
