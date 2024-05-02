#include "graph.h"
#include <queue>

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = "";
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(const std::string& name)
{
    vertexes[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(const std::string& v1, const std::string& v2, int weight)
{
    // Проверяем существование вершин
    if (!vertexExists(v1) || !vertexExists(v2)) {
        std::cerr << "One or both vertices do not exist." << std::endl;
        return;
    }

    int index1 = -1;
    int index2 = -1;

    // Находим индекс v1 и v2 в массиве vertexes
    for (int i = 0; i < vertexCount; i++) {
        if (vertexes[i] == v1)
            index1 = i;
        if (vertexes[i] == v2)
            index2 = i;
    }

    // Если не удалось найти одну из вершин, выводим сообщение об ошибке и выходим
    if (index1 == -1 || index2 == -1) {
        std::cerr << "Failed to find one or both vertices." << std::endl;
        return;
    }

    matrix[index1][index2] = weight;
    matrix[index2][index1] = weight;
}

bool Graph::edgeExists(const std::string& v1, const std::string& v2)
{
    // Проверяем существование вершин
    if (!vertexExists(v1) || !vertexExists(v2))
        return false;

    int index1 = -1;
    int index2 = -1;

    // Находим индекс v1 и v2 в массиве vertexes
    for (int i = 0; i < vertexCount; i++) {
        if (vertexes[i] == v1)
            index1 = i;
        if (vertexes[i] == v2)
            index2 = i;
    }

    // Если не удалось найти одну из вершин, выводим сообщение об ошибке и выходим
    if (index1 == -1 || index2 == -1) {
        std::cerr << "Failed to find one or both vertices." << std::endl;
        return false;
    }
    // Проверяем существование ребра
    return matrix[index1][index2] != "";
   
}
// проверка существования вершины
bool Graph::vertexExists(const std::string& name)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == name)
            return true;
    return false;
}

void Graph::width(const std::string& start) {
    // Проверяем существование начальной вершины
    if (!vertexExists(start)) {
        std::cerr << "Start vertex does not exist." << std::endl;
        return;
    }

    int startIndex = -1;

    // Находим индекс start в массиве vertexes
    for (int i = 0; i < vertexCount; i++) {
        if (vertexes[i] == start) {
            startIndex = i;
            break;
        }
    }

    // Если не удалось найти вершину, выводим сообщение об ошибке и выходим
    if (startIndex == -1) {
        std::cerr << "Failed to find start vertex." << std::endl;
        return;
    }

    std::vector<std::string> vertices_at_distance_3; // Вектор для хранения имен вершин на расстоянии 3 рёбер
    std::queue<std::pair<int, int>> queue_to_visit; // очередь вершин для обхода (вершина, расстояние)
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit.push({ startIndex, 0 }); // кладем в очередь начальную вершину с расстоянием 0
    while (!queue_to_visit.empty())
    {
        // взятие из очереди вершины и расстояния
        int current = queue_to_visit.front().first;
        int distance = queue_to_visit.front().second;
        queue_to_visit.pop();

        if (distance == 3) {
            // Добавляем имя вершины на расстоянии 3 рёбер в вектор
            vertices_at_distance_3.push_back(vertexes[current]);
        }

        if (!visited[current]) {
            visited[current] = true;
            // поиск смежных вершин и добавление их в очередь
            for (int i = 0; i < SIZE; i++)
            {
                if (!visited[i] && edgeExists(vertexes[current], vertexes[i]))
                    queue_to_visit.push({ i, distance + 1 }); // увеличиваем расстояние на 1 для смежных вершин
            }
        }
    }

    // Выводим имена вершин на расстоянии 3 рёбер
    std::cout << "Vertices at distance 3 from " << start << ":" << std::endl;
    for (const std::string& vertex : vertices_at_distance_3) {
        std::cout << vertex << std::endl;
    }
}


