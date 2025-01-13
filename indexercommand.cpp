#include "indexerCommand.h"
#include <QDir>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileInfo>
#include <QDirIterator>

IndexerCommand::IndexerCommand() : status(indexStatus::STOPPED) {}

// Récupérer le statut actuel
IndexerCommand::indexStatus IndexerCommand::getStatus() const {
    return status;
}

// Créer la base de données pour l'indexation
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

// Démarre l'indexation
void IndexerCommand::start() {
    if (status == indexStatus::STOPPED || status == indexStatus::PAUSED) {
        status = indexStatus::INDEXING;
        qDebug() << "Indexation en cours...";

        // Récupère tous les fichiers de l'ordinateur
        QString startFolder = QDir::rootPath(); // Racine de l'ordinateur
        QDirIterator it(startFolder, QDir::Files, QDirIterator::Subdirectories);

        createDatabase(); // Créer ou ouvrir la base de données

        while (it.hasNext()) {
            QString filePath = it.next();
            QFileInfo fileInfo(filePath);

            // Vérifie si le fichier existe déjà dans la base
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

            // Insère le fichier s'il n'existe pas
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

        status = indexStatus::READY;
        qDebug() << "Indexation terminée.";
    }
}

// Arrête l'indexation
void IndexerCommand::stop() {
    if (status == indexStatus::INDEXING || status == indexStatus::PAUSED) {
        status = indexStatus::STOPPED;
        qDebug() << "Indexation arrêtée.";
        indexedFiles.clear();
    }
}

// Met en pause l'indexation
void IndexerCommand::pause() {
    if (status == indexStatus::INDEXING) {
        status = indexStatus::PAUSED;
        qDebug() << "Indexation en pause.";
    }
}

// Reprend l'indexation
void IndexerCommand::resume() {
    if (status == indexStatus::PAUSED) {
        start(); // Reprendre l'indexation
        qDebug() << "Indexation reprise.";
    }
}

// Ajoute un fichier indexé
void IndexerCommand::addIndexedFile(const QString& file) {
    indexedFiles.append(file);
    qDebug() << "Fichier indexé :" << file;
}

// Affiche les fichiers indexés
void IndexerCommand::displayIndexedFiles() const {
    qDebug() << "Fichiers indexés :";
    for (const QString& file : indexedFiles) {
        qDebug() << file;
    }
}

// Affiche le contenu de la base de données
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
