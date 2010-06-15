#ifndef ZZCELL_H
#define ZZCELL_H

#include "Cell.h"
#include <QObject>

class ZZCell : public QObject, public Cell
{
Q_OBJECT
public:
    explicit ZZCell(QObject *parent = 0);

signals:

public slots:

};

#endif // ZZCELL_H
