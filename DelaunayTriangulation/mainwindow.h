#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <iterator>
#include <algorithm>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

#include "vector2.h"
#include "triangle.h"
#include "delaunay.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
        void on_buildMeshButton_clicked();
        void mousePressEvent(QMouseEvent * e);


        void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    std::vector<Vec2f> points;
    void drawPoints();
};

#endif // MAINWINDOW_H
