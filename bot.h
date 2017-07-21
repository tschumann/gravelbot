//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#ifndef _BOT_H_
#define _BOT_H_

#include "eiface.h"
#include "edict.h"
#include "game/server/iplayerinfo.h"
#include "plugin_interface.h"
#include "baseplayer.h"

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

	void HandleRespawn( CBotCmd &cmd );

	// TODO: should be protected
	BotBasePlayer *pPlayer;
protected:
};

class HL2DMBot : public CPluginBot
{
	//
};

class DODBot : public CPluginBot
{
	//
};

class BMSBot : public CPluginBot
{
	//
};

extern CUtlVector<CPluginBot *> s_Bots;

#endif // _BOT_H_
