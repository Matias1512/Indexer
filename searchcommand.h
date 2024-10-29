#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H

#include <QObject>
#include "abstractcommand.h"

class SearchCommand : public AbstractCommand
{
    Q_OBJECT
public:
    explicit SearchCommand(QString name, QObject *parent = nullptr);

public slots:
    void optionChoisie();
};

#endif // SEARCHCOMMAND_H
