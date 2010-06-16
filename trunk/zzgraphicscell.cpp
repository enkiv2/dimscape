#include "zzgraphicscell.h"
#include <QDebug>

void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "Painting" << endl;
    QRectF lowBox = childrenBoundingRect();
    painter->fillRect(QRectF(lowBox.left(), lowBox.top(), lowBox.width(), lowBox.height()), QColor(0, 0, 255, 255));
    /*switch me->getType()) {
    	case 0: // text*/
    		painter->drawText(lowBox, 0, (*me).getContent());
	//	break;
    //}

}

