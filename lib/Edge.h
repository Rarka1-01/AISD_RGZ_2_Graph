#ifndef AISD_RGZ_2_EDGE_H
#define AISD_RGZ_2_EDGE_H

#include "headers.h"
#include "Vertex.h"

template<typename W, typename V, class Vertex>
class Edge{
public:

    Edge(W weight, V value){
        this->weight = weight;
        this->value = value;

        this->first = nullptr;
        this->second = nullptr;
    }

    ~Edge(){
        if(this->first != nullptr)
            delete this->first;

        if(this->second != nullptr)
            delete this->second;
    }


    void setFirst(Vertex *first){
        if(this->first != nullptr)
        {
            delete this->first;
            this->first = nullptr;
        }

        this->first = first;
    }

    void setSecond(Vertex *second){
        if(this->first != nullptr)
        {
            delete this->second;
            this->second = nullptr;
        }

        this->second = second;
    }

    void setFirstAndSecond(Vertex *first, Vertex *second){
        this->setFirst(first);
        this->setSecond(second);
    }

    Vertex* getFirst(){
        return this->first;
    }

    Vertex* getSecond() {
        return this->second;
    }

private:
    W weight;
    V value;

    Vertex* first;
    Vertex* second;
};

#endif //AISD_RGZ_2_EDGE_H
