#include "Artanis.h"

// This gets called when the bot starts!
void Artanis::onStart()
{
	//config part
	
    BWAPI::Broodwar->enableFlag(BWAPI::Flag::UserInput);
   
    BWAPI::Broodwar->printf("Hello! I am %s, written by %s", "Artanis", "LLL");
   
}

void Artanis::onEnd(bool isWinner) 
{
	
}

void Artanis::onFrame()
{
	_workerManager.update();
}

void Artanis::onUnitDestroy(BWAPI::Unit unit)
{
	_workerManager.onUnitDestroy(unit);
}

void Artanis::onUnitMorph(BWAPI::Unit unit)
{
	_workerManager.onUnitMorph(unit);
}

void Artanis::onSendText(std::string text)
{ 
}

void Artanis::onUnitCreate(BWAPI::Unit unit)
{ 
	_workerManager.onUnitCreated(unit);
}

void Artanis::onUnitComplete(BWAPI::Unit unit)
{
	_workerManager.onUnitComplete(unit);
}

void Artanis::onUnitShow(BWAPI::Unit unit)
{ 
	_workerManager.onUnitShow(unit);
}

void Artanis::onUnitHide(BWAPI::Unit unit)
{ 
}

void Artanis::onUnitRenegade(BWAPI::Unit unit)
{ 
	_workerManager.onUnitShow(unit);
}