#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    // outer horizontal-layout
    QVBoxLayout *outer = new QVBoxLayout;
    outer->addWidget(new QLabel("Note:"));
    outer->addWidget(new QTextEdit);
    {
        // nested inner layout
        QHBoxLayout *inner = new QHBoxLayout;
        inner->addWidget(new QPushButton("Clear"));
        inner->addWidget(new QPushButton("Save"));
        outer->addLayout(inner);
    }
    window->setLayout(outer);

    window->show();

    return app.exec();
}
