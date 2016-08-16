#include "rcpcomponent.hpp"

rcpComponent::rcpComponent(QObject *parent, double dWesNeed, int iProdId, int iOrder, QString strName, bool bJustShow) :
    QObject(parent),
    m_strName(strName),
    m_dWesNeed(dWesNeed),
    m_iProdId(iProdId),
    m_iOrder(iOrder){
    m_dWesActual=0;
    m_bJustShow=bJustShow;
}

QString rcpComponent::getName(){
    return m_strName;
}

void rcpComponent::setName(QString str){
    m_strName=str;
}

int rcpComponent::getNameId(){
    return m_iProdId;
}

void rcpComponent::setNameId(int iVal){
    m_iProdId=iVal;
}

double rcpComponent::getWesNeed(){
    return m_dWesNeed;
}

double rcpComponent::getWesActual(){
    return m_dWesActual;
}

void rcpComponent::setWesActual(double dWes){
    m_dWesActual=dWes;
}

void rcpComponent::setJustShow(bool bSet){
    m_bJustShow=bSet;
}

bool rcpComponent::getJustShow(){
    return m_bJustShow;
}
