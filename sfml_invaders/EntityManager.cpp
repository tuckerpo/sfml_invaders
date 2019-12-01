#include "EntityManager.h"

std::vector<std::shared_ptr<Entity>> EntityManager::getEntities() const
{
	return this->m_Entities;
}

std::vector<std::shared_ptr<Entity>> EntityManager::getEntitiesByType(const EntityType et) const
{
	std::vector<std::shared_ptr<Entity>> ret; 
	ret.reserve(this->m_Entities.size());
	for (std::shared_ptr<Entity> entity : this->m_Entities)
	{
		if (entity->getType() == et)
		{
			ret.push_back(entity);
		}
	}
	return ret;
}

bool EntityManager::addEntity(const std::shared_ptr<Entity>& entity)
{
	this->m_Entities.emplace_back(entity);
	return true;
}
