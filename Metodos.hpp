#include <iostream>
#include "Clases.hpp"
using namespace std;

void movimiento(char mov, int *x, int *y) {
    cout << "X = " << *x << endl;
    cout << "Y = " << *y << endl;
    if (mov == 'w') {
        *y -= 1;
    }
    else if (mov == 's') {
        *y += 1;
    }
    else if (mov == 'a') {
        *x -= 1;
    }
    else if (mov == 'd') {
        *x += 1;
    }
}

/********************************CUADRADO********************************/
void Cuadrado::draw() {
    char mov;
    while ((mov = cin.get()) != 'p') {
        Limpiar();
        getX();
        getY();
        cout << "Largo = " << getLargo() << endl;
        movimiento(mov, &x, &y);
        for (int c = 0; c <= 25; c++)
        {
            if (c < 10)
            {
                cout << "  " << c;
            }
            else
            {
                cout << " " << c;
            }
        }
        cout << endl;
        int l = 0;
        while (l < getY())
        {
            cout << l << endl;
            l++;
        }
        for (int c = 0; c < getLargo(); c++)
        {
            cout << l;
            if (l < 10)
            {
                cout << " ";
            }
            for (int n = 1; n < getX(); n++)
            {
                cout << "   ";
            }
            l++;
            
            cout << " ";
            for (int i = 0; i < getLargo(); i++)
            {
                
                if (getTipo() == 1)
                {
                    cout << " *";
                }
                else
                {
                    if ((c == 0 || i == 0) || (c == (getLargo()-1)) || (i == (getLargo()-1)))
                    {
                        cout << " *";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }
}

/********************************TRIANGULO********************************/
void Triangulo::draw() {
    char mov;
    while ((mov = cin.get()) != 'p') {
        Limpiar();
        getX();
        getY();
        cout << "Largo = " << getLargo() << endl;
        movimiento(mov, &x, &y);
        for (int c = 0; c <= 25; c++)
        {
            if (c < 10)
            {
                cout << "  " << c;
            }
            else
            {
                cout << " " << c;
            }
        }
        cout << endl;
        int l = 0;
        while (l < getY())
        {
            cout << l << endl;
            l++;
        }

        int aux = getLargo() - 1;
        for (int c = 1; c <= getLargo(); c++)
        {
            cout << l;
            if (l < 10)
            {
                cout << " ";
            }
            for (int n = 1; n < getX(); n++)
            {
                cout << "   ";
            }
            l++;

            cout << " ";
            for (int n = 0; n < aux; n++)
            {
                cout << " ";
            }
            aux -= 1;
            for (int i = 0; i < c; i++)
            {
                if (getTipo() == 1)
                {
                    cout << " *";
                }
                else
                {
                    if ((i == 0) || (c == getLargo()) || (i == (c-1)))
                    {
                        cout << " *";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
            }       
            cout << endl;
        }
    }
}

/********************************TRAPECIO********************************/
void Trapecio::draw() {
    char mov;
    while ((mov = cin.get()) != 'p') {
        Limpiar();
        getX();
        getY();
        cout << "Largo = " << getLargo() << endl;
        movimiento(mov, &x, &y);
        for (int c = 0; c <= 25; c++)
        {
            if (c < 10)
            {
                cout << "  " << c;
            }
            else
            {
                cout << " " << c;
            }
        }
        cout << endl;
        int l = 0;
        while (l < getY())
        {
            cout << l << endl;
            l++;
        }

        int aux1 = getLargo();
        int aux2 = getLargo();
        for (int c = 0; c < getLargo(); c++)
        {
            cout << l;
            if (l < 10)
            {
                cout << " ";
            }
            for (int n = 1; n < getX(); n++)
            {
                cout << "   ";
            }
            l++;
            
            cout << " ";
            for (int n = 1; n < aux1; n++)
            {
                cout << " ";
            }
            aux1 -= 1;
            
            int i = 0;
            while (i < aux2)
            {
                if (getTipo() == 1)
                {
                    cout << "* ";
                }
                else
                {
                    if ((c == 0 || i == 0) || (c == (getLargo()-1)) || (i == (aux2-1)))
                    {
                        cout << " *";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
                i++;
            }
            aux2++;
            cout << endl;
        }
    }
}

/********************************LIENZO********************************/
void Lienzo (IFigura *forma, int x, int y, int largo, int opc) {
    forma->setX(x);
    forma->setY(y);
    forma->setLargo(largo);
    forma->setTipo(opc);
    forma->draw();
    delete forma;
}

/********************************PROGRAMA********************************/
Programa::Programa() {
	opc = 1;
    x = 0;
    y = 0;
}
void Programa::run() {
    do {
        cout << "Elige la figura:" << endl;
        cout << "1.- Cuadrado." << endl;
        cout << "2.- Triangulo." << endl;
        cout << "3.- Trapecio." << endl;
        cin >> opc;
        Limpiar();

        for (int c = 0; c <= 25; c++)
        {
            if (c < 10)
            {
                cout << "  " << c;
            }
            else
            {
                cout << " " << c;
            }
        }
        cout << endl;
        for (int i = 0; i <= 25; i++)
        {
            cout << i << endl;
        }
        cout << "Seleccione las coordenadas para la figura: ";
        cin >> x;
        cin >> y;
        Limpiar();
                
        menu();
        
        cout << "\nRepetir programa:";
        cout << "\n1.- Si"
                "\n2.- No" << endl;
        cin >> opc;
        Limpiar();
    } while (opc == 1);
}
void Programa::menu() {
    IFigura* forma;
    int largo = 0;
    if (opc == 1)
    {
        cout << "1.- Relleno \t 2.- Hueco" << endl;
        cout << "* * * \t\t * * *" << endl;
        cout << "* * * \t\t *   *" << endl;
        cout << "* * * \t\t * * *" << endl;
        cout << endl;
        cout << "Elija el tipo de figura: ";
        cin >> opc;
        cout << "Introduzca la medida del largo: ";
        cin >> largo;
        forma = new Cuadrado;
    }
    else if (opc == 2)
    {
        cout << "1.- Relleno \t 2.- Hueco" << endl;
        cout << "   *    \t    *   " << endl;
        cout << "  * *   \t   * *  " << endl;
        cout << " * * *  \t  *   * " << endl;
        cout << "* * * * \t * * * *" << endl;
        cout << endl;
        cout << "Elija el tipo de figura: ";
        cin >> opc;
        cout << "Introduzca la medida del largo: ";
        cin >> largo;
        forma = new Triangulo;
    }
    else if (opc == 3)
    {
        cout << "1.- Relleno \t 2.- Hueco" << endl;
        cout << "  * * * *   \t   * * * *   " << endl;
        cout << " * * * * *  \t  *       *  " << endl;
        cout << "* * * * * * \t * * * * * * " << endl;
        cout << endl;
        cout << "Elija el tipo de figura: ";
        cin >> opc;
        cout << "Introduzca la medida del alto: ";
        cin >> largo;
        forma = new Trapecio;
    }
    else
    {
        cout << "Lo sentimos, la opcion no existe" << endl;
    }
    Lienzo(forma, x, y, largo, opc);
}