#ifndef CELL_H
#define CELL_H

using namespace std;
#include <map>
#include <string>

#define cellID int

class Cell {
	public:
	Cell();
	void setContent(char* cont);
	char* getContent();
	void setPos(cellID pos, string dimension);
	cellID getPos(string dimension);
	void setNeg(cellID neg, string dimension);
	cellID getNeg(string dimension);
	void setType(int type);
	int getType();
	cellID getID();
	void setID(cellID myId);
	protected:
	string content;
	map<string,cellID> posward;
	map<string,cellID> negward;
	int type;
	cellID id;
};

#ifndef ZZWORLD
#define ZZWORLD
map<cellID,Cell> world; 
#endif

#endif

