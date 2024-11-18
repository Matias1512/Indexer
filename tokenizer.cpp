#include "tokenizer.h"
#include <QStringList>
#include <QRegularExpression>
#include <QMap>
#include <QDebug>

tokenizer::tokenizer(QObject *parent)
    : QObject{parent}
{}

QMap<QString, QString> tokenizer::tokenizerCommand(QString command){
    QMap<QString, QString> token;

    //Traiter le token (∩^o^)⊃━☆
    QStringList commandPart = command.split(QRegularExpression("\\s+(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)"), Qt::SkipEmptyParts);

    QRegularExpression regex(R"((?:"[^"]*"|[^"\s:]+))");
    QRegularExpressionMatchIterator it = regex.globalMatch(command);

    QStringList commandParts;
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        commandParts << match.captured(0);
    }

    QList<QString> allCommandAccepted = { "SEARCH", "INDEXER", "GET", "ADD", "PUSH", "CLEAR" };
    QList<QString> allOptions = { "LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    QList<QString> allSpecifitions = { "BETWEEN", "AND", "OR", "SINCE LAST"};
    QList<QString> allTimeType = { "MINUTES", "HOURS", "DAYS", "MONTHS", "YEAR"};
    QList<QString> allFileType = {"IMAGE","TEXT","EXE"};
    //type le premier parametre -> sa doit etre une commande
    if(allCommandAccepted.contains(commandParts[0].toUpper())){
        token[commandParts[0]] = "COMMANDE";
    } else {
        token[commandParts[0]] = nullptr;
    }

    QRegularExpression regexSizeSpec("^[0-9].*[KMG]$");
    QRegularExpression regexDate("^(\\d{2}/\\d{2}/\\d{4}|\\d{2}/\\d{4}|\\d{4}|\\d{2})$");

    bool isInteger = false;

    if(commandParts.length() > 1){
        for (int i = 1; i < commandParts.length(); i++) {
            commandParts[i].toInt(&isInteger);
            if(commandParts[i].startsWith("\"") && commandParts[i].endsWith("\"")){
                token[commandParts[i]] = "string";
            } else if (allOptions.contains(commandParts[i].toUpper())) {
                token[commandParts[i]] = "options";
            } else if (allSpecifitions.contains(commandParts[i].toUpper())) {
                token[commandParts[i]] = "specification";
            } else if (regexSizeSpec.match(commandParts[i]).hasMatch()) {
                token[commandParts[i]] = "SizeSpec";
            } else if (allTimeType.contains(commandParts[i].toUpper())) {
                token[commandParts[i]] = "TypeTime";
            } else if (commandParts[i].contains(',')){
                token[commandParts[i]] = "ExtListSpec";
            } else if (allFileType.contains(commandParts[i].toUpper())){
                token[commandParts[i]] = "FileType";
            } else if (regexDate.match(commandParts[i]).hasMatch()) {
                token[commandParts[i]] = "Date";
            } else if (isInteger){
                token[commandParts[i]] = "int";
                isInteger = false;
            } else {
                token[commandParts[i]] = nullptr;
            }
        }
    }

    qDebug() << token;
    return token;
}
