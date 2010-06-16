#ifndef ZZGRAPHICSCELL_H
#define ZZGRAPHICSCELL_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <Qt/qpainter.h>
#include "Cell.h"
#include <math.h>
#include <QPointF>
#include <QKeyEvent>

#ifndef ZZCURRDIMS
extern QString dx, dy, dz;
extern cellID cursorID;
#endif // ZZCURRDIMS


class ZZGraphicsCell : public QGraphicsItem
{

public:
    ZZGraphicsCell(QGraphicsScene* aScene, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(1)
    {
    	me=new ZZCell();
	setFlags(ItemIsFocusable);
	update();
    }
    ZZGraphicsCell(QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent = 0) :
            QGraphicsItem(aParent, aScene), penThick(aPenThick)
    {
    	me=new ZZCell();
	setFlags(ItemIsFocusable);
	update();
    }

/*    ~ZZGraphicsCell() {
    	delete me;
    }*/

    ZZGraphicsCell(ZZCell* foo, QGraphicsScene* aScene, qreal aPenThick, QGraphicsItem* aParent=0) : 
    	QGraphicsItem(aParent, aScene), penThick(aPenThick) 
    {
		me=foo;
		setFlags(ItemIsFocusable);
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
        return QRectF(lowBox.left() - 50 - penThick/2, lowBox.top() - 50  - penThick/2, lowBox.width()  + 50 +  penThick, lowBox.height() + 50  +  penThick);
    }

    void setMe(ZZCell* foo) {
    	//delete me;
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

    void myPaint(QGraphicsScene* s, int centerx, int centery, bool isCursor=false) 
    {
    	if (me->getID()< 0) { QString temp="+"; me->setContent(temp); }
    	QRectF lowBox=boundingRect();
	QGraphicsSimpleTextItem* txt = s->addSimpleText(me->getContent()/*,QFont("Times", 12, QFont::Normal)*/);
	if(txt->boundingRect().width() > lowBox.width() || txt->boundingRect().height() > lowBox.height()) {
		lowBox=txt->boundingRect();
		if(lowBox.width() > lowBox.height()) { 
			lowBox.setWidth(lowBox.height()+100);
			lowBox.setHeight(lowBox.width());
		} else {
			lowBox.setHeight(lowBox.width()+100);
			lowBox.setWidth(lowBox.height());
		}
	}
	lowBox.moveCenter(QPointF((qreal)centerx, (qreal)centery));
	QPen outline;
	QBrush fill;
	if(isCursor) {
		outline=QPen(QColor::fromRgb(0, 0, 0), penThick);
		fill=QBrush(QColor(0,0,255), Qt::SolidPattern);
	} else {
		outline=QPen(QColor::fromRgb(127,127,255), penThick);
		fill=QBrush(QColor(0,0,200), Qt::SolidPattern);
	}
    	s->addRect(lowBox, outline, fill);
	txt->setPos(centerx-(txt->boundingRect().width()/2), centery-(txt->boundingRect().height()/2));
	txt->setZValue(txt->zValue()+1);

    }
    void keyReleaseEvent(QKeyEvent* k);  


private:
    qreal penThick;
    ZZCell* me;
    

};
void paintLoop(ZZGraphicsCell* cursor);
void paintCellsXBar(ZZGraphicsCell* cursor);


#endif // ZZGRAPHICSCELL_H
