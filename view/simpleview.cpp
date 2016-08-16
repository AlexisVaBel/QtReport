#include "simpleview.hpp"
#include "cmn/str_oper.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QPainter>
#include <QPrintDialog>

SimpleView::SimpleView(QWidget *parent) : QDialog(parent){
    m_reporter=new Reporter(this);
    m_printer=new QPrinter();
//    m_btnPrint=new QPushButton(this);
    QFrame *fram=new QFrame();
    QHBoxLayout *frameLt=new QHBoxLayout(fram);
    frameLt->addWidget(m_reporter);
    setLayout(frameLt);

    setGeometry(10,10,1024,840);
    setStyleSheet("background-color:white;");
    printComplexReport();
    connect(m_btnPrint,SIGNAL(clicked(bool)),this,SLOT(printDoc()));
}

void SimpleView::printDoc(){
    QPrintDialog    printDialog(m_printer,this);
    if(printDialog.exec()){
        m_printer->setOrientation(QPrinter::Landscape);
        m_reporter->printDoc(m_printer);
    }
}

void SimpleView::printComplexReport(){
    // далее наполняем контентом
    QStringList strLst;
    m_reporter->setCompanyDoc(QString::fromLocal8Bit("НПФ Промавтоматика"));
    m_reporter->setCaptionDoc(QString::fromLocal8Bit(" Отчет №0"));


    strLst<<QString::fromLocal8Bit("Рецепт         ")<<setStr("Продукт        ")<<setStr("Вес нужный")<<setStr("Вес набранный")
         <<setStr("Задача отпр.")<<setStr("Задача подтв.")<<setStr("Партия");
//    strLst<<QString::fromLocal8Bit("Receipt         ")<<setStr("Product        ")<<setStr("Need weight")<<setStr("Fact weigth")
//         <<setStr("Task send")<<setStr("Task accpt.");
    m_reporter->setDataHeader(strLst);
    strLst.clear();
    for(int i=0;i<2;i++){
        for(int j=0;j<10;j++){
            strLst<<QString::fromLocal8Bit("Рецепт %1:").arg(i)<<setStr("Компонент %1 ").arg(i+j)<<""<<"";
            m_reporter->addData(strLst);
            strLst.clear();
        }

    }


    double dSum=0.0;
    strLst.clear();
//    strLst<<QString::fromLocal8Bit("All components:")<<""<<""<<"";
    strLst<<QString::fromLocal8Bit("Всего компонент:")<<""<<""<<"";
    m_reporter->addData(strLst);

    strLst.clear();
    strLst<<setStr("Сумма:")<<""<<""<<""<<""<<"";
    m_reporter->addData(strLst);
    strLst.clear();
    strLst<<""<<""<<""<<QString::number(dSum)<<""<<"";
    m_reporter->addData(strLst);
    strLst.clear();
    m_reporter->setCaptionDoc(QString(" Report N2"));
    strLst<<QString::fromLocal8Bit("Рецепт         ")<<setStr("Продукт        ")<<setStr("Вес нужный")<<setStr("Вес набранный")
         <<setStr("Задача отпр.")<<setStr("Задача подтв.")<<setStr("Партия");
    m_reporter->setDataHeader(strLst);
    strLst.clear();
}




void SimpleView::showEvent(QShowEvent *){
    // увязка с принтером сначала она
//    QPrintDialog    printDialog(m_printer,this);
//    if(printDialog.exec()){
//        m_printer->setOrientation(QPrinter::Landscape);
//        printComplexReport();
//    }
}


void SimpleView::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QRect rec(0,0,this->width(),this->height());
    m_reporter->getTextDoc()->drawContents(&painter,rec);
}
