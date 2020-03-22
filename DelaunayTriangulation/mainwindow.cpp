#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //scene->setSceneRect(-100, -100, 100, 100);
    //QPen blackPen(Qt::black);
    //blackPen.setWidth(2);
    //scene->addLine(-400, 50, 0, 50, blackPen);
    //scene->addLine(0, 100, 100, 100, blackPen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    QPointF pt = ui->graphicsView->mapToScene(e->pos());
    int pointX = round(pt.x());
    int pointY = round(pt.y());
    if(e->pos().x() < ui->graphicsView->width() && e->pos().y() < ui->graphicsView->height()) {
        points.push_back(Vec2f(pointX-15, pointY-25));
        drawPoints();
        ui->pointsNumberLine->clear();
        ui->trianglesNumberLine->clear();
        //qDebug()<<"Mouse: "<<pt.x()<<" "<<pt.y();
    }
}

void MainWindow::drawPoints()
{
    scene->clear();
    ui->graphicsView->update();
    int pointWidth = 5;
    QPen bluePen(Qt::blue);
    QBrush blueBrush(Qt::blue);
    for(auto p = begin(points); p != end(points); p++) {
        int pointX = round(p->x)-0.5*pointWidth;
        int pointY = round(p->y)-0.5*pointWidth;
        scene->addRect(pointX, pointY, pointWidth, pointWidth, bluePen, blueBrush);
    }
}

void MainWindow::on_buildMeshButton_clicked()
{
    Delaunay triangulation;
    std::vector<Triangle> triangles = triangulation.triangulate(points);
    std::vector<Edge> edges = triangulation.getEdges();
    ui->pointsNumberLine->setText(QString::number(points.size()));
    ui->trianglesNumberLine->setText(QString::number(triangles.size()));
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    for(auto e = begin(edges); e != end(edges); e++) {
        scene->addLine(e->p1.x, e->p1.y, e->p2.x, e->p2.y, blackPen);
    }
}

void MainWindow::on_clearButton_clicked()
{
    scene->clear();
    ui->graphicsView->update();
    points.erase(points.begin(), points.end());
    ui->pointsNumberLine->clear();
    ui->trianglesNumberLine->clear();
}
