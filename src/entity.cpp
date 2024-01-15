#include "entity.hpp"

Entity::Entity()
: Entity({0}, {0}) {}

Entity::Entity(Vector3 position, Vector3 size)
: color({ 255, 0, 255, 255 })
, position(position)
, size(size) {}

Entity::~Entity() {}

const Color&   Entity::Color()    const { return color; }
const Vector3& Entity::Position() const { return position; }
const Vector3& Entity::Size()     const { return size; }

