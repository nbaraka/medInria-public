/* medToolBoxPatient.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Feb 19 09:06:02 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Jun 14 16:34:02 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 39
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "medToolBoxPatient.h"

#include <QtGui>

#include <medCore/medDataIndex.h>

class medToolBoxPatientPrivate
{
public:
    QComboBox *combo;
};

medToolBoxPatient::medToolBoxPatient(QWidget *parent) : medToolBox(parent), d(new medToolBoxPatientPrivate)
{
    QWidget *central = new QWidget(this);

    d->combo = new QComboBox(central);
    d->combo->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(d->combo);

    this->setTitle("Patient");
    this->setWidget(central);

    connect(d->combo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(patientIndexChanged(int)));
}

medToolBoxPatient::~medToolBoxPatient(void)
{
    delete d;

    d = NULL;
}

void medToolBoxPatient::addItem(const QString& item)
{
    d->combo->addItem(item);
}

void medToolBoxPatient::addItem(const QString& item, const QVariant& data)
{
    d->combo->addItem(item, data);
}

void medToolBoxPatient::clear(void)
{
    d->combo->clear();
}

int medToolBoxPatient::patientIndex(void)
{
    return d->combo->currentIndex();
}

int medToolBoxPatient::patientIndex(QString patient)
{
    return d->combo->findText(patient);
}

int medToolBoxPatient::patientIndex(const medDataIndex& index)
{
    return d->combo->findData(index.patientId());
}

void medToolBoxPatient::setPatientIndex(int index)
{
    d->combo->setCurrentIndex(index);
}
