#define ZZCURRDIMS
#include "zzgraphicscell.h"
#include <QDebug>

QString dx, dy, dz;
cellID cursorID;
int inputMode=0;
QString currentString;
ZZGraphicsCell* myCursor;

void ZZGraphicsCell::keyReleaseEvent(QKeyEvent* k) {
	switch(k->key()) {
	case 0x01000013: // up
		if (!inputMode) {
			qDebug() << "Up from " << cursorID << " to ";
			cursorID=world[cursorID].getNeg(dy);
			qDebug() << cursorID << endl;
		}
		break;
	case 0x01000015: // down
		if(!inputMode) {
			qDebug() << "Down from " << cursorID << " to ";
			cursorID=world[cursorID].getPos(dy);
			qDebug() << cursorID << endl;
		}
		break;
	case 0x01000012: // left
		if(!inputMode) {
			qDebug() << "Left from " << cursorID << " to ";
			cursorID=world[cursorID].getNeg(dx);
			qDebug() << cursorID << endl;
		}
		break;
	case 0x01000014: // right
		if(!inputMode) {
			qDebug() << "Right from " << cursorID << " to ";
			cursorID=world[cursorID].getPos(dx);
			qDebug() << cursorID << endl;
		}
		break;
	case 0x01000006: // insert
	case 0x49: // i / insert
		if(!inputMode) { 
			inputMode=1;
			currentString=world[cursorID].getContent();
			qDebug() << "Insert or i" << endl;
		} else {
			currentString+=k->text();
		}
		break;
	case 0x01000000: // esc
		if(inputMode) {
			inputMode=0;
			world[cursorID].setContent(currentString);
		}
		qDebug() << "Escape" << endl;
		break;
	default:
		if(inputMode) {
			 currentString+=k->text();
		}
		break;
	}
	paintLoop(myCursor);
}
void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	if (me->getID()< 0) { QString temp="+"; me->setContent(temp); }
	QRectF lowBox=boundingRect();
	QGraphicsSimpleTextItem* txt = new QGraphicsSimpleTextItem(me->getContent()/*,QFont("Times", 12, QFont::Normal)*/);
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
	painter->setPen(outline);
	painter->fillRect(lowBox, fill);
	painter->drawRect(lowBox);
	painter->drawText(centerx-(txt->boundingRect().width()/2), centery-(txt->boundingRect().height()/2), me->getContent());
}

void paintLoop(ZZGraphicsCell* cursor) {
	if(cursor->getMe()->getID() != cursorID) {
		ZZCell* temp=&world[cursorID];
		cursor->setMe(temp);
	}
	myCursor=cursor;
	paintCellsXBar(cursor);
	cursor->setFocus();
}

void paintCellsXBar(ZZGraphicsCell* cursor) {
	if(dx==QString()) {
		dx=QString("dx");
	}
	if(dy==QString()) {
		dy=QString("dy");
	}
	if(dz==QString()) {
		dz=QString("dz");
	}
	ZZGraphicsCell* posx=(new ZZGraphicsCell(&world[cursor->getMe()->getPos(dx)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* posy=(new ZZGraphicsCell(&world[cursor->getMe()->getPos(dy)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negx=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg(dx)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negy=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg(dy)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	QRectF sr=cursor->scene()->sceneRect();
	cursor->scene()->invalidate(); // clear
	cursor->scene()->addRect(0, 0, sr.width()/8, sr.height()/8, QPen(QColor::fromRgb(0, 0, 0), 3), QBrush(QColor(0,0,200), Qt::SolidPattern));
	cursor->scene()->addSimpleText("dx: "+dx+"\ndy: "+dy+"\ndz: "+dz);
	negx->myPaint(negx->scene(), sr.left(), sr.height()/2);
	negy->myPaint(negy->scene(), sr.width()/2, sr.top());
	posx->myPaint(posx->scene(), (sr.width()*3)/4, sr.height()/2);
	posy->myPaint(posy->scene(), (sr.width()/2), (sr.height()*3)/4);
	cursor->myPaint(cursor->scene(), sr.width()/2, sr.height()/2, true);
}
