#ifndef AISD_RGZ_2_NODE_H
#define AISD_RGZ_2_NODE_H

#include "headers.h"

class Node{
public:

    Node(int index);

private:
    int index;
    int l_p = 0;
    int l_k = 0;
    Node* parents;
    Node* kids;
};

#endif //AISD_RGZ_2_NODE_H
