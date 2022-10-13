#include <list>
#include <string>

#pragma once

struct Node {
  public:
    int index;
    double weight;
    Node *path;

    Node() {
        index = -1;
        weight = -1;
    }

    Node(int _index, double _weight) {
        index = _index;
        weight = _weight;
        path = NULL;
    }

    Node(int _index, double _weight, Node *_path) {
        index = _index;
        weight = _weight;
        path = _path;
    }

    static std::pair<double, std::string *> GetPathDistance(Node *endNode) {
        Node *parent = endNode;
        Node *child;
        double distance;
        std::string *pathString;

        do {
            child = parent;
            parent = child->path;

            pathString->append((*child).index + ", ");
            distance += child->weight;

        } while (parent->path != NULL);

        return {distance, pathString};
    }
};