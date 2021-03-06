#pragma once

#include "Definitions.h"

#include <vector>
#include <map>
#include <string>

enum XMLAttributeDefinition { Id, Name, Dialogue, RoomIdentifier, ItemLocked, StartsUnusable, Examine, PostExamine, North, South, East, West };

class XMLElement
{
public:
	XMLElement() {}
	XMLElement(std::string aNodeName);
	~XMLElement(void);

	void AddAttribute(const std::string& anAttributeKey, const std::string& anAttributeValue) { myAttributes[ConvertStringToAttributeDefinition(anAttributeKey)] = anAttributeValue; }
	void AddChildElement(XMLElement* anXmlElement) { myChildElements.push_back(anXmlElement); }

	XMLElement* GetElementById(const int& aRoomID) const;
	std::string GetDialogueText( const int& aRoomId, const Action& anAction, const Direction& aDirection) const;
	std::string GetNodeName() const { return myNodeName; }
	std::string GetAttributeByKey(const XMLAttributeDefinition& anAttributeDefinition) { return myAttributes[anAttributeDefinition]; }
	int GetAttributeIDByKey(const XMLAttributeDefinition& anAttributeDefinition);
	bool GetAttributeBoolByKey(const XMLAttributeDefinition& anAttributeDefinition) { return myAttributes[anAttributeDefinition] == "TRUE"; }

	std::vector<XMLElement*>& GetChildElements() { return myChildElements; }
	std::vector<XMLElement*> GetAllElementsWithAttribute(const XMLAttributeDefinition& anAttributeDefinition);
	
	bool HasAttribute(const XMLAttributeDefinition& anAttributeDefinition);
private:
	
	XMLAttributeDefinition ConvertStringToAttributeDefinition(const std::string& aString);

	XMLElement* LocateRoom( const int& aRoomID ) const;
	XMLElement* LocateAction( const Action& anAction ) const;
	XMLElement* LocateDirection( const Direction& aDirection ) const;

	std::string myNodeName;
	std::vector<XMLElement*> myChildElements;
	std::map<XMLAttributeDefinition, std::string> myAttributes;
};

