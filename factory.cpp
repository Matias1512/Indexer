#include "factory.h"
#include "token.h"
#include "lastmodified.h"
#include "created.h"
#include "optionUtil.h"
#include "maxsize.h"
#include "minsize.h"
#include "size.h"
#include "ext.h"
#include "type.h"
#include <stdexcept>

Command* Factory::createCommand(const QList<Token>& tokenList) {
    // Logique pour créer une commande
    Command* cmd = nullptr;

    //QList<QString> allOptions = {"LAST_MODIFIED", "CREATES", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    if(tokenList[0].getKey() == "SEARCH") {
        if(tokenList[1].getValue() == "string") {
            QString filename = tokenList[1].getKey();

            //creation de la liste des options
            QList<Option*> optionsList;
            for (int i = 2; i < tokenList.size(); ++i) {

                //LAST_MODIFIED
                if(tokenList[i].getKey() == "LAST_MODIFIED") { //note pour plus tard : mettre se grand if dans une fonction car ce repete pour created
                    QString firstArg = tokenList[i+1].getKey();
                    bool firstArgIsNumber;
                    firstArg.toInt(&firstArgIsNumber);
                    if(tokenList[i+2].getValue() == "option") {
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
                        } else if(tokenList[i+2].getValue() == "int" && tokenList[i+3].getValue() == "TypeTime" && tokenList[i+4].getValue() == "AND"
                                   && tokenList[i+5].getValue() == "int" && tokenList[i+6].getValue() == "TypeTime"){
                            //dateSpec, dateMin, andOr, dateMax, firstTimeUnit, secondTimeUnit
                            optionsList.append(new LastModified(firstArg, tokenList[i+2].getKey(), tokenList[i+4].getKey(), tokenList[i+5].getKey(), tokenList[i+3].getKey(), tokenList[i+6].getKey()));
                        } else {
                            throw std::runtime_error("Erreur avec les arguments du BETWEEN");
                        }
                    } else if(firstArgIsNumber && tokenList[i+2].getValue() == "TypeTime") {
                        optionsList.append(new LastModified(firstArg, tokenList[i+2].getKey()));
                    } else {
                        throw std::runtime_error("Erreur avec les arguments du LAST_MODIFIED");
                    }
                }
                //CREATED
                else if(tokenList[i].getKey() == "CREATED") {
                    QString firstArg = tokenList[i+1].getKey();
                    bool firstArgIsNumber;
                    firstArg.toInt(&firstArgIsNumber);
                    if(tokenList[i+2].getValue() == "option" || tokenList.size()-1 == i+1) {
                        optionsList.append(new Created(firstArg));
                    } else if(tokenList[i+1].getValue() == "SINCE"){
                        //tokenList[i+2] c'est juste "LAST" et on s'en fout
                        if(tokenList[i+3].getValue() == "int" && tokenList[i+4].getValue() == "TypeTime") {//vérification des arguments
                            optionsList.append(new Created(firstArg, tokenList[i+3].getKey(), tokenList[i+4].getKey()));
                        } else {
                            throw std::runtime_error("Erreur avec les arguments du SINCE");
                        }
                    } else if(tokenList[i+1].getValue() == "BETWEEN"){
                        if(tokenList[i+2].getValue() == "Date" && tokenList[i+3].getValue() == "AND" && tokenList[i+4].getValue() == "Date") {//vérification des arguments
                            optionsList.append(new Created(firstArg, tokenList[i+2].getKey(), tokenList[i+3].getKey(), tokenList[i+4].getKey()));
                        } else if(tokenList[i+2].getValue() == "int" && tokenList[i+3].getValue() == "TypeTime" && tokenList[i+4].getValue() == "AND"
                                   && tokenList[i+5].getValue() == "int" && tokenList[i+6].getValue() == "TypeTime"){
                            //dateSpec, dateMin, andOr, dateMax, firstTimeUnit, secondTimeUnit
                            optionsList.append(new Created(firstArg, tokenList[i+2].getKey(), tokenList[i+4].getKey(), tokenList[i+5].getKey(), tokenList[i+3].getKey(), tokenList[i+6].getKey()));
                        } else {
                            throw std::runtime_error("Erreur avec les arguments du BETWEEN");
                        }
                    } else if(firstArgIsNumber && tokenList[i+2].getValue() == "TypeTime") {
                        optionsList.append(new Created(firstArg, tokenList[i+2].getKey()));
                    } else {
                        throw std::runtime_error("Erreur avec les arguments du CREATED");
                    }
                }

                //MAX_SIZE
                else if(tokenList[i].getKey() == "MAX_SIZE") {
                    if(tokenList[i+1].getValue() == "SizeSpec") {
                        QList<QString> sizeSpecSplit = OptionUtil::splitSizeSpec(tokenList[i+1].getKey());
                        QString convertSize = OptionUtil::convertSizeUnit(sizeSpecSplit[0].toInt(), sizeSpecSplit[1]);
                        optionsList.append(new MaxSize(convertSize.toInt(),sizeSpecSplit[1]));
                    } else {
                        throw std::runtime_error("Erreur avec l'argument du MAX_SIZE");
                    }
                }

                //MIN_SIZE
                else if(tokenList[i].getKey() == "MIN_SIZE") {
                    if(tokenList[i+1].getValue() == "SizeSpec") {
                        QList<QString> sizeSpecSplit = OptionUtil::splitSizeSpec(tokenList[i+1].getKey());
                        QString convertSize = OptionUtil::convertSizeUnit(sizeSpecSplit[0].toInt(), sizeSpecSplit[1]);
                        optionsList.append(new MinSize(convertSize.toInt(),sizeSpecSplit[1]));
                    } else {
                        throw std::runtime_error("Erreur avec l'argument du MIN_SIZE");
                    }
                }

                //SIZE
                else if(tokenList[i].getKey() == "SIZE"){
                    if(tokenList[i+1].getValue() == "SizeSpec") {
                        QList<QString> sizeSpecSplit = OptionUtil::splitSizeSpec(tokenList[i+1].getKey());
                        QString convertSize = OptionUtil::convertSizeUnit(sizeSpecSplit[0].toInt(), sizeSpecSplit[1]);
                        optionsList.append(new Size(convertSize.toInt()));
                    } else if (tokenList[i+1].getValue() == "BETWEEN" && tokenList[i+2].getValue() == "SizeSpec"){
                        QList<QString> sizeSpecSplit = OptionUtil::splitSizeSpec(tokenList[i+2].getKey());
                        QString convertSize1 = OptionUtil::convertSizeUnit(sizeSpecSplit[0].toInt(), sizeSpecSplit[1]);
                        QList<QString> sizeSpecSplit2 = OptionUtil::splitSizeSpec(tokenList[i+4].getKey());
                        QString convertSize2 = OptionUtil::convertSizeUnit(sizeSpecSplit2[0].toInt(), sizeSpecSplit2[1]);
                        optionsList.append(new Size(convertSize1.toInt(), convertSize2.toInt()));
                    } else {
                    throw std::runtime_error("Erreur avec l'argument du SIZE");
                    }
                }

                //EXT
                else if(tokenList[i].getKey() == "EXT"){
                    QList<QString> listExtension;
                    if(tokenList[i+1].getKey().contains(",")) {
                        listExtension = tokenList[i+1].getKey().split(",");
                    } else {
                        listExtension = { tokenList[i+1].getKey() };
                    }
                    optionsList.append(new Ext(listExtension));
                }

                //TYPE
                else if(tokenList[i].getKey() == "TYPE"){
                    QList<QString> listType;
                    for (int y = i+1; y < tokenList.size(); ++y) {
                        if(tokenList[y].getValue() == "option") {
                            break;
                        } else if(tokenList[y].getValue() == "FileType"){
                            listType.append(tokenList[y].getKey());
                        }
                    }
                    optionsList.append(new Type(listType));
                }
            }

            return new SearchCommand(filename,optionsList);
        } else {
            throw std::runtime_error("Erreur pas de nom de fichier à chercher");
        }
    }

    return cmd;
}
