/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
int main(int argc, char **argv) {
  QApplication app(argc, argv);
  QGraphicsView view;
  QGraphicsScene *scene = new QGraphicsScene(&view);
  view.setScene(scene);
  QGraphicsRectItem *rect = new QGraphicsRectItem(-10, -10, 120, 50);
  scene->addItem(rect);
  QGraphicsTextItem *text = scene->addText("Hello World!");
  view.show();
  return app.exec();
}

