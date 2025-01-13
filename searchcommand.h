#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H

#include "Command.h"
#include "option.h"

#include<QList>

class SearchCommand : public Command
{
public:
    SearchCommand(const QString& fileName, const QList<Option*> options):
        fileName(fileName), options(options){}

    QString getFileName() const {  return fileName;  }
    QList<Option*> getOptions() const { return options; }

    void setFileName(const QString &newFileName) { fileName = newFileName; }
    void addOptions(Option* option) { options.append(option); }

    virtual QString getSQL() override;

private:
    QString fileName;
    QList<Option*> options;

};

#endif // SEARCHCOMMAND_H
