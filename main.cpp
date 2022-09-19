#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QWidget>

#include "FireEvent.h"
#include <Windows.h>


int main(int argc, char *argv[]) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    QApplication a(argc, argv);
    FireEvent fire;

    auto widget = QWidget();
    widget.resize(500, 240);
    widget.show();


    QPushButton button1("Hit me", &widget);
    button1.move(40, 110);
    button1.show();

    QPushButton button2("Reset", &widget);
    button2.move(200, 110);
    button2.show();

    QProgressBar progressBar1(&widget);
    progressBar1.setRange(0, 100);
    progressBar1.setFixedSize(320, 20);
    progressBar1.show();

    QProgressBar progressBar2(&widget);
    progressBar2.setRange(0, 100);
    progressBar2.move(0, 40);
    progressBar2.setFixedSize(320, 20);
    progressBar2.show();

    QProgressBar progressBar3(&widget);
    progressBar3.setRange(0, 100);
    progressBar3.move(0, 80);
    progressBar3.setFixedSize(320, 20);
    progressBar3.show();


    QObject::connect(&button1, &QPushButton::clicked, &fire, &FireEvent::fire);
    QObject::connect(&fire, &FireEvent::valueChange1, &progressBar1, &QProgressBar::setValue);
    QObject::connect(&fire, &FireEvent::valueChange2, &progressBar2, &QProgressBar::setValue);
    QObject::connect(&fire, &FireEvent::valueChange3, &progressBar3, &QProgressBar::setValue);
    QObject::connect(&button2, &QPushButton::clicked, &fire, &FireEvent::reset);

    return QApplication::exec();
}
