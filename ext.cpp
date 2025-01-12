#include "ext.h"

QString Ext::getSQL(bool isTheLastOption) const {

    QString request = " AND extension IN ";
    if(extList.size() > 1) {
        for (int i=0 ; i < this->extList.size() ; i++) {
            if(i == 0){
                request.append("('"+extList[0]+"', ");
            } else if(i == extList.size() - 1) {
                request.append("'"+extList[i]+"')");
            } else {
                request.append("'"+extList[i]+"', ");
            }
        }
    } else {
        request.append("('"+extList[0]+"')");
    }

    if(isTheLastOption){
        request.append(";");
    }
    return request;
}
