#include "AbstractMissile.h"
#include "Missile.h"
#include "FriendlyMissile.h"

/**
 * @brief Factory function to create different types of missiles.
 * 
 * @param type The type of missile to create (enemy or friendly).
 * @param x The x-coordinate for the missile's initial position.
 * @param y The y-coordinate for the missile's initial position.
 * @return AbstractMissile* Pointer to the created missile object.
 */
AbstractMissile* MissileFactory(MissileType type, float x, float y)
{
	AbstractMissile* missile;
	switch (type) {
		case enemy:
			missile = new Missile(x,y);
			break;
		case friendly:
			missile = new FriendlyMissile(x, y);
			break;
		default:
			missile = NULL;
	}
	return missile;
}

/**
 * @brief Default constructor for AbstractMissile.
 */
AbstractMissile::AbstractMissile()
{
}
