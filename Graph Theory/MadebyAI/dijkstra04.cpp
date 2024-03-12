#include <QtWidgets>

class GraphWidget : public QGraphicsView {
public:
    GraphWidget(QWidget* parent = nullptr) : QGraphicsView(parent) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    void addNode(int id, const QPointF& position) {
        QGraphicsEllipseItem* node = scene->addEllipse(-10, -10, 20, 20);
        node->setPos(position);
        node->setBrush(Qt::blue);

        QGraphicsTextItem* text = scene->addText(QString::number(id));
        text->setPos(position.x() - 5, position.y() - 5);

        nodes[id] = node;
    }

    void addEdge(int source, int target, int weight) {
        QGraphicsLineItem* edge = scene->addLine(nodes[source]->pos().x(), nodes[source]->pos().y(),
                                                 nodes[target]->pos().x(), nodes[target]->pos().y());
        edges.push_back(edge);

        QGraphicsTextItem* text = scene->addText(QString::number(weight));
        text->setPos((nodes[source]->pos().x() + nodes[target]->pos().x()) / 2,
                     (nodes[source]->pos().y() + nodes[target]->pos().y()) / 2);
        edgeLabels.push_back(text);
    }

private:
    QGraphicsScene* scene;
    QMap<int, QGraphicsEllipseItem*> nodes;
    QList<QGraphicsLineItem*> edges;
    QList<QGraphicsTextItem*> edgeLabels;
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QMainWindow window;
    GraphWidget* graphWidget = new GraphWidget(&window);

    // Add nodes
    graphWidget->addNode(0, QPointF(50, 50));
    graphWidget->addNode(1, QPointF(150, 50));
    graphWidget->addNode(2, QPointF(100, 150));

    // Add edges
    graphWidget->addEdge(0, 1, 5);
    graphWidget->addEdge(1, 2, 3);
    graphWidget->addEdge(2, 0, 2);

    window.setCentralWidget(graphWidget);
    window.show();

    return app.exec();
}