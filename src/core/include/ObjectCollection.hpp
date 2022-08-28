#pragma once

#include <memory>
#include <vector>
#include <queue>
#include <variant>

#include "tileson.hpp"
#include "Object.hpp"
#include "DrawableObjects.hpp"

class ObjectCollection
{

public:

  ObjectCollection();
  ~ObjectCollection();

  void Add(std::variant<std::shared_ptr<Object>, std::shared_ptr<tson::Map>> object);

  void Update(float deltaTime);
  void Draw(Window &window);

  void ProcessNewObjects();
  void ProcessRemovedObjects();

private:

  DrawableObjects m_drawableObjects;

  std::vector<std::shared_ptr<Object>> m_objects;
  std::queue<std::variant<std::shared_ptr<Object>, std::shared_ptr<tson::Map>>> m_newObjects;

};