#pragma once

#include "logger.h"
#include "common.h"
#include "gamecommander.h"

class MessageManager
{
	//Simple cinematic Messages to make the bot more lifelike.
public:
	void printMsg(std::string);
	void printGreetingMsg();
	void printVictoryMsg();
	void printDefeatMsg();
	void printAttackMsg();
	void printRetreatMsg();
	void printSearchMsg();
	void printChangeHierachMsg(GameCommander _gamecommander);
	void onSendText(std::string text);
	static MessageManager &  Instance();
};

MessageManager & MessageManager::Instance()
{
	static MessageManager instance;
	return instance;
}