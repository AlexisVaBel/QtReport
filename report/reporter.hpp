#ifndef REPORTER_HPP
#define REPORTER_HPP

#include <QWidget>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>

class Reporter : public QWidget
{
    Q_OBJECT
public:
    explicit Reporter(QWidget *parent = 0);
    ~Reporter();
    void setDateDoc();
    void setCompanyDoc(QString str);
    void setCaptionDoc(QString str);


    void setDataHeader(QStringList strLst);
    void addData(QStringList strLst);

    void setHtml(QString str);
    void writeDoc(QString &strName);
    void printDoc(QPrinter *printer);
    void clearDoc();

    QTextDocument *getTextDoc(){return m_document;}
signals:

public slots:

private:
    int             m_iCntTbls;
    int             m_iColCnt;
    QTextDocument   *const m_document;
    QTextCursor     m_cursor;
};

#endif // REPORTER_HPP
