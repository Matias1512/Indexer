#ifndef CREATED_H
#define CREATED_H

#include <QObject>
#include "option.h"

class Created : public Option
{
private:
    QString dateSpec;
    QString dateMax;
    QString dateMin;
    QString numberSinceLastDate;
    QString timeUnit;
    QString andOr;

    QString formatTimeUnit(const QString& timeUnit) const;
public:

    //CONSTRUCTEUR
    // Constructeur avec uniquement dateSpec
    Created(const QString& dateSpec)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), numberSinceLastDate(""), timeUnit("") {}

    // Constructeur avec dateSpec, dateMin et dateMax
    Created(const QString& dateSpec, const QString& dateMin, const QString& dateMax, const QString& And)
        : dateSpec(dateSpec), dateMax(dateMax), dateMin(dateMin), andOr(andOr), numberSinceLastDate(""), timeUnit("") {}

    // Constructeur avec dateSpec et numberSinceLastDate
    Created(const QString& dateSpec, const QString& numberSinceLastDate, const QString& timeUnit)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), numberSinceLastDate(numberSinceLastDate), timeUnit(timeUnit) {}

    // Méthodes pour récupérer les valeurs des paramètres
    QString getDateSpec() const { return dateSpec; }
    QString getDateMax() const { return dateMax; }
    QString getDateMin() const { return dateMin; }
    QString getNumberSinceLastDate() const { return numberSinceLastDate; }
    QString getTimeUnit() const { return timeUnit; }
    QString getAndOr() const { return andOr; }

    // Méthodes pour modifier les valeurs des paramètres
    void setDateSpec(const QString& value) { dateSpec = value; }
    void setDateMax(const QString& value) { dateMax = value; }
    void setDateMin(const QString& value) { dateMin = value; }
    void setNumberSinceLastDate(const QString& value) { numberSinceLastDate = value; }
    void setTimeUnit(const QString& value) { timeUnit = value; }
    void setAndOr(const QString& value) { andOr = value; }

    QString formatDate(const QString& inputDate) const;
    QString getSQL(bool isTheLastOption) const override;
};

#endif // CREATED_H
