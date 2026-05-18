//
// Created by Tiern on 18/05/2026.
//

#ifndef SPLATFORM_FOLLOWCAM_H
#include "Objects/Behaviour.h"

class TestPlayer;
class FollowCam: public Behaviour
{

private:

    TestPlayer* target = nullptr;

    //Camera Movement Attributes
    float moveSpeed =5;

    float damperForce=5;

    //Camera Framing Settings, we want a lookahead e.t.c
    float lookaheadTarget=20; //X distance from the camera in either direction is better than the player being at the centre



    float heightAdjustTarget=20;

    // we only adjust the target Y when the target has moved > heightAdjustTarget from targetY & then reassign target Y to this
    float targetY=0;

    //Camera zoom settings
    float zoomLevel;
    float zoomSpeed;
    float oldZoom;

    //Render variables
    sf::View cameraView;

    sf::RenderWindow *renderTarget = nullptr;

    void Update(float deltaTime) override;

    void UpdateCameraPos(sf::Vector2f targetPos);

public:

    void Start() override;



    void RestartCamera();






};


#endif // SPLATFORM_FOLLOWCAM_H
