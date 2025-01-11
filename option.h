#ifndef OPTION_H
#define OPTION_H

#include <QObject>

class Option : public QObject
{
public:
    virtual ~Option() {}
    //virtual void execute() const = 0; // Méthode virtuelle pure
    virtual QString getSQL(bool isLast) const = 0;
};

#endif // OPTION_H
