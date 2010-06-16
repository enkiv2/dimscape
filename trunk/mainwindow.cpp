#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsSimpleTextItem>
#include <QFileDialog>
#include "zzgraphicscell.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF(0, 0, 800, 600));
    ui->zzViewWidget->fitInView(scene->sceneRect());
    ui->zzViewWidget->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::newWorld()
{
	qDebug() << QString("Hello new world!") << endl;
	world.insert(1, *(new ZZCell()));
	world[1].setID(1);
	world[1].setContent(*(new QString("Press i to edit me!")));
	ZZGraphicsCell* foo=new ZZGraphicsCell(&(world[1]), scene, (qreal)5, (QGraphicsItem*)0);
	scene->addItem(foo);
	foo->setZValue(2);
	scene->update();
        foo->update();
	ui->zzViewWidget->show();
	cursorID=1;
	//foo->myPaint(scene, 200, 200);
	paintLoop(foo);
}

void MainWindow::loadFile()
{
    // TODO: take this out entirely
/*
    QString fileName = QFileDialog::getOpenFileName(this,tr("Load ZigZag datafile"),
                                                    QDir::currentPath(), tr("ZigZag files (*.zz);;Any (*)"));
    if (!fileName.isEmpty())
    {
        QGraphicsSimpleTextItem* txt;
        scene->addRect(0, 0, 250, 200, QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,100,100), Qt::SolidPattern));
        scene->addRect(0, 260, 250, 200, QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,100,100), Qt::SolidPattern));
        txt = scene->addSimpleText(fileName);
        txt->setPos(0, 520);
    }*/
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
    	break;
    }
}
