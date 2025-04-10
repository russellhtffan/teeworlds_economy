/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "mod.h"
#include <cstring>

CGameControllerMOD::CGameControllerMOD(class CGameContext *pGameServer)
: IGameController(pGameServer)
{
	// Exchange this to a string that identifies your game mode.
	// DM, TDM and CTF are reserved for teeworlds original modes.
	m_pGameType = "Economy";
}

void CGameControllerMOD::Tick()
{
	// this is the main part of the gamemode, this function is run every tick

	IGameController::Tick();
}

void CGameControllerMOD::DoWincheck()
{
      return;
}

void CGameControllerMOD::OnCharacterSpawn(class CCharacter *pChr)
{
    pChr->IncreaseHealth(10);
    pChr->IncreaseArmor(10);
    pChr->GiveWeapon(WEAPON_HAMMER, -1);
    pChr->GiveWeapon(WEAPON_GRENADE, -1);
}

int CGameControllerMOD::OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon)
{
	if(pVictim->GetPlayer()->m_IsDummy == true){
		pKiller->m_Score++;
		return true;
	}
	else{
	    return true;
	}
}
