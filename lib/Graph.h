#ifndef AISD_RGZ_2_GRAPH_H
#define AISD_RGZ_2_GRAPH_H

#include "headers.h"
#include "Vertex.h"
#include "Edge.h"
#include <vector>

template<class E, class V>
class Graph{
public:

    Graph(){

    }

    Graph(Graph<E, V> &g){
        this->vertexes.clear();
        this->vertexes = g.vertexes;
        this->edges.clear();
        this->edges = g.edges;
    }

    Graph(int cVer, int cEdg){
        if(cEdg > cVer){

            vector<V*> v;
            vector<E*> e;

            for(int i = 0; i < cVer; i++)
                v.push_back(new V(i, rand() % 10));

            for(int i = 0; i < cEdg; i++){
                e.push_back(new E(rand() % 50 - 25, -1));
                e[i]->setFirstAndSecond(v[int(rand() % cVer)], v[int(rand() % cVer)]);
            }

            this->setEdges(e);
            this->setVertexes(v);
        }
    }

    ~Graph(){
        this->edges.clear();
        this->vertexes.clear();
    }

    vector<V*> getVertexes(){
        return this->vertexes;
    }

    vector<E*> getEdges(){
        return this->edges;
    }

    template<typename K>
    vector<E*> getEdgesByKeyVertex(K key){
        vector<E*> ed;

        for(auto i: this->getEdges())
            if(i->getFirst()->getKey() == key || i->getSecond()->getKey() == key) {

                if((i->getFirst()->getKey() != key && !i->getFirst()->getVisit()) ||
                (i->getSecond()->getKey() != key && !i->getSecond()->getVisit())) {
                    ed.push_back(i);

                    if (i->getFirst()->getKey() == key)
                        i->getSecond()->setVisit(true);
                    else
                        i->getFirst()->setVisit(true);
                }
            }

        return ed;
    }

    void setAllVisitFalse(){
        for(auto i: this->vertexes)
            i->setVisit(false);
    }

    template<typename K>
    void setVisitByKeyVertex(bool visit, K key){

        for(int i = 0; i < this->vertexes.size(); i++)
            if(this->vertexes[i]->getKey() == key){
                this->vertexes[i]->setVisit(visit);
                break;
            }

    }

    void setVertexes(vector<V*> ver){
        this->vertexes.clear();
        this->vertexes = ver;
    }

    void setEdges(vector<E*> ed){
        this->edges.clear();
        this->edges = ed;
    }

private:
    vector<V*> vertexes;
    vector<E*> edges;
};

#endif //AISD_RGZ_2_GRAPH_H
