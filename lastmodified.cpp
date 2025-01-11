#include "lastmodified.h"
#include "optionUtil.h"
#include <QDate>

QString LastModified::getSQL(bool isTheLastOption) const {
    QString request = "";
    bool isNumber;
    this->dateSpec.toInt(&isNumber);
    request = "AND last_modified_date";

    //a un between
    if(this->dateSpec == "BETWEEN") {
        if(this->firstTimeUnit.isEmpty() && this->secondTimeUnit.isEmpty()){
            request.append(" BETWEEN " + OptionUtil::formatTimeUnit(this->dateMin) + " AND " + OptionUtil::formatTimeUnit(this->dateMax) + " ");
        } else {
            QString formattedTimeUnit1 = OptionUtil::formatTimeUnit(this->firstTimeUnit); // Utilise la version formatée
            QString formattedTimeUnit2 = OptionUtil::formatTimeUnit(this->secondTimeUnit); // Utilise la version formatée
            //BETWEEN DATE_SUB(CURDATE(), INTERVAL 3 DAY) AND DATE_SUB(CURDATE(), INTERVAL 2 DAY);
            request.append(QString(" BETWEEN DATE_SUB(CURDATE(), INTERVAL %1 %2) AND DATE_SUB(CURDATE(), INTERVAL %3 %4) ").arg(
                OptionUtil::formatTimeUnit(this->dateMin), formattedTimeUnit1, OptionUtil::formatTimeUnit(this->dateMax), formattedTimeUnit2 ));
        }

    }   //a un since last
    else if(this->dateSpec == "SINCE") {
        QString formattedTimeUnit = OptionUtil::formatTimeUnit(this->firstTimeUnit); // Utilise la version formatée
        request.append(" >= DATE_SUB(CURDATE(), INTERVAL " + this->numberSinceLastDate + " " + formattedTimeUnit + ") ");
    }
        //est un number
    else if(isNumber && !(this->firstTimeUnit.isEmpty())) {
        QString formattedTimeUnit = OptionUtil::formatTimeUnit(this->firstTimeUnit); // Utilise la version formatée
        request.append(QString(">= DATE_SUB(CURDATE(), INTERVAL %1 %2)").arg( this->numberSinceLastDate, formattedTimeUnit));
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
