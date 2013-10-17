#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.show();

    QPushButton button("Animated Button");
    button.setParent(&window);
    button.show();

    QPropertyAnimation animation(&button, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(0, 0, 100, 30));
    animation.setEndValue(QRect(250, 250, 100, 30));

    animation.setEasingCurve(QEasingCurve::OutBounce);

    animation.start();
    return app.exec();
}
