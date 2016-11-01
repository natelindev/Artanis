#include "common.h"
#include "WorkerData.h"

void WorkerData::addWorker(BWAPI::Unit unit)
{
	if (!unit) { return; }

	workers.insert(unit);
	workerJobMap[unit] = Default;
}
void WorkerData::addWorker(BWAPI::Unit unit, enum WorkerJob job, BWAPI::Unit jobUnit)
{
	
}

void WorkerData::addWorker(BWAPI::Unit unit, enum WorkerJob job, BWAPI::UnitType jobUnitType)
{
	
}

void WorkerData::addDepot(BWAPI::Unit unit)
{
	if (!unit) { return; }

	depots.insert(unit);
	depotWorkerCount[unit] = 0;
}


void WorkerData::workerDestroyed(BWAPI::Unit unit)
{
	if (!unit){return;}
	clearPreviousJob(unit);
	workers.erase(unit);
}

enum WorkerData::WorkerJob WorkerData::getWorkerJob(BWAPI::Unit unit)
{
	if (!unit) { return Default; }

	std::map<BWAPI::Unit, enum WorkerJob>::iterator it = workerJobMap.find(unit);

	if (it != workerJobMap.end())
	{
		return it->second;
	}

	return Default;
}

void WorkerData::clearPreviousJob(BWAPI::Unit unit)
{
	if (!unit){ return; }

}

int	WorkerData::getNumWorkers() const
{
	return workers.size();
}

int WorkerData::getNumMineralWorkers() const
{
	size_t num = 0;
	for (auto & unit : workers)
	{
		if (workerJobMap.at(unit) == Minerals)
		{
			++num;
		}
	}
	return num;
}

int	WorkerData::getNumGasWorkers() const
{
	size_t num = 0;
	for (auto & unit : workers)
	{
		if (workerJobMap.at(unit) == Gas)
		{
			++num;
		}
	}
	return num;
}

int WorkerData::getNumIdleWorkers() const
{
	size_t num = 0;
	for (auto& worker : workers)
	{
		if (workerJobMap.at(worker) == WorkerData::Idle)
		{
			++num;
		}
	}
	return num;
}



char WorkerData::getJobCode(BWAPI::Unit unit)
{
	if (!unit) { return 'X'; }

	WorkerData::WorkerJob j = getWorkerJob(unit);

	if (j == WorkerData::Build) return 'B';
	if (j == WorkerData::Combat) return 'C';
	if (j == WorkerData::Default) return 'D';
	if (j == WorkerData::Gas) return 'G';
	if (j == WorkerData::Idle) return 'I';
	if (j == WorkerData::Minerals) return 'M';
	if (j == WorkerData::Move) return 'O';
	if (j == WorkerData::Scout) return 'S';
	return 'X';
}

void WorkerData::setWorkerJob(BWAPI::Unit unit, enum WorkerJob job, BWAPI::Unit jobUnit)
{
	if (!unit) { return; }

	clearPreviousJob(unit);
	workerJobMap[unit] = job;

	if (job == Minerals)
	{
		workerDepotMap[unit] = jobUnit;
		BWAPI::Unit mineralToMine = getMineralToMine(unit);
		workerMineralAssignment[unit] = mineralToMine;
		unit->rightClick(mineralToMine);
	}
	
}

BWAPI::Unit WorkerData::getMineralToMine(BWAPI::Unit worker)
{
	if (!worker) { return nullptr; }

	// get the depot associated with this unit
	BWAPI::Unit depot = getWorkerDepot(worker);
	BWAPI::Unit bestMineral = nullptr;
	double bestDist = 100000;
	double bestNumAssigned = 10000;

	if (depot)
	{
		BWAPI::Unitset mineralPatches = getMineralPatchesNearDepot(depot);

		for (auto & mineral : mineralPatches)
		{
			double dist = mineral->getDistance(depot);
			double numAssigned = workersOnMineralPatch[mineral];

			if (numAssigned < bestNumAssigned)
			{
				bestMineral = mineral;
				bestDist = dist;
				bestNumAssigned = numAssigned;
			}
			else if (numAssigned == bestNumAssigned)
			{
				if (dist < bestDist)
				{
					bestMineral = mineral;
					bestDist = dist;
					bestNumAssigned = numAssigned;
				}
			}

		}
	}

	return bestMineral;
}

BWAPI::Unit WorkerData::getWorkerDepot(BWAPI::Unit unit)
{
	if (!unit) { return nullptr; }

	std::map<BWAPI::Unit, BWAPI::Unit>::iterator it = workerDepotMap.find(unit);

	if (it != workerDepotMap.end())
	{
		return it->second;
	}

	return nullptr;
}

BWAPI::Unitset WorkerData::getMineralPatchesNearDepot(BWAPI::Unit depot)
{
	// if there are minerals near the depot, add them to the set
	BWAPI::Unitset mineralsNearDepot;

	int radius = 300;

	for (auto & unit : BWAPI::Broodwar->getAllUnits())
	{
		if ((unit->getType() == BWAPI::UnitTypes::Resource_Mineral_Field) && unit->getDistance(depot) < radius)
		{
			mineralsNearDepot.insert(unit);
		}
	}

	// if we didn't find any, use the whole map
	if (mineralsNearDepot.empty())
	{
		for (auto & unit : BWAPI::Broodwar->getAllUnits())
		{
			if ((unit->getType() == BWAPI::UnitTypes::Resource_Mineral_Field))
			{
				mineralsNearDepot.insert(unit);
			}
		}
	}

	return mineralsNearDepot;
}