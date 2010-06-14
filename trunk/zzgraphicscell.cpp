#include "zzgraphicscell.h"

void ZZGraphicsCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF lowBox = childrenBoundingRect();
    painter.drawRect(QRectF(lowBox.left(), lowBox.top(), lowBox.width(), lowBox.height()));
}
