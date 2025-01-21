#include "AbstractMissile.h"
#include "Missile.h"
#include "FriendlyMissile.h"


//void MissileFactory(MissileType type,float x,float y, AbstractMissile *m) {
//	AbstractMissile* missile;
//	switch (type) {
//	case enemy:
//		missile = new Missile(x,y);
//		break;
//	case friendly:
//		missile = new FriendlyMissile(x, y);
//		break;
//	default:
//		missile = NULL;
//	}
//	return missile;
//}

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

AbstractMissile::AbstractMissile()
{
}
