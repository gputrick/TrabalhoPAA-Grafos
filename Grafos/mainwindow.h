#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "graph.h"
#include "vertex.h"
#include "Algorithms/prim.h"
#include "Algorithms/deepfirstsearch.h"
#include "Algorithms/breadthfirstsearch.h"
#include "Algorithms/topologicalsort.h"
#include "Algorithms/dijkstra.h"

#include <QRect>
#include <QDesktopWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    void showGraph ( Graph * );
    Ui::MainWindow *ui;
    Graph *graph, *tmp;
    Prim *prim;
    DeepFirstSearch *DFS;
    BreadthFirstSearch *BFS;
    TopologicalSort *topologicalSort;
    Dijkstra *dijkstra;

    enum Algorithm {DEEPFIRSTSEARCH, BREADTHFIRSTSEARCH, TOPOLOGICALSORT, DIJKSTRA, PRIM, KRUSKAL, FORDFULKERSON};

protected:
    virtual void paintEvent(QPaintEvent *);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_triggered();
    void on_actionSair_triggered();
    void on_pushButton_clicked();

public slots:
    void repaint();
    void finished();
};

#endif // MAINWINDOW_H
