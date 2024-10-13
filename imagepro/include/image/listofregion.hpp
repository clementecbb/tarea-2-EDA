/*
 Class ListOfRegion
*/

#ifndef LISTOFREGION_HPP
#define LISTOFREGION_HPP

#include "region.hpp"

namespace image {
    class NodeRegion;  // Declaración anticipada del nodo

    class ListOfRegion {
    private:
        NodeRegion* head;  // Apuntador al primer nodo
        int size;  // Tamaño de la lista

    public:
        ListOfRegion();  // Constructor
        void addRegion(const Region& region);  // Añadir una región a la lista
        int getSize() const;  // Obtener el tamaño de la lista
        void showRegions() const;  // Mostrar todas las regiones
        void showRegion(int region_id) const;  // Mostrar una región específica
        virtual ~ListOfRegion();  // Destructor
    };

    // Nodo de la lista enlazada
    class NodeRegion {
    public:
        Region region;  // El dato almacenado (la región)
        NodeRegion* next;  // Apuntador al siguiente nodo

        NodeRegion(const Region& reg);  // Constructor
    };
}

#endif // LISTOFREGION_HPP
