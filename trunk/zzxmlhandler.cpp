#include "zzxmlhandler.h"

ZZXmlHandler::ZZXmlHandler(QObject *parent) :
    QXmlHandler(parent)
{
    leaf = NONE;
}

ZZXmlHandler::ZZXmlHandler(ZZSpace* aSpace) :
        space(aSpace)
{
    leaf = NONE;
}

bool ZZXmlHandler::characters(const QString &ch)
{
    switch (leaf)
    {
        case CONTENT:
           space->getCell(parseCell).setContent(ch);
           break;
        case NEG:
           space->getCell(parseCell).setNeg(parseDim, ch);
           break;
        case POS:
           space->getCell(parseCell).setPos(parseDim, ch);
           break;
    }
    return true
}

bool ZZXmlHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if (localName == "zzspace")
    {
        version = atts.value(QString(""), QString("version")).toInt();
    } else if (localName == "cells")
    {
        space->setCurrentCell(atts.value(QString(""), QString("current")))
    } else if (localName == "cell")
    {
        parseCell = atts.value(QString(""), QString("id"));
        space->createCell(parseCell);
    } else if (localName == "connection")
    {
        parseDim = atts.value(QString(""), QString("dim"));
    } else if (localName == "neg")
    {
        leaf = NEG;
    } else if (localName == "pos")
    {
        leaf = POS;
    } else if (localName == "content")
    {
        leaf = CONTENT;
    } else if (localName == "dims")
    {
        space->setDim1(atts.value(QString(""), QString("d1")));
        space->setDim2(atts.value(QString(""), QString("d2")));
        space->setDim3(atts.value(QString(""), QString("d3")));
    } else if (localName == "dim")
    {
        // nothing at the moment
    }
    return true;
}

bool ZZXmlHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    if (NONE != leaf)
    {
        leaf = NONE;
    }
    return true;
}
