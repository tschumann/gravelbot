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

int GetAppID()
{
#ifdef APPID
	return APPID;
#else
	return engine->GetAppID();
#endif // APPID
}

CBaseEntity* GetBaseEntity( edict_t *pEntity )
{
	if( !pEntity || pEntity->IsFree() )
	{
		return nullptr;
	}

	CBaseEntity *pent = pEntity->GetUnknown()->GetBaseEntity();

	return pent;
}

BotBasePlayer *CreateBasePlayer( edict_t *pEdict )
{
	switch( GetAppID() )
	{
	case Game::DOD_APPID:
		return new dod::CBasePlayer( GetBaseEntity( pEdict ) );
		break;
	case Game::HL2DM_APPID:
		return new hl2dm::CBasePlayer( GetBaseEntity( pEdict ) );
		break;
	case Game::PORTAL2_APPID:
	case Game::MM_APPID:
	case Game::INSURGENCY_APPID:
	case Game::EYE_APPID:
	case Game::BMS_APPID:
	default:
		Error( "Unsupported appid %d\n", GetAppID() );
		return nullptr;
	}
}