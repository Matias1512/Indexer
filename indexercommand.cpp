#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDirIterator>

#include "indexercommand.h"

void IndexerCommand::createDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("file_indexer.db");

    if (!db.open()) {
        qCritical() << "Error: unable to open database";
        return;
    }

    QSqlQuery query;

    // Création de la table des fichiers si elle n'existe pas
    query.exec("CREATE TABLE IF NOT EXISTS files ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "fileName TEXT, "
               "filePath TEXT, "
               "fileSize INTEGER, "
               "lastModified TEXT)");
}

void IndexerCommand::indexDirectory(const QString &path) {
    QDirIterator it(path, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString filePath = it.next();
        QFileInfo fileInfo(filePath);

        // Vérifier si le fichier existe déjà dans la base
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM files WHERE filePath = :filePath");
        checkQuery.bindValue(":filePath", fileInfo.absoluteFilePath());

        if (!checkQuery.exec()) {
            qWarning() << "Failed to check existence of file:";
            continue;
        }

        checkQuery.next(); // Avance le curseur pour obtenir le résultat
        int count = checkQuery.value(0).toInt();

        if (count > 0) {
            // Le fichier existe déjà
            qDebug() << "File already exists in the database:" << fileInfo.absoluteFilePath();
            continue;
        }

        // Insérer le fichier s'il n'existe pas
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO files (fileName, filePath, fileSize, lastModified) "
                            "VALUES (:fileName, :filePath, :fileSize, :lastModified)");
        insertQuery.bindValue(":fileName", fileInfo.fileName());
        insertQuery.bindValue(":filePath", fileInfo.absoluteFilePath());
        insertQuery.bindValue(":fileSize", fileInfo.size());
        insertQuery.bindValue(":lastModified", fileInfo.lastModified().toString(Qt::ISODate));

        if (!insertQuery.exec()) {
            qWarning() << "Failed to insert file:" << fileInfo.absoluteFilePath();
        } else {
            qDebug() << "File inserted into database:" << fileInfo.absoluteFilePath();
        }
    }
}


void IndexerCommand::printDatabaseContents() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qWarning() << "La base de données n'est pas ouverte !";
        return;
    }

    QSqlQuery query;
    QString countQuery = "SELECT COUNT() FROM files";
    if (!query.exec(countQuery)) {
        qWarning() << "Erreur lors du comptage des fichiers dans la base de données :";
        return;
    }

    int totalFiles = 0;
    if (query.next()) {
        totalFiles = query.value(0).toInt();
    }

    qDebug() << "Nombre total de fichiers dans la base de données :" << totalFiles;
}
