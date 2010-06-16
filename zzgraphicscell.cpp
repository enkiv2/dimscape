#define ZZCURRDIMS
#include "zzgraphicscell.h"
#include <QDebug>

QString dx, dy, dz;
cellID cursorID;

void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	/* Not used. Use myPaint instead */
}

void paintCellsXBar(ZZGraphicsCell* cursor) {
	ZZGraphicsCell* posx=(new ZZGraphicsCell(&world[cursor->getMe()->getPos(dx)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* posy=(new ZZGraphicsCell(&world[cursor->getMe()->getPos(dy)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negx=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg(dx)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negy=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg(dy)], cursor->scene(), (qreal)5, (QGraphicsItem*)cursor));
	QRectF sr=cursor->scene()->sceneRect();
	negx->myPaint(negx->scene(), sr.left(), sr.height()/2);
	negy->myPaint(negy->scene(), sr.width()/2, sr.top());
	posx->myPaint(posx->scene(), (sr.width()*3)/4, sr.height()/2);
	posy->myPaint(posy->scene(), (sr.width()/2), (sr.height()*3)/4);
	cursor->myPaint(cursor->scene(), sr.width()/2, sr.height()/2, true);
}
