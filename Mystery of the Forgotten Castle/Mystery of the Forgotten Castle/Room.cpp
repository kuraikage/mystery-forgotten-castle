#include "Room.h"
#include "StringUtils.hpp"
#include "Exit.h"

Room::Room(std::string name, std::string description)
	: m_name(std::move(name)), m_description(std::move(description)) {}

void Room::Connect(const std::string_view& direction, const std::shared_ptr<Room>& room, bool isLocked, const std::string& description)
{
	m_exits.push_back(SExit{ direction, room, isLocked, description });
}

std::shared_ptr<Room> Room::GetExit(const std::string_view& direction) const 
{
	for (const auto& exit : m_exits)
	{
		if (exit.direction == direction)
		{
			return exit.destination.lock();
		}
	}

	return nullptr;
}

std::unique_ptr<IPickupable> Room::PickUpItem(const std::string& itemName)
{
	if(itemName.empty())
		return nullptr;

	if(m_interactables.empty())
		return nullptr;

	const std::string& lowerItemName = ToLower(itemName);

	// 1) Find the object
	auto it = std::find_if(m_interactables.begin(), m_interactables.end(),
		[&lowerItemName](const auto& interactable)
	{
		return ToLower(interactable->GetName()) == lowerItemName;
	});

	if(it == m_interactables.end())
		return nullptr;

	// 2) Check if it really is pickupable
	IInteractable* basePtr = it->get(); /// get raw pointer
	auto* pickPtr = dynamic_cast<IPickupable*>(basePtr);
	
	if (!pickPtr)
		return nullptr;  // interactable, but not pickupable

	// 3) Remove it from the room and transfer ownership
	std::unique_ptr<IInteractable> uniqueInteractable = std::move(*it);
	m_interactables.erase(it);

	// 4) Release the raw pointer (so 'uniqueInteractable' doesn't delete it)…
	uniqueInteractable.release();

	// 5) …and wrap it in a unique_ptr<IPickupable>
	//    (now safe, because we checked with dynamic_cast)
	return std::unique_ptr<IPickupable>(pickPtr);
}