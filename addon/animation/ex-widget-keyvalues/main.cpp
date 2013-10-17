#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton("Animated Button");
    button->show();

    QPropertyAnimation animation(button, "geometry");
    animation.setDuration(10000);

    animation.setKeyValueAt(0, QRect(0, 0, 100, 30));
    animation.setKeyValueAt(0.8, QRect(250, 250, 100, 30));
    animation.setKeyValueAt(1, QRect(0, 0, 100, 30));

    animation.start();
    return app.exec();
}
