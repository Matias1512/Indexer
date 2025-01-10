#include "lastmodified.h"
#include <QDate>

//LastModified::LastModified() {}
QString LastModified::formatDate(const QString& inputDate) const {
    QStringList parts = inputDate.split('/'); // Divise la chaîne en segments
    int day = 1, month = 1, year = 0;         // Valeurs par défaut

    if (parts.size() == 3) {
        // Format "dd/mm/yyyy"
        day = parts[0].toInt();
        month = parts[1].toInt();
        year = parts[2].toInt();
    } else if (parts.size() == 2) {
        // Format "mm/yyyy"
        month = parts[0].toInt();
        year = parts[1].toInt();
    } else if (parts.size() == 1) {
        QString part = parts[0];
        if (part.length() == 4) {
            // Format "yyyy"
            year = part.toInt();
        } else if (part.length() == 2) {
            // Format "yy"
            year = part.toInt();
            year += (year < 50) ? 2000 : 1900; // Conversion yy -> yyyy (arbitraire : avant 50 => 2000+)
        }
    } else {
        return "Invalid date format"; // Format non pris en charge
    }

    // Crée une date valide avec QDate
    QDate date(year, month, day);
    if (!date.isValid()) {
        return "Invalid date"; // Si la date n'est pas valide, retour d'une erreur
    }

    return date.toString("dd/MM/yyyy"); // Retourne la date formatée
}

QString LastModified::getSQL(bool isTheFirstOption, bool isTheLastOption) const {
    QString request = "";
    bool isNumber;
    this->dateSpec.toInt(&isNumber);
    //est la premier option
    if(isTheFirstOption) {
        request = "WHERE date_column";
    } else {
        request = "AND ";
    }
        //a un between
    if(this->dateSpec == "BETWEEN") {
        request.append(" BETWEEN " + this->formatDate(this->dateMin) + " AND " + this->formatDate(this->dateMax));
    }   //a un since last
    else if(this->dateSpec == "SINCE") {
        QString formattedTimeUnit = this->formatTimeUnit(this->timeUnit); // Utilise la version formatée
        request.append(" >= DATE_SUB(CURDATE(), INTERVAL " + this->numberSinceLastDate + " " + formattedTimeUnit + ")");
    }
        //est un number
    else if(isNumber && !this->timeUnit.isEmpty()) {
        QString formattedTimeUnit = this->formatTimeUnit(this->timeUnit); // Utilise la version formatée
        request.append(" <= " + this->numberSinceLastDate + formattedTimeUnit);
    }
        //est une date
    else {
        request.append(" = " + formatDate(this->dateSpec));
    }

    //est la dernière option
    if(isTheLastOption){
        request.append(";");
    }
    return request;
}


// à mettre dans une autre fonction type datespec plus tard
QString LastModified::formatTimeUnit(const QString& timeUnit) const {
    if (timeUnit == "DAYS") {
        return "DAY";
    } else if (timeUnit == "MINUTES") {
        return "MINUTE";
    } else if (timeUnit == "HOURS") {
        return "HOUR";
    } else if (timeUnit == "MONTHS") {
        return "MONTH";
    }
    return timeUnit; // Retourne la valeur d'origine si elle n'est pas dans la liste
}
