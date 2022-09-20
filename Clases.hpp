#include <iostream>
#include "Forma.hpp"
using namespace std;

void Limpiar() {
    cout << "\x1B[2J\x1B[H";
}

/********************************CUADRADO********************************/
class Cuadrado : public IFigura {
    public:
        void draw ();
};

/********************************TRIANGULO********************************/
class Triangulo : public IFigura {
    public:
        void draw();
};

/********************************CIRCULO********************************/
class Trapecio : public IFigura {
    public:
        void draw();
};

/********************************PROGRAMA********************************/
class Programa {
    private:
	    int opc;
        int x;
        int y;
	public:
	    Programa();
	    void run();
        void menu();
};