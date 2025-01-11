#include "optionUtil.h"
#include <QDate>

// à mettre dans une autre fonction type datespec plus tard
QString OptionUtil::formatTimeUnit(const QString& timeUnit) {
    if (timeUnit.toUpper() == "DAYS") {
        return "DAY";
    } else if (timeUnit.toUpper() == "MINUTES") {
        return "MINUTE";
    } else if (timeUnit.toUpper() == "HOURS") {
        return "HOUR";
    } else if (timeUnit.toUpper() == "MONTHS") {
        return "MONTH";
    }
    return timeUnit; // Retourne la valeur d'origine si elle n'est pas dans la liste
}

QString OptionUtil::formatDate(const QString& inputDate) {
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

QString OptionUtil::convertSizeUnit(const int& number, const QString& unit) {
    QString convertSize;
    if(unit == "K") {
        convertSize = QString::number(number);
    } else if(unit == "M"){
        convertSize = QString::number(number*1000);
    } else if(unit == "G"){
        convertSize = QString::number(number*1000000);
    }
    return convertSize;
}

QList<QString> OptionUtil::splitSizeSpec(const QString& sizeSpec){
    // Récupère le dernier caractère
    QString unit = sizeSpec.right(1);

    // Récupère tout sauf le dernier caractère
    QString size = sizeSpec.left(sizeSpec.size() - 1);
    return {unit, size};
}
