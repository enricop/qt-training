#include <QtGui>
#include "QuoteButton.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *top = new QWidget;
    top->setWindowTitle("Quotes from Office Space");

    QuoteButton* button = new QuoteButton("Quote", top);
    QTextEdit* edit = new QTextEdit(top);
    QObject::connect(
        button, SIGNAL(quote(const QString &)),
        edit, SLOT(setText(const QString &))
    );

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(edit);
    top->setLayout(layout);
    top->show();

    return app.exec();
}
