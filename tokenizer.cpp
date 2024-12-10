
#include "tokenizer.h"
#include <QStringList>
#include <QRegularExpression>
#include <QMap>
#include <QDebug>
#include "token.h"

tokenizer::tokenizer(QObject *parent)
    : QObject{parent}
{}

QList<Token> tokenizer::tokenizerCommand(QString command){

    //Traiter le token (∩^o^)⊃━☆
    QStringList commandPartWithDoublePoint = command.split(QRegularExpression("\\s+(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)"), Qt::SkipEmptyParts);

    QRegularExpression regex(R"((?:"[^"]*"|[^"\s:]+))");
    QRegularExpressionMatchIterator it = regex.globalMatch(command);

    QStringList commandParts;
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        commandParts << match.captured(0);
    }


    QList<Token> tokenList;

    QList<QString> allCommandAccepted = { "SEARCH", "INDEXER", "GET", "ADD", "PUSH", "CLEAR" };
    QList<QString> allOptions = { "LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    QList<QString> allTimeType = { "MINUTES", "HOURS", "DAYS", "MONTHS", "YEAR"};
    QList<QString> allFileType = {"IMAGE","TEXT","EXE"};
    //type le premier parametre -> sa doit etre une commande
    if(allCommandAccepted.contains(commandParts[0].toUpper())){
        tokenList.append(Token(commandParts[0], "COMMANDE"));
    } else {
        tokenList.append(Token(commandParts[0], nullptr));
    }

    QRegularExpression regexSizeSpec("^[0-9].*[KMG]$");
    QRegularExpression regexDate("^(\\d{2}/\\d{2}/\\d{4}|\\d{2}/\\d{4}|\\d{4}|\\d{2})$");

    bool isInteger = false;

    if(commandParts.length() > 1){
        for (int i = 1; i < commandParts.length(); i++) {
            commandParts[i].toInt(&isInteger);
            if(commandParts[i].startsWith("\"") && commandParts[i].endsWith("\"")){
                tokenList.append( Token(commandParts[i], "string"));
            } else if (allOptions.contains(commandParts[i].toUpper())) {
                tokenList.append( Token(commandParts[i], "options"));
            } else if (commandParts[i].toUpper() == "BETWEEN") {
                tokenList.append( Token(commandParts[i], "BETWEEN"));
            } else if (commandParts[i].toUpper() == "AND") {
                tokenList.append( Token(commandParts[i], "AND"));
            } else if (commandParts[i].toUpper() == "OR") {
                tokenList.append( Token(commandParts[i], "OR"));
            } else if (commandParts[i].toUpper() == "SINCE") {
                tokenList.append( Token(commandParts[i], "SINCE"));
            } else if (commandParts[i].toUpper() == "LAST") {
                tokenList.append( Token(commandParts[i], "LAST"));
            } else if (commandParts[i].toUpper() == "AGO") {
                tokenList.append( Token(commandParts[i], "AGO"));
            } else if (regexSizeSpec.match(commandParts[i]).hasMatch()) {
                tokenList.append( Token(commandParts[i], "SizeSpec"));
            } else if (allTimeType.contains(commandParts[i].toUpper())) {
                tokenList.append( Token(commandParts[i], "TypeTime"));
            } else if (commandParts[i].contains(',')){
                tokenList.append( Token(commandParts[i], "ExtListSpec"));
            } else if (allFileType.contains(commandParts[i].toUpper())){
                tokenList.append( Token(commandParts[i], "FileType"));
            } else if (regexDate.match(commandParts[i]).hasMatch()) {
                tokenList.append( Token(commandParts[i], "Date"));
            } else if (isInteger){
                tokenList.append( Token(commandParts[i], "int"));
                isInteger = false;
            } else {
                tokenList.append( Token(commandParts[i], nullptr));
            }
        }
    }

    for (const Token &token : tokenList) {
        qDebug() << "Key:" << token.getKey() << ", Value:" << token.getValue();
    }

    return tokenList;
}
