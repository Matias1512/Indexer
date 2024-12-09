#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

class Token
{
public:
    Token(); // Constructeur par défaut
    Token(const QString &key, const QString &value); // Constructeur avec paramètres

    // Accesseurs
    QString getKey() const;
    QString getValue() const;

    // Mutateurs
    void setKey(const QString &key);
    void setValue(const QString &value);

private:
    QString m_key;
    QString m_value;
};

#endif // TOKEN_H
