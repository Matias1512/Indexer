#include "State.h"
#include "Transition.h"
#include <QDebug>

State::State(const QString &id) : id(id) {}

State::~State() {}

QString State::getId() const {
    return id;
}

void State::addTransition(Transition *transition) {
    transitions.append(transition);
}

QList<Transition*> State::getTransitions() const {
    return transitions;
}

void State::onEnter() {
    qDebug() << "Entering state:" << id;
}

void State::onExit() {
    qDebug() << "Exiting state:" << id;
}
