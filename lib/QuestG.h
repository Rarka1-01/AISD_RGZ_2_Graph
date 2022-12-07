#ifndef AISD_RGZ_2_QUESTG_H
#define AISD_RGZ_2_QUESTG_H

#include "headers.h"
#include "Graph.h"

class QuestG{
public:

    QuestG(QuestG& T);

    QuestG(Graph g);

    void restart();

    void result();
private:

    void solv();

    Graph g;

};

#endif //AISD_RGZ_2_QUESTG_H
