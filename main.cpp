#include <iostream>

using namespace std;
class Raton {
private:
    double peso;
public:
     Raton(double aux){
        peso=aux;
    }
    double getPeso() const{
        return peso;
    }
};
class Gato{
private:
    double energia;
    int cantidad;
    double tiempo;
    double velociad;
public:
    Gato(){
        energia=10.0;
        cantidad=0;
        tiempo=0;
        velociad=5+energia/10;
    }
    void estadoActual() const{
        cout<<"La energia del gato es de: "<<energia<<" jouls"<<endl;
        cout<<"Comio: "<<cantidad<<" de ratones"<<endl;
        cout<<"Corrio por: "<<tiempo<<"s"<<endl;
    }
    void comer(Raton &aux){
        int peso=(int )aux.getPeso();
        energia=12+peso;
        cantidad+=1;
    }
    void correr(double metros){
        energia= energia -0.5*metros;
        tiempo=(int )metros/velociad;
    }
    bool meConvieneComerRaton(Raton &aux, int distancia) const{
        int energia_por_comida,energia_por_correr,peso;
        peso=(int )aux.getPeso();
        energia_por_comida= 12 + peso;
        energia_por_correr= 0.5 * distancia;
        return energia_por_comida > energia_por_correr;

    }
};

int main() {
    Gato tom;
    Raton jerry(23.0);
    Raton perry(18.0);
    tom.estadoActual();
    tom.comer(jerry);
    tom.estadoActual();
    tom.correr(15.0);
    tom.estadoActual();
    if (tom.meConvieneComerRaton(perry,5000.0))
        cout<<"Me conviene comer ese raton"<<endl;

    return 0;
}
