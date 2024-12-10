#include "Fsm.h"
#include "Transition.h"
#include <QDebug>

Fsm::Fsm(State *initialState) : currentState(initialState) {
    if (initialState) {
        initialState->onEnter();
    }
}

Fsm::~Fsm() {}

void Fsm::addState(State *state) {
    states.append(state);
}

void Fsm::addFinalState(State *state) {
    finalStates.append(state);
}

void Fsm::setInitialState(State *state) {
    currentState = state;
    if (state) {
        state->onEnter();
    }
}

void Fsm::process() {
    if (!currentState) return;
    while(!finalStates.contains(currentState)) {
        for (Transition *transition : currentState->getTransitions()) {
            if (transition->evaluateCondition()) {
                currentState->onExit();
                currentState = transition->getTarget();
                currentState->onEnter();
                return;
            }
        }
    }
}
