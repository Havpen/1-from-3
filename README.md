# 1-from-3
# Graph Class

This is a simple C++ program demonstrating a graph class implementation. It allows adding vertices and edges to a graph and finding vertices at a certain distance from a given vertex.

## Usage

To use this program, simply compile the `main.cpp` file along with the `graph.cpp` and `graph.h` files. Then run the executable.

The program will prompt you to choose a name from the list (Oleg, Nikita, Nastya, Vanya, Jenya, Jesika, Kirill) or type "Exit" to quit. After choosing a name, it will display vertices at a distance of 3 from the selected vertex.

## Class Members

### `Graph`

#### Methods
- `Graph()`: Constructor for the Graph class.
- `void addVertex(const std::string& name)`: Adds a vertex to the graph.
- `void addEdge(const std::string& v1, const std::string& v2, int weight)`: Adds an edge between two vertices with the given weight.
- `bool edgeExists(const std::string& v1, const std::string& v2)`: Checks if an edge exists between two vertices.
- `bool vertexExists(const std::string& name)`: Checks if a vertex exists in the graph.
- `void width(const std::string& start)`: Finds vertices at a distance of 3 from the given vertex using breadth-first search.

## Example

```cpp
#include "graph.h"

int main() {
    Graph friends;
    // Add vertices
    friends.addVertex("Oleg");
    friends.addVertex("Nikita");
    friends.addVertex("Nastya");
    friends.addVertex("Vanya");
    friends.addVertex("Jenya");
    friends.addVertex("Jesika");
    friends.addVertex("Kirill");

    // Add edges
    friends.addEdge("Oleg", "Nikita", 1);
    friends.addEdge("Nikita", "Nastya", 1);
    friends.addEdge("Nastya", "Vanya", 1);
    friends.addEdge("Vanya", "Jenya", 1);
    friends.addEdge("Jenya", "Jesika", 1);
    friends.addEdge("Jesika", "Kirill", 1);

    // Find vertices at distance 3
    std::string name;
    do {
        std::cout << "Choose a name or type 'Exit' to quit: ";
        std::cin >> name;
        if (name != "Exit" && friends.vertexExists(name)) {
            friends.width(name);
        } else if (name != "Exit") {
            std::cout << "Invalid name. Please choose from the list." << std::endl;
        }
    } while (name != "Exit");

    return 0;
}
