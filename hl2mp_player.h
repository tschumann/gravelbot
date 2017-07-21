//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "eiface.h"
#include "bot_baseentity.h"
#include "baseplayer.h"

namespace hl2dm
{
	class CBasePlayer : public BotBasePlayer
	{
	public:
		CBasePlayer( CBaseEntity *pObject );
		virtual const Vector EyeAngles();
	};
}