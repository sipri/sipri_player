#pragma once

#include "include/libzplay.h"

namespace sipri_mp3_player {

	using namespace System;
	using namespace libZPlay;

	ref class CPlayControl
	{
	private:
		ZPlay* m_pPlayer;

	public:
		CPlayControl(void);
		~CPlayControl(void);

		void SetFile(String^ pFileName);

		void Play(void);
		void Stop(void);
		void Pause(void);
		void Resume(void);
	};
}
