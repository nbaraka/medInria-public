#pragma once
/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2020. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medAbstractDataSource.h>
#include <medMoveCommandItem.h>

class medPacsDataSourcePrivate;
class medToolBox;

/**
 * @class Pacs connection datasource that comes with treeview,
 * searchpanel and source selector (DICOM-nodes)
 */
class medPacsDataSource : public medAbstractDataSource
{
    Q_OBJECT
public:

    medPacsDataSource(QWidget* parent = nullptr);
    ~medPacsDataSource();

    QWidget* mainViewWidget();

    QWidget* sourceSelectorWidget();

    QString tabName();

    QList<medToolBox*> getToolBoxes();

    QString description() const;

private slots:
    void onPacsMove( const QVector<medMoveCommandItem>& cmdList);

private:
    medPacsDataSourcePrivate* d;
};
