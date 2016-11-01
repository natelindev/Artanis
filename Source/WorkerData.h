#pragma once
#include "common.h"

class WorkerData
{
public:

	enum WorkerJob{ Minerals, Gas, Build, Combat, Idle, Move, Scout, Default };

private:
	BWAPI::Unitset workers;
	BWAPI::Unitset depots;

	std::map<BWAPI::Unit, enum WorkerJob>   workerJobMap;
	std::map<BWAPI::Unit, BWAPI::Unit>		workerMineralMap;
	std::map<BWAPI::Unit, BWAPI::Unit>		workerRefineryMap;
	std::map<BWAPI::Unit, BWAPI::Unit>		workerDepotMap;

	std::map<BWAPI::Unit, int>              workersOnMineralPatch;
	std::map<BWAPI::Unit, BWAPI::Unit>		workerMineralAssignment;
	std::map<BWAPI::Unit, BWAPI::Unit>		workerGasAssignment;

	std::map<BWAPI::Unit, int>                    depotWorkerCount;
	std::map<BWAPI::Unit, int>                    refineryWorkerCount;

	void clearPreviousJob(BWAPI::Unit unit);

public:
	void		workerDestroyed(BWAPI::Unit unit);

	void		addWorker(BWAPI::Unit unit);
	void		addWorker(BWAPI::Unit unit, WorkerJob job, BWAPI::Unit jobUnit);
	void		addWorker(BWAPI::Unit unit, WorkerJob job, BWAPI::UnitType jobUnitType);

	void		addDepot(BWAPI::Unit unit);

	int					getNumWorkers() const;
	int					getNumMineralWorkers() const;
	int					getNumGasWorkers() const;
	int					getNumIdleWorkers() const;
	char				getJobCode(BWAPI::Unit unit);
	enum WorkerJob			getWorkerJob(BWAPI::Unit unit);

	BWAPI::Unit			getMineralToMine(BWAPI::Unit worker);
	BWAPI::Unit			getWorkerDepot(BWAPI::Unit unit);
	BWAPI::Unitset      getMineralPatchesNearDepot(BWAPI::Unit depot);

	void setWorkerJob(BWAPI::Unit unit, enum WorkerJob job, BWAPI::Unit jobUnit);

	const BWAPI::Unitset & getWorkers() const { return workers; }
	WorkerData();
	~WorkerData();

};
