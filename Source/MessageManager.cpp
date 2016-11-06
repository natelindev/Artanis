#include "MessageManager.h"

//output
void MessageManager::printMsg(std::string msg)
{
	BWAPI::Broodwar->printf(msg.c_str());
}

void MessageManager::printGreetingMsg()
{
	BWAPI::Broodwar->printf("Hello! I am %s, written by %s", Config::BotInfo::BotName, Config::BotInfo::Author);
}

void MessageManager::printVictoryMsg()
{
	BWAPI::Broodwar->printf("Perhaps the cost of greatness is too high.");
}

void MessageManager::printDefeatMsg()
{
	BWAPI::Broodwar->printf("Has it all been for nothing...?");
}

void MessageManager::printSearchMsg()
{
	BWAPI::Broodwar->printf("Our path is clear, Adun, guide my hand.");
}

void MessageManager::printAttackMsg()
{
	BWAPI::Broodwar->printf("With honor I lead, Templars, move forward!,Triumph through sacrifice.");
}

void MessageManager::printRetreatMsg()
{
	BWAPI::Broodwar->printf("My Templars has suffered a great loss, fall back! We must stand as one.");
}

void MessageManager::printChangeHierachMsg(GameCommander _gamecommander)
{
	if (_gamecommander.getCurrentExecutorType() == GameCommander::Artanis)
	{
		BWAPI::Broodwar->printf("En Taro Adun,I,Artanis,am back into the fight.");
	}
	else
	{
		BWAPI::Broodwar->printf("I entrust this task to you, %s ,Lead our warriors while I'm not here",\
			_gamecommander.getCurrentExecutorName.cstr());
		BWAPI::Broodwar->printf("%s: As you command, Hierach", _gamecommander.getCurrentExecutorName());
	}
}

//input
void MessageManager::onSendText(std::string text)
{
	BWAPI::Broodwar->printf("What? Pardon? I can't hear you.");
	//TODO: Implement this later.
}