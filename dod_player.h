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
#ifndef __linux__
		int m_EyePositionOffset = 130;
		int m_EyeAnglesOffset = 131;
#else
		int m_EyePositionOffset = 131;
		int m_EyeAnglesOffset = 132;
#endif // __linux__
	};
}