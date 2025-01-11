#include "created.h"
#include "optionUtil.h"
#include <QDate>

QString Created::getSQL(bool isTheLastOption) const {
    QString request = "";
    bool isNumber;
    this->dateSpec.toInt(&isNumber);
    request = "AND created_date";

    //a un between
    if(this->dateSpec == "BETWEEN") {
        request.append(" BETWEEN " + OptionUtil::formatDate(this->dateMin) + " AND " + OptionUtil::formatDate(this->dateMax));
    }   //a un since last
    else if(this->dateSpec == "SINCE") {
        QString formattedTimeUnit = OptionUtil::formatTimeUnit(this->timeUnit); // Utilise la version formatée
        request.append(" >= DATE_SUB(CURDATE(), INTERVAL " + this->numberSinceLastDate + " " + formattedTimeUnit + ")");
    }
    //est un number
    else if(isNumber && !this->timeUnit.isEmpty()) {
        QString formattedTimeUnit = OptionUtil::formatTimeUnit(this->timeUnit); // Utilise la version formatée
        request.append(" <= " + this->numberSinceLastDate + formattedTimeUnit);
    }
    //est une date
    else {
        request.append(" = " + OptionUtil::formatDate(this->dateSpec));
    }

    //est la dernière option
    if(isTheLastOption){
        request.append(";");
    }
    return request;
}

