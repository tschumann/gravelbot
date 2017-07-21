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
	class CBasePlayer : public BasePlayer
	{
	public:
		virtual const Vector EyeAngles();
	};
}