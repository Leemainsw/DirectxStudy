#pragma once

#include "Stage_Manager.h"

class TitleStage : public Stage
{
public:
	char prevKeyBuffer[256];
	char keyBuffer[256];
	void Update() override;
	void Render() override;
};

