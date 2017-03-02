/****************************************************************************
Florida Institute Of Technology
College of Engineering
Electrical and Computer Engineering Department
Application : Graph Mining Research
Filename : Graph.h  Function : Graph Data Structure Class
File Dependencies : Object.h
*****************************************************************************/
//===========================================================================
//                    MEMO
// Last Update : 4/26/2016 5.00am
// Comments : Class Has not been tested in  main : 
// Comments : Updates to operator* method in vertex class
//===========================================================================

#ifndef GRAPH_H_

#define GRAPH_H_
#include "Object.h"
#include <vector>
#include <map>
#include <list>

using std::vector;
using std::list;


//--------------------------------Decorator Utility Class ------------------------------//

class Decorator {
private:						// member data
	std::map <string, Object*> mapd;			// the map
public:
	Object* get(const string& a)			// get value of attribute
	{
		return mapd[a];
	}
	void set(const string& a, Object* d)		// set value
	{
		mapd[a] = d;
	}
};


//forward declaration of graph class
class Graph;

class Graph
{

public:   //forward declaration of vertex and edge class for typenames
	class Vertex;
	class Edge;

public:  //Name Shortcuts
	typedef list<Vertex> VertexList;
	typedef list<Edge>EdgeList;
	typedef list<Vertex>::iterator VertexItor;
	typedef list<Edge>::iterator EdgeItor;

private: // Graph Attributes
		 	int numNodes;
		 	int vertexCount;
		 	int edgeCount;
		 	VertexList V;
		 	EdgeList   E;
		 	int **adjacencyMatrix;

			friend class Vertex;
			friend class Edge;


public: //Graph Methods
	Graph( const VertexList& vv, const EdgeList& ee);
	
	Vertex insertVertex(const Graph& g, const Vertex& v) const;
	void   insertEdge(const Vertex&v, const Vertex &w, const Decorator& x) const;
	void   eraseVertex(Vertex&v);
	void   eraseEdge(Edge&e);
	~Graph();
public: // Nested Class of Graph : Vertex 

	class Vertex
	{
	private : //Vertex Attributes
		Decorator x;
		EdgeList edges;// incident edges
		int position;
		
	public : // Vertex Methods
		Vertex( Object* data);
		
		Object* operator*();
		void set(const string&a, Object* v);
		Object*get(const string&a);
		EdgeList incidentEdges( Graph &gref);
		bool isAdjacentTo(const Graph& gref, const Vertex&v);
		~Vertex();
	};

public: // Nested class of Graph : Edge

	class Edge
	{
	private: // Edge Attributes
		Decorator x;
		VertexList vertices;// incident edges
		int position;
	public: //  Edge Methods
		Edge(const Vertex u, const Vertex v, Object * data);
		Object* operator*();
		Object* get(const string&a);
		void    set(const string&a, Object*v);
		VertexList endVertices();
		Vertex opposite(const Graph& g, Vertex& v)  throw(NonIncidentEdge);
		bool isAdjacentTo( Edge& e);
		bool isIncidentOn(const Graph& g, Vertex& v);
		~Edge();
	};
};


//------------------------Implemenetation of Vertex Methods-------------------------//

Graph::Vertex::Vertex(Object * data)
{
	x.set("Position", data);
	position = data->intValue();
}

void Graph::Vertex::set(const string&a, Object* v)
{
	x.set(a, v);
}

Object* Graph::Vertex::operator*()
{
	return x.get("Position");
}

Object* Graph::Vertex::get(const string&a)
{
	return x.get(a);
}

bool Graph::Vertex::isAdjacentTo(const Graph& a, const Vertex& v)
{
	Graph gref = a;
	int i = this->position;
	int j = v.position;
	if (gref.adjacencyMatrix[i][j] ==1)
	{
		return true;
	}

	return false;
}

Graph::EdgeList Graph::Vertex::incidentEdges(Graph& gref)
{
	EdgeItor p = gref.E.begin();
	
	for (int j = 0; j < (position*gref.numNodes); j++)
	{
		p++;
	}
	
	for (int i = 0; i < gref.numNodes; i++)
	{
		p++;
		if (gref.adjacencyMatrix[position][i] == 1)
		{	
			edges.push_back(*p);
		}
	}
	return edges;
}
Graph::Vertex::~Vertex()
{}

Graph::Edge::Edge(const Vertex u, const Vertex v, Object * data)
{
	vertices.push_back(u);
	vertices.push_front(v);
	x.set("Weight", data);
	position = data->intValue();
}


Object* Graph::Edge::operator*()
{
	return x.get("position");
}
void Graph::Edge::set(const string& a, Object* v)
{
	x.set(a, v);
}
Object* Graph::Edge::get(const string& a)
{
	return x.get(a);
}

bool Graph::Edge::isIncidentOn(const Graph& g,  Vertex& v)
{
	Vertex a = *  this->vertices.begin();
	Vertex b = *vertices.end();
	Object* oa = a.get("Position");
	Object* ob = b.get("Position");
	Object* oc = v.operator*();
	if (oa->intValue() == oc->intValue())
	{
		return true;
	}

	if (ob->intValue() == oc->intValue())
	{
		return true;
	}else
	{ 
		return false;
	}
	
}


bool Graph::Edge::isAdjacentTo(Edge& e)
{    
	// extract vertices from edge containers
	Vertex a = vertices.front();
	Vertex b = vertices.back();
	Vertex c = e.vertices.front();
	Vertex d = e.vertices.back();
	// extract vertex objects to be compared
	Object* oa = a.get("Position");
	Object* ob = b.get("Position");
	Object* oc = c.get("Position");
	Object* od = d.get("Position");

	//Compara Vertices of each of the edges
	if (oa->intValue() == oc->intValue())
	{
		return true;
    }

	if (oa->intValue() == od->intValue())
	{
		return true;
	}

	if (ob->intValue() == oc->intValue())
	{
		return true;
	}

	if (ob->intValue() == oc->intValue())
	{
		return true;
	}

	return false;
}
Graph::Vertex Graph::Edge::opposite(const Graph& gref,  Vertex& v)  throw(NonIncidentEdge)
{
	if (!isIncidentOn(gref, v)) throw NonIncidentEdge("Non Inicident relation");
	Vertex a = *vertices.begin();
	Vertex b = *vertices.end();
	Object* oa = a.get("Position");
	Object* ob = b.get("Position");
	Object* oc = v.operator*();
	if (oa->intValue() == oc->intValue())
	{
		return *vertices.begin();
	}
	else
	{
		return *vertices.end();
	}
}
Graph::VertexList Graph::Edge::endVertices()
{
	return vertices;
}
Graph::Edge::~Edge()
{}

Graph::Graph(const VertexList& vv, const EdgeList&  ee)
{
	V = vv; //initialize collection of graph Vertices
	E = ee; //initialize collection of graph  edges

	numNodes = V.size();
	
	// Allocate mMemory for Adjacency Matrix
	adjacencyMatrix = new int*[numNodes];

	for (int i = 0; i < numNodes; ++i)
	{
		adjacencyMatrix[i] = new int[numNodes];	//allocate memomry for every row
	}

	
	// Adjacency matrix intialization
	for (int i = 0; i < numNodes; i++)
	{
	    
		for (int j = 0; j < numNodes; j++)
		{
		
		adjacencyMatrix[i][j] = 0;

		}
	}

	Object* v1, *v2;
	EdgeItor e_iter = E.begin();
	for ( e_iter=E.begin() ; e_iter != E.end(); e_iter++)
	{
		Edge e = *e_iter;
		VertexList cur = e.endVertices();
		v1 = cur.front().get("Position");
		v2 = cur.back().get("Position");
		adjacencyMatrix[v1->intValue()][v2->intValue()] = 1;
	}
}

Graph::~Graph()
{

	//for (int i = 0; i < numNodes-1; ++i)
	//{
	//	delete[] adjacencyMatrix[i]; //cleanup x
	//}
	//delete[] adjacencyMatrix; //cleanup y
}

#endif





