#include "framework.h"
#include "CScene_Dungeon.h"

#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"

#include "Back_Ground_Layer.h"
#include "CUICursor.h"

#include "CShort_Sword.h"
#include "CPowerKatana.h"

CScene_Dungeon::CScene_Dungeon()
{
}

CScene_Dungeon::~CScene_Dungeon()
{
}

void CScene_Dungeon::update()
{
	CScene::update();

	if (KeyDown(VK_TAB))
	{
		ChangeScn(GROUP_SCENE::START);
	}
}

void CScene_Dungeon::Enter()
{
	CCameraManager::getInst()->FadeIn(1.f);
	CSoundManager::getInst()->AddSound(L"CScene_Duneon_bgm", L"sound\\1.JailField.wav", false);
	CSoundManager::getInst()->Play(L"CScene_Duneon_bgm");

	wstring path = CPathManager::getInst()->GetContentPath();
	path += L"tile\\test2.tile";
	LoadTile(path);

	CPlayer* pPlayer = new CPlayer;
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);
	pPlayer->SaveData(sPlayer->LoadData());
	//pPlayer->SetPos(fPoint(WINSIZEX / 2, WINSIZEY / 2));
	
	CShort_Sword* pShort_Sword = new CShort_Sword;
	AddObject(pShort_Sword, GROUP_GAMEOBJ::ITEM);

	CPowerKatana* pPowerKatana = new CPowerKatana;
	AddObject(pPowerKatana, GROUP_GAMEOBJ::ITEM);

	
	Back_Ground_Layer* dungeonlayer = new Back_Ground_Layer;
	dungeonlayer->Load(L"SubBG", L"texture\\dungeon\\SubBG.png", fPoint(0.f,0.f), 3.f);
	AddObject(dungeonlayer, GROUP_GAMEOBJ::BACKGROUND);

	CUICursor* pCursortown = new CUICursor;
	pCursortown->Load(L"ShootingCursor", L"texture\\ui\\ShootingCursor.png");
	AddObject(pCursortown, GROUP_GAMEOBJ::CURSOR);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::TILE);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::ITEM);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::TILE, GROUP_GAMEOBJ::ITEM);

	CCameraManager::getInst()->SetTargetObj(pPlayer);
}

void CScene_Dungeon::Exit()
{
	CSoundManager::getInst()->Stop(L"CScene_Duneon_bgm");
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
