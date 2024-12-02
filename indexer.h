#ifndef INDEXER_H
#define INDEXER_H

#include <QObject>
#include <QList>
#include "indexstatus.h"
#include <QDebug>

class Indexer
{
private:
    indexStatus status;
    QList<QString> indexedFiles;

public:
    Indexer();

    indexStatus getStatus() const;

    void start();
    void stop();
    void pause();
    void resume();

    void addIndexedFile(const QString& file);
    void displayIndexedFiles() const;

};

#endif // INDEXER_H
