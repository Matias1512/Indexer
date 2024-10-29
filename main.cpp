#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug> // Pour utiliser qDebug()
#include "indexer.h"

void testIndex(){

    Indexer indexer;
    indexer.start();

    indexStatus status = indexer.getStatus();

    if(status == indexStatus::INDEXING){
        qDebug() << "Index start OK 1";
    }
    else{
        qDebug() << "Index start ECHEC 1";
    }


    if(status == indexStatus::STOPPED){
        qDebug() << "Index stop OK 2";
    }
    else{
        qDebug() << "Index stop ECHEC 2";
    }
}

int main(int argc, char *argv[])
{

    testIndex();


    /*
    // Test de commandAdd, exemple :  'Add WHITELIST "toto"'
    CommandOption whiteListOption("WHITELIST");

    CommandAdd commandAdd;
    commandAdd.setCommandOption(whiteListOption);
    commandAdd.setArgument("toto");
    QString SqlAdd = commandAdd.toSQL();

    if(SqlAdd == "INSERT INTO WHITELIST (arguments VALUES ('toto')"){
        qDebug() << "Commande OK";
    }
    else{
        qDebug() << "Commande ECHEC";
    }

    /*
    QCoreApplication a(argc, argv);

    // Vérifie si des arguments ont été passés
    if (argc < 2) {
        qDebug() << "Aucun argument fourni.";
        return 1; // Indique une erreur
    }

    // Imprime les arguments
    for (int i = 1; i < argc; ++i) {
        qDebug() << "Argument" << i << ":" << argv[i];
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "indexer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec();

*/
}
