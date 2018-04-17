#include "window.h"
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 160);
    _button = new QPushButton("Quit", this);
    _button->setGeometry(10, 10, 110, 30);

    // Do the connection
    connect(_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));

    // Create a progress bar
    // with the range between 0 and 100, and a starting value of 0
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 102);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 50, 180, 30);

    // Create a horizontal slider
    // with the range between 0 and 100, and a starting value of 0
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 97);
    slider->setValue(0);
    slider->setGeometry(10, 90, 180, 30);

    show();

    // Connection
    // This connection set the value of the progress bar
    // while the slider's value changes
    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
}
