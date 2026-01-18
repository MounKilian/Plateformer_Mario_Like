#pragma once

#include "AComponent.h"

class UICoins : public AComponent
{
	int type;
	Entity* m_player;

	public :
		void Init(int type, Entity* player);
		void Update(float deltatime);
		void ChangeCoinUI(int number);
};

