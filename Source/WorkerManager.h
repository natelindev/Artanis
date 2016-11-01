#pragma once
#include "workerData.h"

class WorkerManager
{

	WorkerData workerData;

public:

	void		update();
	void		onUnitCreated(BWAPI::Unit unit);
	void		onUnitComplete(BWAPI::Unit unit);
	void        onUnitDestroy(BWAPI::Unit unit);
	void        onUnitMorph(BWAPI::Unit unit);
	void        onUnitShow(BWAPI::Unit unit);
	void        onUnitRenegade(BWAPI::Unit unit);

	void handleIdleWorkers();
	void setMineralWorker(BWAPI::Unit unit);
	BWAPI::Unit getClosestDepot(BWAPI::Unit worker);

	static WorkerManager &  Instance();
};