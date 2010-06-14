#ifndef ZZSPACE_H
#define ZZSPACE_H

#include <QObject>
#include <QGraphicsView>
#include <QHash>

class ZZSpace : public QObject
{
Q_OBJECT
public:
    explicit ZZSpace(QObject *parent = 0);
    explicit ZZSpace(QGraphicsView* view);
    void move(QString& id);
    void createCell(QString& id);


signals:

public slots:

private:
    QGraphicsView* view;
    QHash<QString, ZZCell*> cells;
    QHash<QString, ZZGraphicsCell*> drawnCells;
    QString currentCellId;
    QString dim1, dim2, dim3;

};

#endif // ZZSPACE_H
