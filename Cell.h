/* dscell.h - headers for the zz cell
 * (c) 2010 John Ohno
 * Licensed under the GNU GPL v.3
 * Part of the DimScape project
 */

#ifndef ZZCELL_H
#define ZZCELL_H

#include <QHash>
#include <QString>
#include <Qt/qhash.h>
#include <Qt/qstring.h>

#define cellID qint64


class ZZCell : public QObject {
	Q_OBJECT
	
	public:
	ZZCell();
	ZZCell(const ZZCell& simulacrum);
	QString getContent();
	cellID getPos(QString& dimension);
	cellID getNeg(QString& dimension);
	int getType();
	cellID getID();
	void setID(cellID myId);
	QList<QString> getDims();

	ZZCell& operator=(const ZZCell& simulacrum) {
		 id=((ZZCell&)simulacrum).getID();
		 content=((ZZCell&)simulacrum).getContent();
		 type=((ZZCell&)simulacrum).getType();
		 QList<QString> temp=((ZZCell&)simulacrum).getDims();
		 for( int i=0; i < temp.size(); i++ ) {
	                 setPos(((ZZCell&)simulacrum).getPos((QString&)temp.at(i)), (QString&)temp.at(i));
	                 setNeg(((ZZCell&)simulacrum).getNeg((QString&)temp.at(i)), (QString&)temp.at(i));
	         }
		 return *this;
	}

	public slots:
	void setContent(QString& cont);
	void setPos(cellID pos, QString& dimension);
	void setNeg(cellID neg, QString& dimension);
	void setType(int type);

	signals:

	void contentChanged(QString& content);
	void poswardChanged(cellID pos, QString& dimension);
	void negwardChanged(cellID neg, QString& dimension);
	void typeChanged(int type);

	protected:
	QString content;
	QHash<QString,cellID> posward;
	QHash<QString,cellID> negward;
	int type;
	cellID id;

};

#ifndef ZZWORLD
#define ZZWORLD
extern QHash<cellID,ZZCell> world; /* this should include all cells */
#endif

#endif

