#include "searchcommand.h"

QString SearchCommand::getSQL() {
    //SELECT * FROM fileName + tout les where des options
    QString request = QString("SELECT * FROM file WHERE name = '%%1%' ").arg(this->fileName.remove('\"'));
    for (int i = 0; i < this->options.size(); ++i) {
        const Option* option = this->options[i]; // Accéder via le pointeur

        bool isLastOption = (i == options.size() - 1);

        request.append(option->getSQL(isLastOption));
    }
    return request;
}
