/*
Xavid Ramirez  - 3/6/2015
Manual implementation of a graph and the breadthfirstsearch
*/

#include "Graph.h"

void buildWorld(gameGraph &world)
{
	world.addVertex("1.272");
	world.addVertex("staples");
	world.addVertex("whataburger");
	world.addVertex("dubai");
	world.addVertex("target");
	world.addVertex("heb");
	world.addVertex("walmart");
	world.addVertex("mydorm");
	world.addVertex("tacobell");

	//add some connections
	world.addEdge("start room", "walmart");
	world.addEdge("tacobell", "whataburger");
	world.addEdge("heb", "target");
	world.addEdge("target", "walmart");
	world.addEdge("target", "tacobell");
	world.addEdge("tacobell", "mydorm");
	world.addEdge("dubai", "1.272");
}

int main()
{
	gameGraph world;
	buildWorld(world);

	while(true)
	{
		//tell player where they are at
		cout << "You are at the " << world.getPlayerLocation() << endl;

		//tell player where they can go
		cout << "You may walk to: " << world.getPlayerExits() << endl;

		//ask them where they want to go
		cout << "Where would you like to go? " << endl;
		string destination;
		getline(cin,destination);

		//go there (if possible)
		cout << "The shortest path to your destination is as follows: " << endl;
		world.breadthFirstSearch(world.findVertex("start room"));
		world.tracePath(world.findVertex(destination));
	}

	return 0;
}