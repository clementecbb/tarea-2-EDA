/**
 * Class Image
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include "listofregion.hpp"  // Asegúrate de incluir la lista de regiones correctamente

namespace image {
    class Image; 
    typedef unsigned char uchar;

    class Image {
    private:
        int width;
        int height;
        int th_value;
        uchar* data;

        // Función auxiliar que utiliza una pila para recorrer una región conectada
        void stackBasedRegionSearch(int row, int col, bool* visited, Region& region);

    public:
        Image();
        Image(int w, int h);
        Image(int w, int h, uchar* _data);
        void threshold(); 
        int getValue(int row, int col);
        void show();
        ListOfRegion getRegions();  // Cambiado a "ListOfRegion", que es el tipo correcto
        virtual ~Image(); 
        static Image* readImage(std::string &path);        
    };
}

#endif // IMAGE_HPP
