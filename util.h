//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "eiface.h"

#ifndef _UTIL_H_
#define _UTIL_H_

#if __has_include("../appid.h")
#include "../appid.h"
#endif

extern IVEngineServer *engine;

int GetAppID();
CBaseEntity* GetBaseEntity( edict_t *pEntity );
BotBasePlayer *CreateBasePlayer(edict_t *pEdict);

#endif // _UTIL_H_