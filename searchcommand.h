#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H

#include "command.h"
#include "option.h"
#include "fsm.h"

#include<QList>

class SearchCommand : public Command
{
public:
    void execute() const override
    {
        qDebug() << "Executing Search Command";
    }

    QString getFileName() const {  return fileName;  }

    void setFileName(const QString &newFileName) { fileName = newFileName; }
    //void addOption(const Option &option) { options.append(option); }

private:
    QString fileName;
    //QList<Option> options;
    Fsm fsm;

};

#endif // SEARCHCOMMAND_H
