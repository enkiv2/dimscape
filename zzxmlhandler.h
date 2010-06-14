#ifndef ZZXMLHANDLER_H
#define ZZXMLHANDLER_H

#include <QXmlDefaultHandler>

#include "zzspace.h"

class ZZXmlHandler : public QXmlDefaultHandler
{
Q_OBJECT
public:

    enum leaf_t { POS, NEG, CONTENT, NONE };

    explicit ZZXmlHandler(QObject *parent = 0);
    explicit ZZXmlHandler(ZZSpace* aSpace = 0);
    bool characters(const QString &ch);
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);

signals:

public slots:

private:
    ZZSpace* space;
    leaf_t leaf;
    QString parseCell;
    QString parseDim;
    int version;


};

#endif // ZZXMLHANDLER_H
