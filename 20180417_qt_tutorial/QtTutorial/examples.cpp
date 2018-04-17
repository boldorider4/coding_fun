#include "examples.h"
#include <QPushButton>
#include <QTextStream>

void firstExample(QWidget& win) {

    QPushButton* button0 = new QPushButton(QIcon ("icon.png"), "Custom text", &win);
    button0->setToolTip("Random tooltip");

    QTextStream ts( stdout );

    QFont retFont = button0->font();
    QString retString = retFont.family();
    ts << retString << endl;

    QFont font ("Courier", 100, 150, true);
    button0->setFont(font);

    retFont = button0->font();
    retString = retFont.family();
    ts << retString << endl;

    QPushButton* button1 = new QPushButton("test");
    QPushButton* button2 = new QPushButton("other", button1);

    button1->show();
}
