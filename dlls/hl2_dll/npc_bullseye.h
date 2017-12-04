//========= Copyright � 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef NPC_BULLSEYE_H
#define NPC_BULLSEYE_H
#ifdef _WIN32
#pragma once
#endif

#include "AI_BaseNPC.h"

//=========================================================
//	>> CBullseye
//=========================================================
class CNPC_Bullseye : public CAI_BaseNPC
{
	DECLARE_CLASS( CNPC_Bullseye, CAI_BaseNPC );

public:
	CNPC_Bullseye(void);
	~CNPC_Bullseye();

	virtual void Precache( void );
	virtual void Spawn( void );
	virtual void Activate( void );

	Class_T Classify( void );
	void	Event_Killed( const CTakeDamageInfo &info );
	void	DecalTrace( trace_t *pTrace, char const *decalName );
	void	ImpactTrace( trace_t *pTrace, int iDamageType, char *pCustomImpactName );
	bool	IsLightDamage( float flDamage, int bitsDamageType );
	void	TraceAttack( const CTakeDamageInfo &info, const Vector &vecDir, trace_t *ptr );
	int		OnTakeDamage( const CTakeDamageInfo &info );
	bool	UsePerfectAccuracy( void ) { return m_bPerfectAccuracy; }
	
	void	BullseyeThink( void );

	void	SetPainPartner( CBaseEntity *pOther );
	void	InputTargeted( inputdata_t &inputdata );
	void	InputReleased( inputdata_t &inputdata );
	bool	CanBecomeServerRagdoll( void ) { return false;	} // VXP

protected:

	EHANDLE			m_hPainPartner;	//Entity that the bullseye will pass any damage it take to
	COutputEvent	m_OnTargeted;
	COutputEvent	m_OnReleased;
	bool			m_bPerfectAccuracy;	// Entities that shoot at me should be perfectly accurate

	DECLARE_DATADESC();
};

int FindBullseyesInCone( CBaseEntity **pList, int listMax, const Vector &coneOrigin, const Vector &coneAxis, float coneAngleCos, float coneLength );

#define SF_BULLSEYE_NONSOLID		(1 << 16)
#define SF_BULLSEYE_NODAMAGE		(1 << 17)
#define	SF_BULLSEYE_ENEMYDAMAGEONLY	(1 << 18)
#define	SF_BULLSEYE_BLEED			(1 << 19)
#define SF_BULLSEYE_PERFECTACC		(1 << 20)


#endif	// NPC_BULLSEYE_H

