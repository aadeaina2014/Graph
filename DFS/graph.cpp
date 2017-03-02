/**
 *@ brief API
 *
 *@ filename Graph.cpp
 *@ Author 
 *@ Date February 25,2017
 *@
 */


#include  "graph.h"

Object Graph::Vertext::operator*() {
      	
    // Return the element associated with u.
    return x;
}


EdgeList Graph::Vertex::incidentEdges() {
	
    // Return an edge list of the edges incident on u.
   
}


bool Graph::Vertex::isAdjacentTo(v){

    /*Test whether vertices u and v are adjacent.
    Each Edge object e supports the following
    operations, which provide access to the edge
    end vertices and information regarding the
    edge incidence relationships */
}

object Graph::Edge::operator*() {
  	
    // Return the element associated with e
    return y;
}

	
VetexList Graph::Edge::endVertices() {
       
    // Return a vertex list containing e end vertices.

}

Vertex Graph::Edge::opposite(v) {

    /*Return the end vertex of edge e distinct
      from vertex v; an error occurs if e is not
      incident on v. */
}

bool Graph::Edge::isAdjacentTo(f) {
	// Test whether edges e and f are adjacent.


}

bool Graph::Edge::isIncidentOn(v) {
	// Test whether e is incident on v.

}




    /*Finally, the full graph ADTconsists of the following operations,
    which provide access to the lists of vertices and edges, and
    provide functions for modifying the graph. */


VertextList Graph::vertices() { 
	
	//: Return a vertex list of all the vertices of the graph.
}

EdgeList Graph::edges() {
	
	//: Return an edge list of all the edges of the graph.
}

Object Graph::insertVertex(x){

	
	// Insert and return a new vertex storing element x.
}

Object Graph::insertEdge(v,w,x): {
	
	//Insert and return anew undirected edge withend 
	//vertices v and w and storing element x.
}

void Graph::eraseVertex(v) {

	// Remove vertex v and all its incident edges.

}


void Graph::eraseEdge(e){
       
       	//: Remove edge e.
}

