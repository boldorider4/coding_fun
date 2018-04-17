#include "window.h"
#include "examples.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QWidget win1;
 firstExample(win1);
 win1.show();

 Window win2;
 win2.show();

 return app.exec();
}
