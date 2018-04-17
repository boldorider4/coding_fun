#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>


class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPushButton* _button;
    QProgressBar* progressBar;
    QSlider* slider;
};

#endif // WINDOW_H
