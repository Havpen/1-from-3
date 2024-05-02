#pragma once
#define SIZE 10
#include <iostream>
#include <string>

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(const std::string& name);
    // добавление ребра
    void addEdge(const std::string& v1, const std::string& v2, int weight);
    void width(const std::string& start);
    
private:
    bool edgeExists(const std::string& v1, const std::string& v2);
    bool vertexExists(const std::string& name);
    std::string matrix[SIZE][SIZE];// матрица смежности
    std::string vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};