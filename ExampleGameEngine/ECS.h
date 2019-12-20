#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class ECS
{

};

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getCOmponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}


template <typename T> inline ComponentID getCOmponentTypeID() noexcept
{
	static ComponentID typeID = getCOmponentTypeID();
	return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}

};

class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
public:
	void update()
	{
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw() {}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getCOmponentID<T>];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getCOmponentTypeID<T>()]; = c;
		componentBitSet[getCOmponentTypeID<T>()]; = true;

		c->init();
		return *c;

	}

	template <typename T> T& getCOmponent() const
	{
		auto ptr(componentArray[getCOmponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};


