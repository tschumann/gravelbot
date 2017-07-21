//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "eiface.h"

#ifndef _BOTBASEPLAYER_H_
#define _BOTBASEPLAYER_H_

class BotBasePlayer
{
public:
	BotBasePlayer();
	BotBasePlayer( CBaseEntity *pObject );
	virtual const Vector EyeAngles() = 0;
protected:
	CBaseEntity *pObject;
};

#endif // _BOTBASEPLAYER_H_