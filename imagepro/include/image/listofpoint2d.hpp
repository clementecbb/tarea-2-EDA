/*
 Class ListOfPoint2D
*/

#ifndef LISTOFPOINT2D_HPP
#define LISTOFPOINT2D_HPP

#include "point2D.hpp"

namespace image {
    class NodePoint2D;  // Declaración anticipada del nodo

    class ListOfPoint2D {
    private:
        NodePoint2D* head;  // Apuntador al primer nodo
        int size;  // Tamaño de la lista

    public:
        ListOfPoint2D();  // Constructor
        void addPoint(const Point2D& point);  // Añadir un punto a la lista
        void show() const;  // Mostrar todos los puntos en la lista
        int getSize() const;  // Obtener el tamaño de la lista
        virtual ~ListOfPoint2D();  // Destructor
    };

    // Nodo de la lista enlazada
    class NodePoint2D {
    public:
        Point2D point;  // El dato almacenado
        NodePoint2D* next;  // Apuntador al siguiente nodo

        NodePoint2D(const Point2D& p);  // Constructor
    };
}

#endif // LISTOFPOINT2D_HPP
