#include "factory.h"
#include "token.h"
#include "lastmodified.h"
#include <stdexcept>

Command* Factory::createCommand(const QList<Token>& tokenList) {
    // Logique pour créer une commande
    Command* cmd = nullptr;

    QList<QString> allOptions = {"LAST_MODIFIED", "CREATES", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};

    if(tokenList[0].getValue() == "SEARCH") {
        if(tokenList[1].getValue() == "string") {
            QString filename = tokenList[1].getKey();

            //creation de la liste des options
            QList<Option*> optionsList;
            for (int i = 2; i < tokenList.size(); ++i) {

                //LAST_MODIFIED
                if(tokenList[i].getValue() == "LAST_MODIFIED") {
                    QString firstArg = tokenList[i+1].getKey();
                    bool firstArgIsNumber;
                    firstArg.toInt(&firstArgIsNumber);
                    if(allOptions.count(tokenList[i+1].getValue()) >= 1) {
                        optionsList.append(new LastModified(firstArg));
                    } else if(tokenList[i+1].getValue() == "SINCE"){
                        //tokenList[i+2] c'est juste "LAST" et on s'en fout
                        if(tokenList[i+3].getValue() == "int" && tokenList[i+4].getValue() == "TypeTime") {//vérification des arguments
                            optionsList.append(new LastModified(firstArg, tokenList[i+3].getKey(), tokenList[i+4].getKey()));
                        } else {
                            throw std::runtime_error("Erreur avec les arguments du SINCE");
                        }
                    } else if(tokenList[i+1].getValue() == "BETWEEN"){
                        if(tokenList[i+2].getValue() == "Date" && tokenList[i+3].getValue() == "AND" && tokenList[i+4].getValue() == "Date") {//vérification des arguments
                            optionsList.append(new LastModified(firstArg, tokenList[i+2].getKey(), tokenList[i+3].getKey(), tokenList[i+4].getKey()));
                        }
                        throw std::runtime_error("Erreur avec les arguments du BETWEEN");
                    } else if(firstArgIsNumber && tokenList[i+2].getValue() == "TypeTime") {
                        optionsList.append(new LastModified(firstArg, tokenList[i+2].getKey()));
                    } else {
                        throw std::runtime_error("Erreur avec les arguments du LAST_MODIFIED");
                    }
                }
                //CREATED

            }

            return new SearchCommand(filename,optionsList);
        } else {
            throw std::runtime_error("Erreur pas de nom de fichier à chercher");
        }
    }

    return cmd;
}
