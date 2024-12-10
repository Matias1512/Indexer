#include "lastmodified.h"
#include <QDate>

//LastModified::LastModified() {}
QString LastModified::formatDate(const QString& inputDate) {
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

QString LastModified::getSQL(const bool isTheFirstOption, const bool isTheLastOption) {
    QString request = "";
    //est la premier option
    if(isTheFirstOption) {
        request = "WHERE lastModified ";
    }
        //a un between
    if(this->dateSpec == "BETWEEN") {
        request += " BETWEEN " << this->dateMax << this->andOr << this->dateMin;
    }

        //a un since last

        //est un number

        //est une date

//WHERE date_column BETWEEN '2023-01-01' AND '2023-12-31'
    return request;
}
