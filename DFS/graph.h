/**
 * @brief API 
 *
 *
 * @filename graph.h
 * @Author  Ayokunle Ade-Aina  
 * @date
 *
 */




/**
* @brief API Vertex
*@operator*() 
*  Return the element associated with u.
*@method incidentEdges
*  Return an edge list of the edges incident on u.
*@method isAdjacentTo(v) 
*  Test whether vertices u and v are adjacent.
*  Each Edge object e supports the following
*  operations, which provide access to the edge
*  end vertices and information regarding the
*  edge incidence relationships 
*/


/**
*@brief API Edge 
*@method operator*() 
* Return the element associated with e
*@method endVertices()  
* Return a vertex list containing e end vertices.
@method opposite(v)
* Return the end vertex of edge e distinct
* from vertex v; an error occurs if e is not
* incident on v. 
@method isAdjacentTo(f): 
* Test whether edges e and f are adjacent.
@method isIncidentOn(v)
* Test whether e is incident on v
*/

/**
*@ brief API Graph
*    Finally, the full graph ADTconsists of the following operations,
*    which provide access to the lists of vertices and edges, and
*    provide functions for modifying the graph. 
*
*
*@method vertices(): 
* Return a vertex list of all the vertices of the graph.
*@method edges() 
* Return an edge list of all the edges of the graph.
*@method insertVertex(x): 
* Insert and return a new vertex storing element x.
*@method insertEdge(v,w,x):
* Insert and return anew undirected edge withend
* vertices v and w and storing element x.
*@method eraseVertex(v): 
* Remove vertex v and all its incident edges.
* eraseEdge(e): 
* Remove edge e.
*/

#ifndef GRAPH_H_
#define GRAPH_H_


#include <list>


class Graph {

    public:
	class Vertex;
	class Edge;
        typedef std::list <Vertex> VertexList;
	typedef std::list <Edge> EdgeList;
        typedef std::list <Vertex>::iterator VertexIterator;
        typedef std::list <Edge>::iterator EdgeIterator;

    class Vertext {
	public:    
            object operator*()   
            EdgeList incidentEdges() ; 
            bool isAdjacentTo(v);  
	private:
	    object x;
    };


    class Edge {
	public:
            object operator*()   
            VertexList endVertices()  
            Vertex opposite(v)
            bool isAdjacentTo(f) ; 
            bool isIncidentOn(v);  
        private:
            object x;

    };

    public :
 
    VertexList vertices() ; 
    EdgeList edges()   ;
    void insertVertex(x) ;  
    void insertEdge(v,w,x) ;  
    void eraseVertex(v)  ; 
    void eraseEdge(e) ;
    
    private : 
       VertexList listOfVertices;
       EdgeList   listOfEdges;
};


#endif
