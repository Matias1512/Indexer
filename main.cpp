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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
    Command* command = Factory::createCommand(listToken[0].getKey());
    if (command) {
        command->execute();
        delete command; // Libérer la mémoire
    } else {
        qDebug() << "Commande inconnue : " << listToken[0].getKey();
    }

    // Créer les états
    State *initialState = new State("CommandWithoutOption");
    State *commandWithoutOption = new State("CommandWithoutOption");
    State *addingOption  = new State("AddingOption");
    State *validatingOption  = new State("ValidatingOption ");
    State *completeCommand   = new State("ValidatingOption ");
    State *errorState   = new State("ValidatingOption ");

    // Créer des transitions
    Transition *CommandCreate = new Transition(initialState, commandWithoutOption, []() { return true; }); // Condition toujours vraie
    Transition *AddOption = new Transition(commandWithoutOption, addingOption, []() { return true; });
    Transition *SpecificationCheck = new Transition(ValidatingOption, AddingOption, []() { return true; });
    Transition *AddAnotherOption = new Transition(ValidatingOption, CompleteCommand, []() { return true; });
    Transition *LastOption = new Transition(ValidatingOption, ErrorState, []() { return true; });
    Transition *LastOption = new Transition(ValidatingOption, ErrorState, []() { return true; });

    // Ajouter les transitions aux états
    stateA->addTransition(t1);
    stateB->addTransition(t2);
    stateC->addTransition(t3);

    // Créer et initialiser la FSM
    Fsm fsm(CommandWithoutOption);
    fsm.addState(CommandWithoutOption);
    fsm.addState(AddingOption);
    fsm.addState(ValidatingOption);
    fsm.addState(CompleteCommand);
    fsm.addState(ErrorState);
    fsm.addFinalState(CompleteCommand, ErrorState);

    // Simuler des transitions
    while(true){
        fsm.process();
        QThread::msleep(500);
    }
    //fsm.process(); // Devrait aller de A à B
    //fsm.process(); // Devrait aller de B à C

    // Nettoyage
    delete CommandWithoutOption;
    delete AddingOption;
    delete ValidatingOption;
    delete CompleteCommand;
    delete ErrorState;
    delete t1;
    delete t2;



    // Créer la base de données SQLite
    IndexerCommand* indexer = new IndexerCommand();
    indexer->createDatabase();

    // Indexer les fichiers dans le répertoire spécifié (ex: "C:\Users\matia\Documents")
    indexer->indexDirectory("C:/Users/matia/Documents/Scripting");

    indexer->printDatabaseContents();

    qDebug() << "File indexing complete.";
    **/


    //{"SEARCH", "testme please", "LAST_MODIFIED", "BETWEEN", "2", "days", "and", "3", "days", "CREATED", "31/12/2020", "MAX_SIZE", "10M", "MIN_SIZE", "1M", "SIZE", "BETWEEN", "10M", "AND", "20M", "EXT", "txt,doc,xlsx", "TYPE", "image", "OR", "text"}


    GetCommand testGet("WHITELIST");
    qDebug() << testGet.getSQL();

    AddCommand addTest1("WHITELIST", "blablabla/tamere.exe");
    qDebug() << addTest1.getSQL();
    QList<QString> listExt = { "exe", "jpg", "txt"};
    AddCommand addTest2("WHITELIST", listExt);
    qDebug() << addTest2.getSQL();

    LastModified testlast("SINCE", "3", "DAYS");
    qDebug() << testlast.getSQL(true, true);

    // Création de la liste avec des pointeurs
    QList<Option*> listOption = { &testlast }; // Utilisation de &testlast pour obtenir un pointeur

    SearchCommand testSearchCommand("bonjour", listOption);
    qDebug() << testSearchCommand.getSQL();

    tokenizer token;
    QList<Token> listToken = token.tokenizerCommand("SEARCH \"testme please\" LAST_MODIFIED:BETWEEN 2 days and 3 days");
    SearchCommand* factoryTest = static_cast<SearchCommand*>(Factory::createCommand(listToken));
    qDebug() << factoryTest->getSQL();

    return a.exec();
}
