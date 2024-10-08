#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug> // Pour utiliser qDebug()

int main(int argc, char *argv[])
{
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
}
