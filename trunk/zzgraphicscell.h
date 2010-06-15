#ifndef ZZGRAPHICSCELL_H
#define ZZGRAPHICSCELL_H

#include <QGraphicsItem>
#include <Qt/qpainter.h>

class ZZGraphicsCell : public QGraphicsItem
{

public:
    ZZGraphicsCell(QGraphicsScene* aScene, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(1)
    {}
    ZZGraphicsCell(QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(aPenThick)
    {}

    QRectF boundingRect()
    {
        QRectF lowBox = childrenBoundingRect();
        return QRectF(lowBox.left() - penThick/2, lowBox.top() - penThick/2, lowBox.width() + penThick, lowBox.height() + penThick);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getPenThick() const
    {
        return penThick;
    }
    void setPenThick(int aThick)
    {
        penThick = aThick;
    }

private:
    qreal penThick;
    

};

#endif // ZZGRAPHICSCELL_H
