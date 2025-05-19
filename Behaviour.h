#pragma once

class GameObject;
/// <summary>
/// Version of a Component Or Adjacent to Unity Monobehaviour
/// </summary>
class Behaviour {
public:
    GameObject* gameObject = nullptr;

    virtual ~Behaviour() = default;

    // Called after being added to a gameobject
    virtual void Start();

    //Main Update of a behaviour, once per frame
    virtual void Update(float deltaTime);



    // Set the parent GameObject pointer
    void SetGameObject(GameObject* parent) {
        gameObject = parent;
    }
};