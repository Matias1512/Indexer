#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <QStringList>
#include <QRegularExpression>
#include <QMap>
#include <QObject>

class tokenizer : public QObject
{
    Q_OBJECT
public:
    explicit tokenizer(QObject *parent = nullptr);

    QMap<QString, QString> tokenizerCommand(QString command);

signals:
};

#endif // TOKENIZER_H
