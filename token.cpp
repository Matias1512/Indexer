#include "token.h"

// Constructeur par défaut
Token::Token() : m_key(""), m_value("") {}

// Constructeur avec paramètres
Token::Token(const QString &key, const QString &value) : m_key(key), m_value(value) {}

// Accesseurs
QString Token::getKey() const
{
    return m_key;
}

QString Token::getValue() const
{
    return m_value;
}

// Mutateurs
void Token::setKey(const QString &key)
{
    m_key = key;
}

void Token::setValue(const QString &value)
{
    m_value = value;
}
