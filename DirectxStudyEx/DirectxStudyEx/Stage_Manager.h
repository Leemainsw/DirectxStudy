#pragma once

class Stage {
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};

class Stage_Manager
{
public:
	Stage* currentStage;

	void Render();
	void Update();

	void MakeTitleStage();
	void MakeGameStage();
};

