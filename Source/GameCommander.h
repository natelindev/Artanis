#pragma once
#include "common.h"


class GameCommander
{
public:
	enum Executors{Artanis, Alarak, Vorazun, Tassadar, karax, Fenix};
	std::string *executors;
/*
*	Artanis ( All + carrier + arbiter)
*	Alarak(Basic + reaver + Shuttle +  Cosair)
*	Vorazun(Basic + dark templar  + Observer + Dark Archons)
*	Tassadar(Basic+ high Templars + Archons)
*	karax(Basic Phton Cannon + buildings)
*	Fenix (Basic zealot+dragoon)
*/
	
private:
	enum Executors currentExecutor;
	

public:

	enum Executors getCurrentExecutorType();
	std::string	   getCurrentExecutorName();


	void update();

	void handleUnitAssignments();
	void setScoutUnits();

	void onUnitShow(BWAPI::Unit unit);
	void onUnitHide(BWAPI::Unit unit);
	void onUnitCreate(BWAPI::Unit unit);
	void onUnitComplete(BWAPI::Unit unit);
	void onUnitRenegade(BWAPI::Unit unit);
	void onUnitDestroy(BWAPI::Unit unit);
	void onUnitMorph(BWAPI::Unit unit);
	void onUnitCreated(BWAPI::Unit unit);

	GameCommander();
	~GameCommander();
};

GameCommander::GameCommander()
{
	executors = new std::string[6] { "Artanis", "Alarak", "Vorazun", "Tassadar", "karax", "Fenix" };
	currentExecutor = Config::Module::defaultExecutor;
}

GameCommander::~GameCommander()
{
	free(executors);
}

class UnitToAssign
{
public:

	BWAPI::Unit unit;
	bool isAssigned;
	UnitToAssign(BWAPI::Unit u) :unit(u), isAssigned(false){};
};