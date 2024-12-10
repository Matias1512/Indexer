#ifndef FSM_H
#define FSM_H

#include "State.h"

class Fsm {
public:
    explicit Fsm(State *initialState);
    ~Fsm();
    Fsm();
    void addState(State *state);
    void addFinalState(State *state);
    void setInitialState(State *state);
    void process();

private:
    State *currentState;
    QList<State*> states;
    QList<State*> finalStates;
};

#endif // FSM_H
