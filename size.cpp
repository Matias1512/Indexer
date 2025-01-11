#include "size.h"

QString Size::getSQL(bool isTheLastOption) const {
    QString request = "";

    if(this->maxSize == -1){
        request = "AND size = " + QString::number(this->size);
    } else {
        request = QString("AND size BETWEEN %1 AND %2 ").arg(this->size, this->maxSize);
    }

    if(isTheLastOption){
        request.append(";");
    }
    return request;
}
