/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "BookStore.h"
#include <qdatawidgetmapper.h>
#include "ui_BookStore.h"

BookStore::BookStore( QAbstractItemModel* model )
    : QWidget(), _ui( new Ui::BookStore )
{
    _ui->setupUi(this);

    QDataWidgetMapper* mapper = new QDataWidgetMapper( this );
    mapper->setModel( model );

    mapper->addMapping( _ui->title, 0 );
    mapper->addMapping( _ui->author, 1 );
    mapper->addMapping( _ui->price, 2 );

    connect( _ui->first, SIGNAL( clicked() ), mapper, SLOT( toFirst() ) );
    connect( _ui->previous,SIGNAL( clicked() ), mapper, SLOT( toPrevious() ) );
    connect( _ui->next,SIGNAL( clicked() ), mapper, SLOT( toNext() ) );
    connect( _ui->last,SIGNAL( clicked() ), mapper, SLOT( toLast() ) );

    mapper->toFirst();
}
