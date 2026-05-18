//
// Created by Tiern on 18/05/2026.
//
#include "TestPlayer/FollowCam.h"

#include "Objects/GameObject.h"
#include "Scenes/SceneManager.h"
#include "TestPlayer/TestPlayer.h"

void FollowCam::UpdateCameraPos(sf::Vector2f targetPos)
{
    sf::Vector2f lookahead=targetPos;
    lookahead.x+= lookaheadTarget;
    gameObject->transform.SetPosition(lookahead);
    targetY= targetPos.y;
}
void FollowCam::Start()
{
    target= SceneManagement::GetBehaviourOfType<TestPlayer>();

    if (target!=nullptr)
    {
        UpdateCameraPos(target->gameObject->transform.GetPosition());
    }

    renderTarget = &Engine::GEngine->GetRenderWindow();

    cameraView = renderTarget->getView();

}

void FollowCam::RestartCamera()
{

}

void FollowCam::Update(float deltaTime)
{

}