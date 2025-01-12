#include "type.h"

QString Type::getSQL(bool isTheLastOption) const {
    QString request = " AND type IN ";
    if(this->listType.size() > 1) {
        for (int i=0 ; i < this->listType.size() ; i++) {
            if(i == 0){
                request.append("('"+this->listType[0]+"', ");
            } else if(i == this->listType.size() - 1) {
                request.append("'"+this->listType[i]+"')");
            } else {
                request.append("'"+this->listType[i]+"', ");
            }
        }
    } else {
        request.append("('"+this->listType[0]+"')");
    }

    if(isTheLastOption){
        request.append(";");
    }
    return request;
}
