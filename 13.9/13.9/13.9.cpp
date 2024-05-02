
#include "graph.h"

auto main() -> int {

	Graph friends;
	friends.addVertex("Oleg");
	friends.addVertex("Nikita");
	friends.addVertex("Nastya");
	friends.addVertex("Vanya");
	friends.addVertex("Jenya");
	friends.addVertex("Jesika");
	friends.addVertex("Kirill");

	friends.addEdge("Oleg", "Nikita", 1);
	friends.addEdge("Nikita", "Nastya", 1);
	friends.addEdge("Nastya", "Vanya", 1);
	friends.addEdge("Vanya", "Jenya", 1);
	friends.addEdge("Jenya", "Jesika", 1);
	friends.addEdge("Jesika", "Kirill", 1);

	std::string kaka;
	do {
		std::cout << "Choose the Name or whrite Exit (Oleg, Nikita, Nastya, Vanya, Jenya, Jesika, Kirill): ";
		std::cin >> kaka;
		if (kaka != "Oleg" && kaka != "Nikita" && kaka != "Nastya" && kaka != "Vanya" && kaka != "Jenya" && kaka != "Jesika" && kaka != "Kirill")
			break;
		if (kaka == "Exit")
			break;
		friends.width(kaka);

	} while (kaka != "Exit");
	return 0;
}