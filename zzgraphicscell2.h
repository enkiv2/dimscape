#ifndef ZZGRAPHICSCELL2_H
#define ZZGRAPHICSCELL2_H

#include <QGraphicsRectItem>
#include <QList>

#include "lib/ZZCell.h"


class ZZGraphicsCell2 : public QGraphicsRectItem
{

public:
    ZZGraphicsCell2(QGraphicsItem* aParent = 0) :
            QGraphicsRectItem(aParent), penThick(1)
    {
    	me=new ZZCell();
	setFlags(ItemIsFocusable);
	update();
    }
    ZZGraphicsCell2(QRectF& aRect, QGraphicsItem* aParent = 0) :
            QGraphicsRectItem(aRect,aParent)
    {
    	me=new ZZCell();
	setFlags(ItemIsFocusable);
	update();
    }

    int type ()
    {
    	return UserType+(*me).getType();
    }
    
    QRectF boundingRect() const
    {
        QRectF lowBox = childrenBoundingRect();
        return QRectF(lowBox.left() - penThick/2, lowBox.top() - penThick/2, 
			lowBox.width() + penThick, lowBox.height() + penThick);
    }

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

#endif // ZZGRAPHICSCELL2_H
