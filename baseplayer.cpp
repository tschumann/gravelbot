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

const Vector BotBasePlayer::EyeAngles()
{
	// get this
	void **pThis = *(void ***)&this->pObject;
	// get the vtable as an array of void *
	void **vtable = *(void ***)pThis;
#ifndef __linux__
	// the method we want is in the vtable
	void *pMethod = vtable[this->m_EyeAnglesOffset];
#else
	// the method we want is 132nd in the vtable
	void *pMethod = vtable[132];
#endif // __linux__

	// use a union to get the address as a function pointer
	union
	{
		Vector(VirtualEmpty::*mfpnew)();
#ifndef __linux__
		void *addr;
	} u;

	u.addr = pMethod;
#else // GCC's member function pointers all contain this pointer adjustor - you'd probably set it to 0 
		struct
		{
			void *addr;
			intptr_t adjustor;
		} s;
	} u;

	u.s.addr = pMethod;
	u.s.adjustor = 0;
#endif // __linux__

	return (Vector)(reinterpret_cast<VirtualEmpty*>(pThis)->*u.mfpnew)();
}