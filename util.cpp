//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "util.h"

CBaseEntity* GetBaseEntity( edict_t *pEntity )
{
	if( !pEntity || pEntity->IsFree() )
	{
		return NULL;
	}

	CBaseEntity *pent = pEntity->GetUnknown()->GetBaseEntity();

	return pent;
}