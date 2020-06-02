#include "Stage_Manager.h"
#include "Global.h"

void Stage_Manager::MakeGameStage()
{
	if (currentStage != nullptr)
		delete currentStage;
	//stage ����
	//currentStage�� stage ����
}

void Stage_Manager::MakeTitleStage()
{
	if (currentStage != nullptr)
		delete currentStage;
	TitleStage* stage = new TitleStage();
	currentStage = stage;
	//currentStage�� stage ����
}

void Stage_Manager::Update()
{
	if (currentStage != nullptr)
		currentStage->Update();

}

void Stage_Manager::Render()
{
	if (currentStage != nullptr)
		currentStage->Render();
}