#include "maxsize.h"

QString MaxSize::getSQL(bool isTheLastOption) const {
    QString request = "";
    request = "AND size <= "+ QString::number(this->number);

    if(isTheLastOption){
        request.append(";");
    }
    return request;
}
