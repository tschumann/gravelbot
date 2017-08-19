//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "eiface.h"
#include "bot_baseentity.h"
#include "baseplayer.h"

namespace dod
{
	class CBasePlayer : public BotBasePlayer
	{
	public:
		explicit CBasePlayer( CBaseEntity *pObject ) : BotBasePlayer( pObject )
		{
		}
	protected:
		int m_EyeAnglesOffset = 131;
	};
}