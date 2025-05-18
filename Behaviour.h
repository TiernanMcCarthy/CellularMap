#pragma once

class GameObject;
/// <summary>
/// Version of a Component Or Adjacent to Unity Monobehaviour
/// </summary>
class Behaviour {
public:
    GameObject* gameObject = nullptr;

    virtual ~Behaviour() = default;

    // Called after construction and after being added to a GameObject
    virtual void Start();

    // Set the parent GameObject pointer
    void SetGameObject(GameObject* parent) {
        gameObject = parent;
    }
};