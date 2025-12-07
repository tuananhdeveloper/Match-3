#pragma once
#include "../Kernel/EngineScene.h"
#include <vector>

class EngineApplication {
public:
    EngineApplication();
    ~EngineApplication();
    
    void registerScene(EngineScene* scene);
    void run();

private:
    std::vector<EngineScene*> scenes;
    int currentScene = 0;
    
    void handleInput();
};