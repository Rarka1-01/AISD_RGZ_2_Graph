#include "./lib/headers.h"
#include "./lib/QuestG.h"

Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> createGraphFirst(){
    vector<Vertex<int, int> *> ver;

    for(int i = 0; i < 10; i++)
        ver.push_back(new Vertex<int, int>(i, -1));

    vector<Edge<int, int, Vertex<int, int>>* > edg;

    for(int i = 0; i < 12; i++)
        edg.push_back(new Edge<int, int, Vertex<int, int>>(1, 1));

    edg[0]->setFirstAndSecond(ver[0], ver[1]);
    edg[1]->setFirstAndSecond(ver[1], ver[2]);
    edg[2]->setFirstAndSecond(ver[1], ver[3]);
    edg[3]->setFirstAndSecond(ver[1], ver[4]);
    edg[4]->setFirstAndSecond(ver[3], ver[5]);
    edg[5]->setFirstAndSecond(ver[3], ver[6]);
    edg[6]->setFirstAndSecond(ver[5], ver[6]);
    edg[7]->setFirstAndSecond(ver[4], ver[6]);
    edg[8]->setFirstAndSecond(ver[4], ver[7]);
    edg[9]->setFirstAndSecond(ver[6], ver[7]);
    edg[10]->setFirstAndSecond(ver[7], ver[8]);
    edg[11]->setFirstAndSecond(ver[8], ver[9]);

    Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> gr;
    gr.setVertexes(ver);
    gr.setEdges(edg);

    return gr;
}

Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> createGraphSecond(){
    vector<Vertex<int, int> *> ver;

    for(int i = 0; i < 8; i++)
        ver.push_back(new Vertex<int, int>(i, -1));

    vector<Edge<int, int, Vertex<int, int>>* > edg;

    for(int i = 0; i < 7; i++)
        edg.push_back(new Edge<int, int, Vertex<int, int>>(1, 1));

    edg[0]->setFirstAndSecond(ver[0], ver[5]);
    edg[1]->setFirstAndSecond(ver[5], ver[6]);
    edg[2]->setFirstAndSecond(ver[6], ver[7]);
    edg[3]->setFirstAndSecond(ver[7], ver[4]);
    edg[4]->setFirstAndSecond(ver[4], ver[3]);
    edg[5]->setFirstAndSecond(ver[3], ver[2]);
    edg[6]->setFirstAndSecond(ver[2], ver[1]);

    Graph<Edge<int,int,Vertex<int, int>>, Vertex<int, int>> gr;
    gr.setVertexes(ver);
    gr.setEdges(edg);

    return gr;
}

int main() {

    auto gr = createGraphFirst();
    auto gr1 = createGraphSecond();
    QuestG<Edge<int,int,Vertex<int, int>>, Vertex<int, int>, int> q(gr, 7, 3);

    q.result();

    q.setGraph(gr, 4, 2);

    q.result();
    q.setKeyAndD(1, 1);
    q.restart();
    q.result();

    return 0;
}
