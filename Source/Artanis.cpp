#include "Artanis.h"
#include "config.h"
// This gets called when the bot starts!
void Artanis::onStart()
{
	//config part
	
    BWAPI::Broodwar->enableFlag(BWAPI::Flag::UserInput);
   
	if (Config::Module::UsingMessageManager)
	{
		MessageManager::Instance().printGreetingMsg();
	}
}

void Artanis::onEnd(bool isWinner) 
{
	if (Config::Module::UsingMessageManager)
	{
		if (isWinner)
		{
			MessageManager::Instance().printVictoryMsg();
		}
		else
		{
			MessageManager::Instance().printDefeatMsg();
		}
	}
}

void Artanis::onFrame()
{
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.update();
	}
	
}

void Artanis::onUnitDestroy(BWAPI::Unit unit)
{
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitDestroy(unit);
	}
}

void Artanis::onUnitMorph(BWAPI::Unit unit)
{
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitMorph(unit);
	}
}

void Artanis::onSendText(std::string text)
{ 
	if (Config::Module::UsingMessageManager)
	{
		MessageManager::Instance.onSendText(text);
	}
}

void Artanis::onUnitCreate(BWAPI::Unit unit)
{ 
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitCreated(unit);
	}
}

void Artanis::onUnitComplete(BWAPI::Unit unit)
{
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitComplete(unit);
	}
}

void Artanis::onUnitShow(BWAPI::Unit unit)
{ 
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitShow(unit);
	}
}

void Artanis::onUnitHide(BWAPI::Unit unit)
{ 
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitHide(unit);
	}
}

void Artanis::onUnitRenegade(BWAPI::Unit unit)
{ 
	if (Config::Module::UsingGameCommander)
	{
		_gameCommander.onUnitShow(unit);
	}
	
}