#ifndef ZZGRAPHICSCELL_H
#define ZZGRAPHICSCELL_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <Qt/qpainter.h>
#include "Cell.h"
#include <math.h>
#include <QPointF>

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
        return QRectF(lowBox.left()  - 100 - penThick/2, lowBox.top()  - 100 - penThick/2, lowBox.width() + 100 +  penThick, lowBox.height() + 100 +  penThick);
    }

    void setMe(ZZCell* foo) {
    	delete me;
    	me=foo;
    }
    ZZCell* getMe() {
    	return me;
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
    	if (me->getID()< 0) { QString temp="+"; me->setContent(temp); }
    	QRectF lowBox=boundingRect();
	lowBox.moveCenter(QPointF((qreal)centerx, (qreal)centery));
    	s->addRect(lowBox,  QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,0,75), Qt::SolidPattern));
	QGraphicsSimpleTextItem* txt = s->addSimpleText(me->getContent()/*,QFont("Times", 12, QFont::Normal)*/);
	txt->setPos(centerx, centery);
    }

private:
    qreal penThick;
    ZZCell* me;
    

};

void paintCellsXBar(ZZGraphicsCell* cursor);

#endif // ZZGRAPHICSCELL_H
