#pragma once
#include <string_view> 
#include <map>
#include <memory>
#include <vector>
class Room
{
private:
	std::string m_name;
	std::string m_description;
	std::map<std::string_view, std::weak_ptr<Room>> m_exits; // Using weak_ptr to prevent circular references
	//std::vector<std::unique_ptr<Item>> m_items;
public:
	Room(std::string name, std::string description);

	Room(const Room&) = delete;
	Room& operator=(const Room&) = delete;
	Room(Room&&) = delete;
	Room& operator=(Room&&) = delete;

	void Connect(const std::string_view& direction, const std::shared_ptr<Room>& room);

	std::shared_ptr<Room> GetExit(const std::string_view& direction) const;

	std::string_view GetName() const;
	std::string_view GetDescription() const;
};


