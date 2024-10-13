/*
 Class Region
*/

#ifndef REGION_HPP
#define REGION_HPP

#include "listofpoint2d.hpp"  // Necesitamos la lista de puntos

namespace image {
    class Region {
    private:
        int size;  // Tamaño de la región
        ListOfPoint2D points;  // Lista de puntos que componen la región

    public:
        Region();  // Constructor por defecto
        void addPoint(const Point2D& point);  // Añadir un punto a la región
        int getSize() const;  // Obtener el tamaño de la región
        void showRegion() const;  // Mostrar la región
        virtual ~Region();  // Destructor
    };
}

#endif // REGION_HPP
