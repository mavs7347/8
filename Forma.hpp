/********************************FORMA********************************/
class IFigura {
    protected:
        int tipo;
        int largo;
        int x;
        int y;
    public:
        virtual void setX(int x) {
            this->x = x;
        }
        virtual int getX() {
            if (this->x < 0) {
                this->x = 0;
            }
            else if(this->x >= 25) {
                this->x = 25;
            }
            return x;
        }
        virtual void setY(int y) {
            this->y = y;
        }
        virtual int getY() {
            if (this->y < 0) {
                this->y = 0;
            }
            else if(this->y >= 25) {
                this->y = 25;
            }
            return y;
        }
        virtual void setTipo(int type = 1) {
            tipo = type;
        }
        virtual int getTipo() {
            if (tipo != 1 && tipo != 2) {
                tipo = 1;
            }
            return tipo;
        }
        virtual void setLargo(int large = 2) {
            largo = large;
        }
        virtual int getLargo() {
        	if (largo < 2) {
                largo = 2;
        	}
            return largo;
        }
        virtual void draw() {
            //Cada clase tiene su propio metodo draw
        }
};