#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include "tokenizer.h"
#include "token.h"
#include "Command.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tokenizer token;
    QList<Token> listToken = token.tokenizerCommand("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:31/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx TYPE:image OR text");

    Command* command = Factory::createCommand(listToken[0].getKey());
    if (command) {
        command->execute();
        delete command; // Libérer la mémoire
    } else {
        qDebug() << "Commande inconnue : " << listToken[0].getKey();
    }

    return a.exec();
}
