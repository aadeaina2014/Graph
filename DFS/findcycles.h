

/**
*@brief API for finding cycles in depth first search
* to prevent going back in 
* previously traversed direction
*
*
*@filename findcycles.h
*@author Ayokunle Ade-Aina
*@Date February 25,2017
*
*
*/


#ifdef FIND_CYCLES_H_
#define FIND_CYCLES_H_



template <typename G>
class FindCycle : public DFS<G> {
    private: 						// local data
        EdgeList cycle;					// cycle storage
        Vertex cycleStart;				// start of cycle
        bool done;					// cycle detected?
    protected: 						// overridden functions
        void traverseDiscovery(const Edge& e, const Vertex& from);
        void traverseBack(const Edge& e, const Vertex& from);
        void finishVisit(const Vertex& v);	 	// finished with vertex
        bool isDone() const;		 		// done yet?
    public:
        FindCycle(const G& g) : DFS<G>(g) {}		// constructor
        EdgeList operator()(const Vertex& s);		// find a cycle
};



template <typename G>					// discovery edge e
void FindCycle<G>::traverseDiscovery(const Edge& e, const Vertex& from) {
    if (!done) cycle.push_back(e); 
}			// add edge to list

template <typename G>					// back edge e
void FindCycle<G>::traverseBack(const Edge& e, const Vertex& from) {
    if (!done) {					// no cycle yet?
      done = true;					// cycle now detected
      cycle.push_back(e);				// insert final edge
      cycleStart = e.opposite(from);			// save starting vertex
    }
}

template <typename G> 				// finished with vertex
    void FindCycle<G>::finishVisit(const Vertex& v) {
        if (!cycle.empty() && !done)			// not building a cycle?
            cycle.pop_back();					// remove this edge
}


template <typename G> 				// done yet?
    bool FindCycle<G>::isDone() const {
        return done; 
}


template <typename G>					// find a cycle
typename FindCycle<G>::EdgeList FindCycle<G>::operator()(const Vertex& s) {
    initialize();					// initialize DFS
    cycle = EdgeList();  done = false;			// initialize members
    dfsTraversal(s);					// do the search
    if (!cycle.empty() && s != cycleStart) {		// found a cycle?
        EdgeItor pe = cycle.begin();
        while (pe != cycle.end()) {			// search for prefix
            if ((pe++)->isIncidentOn(cycleStart)) break;	// last edge of prefix?
        }
        cycle.erase(cycle.begin(), pe);			// remove prefix
    }
    return cycle;					// return the cycle
}

#endif

