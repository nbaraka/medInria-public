/* medDatabaseNonPersitentItem.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Sun Jun 27 18:42:08 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Sun Jun 27 18:54:44 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 17
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "medDatabaseNonPersistentItem.h"
#include "medDatabaseNonPersistentItem_p.h"

medDatabaseNonPersistentItem::medDatabaseNonPersistentItem(void) : QObject(), d(new medDatabaseNonPersistentItemPrivate)
{
    //d->data = NULL;
}

medDatabaseNonPersistentItem::~medDatabaseNonPersistentItem(void)
{
    delete d;

    d = NULL;
}

const QString& medDatabaseNonPersistentItem::name(void) const
{
    return d->name;
}

const QString& medDatabaseNonPersistentItem::birthdate ( void ) const
{
    return d->birthdate;
}

const QString& medDatabaseNonPersistentItem::patientId ( void ) const
{
  return d->patientId;
}

const QString& medDatabaseNonPersistentItem::studyName(void) const
{
    return d->studyName;
}

const QString& medDatabaseNonPersistentItem::studyId ( void ) const
{
  return d->studyId;
}

const QString& medDatabaseNonPersistentItem::studyUid ( void ) const
{
  return d->studyUid;
}


const QString& medDatabaseNonPersistentItem::seriesName(void) const
{
    return d->seriesName;
}

const QString& medDatabaseNonPersistentItem::seriesId ( void ) const
{
    return d->seriesId;
}

const QString& medDatabaseNonPersistentItem::seriesUid ( void ) const
{
  return d->seriesUid;
}

const QString& medDatabaseNonPersistentItem::file(void) const
{
    return d->file;
}

const QImage& medDatabaseNonPersistentItem::thumb(void) const
{
    return d->thumb;
}

const medDataIndex& medDatabaseNonPersistentItem::index(void) const
{
    return d->index;
}

dtkAbstractData *medDatabaseNonPersistentItem::data(void)
{
    return d->data;
}
