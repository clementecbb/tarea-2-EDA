/* implementation of the class Region
 */

#include "../include/image/region.hpp"

namespace image {
    Region::Region() : size(0) {}

    void Region::addPoint(const Point2D& point) {
        points.addPoint(point);
        size++;
    }

    int Region::getSize() const {
        return size;
    }

    void Region::showRegion() const {
        points.show();  // Mostrar todos los puntos de la región
    }

    Region::~Region() {}
}
