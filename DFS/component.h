#ifndef COMPOENT_H_
#define COMPOENT_H_

#include "dfs.h"
template <typename G>
    class Components : public DFS<G> {			// count components
        private:
            int nComponents;					// num of components
        public:
            Components(const G& g): DFS<G>(g) {}		// constructor
           int operator()();					// count components
  };



template <typename G>					// count components
    int Components<G>::operator()() {
    initialize();					// initialize DFS
    nComponents = 0;					// init vertex count
    VertexList verts = graph.vertices();
    for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv) {
        if (!isVisited(*pv)) {				// not yet visited?
            dfsTraversal(*pv);				// visit
            nComponents++;					// one more component
      }
    }
    return nComponents;
  }
#endif