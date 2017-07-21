//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "eiface.h"

class BasePlayer
{
public:
	virtual const Vector EyeAngles() = 0;
protected:
	CBaseEntity *pObject;
};