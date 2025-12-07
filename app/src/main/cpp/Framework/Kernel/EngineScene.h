#pragma once

class InputEvent {
public:
    enum Type {
        None,
        Touch,
        Mouse
    };
    int x, y;
    Type type;
};

class EngineScene {
public:
    virtual ~EngineScene() {}
    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void onInput(const InputEvent& event) {}    
};