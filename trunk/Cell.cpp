#include <Cell.h>

Cell::Cell() { // default constructor
	content="";
	type=0;
	id=-1;
}

void Cell::setContent(char* cont) {
	content=content;
}

char* Cell::getContent() {
	return (char*)content.c_str();
}

void Cell::setNeg(cellID neg, string dimension) {
        negward[dimension]=neg;
}


void Cell::setPos(cellID pos, string dimension) {
	posward[dimension]=pos;
	world[pos].setNeg(getID(), dimension);
}

cellID Cell::getPos(string dimension) {
	return posward[dimension];
}


cellID Cell::getNeg(string dimension) {
	return negward[dimension];
}

void Cell::setType(int typ) {
	type=typ;
}

int Cell::getType() {
	return type;
}

cellID Cell::getID() {
	return id;
}

void Cell::setID(cellID myId) {
	if(id<0) { // cell IDs should be immutable.
		id=myId;
	}
}

