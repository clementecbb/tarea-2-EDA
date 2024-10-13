#include "image/image.hpp"
#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, image::Image*> images;  // Mapa para almacenar imágenes
    std::string command;

    std::cout << "Bienvenido a ImagePro" << std::endl;

    while (true) {
        std::cout << ">> ";
        std::cin >> command;  // Leer el comando

        if (command == "read") {
            std::string img_id, path;
            std::cin >> img_id >> path;
            images[img_id] = image::Image::readImage(path);
            std::cout << "Imagen " << img_id << " leída desde " << path << std::endl;
        
        } else if (command == "show") {
            std::string img_id;
            std::cin >> img_id;
            if (images.find(img_id) != images.end()) {
                images[img_id]->show();
            } else {
                std::cout << "Imagen " << img_id << " no encontrada." << std::endl;
            }

        } else if (command == "getRegions") {
            std::string img_id;
            std::cin >> img_id;
            if (images.find(img_id) != images.end()) {
                image::ListOfRegion regions = images[img_id]->getRegions();
                std::cout << "La imagen " << img_id << " tiene " << regions.getSize() << " regiones." << std::endl;
                regions.showRegions();
            } else {
                std::cout << "Imagen " << img_id << " no encontrada." << std::endl;
            }

        } else if (command == "showRegion") {
            std::string img_id;
            int region_id;
            std::cin >> img_id >> region_id;
            if (images.find(img_id) != images.end()) {
                image::ListOfRegion regions = images[img_id]->getRegions();
                regions.showRegion(region_id);  // Necesitas implementar showRegion en ListOfRegion
            } else {
                std::cout << "Imagen " << img_id << " no encontrada." << std::endl;
            }

        } else if (command == "exit") {
            break;  // Salir del programa

        } else {
            std::cout << "Comando no reconocido." << std::endl;
        }
    }

    // Liberar la memoria de las imágenes
    for (auto& img : images) {
        delete img.second;
    }

    return 0;
}
