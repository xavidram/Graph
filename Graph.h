/*
Xavid Ramirez  - 3/6/2015
Manual implementation of a graph and the breadthfirstsearch
*/
#include <iostream>
#include <list>
#include <string>
#include <queue>
using namespace std;

class gameGraph
{
private:
	class vertex
	{
	public:
		string data;
		list<vertex* > exitList;
		bool visited;
		vertex * pred;

		vertex(string s)
		{
			data = s;
		}

		vertex()
		{
			data = "";
		}
	};
	// holds the player loction
	vertex * playerLocation;
	//holds list of veertex
	list<vertex*> vertexList;
	// initialize the queue for the vertexes
	queue<vertex*> Q;

public:
	gameGraph()
	{
		vertex * startvert = new vertex("start room");
		vertexList.push_back(startvert);
		playerLocation = startvert;
	}
	gameGraph(string s)
	{
		vertex * startvert = new vertex(s);
		vertexList.push_back(startvert);
		playerLocation = startvert;
	}

	void addVertex(string s)
	{
		vertex * newguy = new vertex(s);
		vertexList.push_back(newguy);
	}

	vertex * findVertex(string s)
	{
		for each(vertex * v in vertexList)
		{
			if(v->data == s)
				return v;
		}
		return NULL;
	}

	//this function will create a onsided edge from one
	// vertex to another
	void addDirectedEdge(string s, string t)
	{
		vertex * svert = findVertex(s);
		vertex * tvert = findVertex(t);
		svert->exitList.push_back(tvert);
	}

	//this function creates a double sided edge between two vertexes
	void addEdge(string s, string t)
	{
		addDirectedEdge(s,t);
		addDirectedEdge(t,s);
	}



	string getPlayerLocation()
	{
		return playerLocation->data;
	}

	string getPlayerExits()
	{
		string output = " ";
		for each (vertex * v in playerLocation->exitList)
		{
			output += v->data + ", ";
		}
		return output;
	}

	bool travelTo(string dest)
	{
		vertex * dvert = findVertex(dest);
		for each(vertex * v in playerLocation->exitList)
		{
			if (v == dvert)
			{
				playerLocation = dvert;
				return true;
			}
		}
		return false;
	}

	void clearData()
	{
		for each (vertex * v in playerLocation->exitList)
		{
			v->pred = NULL;
			v->visited = false;
		}
	}

	void breadthFirstSearch (vertex * start)
	{
		// setp 0: initialize all aogorithm variables
		clearData();

		//step1: put start into Q
		start->visited = true;
		Q.push(start);
		//setp 2: that big loop
		while(!Q.empty())
		{
			//get item for Q
			vertex * x = Q.front();
			Q.pop();

			//throw unvisted neighbors of x into Q
			for each(vertex * y in x->exitList)
			{
				if (!y->visited)
				{
					y->visited = true;
					y->pred = x;
					Q.push(y);
				}
			}
		}
	}

	void tracePath(vertex * dest)
	{
		if (dest->pred == NULL)
		{}
		else
		{	
			tracePath(dest->pred);
			cout << dest->data;
		}
	}

};