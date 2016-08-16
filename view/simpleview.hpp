#ifndef SIMPLEVIEW_H
#define SIMPLEVIEW_H

#include <QPushButton>
#include <QWidget>
#include "report/reporter.hpp"
#include <QDialog>
class SimpleView : public QDialog
{
    Q_OBJECT
public:
    explicit SimpleView(QWidget *parent = 0);

signals:

public slots:
    void printDoc();
private:
    QPushButton *m_btnPrint;
    Reporter *m_reporter;
    QPrinter *m_printer;

    void printComplexReport  ();
    // QWidget interface
protected:
    void showEvent(QShowEvent *);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // SIMPLEVIEW_H
