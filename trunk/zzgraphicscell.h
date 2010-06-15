#ifndef ZZGRAPHICSCELL_H
#define ZZGRAPHICSCELL_H

#include <QGraphicsItem>
#include <Qt/qpainter.h>
#include "Cell.h"

class ZZGraphicsCell : public QGraphicsItem
{

public:
    ZZGraphicsCell(QGraphicsScene* aScene, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(1)
    {
    	me=new ZZCell();
    }
    ZZGraphicsCell(QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(aPenThick)
    {
    	me=new ZZCell();
    }

    ~ZZGraphicsCell() {
    	delete me;
    }

    ZZGraphicsCell(ZZCell* foo, QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent=0) : 
    	QGraphicsItem(aParent, aScene), penThick(aPenThick) 
    {
		me=foo;
    }
    
    void advance(int phase) {}

    bool collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode  mode = Qt::IntersectsItemShape) 
    {
    	return false;
    }

    bool collidesWithPath ( const QPainterPath & path, Qt::ItemSelectionMode  mode = Qt::IntersectsItemShape ) 
    {
    	return false;
    }

    bool contains ( const QPointF & point  ) 
    {
    	return false;
    }

    bool isObscuredBy ( const QGraphicsItem * item  )
    {
    	return false;
    }
    /*
    QPainterPath  opaqueArea () 
    {
    	return new QPainterPath();
    }
    */
    int type ()
    {
    	return UserType+(*me).getType();
    }

    bool isVisible() 
    {
    	return true;
    }

    QRectF boundingRect() const
    {
        QRectF lowBox = childrenBoundingRect();
        return QRectF(lowBox.left() - penThick/2, lowBox.top() - penThick/2, lowBox.width() + penThick, lowBox.height() + penThick);
    }

    void setMe(ZZCell* foo) {
    	delete me;
    	me=foo;
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
    ZZCell* me;
    

};

#endif // ZZGRAPHICSCELL_H
