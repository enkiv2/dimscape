/* dscell.h - headers for the zz cell
 * (c) 2010 John Ohno
 * Licensed under the GNU GPL v.3
 * Part of the DimScape project
 */

#ifndef ZZCELL_H
#define ZZCELL_H

#include <QHash>
#include <QString>

#define cellID qint64


class ZZCell : public QObject {
	Q_OBJECT
	
	public:
	ZZCell();
	QString getContent();
	cellID getPos(QString& dimension);
	cellID getNeg(QString& dimension);
	int getType();
	cellID getID();
	void setID(cellID myId);
	
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
QHash<cellID,Cell> world; /* this should include all cells */
#endif

#endif

