#include <iostream>

class Forma {
    protected:
        
        double perimetro() {}
        double area() {}
        void toString() {}
        friend std::ostream& operator<<(std::ostream& out, const Forma& forma) {}
};