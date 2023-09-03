//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#ifndef _BOT_H_
#define _BOT_H_

#include "eiface.h"
#include "edict.h"
#if __has_include("dlls/iplayerinfo.h")
#include "dlls/iplayerinfo.h"
#endif
#if __has_include("game/server/iplayerinfo.h")
#include "game/server/iplayerinfo.h"
#endif
#include "plugin_interface.h"
#include "baseplayer.h"

extern ConVar bot_move;

// This is our bot class.
class CPluginBot
{
public:
	CPluginBot( edict_t *pEdict );

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

	int GetMaxHealth();

	void HandleRespawn( CBotCmd &cmd );

	bool CanMove();

	const Vector EyePosition();
	const Vector EyeAngles();

	bool FInAimCone( const Vector &vecSpot );

	// TODO: should be protected
	BotBasePlayer *pPlayer;
protected:
	QAngle BodyAngles();
	Vector BodyDirection2D( void );
	Vector BodyDirection3D( void );
};

class HL2DMBot : public CPluginBot
{
public:
	explicit HL2DMBot( edict_t *pEdict ) : CPluginBot( pEdict )
	{
	}
};

class DODBot : public CPluginBot
{
public:
	explicit DODBot( edict_t *pEdict ) : CPluginBot( pEdict )
	{
	}
};

class BMSBot : public CPluginBot
{
public:
	explicit BMSBot( edict_t *pEdict ) : CPluginBot( pEdict )
	{
	}
};

extern CUtlVector<CPluginBot *> s_Bots;

#endif // _BOT_H_
