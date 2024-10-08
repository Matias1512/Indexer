#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QObject>

class AbstractCommand : public QObject
{
    Q_OBJECT

private:
    std::string name;

public:
    AbstractCommand(const std::string& name);

signals:
};

#endif // ABSTRACTCOMMAND_H
