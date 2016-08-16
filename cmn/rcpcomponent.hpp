#ifndef RCPCOMPONENT_HPP
#define RCPCOMPONENT_HPP

#include <QObject>
#include <QString>

class rcpComponent : public QObject
{
    Q_OBJECT
public:
    explicit rcpComponent(QObject *parent = 0,double dWesNeed=0,int iProdId=0,int iOrder=0,QString strName="",bool bJustShow=false);
    Q_PROPERTY(QString m_strName READ getName WRITE setName)

    QString getName();
    void    setName(QString str);

    int     getNameId();
    void    setNameId(int iVal);

    double  getWesNeed();

    double  getWesActual();
    void    setWesActual(double dWes);

    void    setJustShow(bool bSet);
    bool    getJustShow();

signals:

public slots:
private:
    QString m_strName;
    double  m_dWesNeed;
    double  m_dWesActual;
    int     m_iOrder;
    int     m_iProdId;
    bool    m_bJustShow;        // don`t need to read wes
    bool    m_bInterrupted;
};

#endif // RCPCOMPONENT_HPP
