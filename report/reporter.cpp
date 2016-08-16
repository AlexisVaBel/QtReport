#include "reporter.hpp"
#include <QDebug>
#include <QHBoxLayout>
#include <QDateTime>
#include <QTextDocumentWriter>
#include <QTextTableFormat>
#include <QTextTable>
#include <QMessageBox>
Reporter::Reporter(QWidget *parent) :
    QWidget(parent),
    m_document(new QTextDocument()),
    m_cursor(m_document),m_iCntTbls(0) {
}


Reporter::~Reporter(){
    delete m_document;
}

void Reporter::setDateDoc(){
    m_cursor.movePosition(QTextCursor::End);
    if(m_iCntTbls>0){
        m_cursor.insertBlock();
        m_cursor.insertBlock();
        m_cursor.movePosition(QTextCursor::End);
    }
    m_cursor.insertText(QDateTime::currentDateTime().toString("dd.MM.yy hh:mm"));
}

void Reporter::setCompanyDoc(QString str){
    m_cursor.movePosition(QTextCursor::End);
    if(m_iCntTbls>0){
        m_cursor.insertBlock();
        m_cursor.insertBlock();
        m_cursor.movePosition(QTextCursor::End);
    }
    QTextBlockFormat blockFrm;
    QTextBlockFormat blockRght;
    blockFrm.setTopMargin(5);
    blockFrm.setBottomMargin(5);
    blockFrm.setAlignment(Qt::AlignLeft);
    blockFrm.setBackground(QBrush(QColor("lightGray")));
    blockRght.setAlignment(Qt::AlignRight);
    blockRght.setBackground(QBrush(QColor("lightGray")));
    m_cursor.insertBlock(blockFrm);
    m_cursor.insertText(str);
    m_cursor.insertBlock(blockRght);
    setDateDoc();
}

void Reporter::setCaptionDoc(QString str){
    m_cursor.movePosition(QTextCursor::End);
    if(m_iCntTbls>0){
        m_cursor.insertBlock();
        m_cursor.insertBlock();
        m_cursor.movePosition(QTextCursor::End);
    }
    QTextBlockFormat blockFrm;
    blockFrm.setTopMargin(5);
    blockFrm.setBottomMargin(5);
    blockFrm.setAlignment(Qt::AlignCenter);
    m_cursor.insertBlock(blockFrm);
    m_cursor.insertText(str);
}

void Reporter::setHtml(QString str){
    m_document->setHtml(str);
}

void Reporter::setDataHeader(QStringList strLst){
    m_cursor.movePosition(QTextCursor::End);
    if(m_iCntTbls>0){
        m_cursor.insertBlock();
        m_cursor.insertBlock();
        m_cursor.movePosition(QTextCursor::End);
    }
    QBrush  borderBrush(Qt::SolidPattern);
    QTextTableFormat tableFormat;
    tableFormat.setCellPadding(5);
    tableFormat.setCellSpacing(0);
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderBrush(borderBrush);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Ridge);
    tableFormat.setBorder(1);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength,100));    
    m_cursor.insertTable(1,strLst.count(),tableFormat);
    foreach(QString str, strLst){
        m_cursor.insertText(str);
        m_cursor.movePosition(QTextCursor::NextCell);
    }
    m_iCntTbls++;
    m_iColCnt=strLst.count();
}

void Reporter::addData(QStringList strLst){
    if(strLst.count()<m_iColCnt){
        int iAdd=m_iColCnt-strLst.count();
        while(iAdd>0){
            iAdd--;
            strLst<<"";
        }
    }else
    if(strLst.count()>m_iColCnt){
        QMessageBox::critical(0, tr("AddData"),
                              tr("Too many elements to paste wait %1 got%2").arg(m_iColCnt).arg(strLst.count()),
                              QMessageBox::Ok,QMessageBox::Ok
                              );
        return;
    }
    QTextTable *tbl=m_cursor.currentTable();
    tbl->appendRows(1);
    m_cursor.movePosition(QTextCursor::PreviousRow);
    foreach(QString str, strLst){
        m_cursor.movePosition(QTextCursor::NextCell);
        m_cursor.insertText(str);
    }
}

void Reporter::writeDoc(QString &strName){
    m_document->setPageSize(QSizeF(29.7,21));
     QTextDocumentWriter writer(strName);
     writer.write(m_document);
}

void Reporter::printDoc(QPrinter *printer){
    m_document->print(printer);
}

void Reporter::clearDoc(){
    m_document->clear();
    m_cursor.movePosition(QTextCursor::End);
}
