#include "EngineApplication.h"
#include <chrono>
#include <thread>
#include <iostream>

EngineApplication::EngineApplication() {}

EngineApplication::~EngineApplication() {
    for (EngineScene* scene : scenes) {
        delete scene;
    }
}

void EngineApplication::registerScene(EngineScene* scene) {
    scenes.push_back(scene);
    scene->init();
}

void EngineApplication::run() {
    constexpr float frameTime = 1.0f/ 60.0f;
    auto last = std::chrono::high_resolution_clock::now();

    while (true) {
        auto now = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(now - last).count();

        if (deltaTime >= frameTime) {
            if (!scenes.empty()) {
                scenes[currentScene]->update(deltaTime);
            }
            if (!scenes.empty()) {
                scenes[currentScene]->render();
            }
            handleInput();
            last = now;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void EngineApplication::handleInput() {
    InputEvent event;
    event.type = InputEvent::None;
    if (!scenes.empty()) {
        scenes[currentScene]->onInput(event);
    }
}