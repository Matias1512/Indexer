#ifndef TRANSITION_H
#define TRANSITION_H

#include <QString>
#include <functional>

class State;

class Transition {
public:
    Transition(State *source, State *target, const std::function<bool()> &condition);
    ~Transition();

    State* getSource() const;
    State* getTarget() const;
    bool evaluateCondition() const;

private:
    State *source;
    State *target;
    std::function<bool()> condition;
};

#endif // TRANSITION_H
