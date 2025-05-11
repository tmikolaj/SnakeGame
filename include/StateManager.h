#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>
#include <memory>
#include "State.hpp"

namespace Engine {

    class StateManager {
    private:
        std::stack<std::unique_ptr<State>> stateStack;
        std::unique_ptr<State> newState;

        // m = manager
        bool m_add;
        bool m_replace;
        bool m_remove;
    public:
        StateManager();
        ~StateManager() = default;

        void add(std::unique_ptr<State> toAdd, bool replace = false);
        void popCurrent();
        void processState();
        std::unique_ptr<State>& getCurrentState();
    };
}


#endif //STATEMANAGER_H
