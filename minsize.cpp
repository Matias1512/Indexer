#include "minsize.h"

QString MinSize::getSQL(bool isTheLastOption) const {
    QString request = "";
    request = " AND size >= "+ QString::number(this->number);

    if(isTheLastOption){
        request.append(";");
    }
    return request;
}
