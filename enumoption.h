#ifndef ENUMOPTION_H
#define ENUMOPTION_H

#include <QObject>
#include <QStringList>

class EnumOption : public QObject
{
    Q_OBJECT

private:
    QStringList listOptions;

public:
    explicit EnumOption(QStringList& listOptions, QObject *parent = nullptr);

signals:
};

#endif // ENUMOPTION_H
