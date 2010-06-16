#include "zzgraphicscell.h"
#include <QDebug>

void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{/*
    qDebug() << "Painting" << endl;
    QRectF lowBox = childrenBoundingRect();
    painter->fillRect(QRectF(lowBox.left(), lowBox.top(), lowBox.width(), lowBox.height()), QColor(0, 0, 255, 255));
    //switch me->getType()) {
    //	case 0: // text*/
    //		painter->drawText(lowBox, 0, (*me).getContent());
	//	break;
    //} */

}

void paintCellsXBar(ZZGraphicsCell* cursor) {
	ZZGraphicsCell* posx=(new ZZGraphicsCell(&world[cursor->getMe()->getPos("dx")], cursor->scene(), (qreal)10, (QGraphicsItem*)cursor));
	ZZGraphicsCell* posy=(new ZZGraphicsCell(&world[cursor->getMe()->getPos("dy")], cursor->scene(), (qreal)10, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negx=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg("dx")], cursor->scene(), (qreal)10, (QGraphicsItem*)cursor));
	ZZGraphicsCell* negy=(new ZZGraphicsCell(&world[cursor->getMe()->getNeg("dy")], cursor->scene(), (qreal)10, (QGraphicsItem*)cursor));
	negx->myPaint(negx->scene(), 0, 200);
	negy->myPaint(negy->scene(), 200, 0);
	posx->myPaint(posx->scene(), 450, 200);
	posy->myPaint(posy->scene(), 200, 450);
	cursor->myPaint(cursor->scene(), 200, 200);
}
