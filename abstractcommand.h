#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QObject>
#include <QDebug>

class AbstractCommand : public QObject
{
    Q_OBJECT

public:
    explicit AbstractCommand(QString name, QObject *parent = nullptr);

    void setName(const QString &name);

private:
    QString name_;

signals:
};

#endif // ABSTRACTCOMMAND_H
