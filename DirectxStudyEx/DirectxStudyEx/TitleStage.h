#pragma once
#include "Global.h"
#include "Stage_Manager.h" 

class TitleStage : public Stage
{
public:
	void Update() override;
	void Render() override;
};

