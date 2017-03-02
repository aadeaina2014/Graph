/**
 *@ brief FindPath API
 * this object used depth first search algorithm to find 
 * path from a node s to another node t using graph data 
 * structure
 * 
 *@file name
 *@brief find path API for graphs data structures
 *@author Ayokunle Ade-Aina
 *@date  February 24,2017
*/

#ifndef FINDPATH_H_
#define FINDPATH_H_




template <typename G>
    class FindPath : public DFS<G> {			// find a path by DFS
       private: 						// local data
           VertexList path;					// the path
           Vertex target;					// the target vertex
           bool done;						// is target found?
       protected: 						// overridden functions
           void startVisit(const Vertex& v);			// visit vertex
           void finishVisit(const Vertex& v);			// finished with vertex
           bool isDone() const; 				// done yet?
       public:
           FindPath(const G& g) : DFS<G>(g) {}			// constructor
  	                        				// find path from s to t
           VertexList operator()(const Vertex& s, const Vertex& t);
  };





template <typename G>					// visit vertex
    void FindPath<G>::startVisit(const Vertex& v) {
    path.push_back(v); 					// insert into path
    if (v == target) done = true;			// reached target vertex
    }

template <typename G>					// finished with vertex
void FindPath<G>::finishVisit(const Vertex& v) {
     if (!done) path.pop_back(); 
    }			// remove last vertex


template <typename G> 				// done yet?
bool FindPath<G>::isDone() const {
     return done; 
}


template <typename G> typename FindPath<G>::VertexList //find path from s to t
FindPath<G>::operator()(const Vertex& s, const Vertex& t) {
    initialize();					// initialize DFS
    path.clear();					// clear the path
    target = t;						// save the target
    done = false;
    dfsTraversal(s);					// traverse starting at s
    return path;					// return the path
}


#endif 
