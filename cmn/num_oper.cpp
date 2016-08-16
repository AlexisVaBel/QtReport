#include "num_oper.h"
#include <QDebug>

int hexToInt(QString strHex){
    bool bOk=1;
    int iTmp=0;
    strHex.replace(" ","");
    iTmp=strHex.toInt(&bOk,16);
    strHex=QString::number(iTmp);
    return strHex.toInt(&bOk,10);
}
