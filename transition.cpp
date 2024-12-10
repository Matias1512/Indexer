#include "Transition.h"

Transition::Transition(State *source, State *target, const std::function<bool()> &condition)
    : source(source), target(target), condition(condition) {}

Transition::~Transition() {}

State* Transition::getSource() const {
    return source;
}

State* Transition::getTarget() const {
    return target;
}

bool Transition::evaluateCondition() const {
    return condition();
}
