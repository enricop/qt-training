/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QHash<int, QStringList> players;
    players[2] = QStringList() << "Bob" << "Defender" << "1";
    players[3] = QStringList() << "Patrick" << "Defender" << "0";
    players[4] = QStringList() << "Susan" << "Midfielder" << "3";
    players[5] = QStringList() << "Felipe" << "Midfielder" << "5";
    players[6] = QStringList() << "Donna" << "Striker" << "6";

    QTreeWidget *w = new QTreeWidget;

    QStringList headerTexts;
    headerTexts << "Name" << "Player" << "Goals";
    w->setHeaderLabels(headerTexts);

    QTreeWidgetItem *teamItem = new QTreeWidgetItem(w);
    teamItem->setText(0, "Qt FC");
    teamItem->setText(2, "19");

    // Creating a child item with a parent item.
    QTreeWidgetItem *player1 = new QTreeWidgetItem(teamItem);
    player1->setText(0, "James");
    player1->setText(1, "Goalkeeper");
    player1->setText(2, "0");
    player1->setIcon(1, QPixmap(":images/1.png"));

    for (int i = 2; i <= 6; ++i) {
        QTreeWidgetItem *player = new QTreeWidgetItem(teamItem);
        player->setText(0, players[i][0]);
        player->setText(1, players[i][1]);
        player->setText(2, players[i][2]);
        player->setIcon(1, QPixmap(QString(":images/%1.png").arg(i)));
    }

    // Adding child items later.
    QTreeWidgetItem *player7 = new QTreeWidgetItem();
    player7->setText(0, "Bernie");
    player7->setText(1, "Striker");
    player7->setText(2, "4");
    player7->setIcon(1, QPixmap(":images/7.png"));
    teamItem->addChild(player7);

    w->setWindowTitle("Tree Child Items");
    w->show();
    return app.exec();
}
