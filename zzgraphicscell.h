#ifndef ZZGRAPHICSCELL_H
#define ZZGRAPHICSCELL_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <Qt/qpainter.h>
#include "Cell.h"

class ZZGraphicsCell : public QGraphicsItem
{

public:
    ZZGraphicsCell(QGraphicsScene* aScene, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(1)
    {
    	me=new ZZCell();
	update();
    }
    ZZGraphicsCell(QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(aPenThick)
    {
    	me=new ZZCell();
	update();
    }

    ~ZZGraphicsCell() {
    	delete me;
    }

    ZZGraphicsCell(ZZCell* foo, QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent=0) : 
    	QGraphicsItem(aParent, aScene), penThick(aPenThick) 
    {
		me=foo;
		update();
    }
    
    void advance(int phase) 
    {/*
    	QGraphicsScene* scene=this->scene();
    	scene->addRect(boundingRect());
	QGraphicsSimpleTextItem* txt=scene->addSimpleText(me->getContent());
	txt->setPos(0, 520);*/
    }

    //bool collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode  mode = Qt::IntersectsItemShape) 
    //{
    //	return false;
    //}

    //bool collidesWithPath ( const QPainterPath & path, Qt::ItemSelectionMode  mode = Qt::IntersectsItemShape ) 
    //{
    //	return false;
    //}

    //bool contains ( const QPointF & point  ) 
    //{
    //	return false;
    //}

    //bool isObscuredBy ( const QGraphicsItem * item  )
    //{
    //	return false;
    //}
    
    QPainterPath opaqueArea() {
    	QPainterPath temp;
	temp.addRect(boundingRect());
	return temp;
    }

    int type ()
    {
    	return UserType+(*me).getType();
    }
    /*
    bool isVisible() 
    {
    	return true;
    }*/

    QRectF boundingRect() const
    {
        QRectF lowBox = childrenBoundingRect();
        return QRectF(lowBox.left()  - penThick/2, lowBox.top()  - penThick/2, lowBox.width() +  penThick, lowBox.height() +  penThick);
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

    void myPaint(QGraphicsScene* s, int centerx, int centery) 
    {
    	QRectF lowBox=boundingRect();
    	s->addRect(centerx - lowBox.right()/2, centery - lowBox.bottom()/2, centerx + lowBox.right()/2, centery + lowBox.bottom()/2,  QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,100,100), Qt::SolidPattern));
	QGraphicsSimpleTextItem* txt = s->addSimpleText(me->getContent()/*,QFont("Times", 12, QFont::Normal)*/);
	txt->setPos(centerx, centery);
    }

private:
    qreal penThick;
    ZZCell* me;
    

};

#endif // ZZGRAPHICSCELL_H
