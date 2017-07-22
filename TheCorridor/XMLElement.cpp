#include "stdafx.h"
#include "XMLElement.h"

XMLElement::XMLElement(std::string aNodeName) : myNodeName(aNodeName)
{
}


XMLElement::~XMLElement(void)
{
	for (XMLElement* element : myChildElements)
	{
		delete element;
	}
}

XMLAttributeDefinition XMLElement::ConvertStringToAttributeDefinition(const std::string& aString)
{
	if (aString == "Id")
	{
		return Id;
	}

	if (aString == "Name")
	{
		return Name;
	}

	if (aString == "Dialogue")
	{
		return Dialogue;
	}

	if (aString == "RoomID")
	{
		return RoomIdentifier;
	}

	if (aString == "ItemLocked")
	{
		return ItemLocked;
	}

	if (aString == "Examine")
	{
		return Examine;
	}

	if (aString == "StartsUnusable")
	{
		return StartsUnusable;
	}

	if (aString == "North")
	{
		return North;
	}

	if (aString == "East")
	{
		return East;
	}

	if (aString == "South")
	{
		return South;
	}

	if (aString == "West")
	{
		return West;
	}

	throw "Invalid attribute set in XML File";
}

std::string XMLElement::GetDialogueText( const int& aRoomId, const Action& anAction, const Direction& aDirection) const
{
	std::string dialogueText = std::string();

	if (XMLElement* roomElement = LocateRoom(aRoomId))
	{
		if (XMLElement* actionElement = roomElement->LocateAction(anAction))
		{
			if (XMLElement* directionElement = actionElement->LocateDirection(aDirection))
			{
				dialogueText = directionElement->GetAttributeByKey(Dialogue);
			}
		}
	}

	return dialogueText;
}

XMLElement* XMLElement::GetElementById(const int& aRoomID) const
{
	for (XMLElement* element : myChildElements)
	{
		if (element->GetAttributeIDByKey(Id) == aRoomID)
		{
			return element;
		}
	}

	return nullptr;
}

int XMLElement::GetAttributeIDByKey(const XMLAttributeDefinition& anAttributeDefinition)
{ 
	if (GetAttributeByKey(anAttributeDefinition) != std::string())
	{
		return std::stoi(GetAttributeByKey(anAttributeDefinition));
	}
	
	return NULL;
}

std::vector<XMLElement*> XMLElement::GetAllElementsWithAttribute(const XMLAttributeDefinition& anAttributeDefinition)
{
	std::vector<XMLElement*> elementsWithAttribute;

	if (HasAttribute(anAttributeDefinition))
	{
		elementsWithAttribute.push_back(this);
	}

	for (XMLElement* element : myChildElements)
	{
		std::vector<XMLElement*> childElementsWithAttributes = element->GetAllElementsWithAttribute(anAttributeDefinition);
		elementsWithAttribute.insert( elementsWithAttribute.end(), childElementsWithAttributes.begin(), childElementsWithAttributes.end() );
	}

	return elementsWithAttribute;
}

bool XMLElement::HasAttribute(const XMLAttributeDefinition& anAttributeDefinition)
{
	return myAttributes.count(anAttributeDefinition) > 0;
}

XMLElement* XMLElement::LocateRoom( const int& aRoomId ) const
{
	std::string roomIdAsString = std::to_string(aRoomId);

	for (XMLElement* element : myChildElements)
	{
		if (element->GetAttributeByKey(Id) == roomIdAsString)
		{
			return element;
		}
	}

	return nullptr;
}

XMLElement* XMLElement::LocateAction( const Action& anAction ) const
{
	std::string actionAsString = Definitions::GetStringForAction(anAction);

	for (XMLElement* element : myChildElements)
	{
		if (element->GetNodeName() == actionAsString)
		{
			return element;
		}
	}

	return nullptr;
}

XMLElement* XMLElement::LocateDirection( const Direction& aDirection ) const
{
	std::string directionAsString = Definitions::GetStringForDirection(aDirection);

	for (XMLElement* element : myChildElements)
	{
		if (element->GetNodeName() == directionAsString)
		{
			return element;
		}
	}

	return nullptr;
}