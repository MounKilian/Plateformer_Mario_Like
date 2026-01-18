#pragma once

#include "AComponent.h"

class UICoins : public AComponent
{
	int type;

	public :
		void Init(int type);
		void Update(float deltatime);
		void CreateUI(int type);
};

