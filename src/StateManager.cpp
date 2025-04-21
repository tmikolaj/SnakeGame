#include "../include/StateManager.h"

Engine::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false) {

}
Engine::StateManager::~StateManager() {

}
void Engine::StateManager::add(std::unique_ptr<Engine::State> toAdd, bool replace) {
    m_add = true;
    newState = std::move(toAdd);

    m_replace = replace;
}
void Engine::StateManager::popCurrent() {
    m_add = true;
}
void Engine::StateManager::processState() {
    if (m_remove && (!stateStack.empty())) {

        stateStack.pop();

        if (!stateStack.empty()) {
            stateStack.top()->start();
        }
        m_remove = false;
    }

    if (m_add) {
        if (m_replace && (!stateStack.empty())) {
            stateStack.pop();
            m_replace = false;
        }
        if (!stateStack.empty()) {
            stateStack.top()->pause();
        }
        stateStack.push(std::move(newState));
        stateStack.top()->init();
        stateStack.top()->start();
        m_add = false;
    }

}
std::unique_ptr<Engine::State>& Engine::StateManager::getCurrentState() {
    return stateStack.top();
}