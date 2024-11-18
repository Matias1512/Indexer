#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include "tokenizer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tokenizer token;
    token.tokenizerCommand("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:31/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx TYPE:image OR text");

    return a.exec();
}
