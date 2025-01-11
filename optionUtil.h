#ifndef OPTIONUTIL_H
#define OPTIONUTIL_H

#include <QObject>

class OptionUtil : public QObject
{
    Q_OBJECT
public:
    static QString formatTimeUnit(const QString& timeUnit);
    static QString formatDate(const QString& inputDate);
signals:
};

#endif // OPTIONUTIL_H
