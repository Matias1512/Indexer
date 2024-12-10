#ifndef STATE_H
#define STATE_H

#include <QString>
#include <QList>

class Transition; // Déclaration avant usage

class State {
public:
    explicit State(const QString &id);
    ~State();

    QString getId() const;
    void addTransition(Transition *transition);
    QList<Transition*> getTransitions() const;

    void onEnter();
    void onExit();

private:
    QString id;
    QList<Transition*> transitions;
};

#endif // STATE_H
