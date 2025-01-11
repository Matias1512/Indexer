#include "searchcommand.h"

QString SearchCommand::getSQL() {
    //SELECT * FROM fileName + tout les where des options
    QString request = "SELECT * FROM fileName ";

    for (int i = 0; i < this->options.size(); ++i) {
        const Option* option = this->options[i]; // Accéder via le pointeur

        bool isFirstOption = (i == 0);
        bool isLastOption = (i == options.size() - 1);

        request.append(option->getSQL(isFirstOption, isLastOption));
    }
    return request;
}
