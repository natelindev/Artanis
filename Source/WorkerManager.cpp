
#include "common.h"
#include "WorkerManager.h"



void WorkerManager::update()
{
	handleIdleWorkers();
}

void WorkerManager::onUnitDestroy(BWAPI::Unit unit)
{
	if (unit->getType().isWorker() && unit->getPlayer() == BWAPI::Broodwar->self())
	{
		workerData.workerDestroyed(unit);
	}
}

void  WorkerManager::onUnitShow(BWAPI::Unit unit)
{
	if (unit->getType().isResourceDepot() && unit->getPlayer() == BWAPI::Broodwar->self())
	{
		workerData.addDepot(unit);
	}

	// if something morphs into a worker, add it
	if (unit->getType().isWorker() && unit->getPlayer() == BWAPI::Broodwar->self() && unit->getHitPoints() >= 0)
	{
		//BWAPI::Broodwar->printf("A worker was shown %d", unit->getID());
		workerData.addWorker(unit);
	}
}

void	WorkerManager::onUnitMorph(BWAPI::Unit unit)
{
	if (unit->getType().isWorker() && unit->getPlayer() == BWAPI::Broodwar->self() && unit->getHitPoints() >= 0)
	{
		//BWAPI::Broodwar->printf("A worker was shown %d", unit->getID());
		workerData.addWorker(unit);
	}
}

void	WorkerManager::onUnitCreated(BWAPI::Unit unit)
{
	if (unit->getType().isWorker() && unit->getPlayer() == BWAPI::Broodwar->self() && unit->getHitPoints() >= 0)
	{
		//BWAPI::Broodwar->printf("A worker was shown %d", unit->getID());
		workerData.addWorker(unit);
	}
}

void	WorkerManager::onUnitComplete(BWAPI::Unit unit)
{
	if (unit->getType().isWorker() && unit->getPlayer() == BWAPI::Broodwar->self() && unit->getHitPoints() >= 0)
	{
		//BWAPI::Broodwar->printf("A worker was shown %d", unit->getID());
		workerData.addWorker(unit);
	}
}

void WorkerManager::handleIdleWorkers(){
	for (auto & worker : workerData.getWorkers())
	{
		if (workerData.getWorkerJob(worker) == WorkerData::Idle || workerData.getWorkerJob(worker) == WorkerData::Default)
		{
			setMineralWorker(worker);
		}
	}
}

void WorkerManager::setMineralWorker(BWAPI::Unit unit)
{
	
	BWAPI::Unit depot = getClosestDepot(unit);
	if (depot)
	{
		workerData.setWorkerJob(unit, WorkerData::Minerals, depot);
	}
}

BWAPI::Unit WorkerManager::getClosestDepot(BWAPI::Unit worker)
{

	BWAPI::Unit closestDepot = nullptr;
	double closestDistance = 0;

	for (auto & unit : BWAPI::Broodwar->self()->getUnits())
	{
		if (unit->getType().isResourceDepot() && unit->isCompleted())
		{
			double distance = unit->getDistance(worker);
			if (!closestDepot || distance < closestDistance)
			{
				closestDepot = unit;
				closestDistance = distance;
			}
		}
	}

	return closestDepot;
}