//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "bot.h"
#include "game.h"
#include "util.h"
#include "hl2mp_player.h"
#include "dod_player.h"

CBaseEntity* GetBaseEntity( edict_t *pEntity )
{
	if( !pEntity || pEntity->IsFree() )
	{
		return NULL;
	}

	CBaseEntity *pent = pEntity->GetUnknown()->GetBaseEntity();

	return pent;
}

BotBasePlayer *CreateBasePlayer( edict_t *pEdict )
{
	switch( engine->GetAppID() )
	{
	case Game::HL2DM_APPID:
		return new hl2dm::CBasePlayer( GetBaseEntity( pEdict ) );
		break;
	case Game::DOD_APPID:
		return new dod::CBasePlayer( GetBaseEntity( pEdict ) );
		break;
	case Game::BMS_APPID:
		break;
	default:
		Error( "Unsupported appid %d\n", engine->GetAppID() );
		return NULL;
	}
}