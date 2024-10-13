#include "image/image.hpp"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stack>  // para usar la pila

namespace image{

    Image::Image(): width(0), height(0), th_value(120), data(nullptr){

    }

    Image::Image(int w, int h): width(w), height(h), th_value(120),  data(nullptr){

    }

    Image::Image(int w, int h, uchar* _data): width(w), height(h), th_value(120), data(_data){
       threshold();
    }

    void Image::threshold(){
        if (data != nullptr) {
            for(int i = 0; i < height*width; i++){            
                if (static_cast<int>(data[i]) < th_value){
                    data[i] = static_cast<char>(0);
                }
                else{
                    data[i] = static_cast<char>(1);                    
                }
            }
        }
    }

    int Image::getValue(int row, int col){
        int pos = row*width + col;
        return static_cast<int>(data[pos]);
    }

    void Image::show(){
        std::cout << "----------------------" << std::endl;
        std::cout << "size [ (w: " << width << ") x   ( h:" << height << ")]" <<  std::endl;        
        std::cout << "---------------------" << std::endl;
        for(int i = 0 ; i < height ; i++ ){
            for(int j = 0; j < width; j++ ){
                if (getValue(i,j) == 0) {
                    std::cout<<"0";
                }
                else{
                    std::cout<<"1";
                }
            }
            std::cout<<std::endl;
        }
    }

    Image::~Image(){

    }

    Image* Image::readImage(std::string &path){

        Image* im = nullptr;
        std::ifstream fin(path, std::ios::binary);
        char info[54];
        // read the 54-byte header
        fin.read(info, 54);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];
        short int planes = *(short int*)&info[26];
        short int bits = *(short int*)&info[28];
        int imagesize = *(int*)&info[34];
        int numcolors = *(int*)&info[46];
        assert(info[0]=='B' && info[1] =='M');
        assert(bits == 8);
        // std::cout<< "planes " << planes << std::endl;
        // std::cout<< "bits " << bits << std::endl;
        // std::cout<< "imagesize " << imagesize << std::endl;
        // std::cout<< "numcolors " << numcolors << std::endl;
        // std::cout<< info[0] << info[1] << std::endl;
        //reading colortable
        char  colors[numcolors*4];
        fin.read(colors, numcolors*4);        
        if (imagesize == height * width) {            
            char* data = new char[imagesize];
            //read the pixel values
            fin.read(data, imagesize); 
            fin.close();
            char* ordered_data = new char[imagesize];
            //copy data in in a proper order            
            std::cout<< "----------------" <<std::endl;
            for(int i = 0; i < height ; i++){
                std::memcpy(ordered_data + width*i, data + width*(height - 1 - i ), width);
            }                    
            delete[]  data;            
            im = new Image(width, height, reinterpret_cast<uchar*>(ordered_data));        
        }
        assert(im != nullptr);
        return im;
    }

    // ---------------- NUEVAS FUNCIONES ---------------------

    // Método que encuentra todas las regiones en la imagen usando una pila
    ListOfRegion Image::getRegions() {
        ListOfRegion regions;
        bool* visited = new bool[width * height]();  // Array para marcar píxeles visitados

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (getValue(i, j) == 1 && !visited[i * width + j]) {
                    // Nueva región encontrada, iniciar un nuevo recorrido con pila
                    Region newRegion;
                    stackBasedRegionSearch(i, j, visited, newRegion);
                    regions.addRegion(newRegion);  // Añadir la región encontrada
                }
            }
        }

        delete[] visited;
        return regions;
    }

    // Método auxiliar que utiliza una pila para recorrer una región conectada
    void Image::stackBasedRegionSearch(int row, int col, bool* visited, Region& region) {
        std::stack<Point2D> stack;
        stack.push(Point2D(row, col));

        while (!stack.empty()) {
            Point2D current = stack.top();
            stack.pop();

            int x = current.getX();
            int y = current.getY();

            // Validar si el pixel es parte de la imagen y no ha sido visitado
            if (x >= 0 && x < height && y >= 0 && y < width && getValue(x, y) == 1 && !visited[x * width + y]) {
                visited[x * width + y] = true;  // Marcar el pixel como visitado
                region.addPoint(Point2D(x, y));  // Añadir el pixel a la región

                // Añadir los vecinos a la pila para continuar la exploración
                stack.push(Point2D(x+1, y));
                stack.push(Point2D(x-1, y));
                stack.push(Point2D(x, y+1));
                stack.push(Point2D(x, y-1));
            }
        }
    }

}
