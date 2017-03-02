#include <cstdlib>
#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{   
	Integer d1(1), d2(2), d3(3), d4(4);

	Graph::Vertex  v1(&d1), v2(&d2), v3(&d1), v4(&d2);
	Graph::Edge    e1(v1, v2, &d1), e2(v1, v3, &d2), e3(v2, v3, &d2), e4(v2, v4, &d2);
	Graph::VertexList myVertexList;
	Graph::EdgeList myEdgeList;
	
	myVertexList.push_back(v1);
	myVertexList.push_back(v2);
	myVertexList.push_back(v3);
	myVertexList.push_back(v4);

	myEdgeList.push_back(e1);
	myEdgeList.push_back(e2);
	myEdgeList.push_back(e3);
	myEdgeList.push_back(e4);

	Graph myGraph(myVertexList, myEdgeList);

	bool state = v1.isAdjacentTo(myGraph, v2);

	if (state)
	{
		cout << "Vertex is incident " << endl;
	}
	else
	{
		cout << "Vertex is not incident " << endl;
	}


	state = e1.isAdjacentTo(e2);
	if (state)
	{
		cout << "Edge  is adjacent " << endl;
	}
	else
	{
		cout << "Edge is not adjacent  " << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
