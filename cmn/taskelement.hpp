#ifndef TASKELEMENT_HPP
#define TASKELEMENT_HPP

#include <QString>

class taskElement{

public:
    explicit taskElement(int iTask=0, int iRcp=0, int iOrder=0, QString strRcp="");

    int     getTaskId();
    int     getRcpId();
    int     getRcpOrder();
    QString getRcpName();

    void    setTaskId(int iVal);
    void    setRcpId(int iVal);
    void    setRcpOrder(int iVal);
    void    setRcpName(QString strVal);

private:
    int     m_iTaskId;
    int     m_iRcpId;
    int     m_iRcpOrder;
    QString m_strRcp;
};

#endif // TASKELEMENT_HPP
