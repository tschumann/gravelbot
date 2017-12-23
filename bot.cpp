//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "bot.h"
#include "util.h"

CPluginBot::CPluginBot( edict_t *pEdict )
{
	m_bBackwards = 0;
	m_flNextTurnTime = 0;
	m_bLastTurnToRight = 0;
	m_flNextStrafeTime = 0;
	m_flSideMove = 0;
	m_ForwardAngle = QAngle();
	m_LastAngles = QAngle();
	m_Respawn = false;
	this->m_BotEdict = pEdict;
	this->pPlayer = CreateBasePlayer( pEdict );
}

int CPluginBot::GetMaxHealth()
{
	return 100;
}

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

bool CPluginBot::CanMove()
{
	return bot_move.GetInt() > 0;
}

const Vector CPluginBot::EyeAngles()
{
	return this->pPlayer->EyeAngles();
}

//-----------------------------------------------------------------------------
// Repurposed from CAI_BaseNPC::FInAimCone in game/server/ai_basenpc.cpp
//-----------------------------------------------------------------------------
bool CPluginBot::FInAimCone( const Vector &vecSpot )
{
	Vector los = ( vecSpot - this->m_PlayerInfo->GetAbsOrigin() );

	// do this in 2D
	los.z = 0;
	VectorNormalize( los );

	Vector facingDir = BodyDirection2D();

	float flDot = DotProduct(los, facingDir);

	// 60 degree field of view
	return ( flDot > 0.50 );
}

//-----------------------------------------------------------------------------
// Repurposed from CBaseCombatCharacter::BodyAngles in game/server/basecombatcharacter.cpp
//-----------------------------------------------------------------------------
QAngle CPluginBot::BodyAngles()
{
	return this->m_PlayerInfo->GetAbsAngles();
}

//-----------------------------------------------------------------------------
// Repurposed from CBaseCombatCharacter::BodyDirection2D in game/server/basecombatcharacter.cpp
//-----------------------------------------------------------------------------
Vector CPluginBot::BodyDirection2D( void )
{
	Vector vBodyDir = BodyDirection3D();
	vBodyDir.z = 0;
	vBodyDir.AsVector2D().NormalizeInPlace();
	return vBodyDir;
}

//-----------------------------------------------------------------------------
// Repurposed from CBaseCombatCharacter::BodyDirection3D in game/server/basecombatcharacter.cpp
//-----------------------------------------------------------------------------
Vector CPluginBot::BodyDirection3D( void )
{
	QAngle angles = BodyAngles();

	// FIXME: cache this
	Vector vBodyDir;
	AngleVectors( angles, &vBodyDir );
	return vBodyDir;
}