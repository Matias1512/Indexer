#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QThread>
#include "tokenizer.h"
#include "token.h"
#include "Command.h"
#include "factory.h"
#include "State.h"
#include "Transition.h"
#include "Fsm.h"
#include "lastmodified.h"
#include "created.h"
#include "optionUtil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tokenizer token;
    QList<Token> listToken = token.tokenizerCommand("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days CREATED:21/12/2020 MAX_SIZE:10M MIN_SIZE:1M SIZE:BETWEEN 10M AND 20M EXT:txt,doc,xlsx TYPE:image OR text");
    SearchCommand* factoryTest = static_cast<SearchCommand*>(Factory::createCommand(listToken));
    qDebug() << factoryTest->getSQL();

    return a.exec();
}
