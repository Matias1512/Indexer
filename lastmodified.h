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
    QString numberSinceLastDate;
    QString firstTimeUnit;
    QString secondTimeUnit;
    QString andOr;
public:

    //CONSTRUCTEUR
    // Constructeur avec uniquement dateSpec ----- 1 arguments
    LastModified(const QString& dateSpec)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), numberSinceLastDate(""), firstTimeUnit(""), secondTimeUnit("") {}

    // Constructeur avec dateSpec et firstTimeUnit ----- 2 arguments
    LastModified(const QString& dateSpec, const QString& firstTimeUnit)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), numberSinceLastDate(""), firstTimeUnit(firstTimeUnit), secondTimeUnit("") {}

    // Constructeur avec dateSpec, numberSinceLastDate et firstTimeUnit ----- 3 arguments
    LastModified(const QString& dateSpec, const QString& numberSinceLastDate, const QString& firstTimeUnit)
        : dateSpec(dateSpec), dateMax(""), dateMin(""), numberSinceLastDate(numberSinceLastDate), firstTimeUnit(firstTimeUnit), secondTimeUnit("") {}

    // Constructeur avec dateSpec, dateMin, dateMax et andOr ----- 4 arguments
    LastModified(const QString& dateSpec, const QString& dateMin, const QString& andOr, const QString& dateMax)
        : dateSpec(dateSpec), dateMax(dateMax), dateMin(dateMin), andOr(andOr), numberSinceLastDate(""), firstTimeUnit(""), secondTimeUnit("") {}

    // Constructeur avec dateSpec, dateMin, dateMax, And, firstTimeUnit et secondTimeUnit ----- 6 arguments
    LastModified(const QString& dateSpec, const QString& dateMin, const QString& andOr, const QString& dateMax, const QString& firstTimeUnit, const QString& secondTimeUnit)
        : dateSpec(dateSpec), dateMax(dateMax), dateMin(dateMin), andOr(andOr), numberSinceLastDate(""), firstTimeUnit(firstTimeUnit), secondTimeUnit(secondTimeUnit) {}

    // Méthodes pour récupérer les valeurs des paramètres
    QString getDateSpec() const { return dateSpec; }
    QString getDateMax() const { return dateMax; }
    QString getDateMin() const { return dateMin; }
    QString getNumberSinceLastDate() const { return numberSinceLastDate; }
    QString getfirstTimeUnit() const { return firstTimeUnit; }
    QString getsecondTimeUnit() const { return secondTimeUnit; }
    QString getAndOr() const { return andOr; }

    // Méthodes pour modifier les valeurs des paramètres
    void setDateSpec(const QString& value) { dateSpec = value; }
    void setDateMax(const QString& value) { dateMax = value; }
    void setDateMin(const QString& value) { dateMin = value; }
    void setNumberSinceLastDate(const QString& value) { numberSinceLastDate = value; }
    void setfirstTimeUnit(const QString& value) { firstTimeUnit = value; }
    void setSecondTimeUnit(const QString& value) { secondTimeUnit = value; }
    void setAndOr(const QString& value) { andOr = value; }

    QString getSQL(bool isTheLastOption) const override;
};

#endif // LASTMODIFIED_H
