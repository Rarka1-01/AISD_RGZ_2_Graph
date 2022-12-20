#ifndef AISD_RGZ_2_QUESTG_H
#define AISD_RGZ_2_QUESTG_H

#include "headers.h"
#include <set>
#include "Graph.h"

template<class E, class V, typename K>
class QuestG{
public:

    QuestG(Graph<E, V> g, K key, int d){
        this->g = g;
        this->solve(key, d);
        this->key = key;
        this->d = d;
    }

    QuestG(QuestG& q){
        this->g = q.g;
        this->sl = q.sl;
        this->key = q.key;
        this->d = q.d;
    }

    void setGraph(Graph<E, V> g, K key, int d){
        this->g = g;
        this->key = key;
        this->d = d;
        this->restart();
    }

    void restart(){
        this->g.setAllVisitFalse();
        this->solve(this->key, this->d);
    }

    void result(){

        for(auto i: this->sl)
            cout << i << " ";
        cout << endl;
    }

    void setKeyAndD(K key, int d){
        this->key = key;
        this->d = d;
    }

private:
    Graph<E, V> g;
    vector<K> sl;

    K key;
    int d;

    void solve(K key, int d){

        vector<K> nextKeys;
        set<K> tmp;
        nextKeys.push_back(key);

        this->g.setVisitByKeyVertex(true, key);

        for(int i = 0; i < d; i++){

            while(!nextKeys.empty()) {
                auto ed = this->g.getEdgesByKeyVertex(nextKeys[nextKeys.size() - 1]);

                for(auto ai: ed)
                    if(ai->getFirst()->getKey() == nextKeys[nextKeys.size() - 1])
                        tmp.insert(ai->getSecond()->getKey());
                    else
                        tmp.insert(ai->getFirst()->getKey());

                nextKeys.pop_back();
            }

            for(auto ai: tmp)
                nextKeys.push_back(ai);

            tmp.clear();
        }

        this->sl.clear();

        for(auto i: nextKeys)
            this->sl.push_back(i);

    }
};

#endif //AISD_RGZ_2_QUESTG_H
