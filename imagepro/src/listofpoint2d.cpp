/* implementation of the class ListOfPoint2D
 */

#include "../include/image/listofpoint2d.hpp"
#include <iostream>

namespace image {
    ListOfPoint2D::ListOfPoint2D() : head(nullptr), size(0) {}

    void ListOfPoint2D::addPoint(const Point2D& point) {
        NodePoint2D* newNode = new NodePoint2D(point);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void ListOfPoint2D::show() const {
        NodePoint2D* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->point.getX() << ", " << current->point.getY() << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int ListOfPoint2D::getSize() const {
        return size;
    }

    ListOfPoint2D::~ListOfPoint2D() {
        while (head) {
            NodePoint2D* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    NodePoint2D::NodePoint2D(const Point2D& p) : point(p), next(nullptr) {}
}
