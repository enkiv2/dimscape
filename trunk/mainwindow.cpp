#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsSimpleTextItem>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->zzViewWidget->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::loadFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Load ZigZag datafile"),
                                                    QDir::currentPath(), tr("ZigZag files (*.zz);;Any (*)"));
    if (!fileName.isEmpty())
    {
        QGraphicsSimpleTextItem* txt;
        scene->addRect(0, 0, 250, 200, QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,100,100), Qt::SolidPattern));
        scene->addRect(0, 260, 250, 200, QPen(QColor::fromRgb(255,255,255)), QBrush(QColor(0,100,100), Qt::SolidPattern));
        txt = scene->addSimpleText(fileName,QFont("Times", 12, QFont::Normal));
        txt->setPos(0, 520);
    }
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
