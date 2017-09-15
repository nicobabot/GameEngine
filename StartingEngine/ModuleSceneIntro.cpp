#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include"ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->LookAt(vec3(0, 0, 0));

	Cube PlainGame;
	PlainGame.size.x = 700;
	PlainGame.size.z = 700;
	MyCubeMap.PushBack(PlainGame);
	PlainGame_Body = App->physics->AddBody(PlainGame, 0);
	PlainGame_Body->SetPos(102.5, -0.5, -30);
	PlainGame_Body->collision_listeners.add(this);
	MyPhysbodyCubeMap.PushBack(PlainGame_Body);

	return ret;
}


update_status ModuleSceneIntro::PreUpdate(float dt)
{

	

	return UPDATE_CONTINUE;
}


// Update
update_status ModuleSceneIntro::Update(float dt)
{
	
	for (int i = 0; i < MyCubeMap.Count(); i++) {
		MyPhysbodyCubeMap[i]->GetTransform(&MyCubeMap[i].transform);
		MyCubeMap[i].Render();

	}
	for (int i = 0; i < MySphereObj.Count(); i++) {
		MyPhysbodySphereobj[i]->GetTransform(&MySphereObj[i].transform);
		MySphereObj[i].Render();

	}
	for (int i = 0; i < MyCubeObj.Count(); i++) {
		MyPhysbodyCubeobj[i]->GetTransform(&MyCubeObj[i].transform);
		MyCubeObj[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}




