/* implementation of the class ListOfRegion
 */

#include "image/listofregion.hpp"
#include <iostream>

namespace image {
    ListOfRegion::ListOfRegion() : head(nullptr), size(0) {}

    void ListOfRegion::addRegion(const Region& region) {
        NodeRegion* newNode = new NodeRegion(region);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int ListOfRegion::getSize() const {
        return size;
    }

    void ListOfRegion::showRegions() const {
        NodeRegion* current = head;
        int regionID = 1;
        while (current != nullptr) {
            std::cout << "Región " << regionID << " -> size " << current->region.getSize() << std::endl;
            current->region.showRegion();
            current = current->next;
            regionID++;
        }
    }

    void ListOfRegion::showRegion(int region_id) const {
        if (region_id > 0 && region_id <= size) {
            NodeRegion* current = head;
            for (int i = 1; i < region_id; ++i) {
                current = current->next;
            }
            current->region.showRegion();
        } else {
            std::cout << "ID de región no válido." << std::endl;
        }
    }

    ListOfRegion::~ListOfRegion() {
        while (head) {
            NodeRegion* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    NodeRegion::NodeRegion(const Region& reg) : region(reg), next(nullptr) {}
}
