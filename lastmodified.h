#ifndef LASTMODIFIED_H
#define LASTMODIFIED_H

#include <QObject>
#include "option.h"

class LastModified : public Option
{
private:
    QString dateSpec;
    QString dateMax;
    QString dateMin;
    QString sinceLastDate;
    QString andOr;

public:
    // Constructeur avec uniquement dateSpec
    explicit LastModified(const QString& dateSpec)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), sinceLastDate("") {}

    // Constructeur avec dateSpec, dateMin et dateMax
    LastModified(const QString& dateSpec, const QString& dateMin, const QString& dateMax, const QString& andOr)
        : dateSpec(dateSpec), dateMax(dateMax), dateMin(dateMin), andOr(andOr), sinceLastDate("") {}

    // Constructeur avec dateSpec et sinceLastDate
    LastModified(const QString& dateSpec, const QString& sinceLastDate)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), sinceLastDate(sinceLastDate) {}

    // Méthodes pour récupérer les valeurs des paramètres
    QString getDateSpec() const { return dateSpec; }
    QString getDateMax() const { return dateMax; }
    QString getDateMin() const { return dateMin; }
    QString getSinceLastDate() const { return sinceLastDate; }
    QString getAndOr() const { return andOr; }

    // Méthodes pour modifier les valeurs des paramètres
    void setDateSpec(const QString& value) { dateSpec = value; }
    void setDateMax(const QString& value) { dateMax = value; }
    void setDateMin(const QString& value) { dateMin = value; }
    void setSinceLastDate(const QString& value) { sinceLastDate = value; }
    void setAndOr(const QString& value) { andOr = value; }

    QString formatDate(const QString& inputDate);
    QString getSQL(const bool isTheFirstOption, const bool isTheLastOption);
};

#endif // LASTMODIFIED_H
