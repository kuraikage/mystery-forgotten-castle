#pragma once
#include <map>
#include <memory>
#include <vector>
#include "Interactable.h"
#include "Pickupable.h"

class string_view;
struct SExit;

class Room
{
private:
	std::string m_name;
	std::string m_description;
	std::vector<SExit> m_exits; // Using weak_ptr to prevent circular references
	std::vector<std::unique_ptr<IInteractable>> m_interactables;
public:
	Room(std::string name, std::string description);

	// Deleted copy and move constructors and assignment operators
	Room(const Room&) = delete;
	Room& operator=(const Room&) = delete;
	Room(Room&&) = delete;
	Room& operator=(Room&&) = delete;

	void Connect(const std::string_view& direction, const std::shared_ptr<Room>& room, bool isLocked = false, const std::string& description = "");
	std::shared_ptr<Room> GetExit(const std::string_view& direction) const;

	[[nodiscard]] inline const std::vector<std::unique_ptr<IInteractable>>& GetItems() const { return m_interactables; }
	inline void AddItem(std::unique_ptr<IInteractable> item) { m_interactables.push_back(std::move(item)); }
	std::unique_ptr<IPickupable> PickUpItem(const std::string& itemName);

    [[nodiscard]] inline std::string_view GetName() const { return m_name; }
	[[nodiscard]] inline std::string_view GetDescription() const { return m_description; }
};
