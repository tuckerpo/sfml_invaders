#pragma once
#include "Entity.h"
class EntityManager
{
public:
	EntityManager() = default;
	virtual ~EntityManager() = default;
	virtual std::vector<std::shared_ptr<Entity>> getEntities() const;
	virtual std::vector<std::shared_ptr<Entity>> getEntitiesByType(const EntityType et) const;
	virtual bool addEntity(const std::shared_ptr<Entity>& entity);

private:
	std::vector<std::shared_ptr<Entity>> m_Entities;
};

