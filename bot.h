#ifndef _BOT_H_
#define _BOT_H_

#include "eiface.h"
#include "edict.h"
#include "game/server/iplayerinfo.h"

// This is our bot class.
class CPluginBot
{
public:
	CPluginBot() :
		m_bBackwards(0),
		m_flNextTurnTime(0),
		m_bLastTurnToRight(0),
		m_flNextStrafeTime(0),
		m_flSideMove(0),
		m_ForwardAngle(),
		m_LastAngles()
	{
		m_Respawn = false;
	}

	bool			m_bBackwards;

	float			m_flNextTurnTime;
	bool			m_bLastTurnToRight;

	float			m_flNextStrafeTime;
	float			m_flSideMove;

	QAngle			m_ForwardAngle;
	QAngle			m_LastAngles;

	IBotController	*m_BotInterface;
	IPlayerInfo		*m_PlayerInfo;
	edict_t			*m_BotEdict;

	bool			m_Respawn;
};

extern CUtlVector<CPluginBot *> s_Bots;

#endif // _BOT_H_
