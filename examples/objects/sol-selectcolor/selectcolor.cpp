#include "selectcolor.h"

SelectColor::SelectColor(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel("Not Set");
    m_label->setAutoFillBackground(true);
    QPushButton *button = new QPushButton("Select Color");
    connect(button, SIGNAL(clicked()), this, SLOT(slotSelectColor()));

    QVBoxLayout *col = new QVBoxLayout;
    {
        QHBoxLayout *row = new QHBoxLayout;
        row->addWidget(new QLabel("Color is: "));
        row->addWidget(m_label);
        col->addLayout(row);
    }
    col->addWidget(button);

    setLayout(col);
}

void SelectColor::slotSelectColor()
{
    QColor color = QColorDialog::getColor(QColor(m_label->text()), this);

    if (color.isValid())
    {
        m_label->setText(color.name());
        QPalette palette = m_label->palette();
        palette.setColor(QPalette::Window, color);
        m_label->setPalette(palette);
    }
}
