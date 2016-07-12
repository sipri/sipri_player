#include "StdAfx.h"
#include "PlayControl.h"

#include "StringConverter.h"
#include <wchar.h>

using namespace sipri_mp3_player;
using namespace common;

CPlayControl::CPlayControl(void)
{
	m_pPlayer = CreateZPlay();
}

CPlayControl::~CPlayControl(void)
{
	m_pPlayer->Release();
}

void CPlayControl::SetFile(System::String^ pFileName)
{
	size_t szNameSize = pFileName->Length+1;

	wchar_t* pWcFileName = new wchar_t[pFileName->Length+1];
	wmemset(pWcFileName, 0, szNameSize);
	CStringConverter::StringToWchar(pFileName, pWcFileName, szNameSize);

	m_pPlayer->OpenFileW(pWcFileName, sfAutodetect);
}

void CPlayControl::Play(void)
{
	m_pPlayer->Play();
}

void CPlayControl::Stop(void)
{
	m_pPlayer->Stop();
}

void CPlayControl::Pause(void)
{
	m_pPlayer->Pause();
}

void CPlayControl::Resume(void)
{
	m_pPlayer->Resume();
}
