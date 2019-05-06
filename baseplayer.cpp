//
// Gravelbot
//
// (http://www.teamsandpit.com/)
//

#include "baseplayer.h"
#include "bot_baseentity.h"

BotBasePlayer::BotBasePlayer( CBaseEntity *pObject )
{
	this->pObject = pObject;
}

const Vector BotBasePlayer::EyePosition()
{
	const CBaseEntity *pEntity = this->pObject;

	// get this
	const void **ppThis = *(const void ***)&pEntity;
	// get the vtable as an array of void *
	const void **ppVirtualTable = *(const void ***)pEntity;
	// the method we want is in the vtable
	const void *pMethod = ppVirtualTable[this->m_EyePositionOffset];

	// use a union to get the address as a function pointer
	union
	{
		Vector(VirtualEmpty::*mfpnew)();
#ifndef __linux__
		const void *addr;
	} u;

	u.addr = pMethod;
#else // GCC's member function pointers all contain this pointer adjustor - you'd probably set it to 0 
		struct
		{
			const void *addr;
			intptr_t adjustor;
		} s;
} u;

	u.s.addr = pMethod;
	u.s.adjustor = 0;
#endif // __linux__

	return (Vector)(reinterpret_cast<VirtualEmpty*>(ppThis)->*u.mfpnew)();
}

const Vector BotBasePlayer::EyeAngles()
{
	const CBaseEntity *pEntity = this->pObject;

	// get this
	const void **ppThis = *(const void ***)&pEntity;
	// get the vtable as an array of void *
	const void **ppVirtualTable = *(const void ***)pEntity;
	// the method we want is in the vtable
	const void *pMethod = ppVirtualTable[this->m_EyeAnglesOffset];

	// use a union to get the address as a function pointer
	union
	{
		Vector(VirtualEmpty::*mfpnew)();
#ifndef __linux__
		const void *addr;
	} u;

	u.addr = pMethod;
#else // GCC's member function pointers all contain this pointer adjustor - you'd probably set it to 0 
		struct
		{
			const void *addr;
			intptr_t adjustor;
		} s;
	} u;

	u.s.addr = pMethod;
	u.s.adjustor = 0;
#endif // __linux__

	return (Vector)(reinterpret_cast<VirtualEmpty*>(ppThis)->*u.mfpnew)();
}