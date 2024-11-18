#include "indexer.h"
#include "indexstatus.h"


Indexer::Indexer() : status(indexStatus::STOPPED) {}

// Récupérer le statut actuel
indexStatus Indexer::getStatus() const {
    return status;
}

// Démarrer l'indexation
void Indexer::start() {
    status = indexStatus::INDEXING;
    qDebug() << "Indexation en cours...";
}

// Arrêter l'indexation
void Indexer::stop() {
    status = indexStatus::STOPPED;
    qDebug() << "Indexation arrêtée.";
}

// Mettre en pause l'indexation
void Indexer::pause() {
    if (status == indexStatus::INDEXING) {
        status = indexStatus::PAUSED;
        qDebug() << "Indexation en pause.";
    }
}

// Reprendre l'indexation
void Indexer::resume() {
    if (status == indexStatus::PAUSED) {
        status = indexStatus::INDEXING;
        qDebug() << "Indexation reprise.";
    }
}

// Ajouter un fichier indexé
void Indexer::addIndexedFile(const QString& file) {
    indexedFiles.append(file);
    qDebug() << "Fichier indexé:" << file;
}

// Afficher les fichiers indexés
void Indexer::displayIndexedFiles() const {
    qDebug() << "Fichiers indexés :";
    for (const QString& file : indexedFiles) {
        qDebug() << file;
    }
}
