#define ZZCURRDIMS
#include "zzgraphicscell.h"
#include <QDebug>

QString dx, dy, dz;
cellID cursorID;

void ZZGraphicsCell::keyReleaseEvent(QKeyEvent* k) {
	switch(k->key()) {
	case 0x01000013: // up
		qDebug() << "Up from " << cursorID << " to ";
		cursorID=world[cursorID].getNeg(dy);
		qDebug() << cursorID << endl;
		break;
	case 0x01000015: // down
		qDebug() << "Down from " << cursorID << " to ";
		cursorID=world[cursorID].getPos(dy);
		qDebug() << cursorID << endl;
		break;
	case 0x01000012: // left
		qDebug() << "Left from " << (int)cursorID << " to ";
		cursorID=world[cursorID].getNeg(dx);
		qDebug() <<(int)cursorID << endl;
		break;
	case 0x01000014: // right
		qDebug() << "Right from " << (int)cursorID << " to ";
		cursorID=world[cursorID].getPos(dx);
		qDebug() << (int)cursorID << endl;
		break;
	case 0x01000006: // insert
	case 0x49: // i / insert
		// TODO
		qDebug() << "Insert or i" << endl;
		break;
	case 0x01000000: // esc
		// TODO
		qDebug() << "Escape" << endl;
		break;
	}
}
void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	/* Not used. Use myPaint instead */
}

void paintLoop(ZZGraphicsCell* cursor) {
	ZZCell temp=world[cursorID];
	cursor->setMe(&temp);
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
	cursor->scene()->addRect(0, 0, sr.width()/8, sr.height()/8, QPen(QColor::fromRgb(0, 0, 0), 3), QBrush(QColor(0,0,200), Qt::SolidPattern));
	cursor->scene()->addSimpleText("dx: "+dx+"\ndy: "+dy+"\ndz: "+dz);
	negx->myPaint(negx->scene(), sr.left(), sr.height()/2);
	negy->myPaint(negy->scene(), sr.width()/2, sr.top());
	posx->myPaint(posx->scene(), (sr.width()*3)/4, sr.height()/2);
	posy->myPaint(posy->scene(), (sr.width()/2), (sr.height()*3)/4);
	cursor->myPaint(cursor->scene(), sr.width()/2, sr.height()/2, true);
}
