//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "bot.h"

void CPluginBot::HandleRespawn( CBotCmd &cmd )
{
	// Wait for Reinforcement wave
	if( this->m_PlayerInfo->IsDead() )
	{
		DevMsg( "Bot is spawning on team index %d\n", this->m_PlayerInfo->GetTeamIndex() );
		if( this->m_PlayerInfo->GetTeamIndex() == 0 )
		{
			helpers->ClientCommand( this->m_BotEdict, "joingame" );
			helpers->ClientCommand( this->m_BotEdict, "jointeam 2" );
			this->m_Respawn = true;
		}
	}
}