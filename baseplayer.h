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
	BotBasePlayer( CBaseEntity *pObject );
	virtual const Vector EyePosition();
	virtual const Vector EyeAngles();
protected:
	CBaseEntity *pObject;

	int m_EyePositionOffset;
	int m_EyeAnglesOffset;
};

#endif // _BOTBASEPLAYER_H_