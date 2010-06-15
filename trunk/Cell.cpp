#include <Cell.h>


ZZCell::ZZCell(const ZZCell& simulacrum) {
	id=((ZZCell&)simulacrum).getID();
	content=((ZZCell&)simulacrum).getContent();
	type=((ZZCell&)simulacrum).getType();
	QList<QString> temp=((ZZCell&)simulacrum).getDims();
	for( int i=0; i < temp.size(); i++ ) {
		setPos(((ZZCell&)simulacrum).getPos((QString&)temp.at(i)), (QString&)temp.at(i));
		setNeg(((ZZCell&)simulacrum).getNeg((QString&)temp.at(i)), (QString&)temp.at(i));
	}
}

QList<QString> ZZCell::getDims() {
	return posward.keys();
}

ZZCell::ZZCell() { // default constructor
	content="";
	type=0;
	id=-1; /* if this is -1 then the cell is uninitialized. This is very useful for transparency with the database */
}

void ZZCell::setContent(QString& cont) {
	// a bit dangerous not having a guard here
	// due to potential cyclical slot/signal signal/slot
	// but, a full-text comparison check seems a bit much,
	// maybe for a debug build
	content=cont;
	emit contentChanged(cont);
}

QString ZZCell::getContent() {
	// the callee gets a copy
	return QString(content);
}

void ZZCell::setNeg(cellID neg, QString& dimension) {
	if (!negward.contains(dimension))
	{
        	negward.insert(dimension, neg);
		emit negwardChanged(neg, dimension);
	}
}


void ZZCell::setPos(cellID pos, QString& dimension) {
	if (!posward.contains(dimension))
	{
		posward.insert(dimension, pos);
		((ZZCell&)world.value(pos)).setNeg(id, dimension);
		emit poswardChanged(pos, dimension);
	}
}

cellID ZZCell::getPos(QString& dimension) {
	return posward.value(dimension);
}


cellID ZZCell::getNeg(QString& dimension) {
	return negward.value(dimension);
}

void ZZCell::setType(int typ) {
	if (type != typ)
	{
		type=typ;
		emit typeChanged(typ);
	}
}

int ZZCell::getType() {
	return type;
}

cellID ZZCell::getID() {
	return id;
}

void ZZCell::setID(cellID myId) {
	if(id<0) { // cell IDs should be immutable.
		id=myId;
	}
}

