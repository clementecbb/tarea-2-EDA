/*
 Class Point2D
*/


#ifndef POINT2D_HPP
#define POINT2D_HPP

namespace image {
    class Point2D {
    private:
        int x;
        int y;

    public:
        Point2D();  // Constructor por defecto
        Point2D(int _x, int _y);  // Constructor con parámetros
        int getX() const;  // Método para obtener x
        int getY() const;  // Método para obtener y
        void setX(int _x);  // Método para establecer x
        void setY(int _y);  // Método para establecer y
        virtual ~Point2D();  // Destructor
    };
}

#endif // POINT2D_HPP
