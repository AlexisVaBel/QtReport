#include "taskelement.hpp"

taskElement::taskElement(int iTask, int iRcp, int iOrder, QString strRcp){
    m_iTaskId   =iTask;
    m_iRcpId    =iRcp;
    m_iRcpOrder =iOrder;
    m_strRcp    =strRcp;
}

int taskElement::getTaskId(){
    return m_iTaskId;
}

int taskElement::getRcpId(){
    return m_iRcpId;
}

int taskElement::getRcpOrder(){
    return m_iRcpOrder;
}

QString taskElement::getRcpName(){
    return m_strRcp;
}

void taskElement::setTaskId(int iVal){
    m_iTaskId=iVal;
}

void taskElement::setRcpId(int iVal){
    m_iRcpId=iVal;
}

void taskElement::setRcpOrder(int iVal){
    m_iRcpOrder=iVal;
}

void taskElement::setRcpName(QString strVal){
    m_strRcp=strVal;
}
