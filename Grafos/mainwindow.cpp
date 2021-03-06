#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Algorithms/breadthfirstsearch.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    //Posicina no centro do monitor
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);

    QMainWindow::paintEvent(new QPaintEvent(this->geometry()));
    this->graph = this->tmp = NULL;
    //connect( this, SIGNAL (mostrar(Grafo * )), this, SLOT(mostrarGrafo(Grafo*)) );
}

void MainWindow::paintEvent(QPaintEvent *) {
    if (this->tmp==NULL) return;

    QPainter painter(this);
    painter.setPen(Qt::SolidLine);

    Vertex **vertex = tmp->getVertex();
    Vertex *v, *v1, *v2;
    Edge *e;
    int n = tmp->getVertexCount();

    // Pintar primeiramente as arestas
    painter.setPen( Qt::black );
    painter.setPen( Qt::SolidLine );

    for (int i = 0; i < n; i++) {
        e = vertex[i]->getEdge();
        while (e!=NULL) {
            v1 = vertex[e->getSourceID()];
            v2 = vertex[e->getTargetID()];
            painter.drawLine( QPoint (v1->getX(), v1->getY()), QPoint (v2->getX(), v2->getY()) );
            e = e->getNext();
        }
    }

    for (int i = 0; i < n; i++) {
        v = vertex[i];
        painter.setBrush ( v->getColor() );
        painter.setPen( (v->getColor() == Qt::white)? Qt::black : Qt::white );
        painter.drawEllipse( v->getX()-20,  v->getY()-20, 40, 40 );
        QRect r1 ( v->getX()-4,  v->getY()-8, v->getX()+4,  v->getY()+8 );
        painter.drawText( r1, v->getName() );
    }
}

void MainWindow::showGraph(Graph *g){
    this->tmp = g;
    update ();
}

void MainWindow::on_actionLoad_triggered() {
    QDir::setCurrent("../files");
    qDebug() << QDir::currentPath();
    QString filename =  QFileDialog::getOpenFileName( this, tr("Open Document"),
                                                     QDir::currentPath(),
                                                     tr("Document files (*.txt);;All files (*.*)"), 0,
                                                     QFileDialog::DontUseNativeDialog );
    if( !filename.isNull() ) {
        qDebug() << filename;

        QFile file( filename );
        if(!file.open(QIODevice::ReadOnly)) {
            qDebug() << "error " << file.errorString();
            QMessageBox::critical(this, "Lendo arquivo", "Erro na leitura do arquivo selecionado");
            return;
        }
        QTextStream in(&file);
        QString line;
        QStringList sl;

        if (graph != NULL){
            delete graph;
        }

        line = in.readLine();     // n�mero de v�rtices
        graph = new Graph ( line.toInt(), this );

        ui->cbOrigem->clear();
        ui->cbFinal->clear();

        bool loadvertex = true;
        while(!in.atEnd() && loadvertex) {
            line = in.readLine();
            if (line.length() > 0 && line.at(0) != '(') {
                //line = 1,100,100 ==> nome v�rtice, coordenada x, coordenada y
                sl = line.split(",");
                if (sl.count() == 3) {
                    graph->add( sl[0], sl[1].toInt(), sl[2].toInt() );
                    ui->cbOrigem->addItem( sl[0] );
                    ui->cbFinal->addItem( sl[0] );
                } else {
                    QMessageBox::critical(this,"Carregar v�rtices", "Erro na estrutura do arquivo - n�s [node, coord. x, coord. y]!");
                    return;
                }
            } else
                loadvertex = false;
        }
        if (!in.atEnd()) {
            do {
                // line = (1,2,5)
                line = line.mid(1, line.length() -2 );

                // line = 1,2,5
                //qDebug() << line;
                sl = line.split(",");
                if (sl.count()==3)
                    graph->addEdge(sl[0], sl[1], sl[2].toInt() );
                else {
                    QMessageBox::critical(this,"Carregar arestas", "Erro na estrutura do arquivo - n�s [node, coord. x, coord. y]!");
                    return;
                }

                line = in.readLine();
            } while(!in.atEnd());
        }

        qDebug() << "Carregado com sucesso!";
        file.close();

        this->showGraph(graph);
    }
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}

MainWindow::~MainWindow() {
    if (graph != NULL)
        delete graph;
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    if(graph != NULL){
        switch (ui->algorithm->currentIndex()) {
        case DEEPFIRSTSEARCH:
            this->DFS = new DeepFirstSearch(ui->cbOrigem->currentIndex(), ui->cbFinal->currentIndex(), this->graph);
            connect(DFS, SIGNAL(repaint()), this, SLOT(repaint()), Qt::QueuedConnection);
            connect(DFS, SIGNAL(finished()), this, SLOT(finished()));
            DFS->start();
            break;
        case BREADTHFIRSTSEARCH:
            this->BFS = new BreadthFirstSearch(ui->cbOrigem->currentIndex(), ui->cbFinal->currentIndex(), this->graph);
            connect(BFS, SIGNAL(repaint()), this, SLOT(repaint()), Qt::QueuedConnection);
            connect(BFS, SIGNAL(finished()), this, SLOT(finished()));
            BFS->start();
            break;
        case TOPOLOGICALSORT:
            this->topologicalSort = new TopologicalSort(ui->cbOrigem->currentIndex(), ui->cbFinal->currentIndex(), this->graph);
            connect(topologicalSort, SIGNAL(repaint()), this, SLOT(repaint()), Qt::QueuedConnection);
            connect(topologicalSort, SIGNAL(finished()), this, SLOT(finished()));
            topologicalSort->start();
            break;
        case DIJKSTRA:
            this->dijkstra = new Dijkstra(ui->cbOrigem->currentIndex(), ui->cbFinal->currentIndex(), this->graph);
            connect(dijkstra, SIGNAL(repaint()), this, SLOT(repaint()), Qt::QueuedConnection);
            connect(dijkstra, SIGNAL(finished()), this, SLOT(finished()));
            dijkstra->start();
            break;
        case PRIM:
            this->prim = new Prim(ui->cbOrigem->currentIndex(), this->graph);
            connect(prim, SIGNAL(repaint()), this, SLOT(repaint()), Qt::QueuedConnection);
            connect(prim, SIGNAL(finished()), this, SLOT(finished()));
            prim->start();
            break;
        case KRUSKAL:
            break;
        case FORDFULKERSON:
            break;
        default:
            break;
        }
    }
}

void MainWindow::repaint()
{
    this->update();
}

void MainWindow::finished()
{
    if(ui->algorithm->currentIndex() == TOPOLOGICALSORT){
        QStringList strList;
        Element<Vertex> *e;

        while(true){
            e = topologicalSort->getQueue()->popBegin();
            if(e == NULL) break;
            strList.append(e->getElement()->getName());
        }

        QString str = "";
        for(int i = 0; i < strList.size() - 1; i++)
            str += strList.at(i) + " - ";
        str += strList.at(strList.size() -1);

        this->ui->path->setText(str);

        return;
    }

    Vertex *vertex = this->graph->getVertex()[ui->cbFinal->currentIndex()];
    QString msg = "";
    int cont = 0;
    while (vertex->getParent() != NULL){
        msg = vertex->getName() + msg;
        msg = " -> " + msg;
        vertex = vertex->getParent();
        cont++;
    }
    msg = this->graph->getVertex()[ui->cbOrigem->currentIndex()]->getName() + msg;
    qDebug() << msg;
    this->ui->path->setText(msg);
}
