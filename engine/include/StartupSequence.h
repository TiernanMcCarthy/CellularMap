//
// Created by Tiern on 25/06/2025.
//
#pragma once

///Exists as something for the engine to execute during startup, cheap and quick fix to spawn objects from the game .cpp
///This is a really cheap way to do a bit of editor work for now
class StartupSequence {

public:

    virtual ~StartupSequence() = default;

    StartupSequence();

    virtual void Execute();




};
