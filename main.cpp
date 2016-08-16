#include <QApplication>
#include "view/simpleview.hpp"

int main(int argc,char **argv){
    QApplication app(argc,argv);
    SimpleView *vw=new SimpleView();    
    vw->show();
    return app.exec();
}
