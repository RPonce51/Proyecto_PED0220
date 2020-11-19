#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct automovil{
    string marca;
    string placa;
    int precio;
};typedef struct automovil Automovil;


void agregardisponibles(vector<automovil> *autosDisponibles){
    automovil nuevo;
    bool status=true;
    cin.ignore();
    cout<<endl<<"Agregar marca del carro: "<<endl;
    getline(cin, nuevo.marca);
    cout<<"Agregar placas del carro: "<<endl;
    cin>>nuevo.placa;
    for (unsigned i = 0; i < autosDisponibles->size(); i++) {
        if(autosDisponibles->at(i).placa == nuevo.placa) {
            cout<<endl<<"Error, las placas " << nuevo.placa <<" ya existen!"<<endl;
            return;
        }
    }
    while(status){
    cout<<"Agregar precio del carro: "<<endl;
    cin>>nuevo.precio;
    if(nuevo.precio<=0){
        cout<<"Precio no valido!"<<endl;
    }else{
        status=false;
    }
    }
    
    autosDisponibles->push_back(nuevo);
    cout<<"Auto anadido con exito en la lista de disponibles"<<endl<<endl;

}

void agregarimportacion(vector<automovil> *autosImportacion){
    automovil nuevo;
    bool status=true;
    nuevo.precio=0;
    cin.ignore();
    cout<<endl<<"Agregar marca del carro: "<<endl;
    getline(cin, nuevo.marca);
    cout<<"Agregar placas del carro: "<<endl;
    cin>>nuevo.placa;
    for (unsigned i = 0; i < autosImportacion->size(); i++) {
        if(autosImportacion->at(i).placa == nuevo.placa) {
            cout<<endl<<"Error, las placas " << nuevo.placa <<" ya existen!"<<endl;
            return;
        }
    }
    while(status){
    cout<<"Agregar precio del carro: "<<endl;
    cin>>nuevo.precio;
    if(nuevo.precio<=0){
        cout<<"Precio no valido!"<<endl;
    }else{
        status=false;
    }
    }

    autosImportacion->push_back(nuevo);
    cout<<"Auto anadido con exito en la lista de importaciones"<<endl<<endl;

}

void Importar(vector<automovil> *autosDisponibles, vector<automovil> *autosImportacion) {
    bool encontrado = false;
    unsigned posicion;
    automovil importado;
    cin.ignore();
    cout<<endl<<"Ingresa las placas: ";
    char placas[128];
    cin.getline(placas, 128);
    string placass(placas, cin.gcount() - 1);


    for (unsigned i = 0; i < autosImportacion->size(); i++) {
        automovil importado = autosImportacion->at(i);

        if(importado.placa.compare(placass.substr(0, placass.size())) == 0) {
            autosDisponibles->push_back(importado);
            encontrado = true;
            posicion = i;
        }
    }

    if (encontrado) {
        cout<<endl<<"Auto importado"<<endl;
        autosImportacion->erase(autosImportacion->begin()+posicion);
    } else {
        cout<<endl<<"No se encontraron las placas del auto por importar"<<endl;
    }
}

void Mostrarvendidos(const queue<automovil> *autosvendidos){
    queue<automovil> Temporal =  *autosvendidos;
    int ganancias = 0;

    cout<<endl<<"Los autos vendidos son"<<endl;
    while(!Temporal.empty()){
        cout<<endl;
        cout<<"Marca: " <<Temporal.back().marca <<endl;
        cout<<"Placa: " <<Temporal.back().placa <<endl;
        cout<<"Precio: $"<<Temporal.back().precio <<endl;
        ganancias += Temporal.back().precio;
        
        Temporal.pop();
    }

    cout<<endl<<"Con una ganancia total de $"<<ganancias<<endl;
}

void Mostrardisponibles(vector<automovil> *autosDisponibles){
    vector<automovil> Temporal = *autosDisponibles;
    while(!Temporal.empty()){
        cout<<endl;
        cout<<"Marca: " <<Temporal.back().marca <<endl;
        cout<<"Placa: " <<Temporal.back().placa <<endl;
        cout<<"Precio: $"<<Temporal.back().precio <<endl;
        

        Temporal.pop_back(); 
    }

}

void MostrarImportacion(vector<automovil> *autosImporacion){
    vector<automovil> Temporal = *autosImporacion;
    while(!Temporal.empty()){
        cout<<endl;
        cout<<"Marca: " <<Temporal.back().marca <<endl;
        cout<<"Placa: " <<Temporal.back().placa <<endl;
        cout<<"Precio: $"<<Temporal.back().precio <<endl;
        

        Temporal.pop_back(); 
    }

}


bool verificar(vector<automovil> *ListaDeAutos, string placa1){
    
    vector<automovil> ListaAux = *ListaDeAutos;
    while(!ListaAux.empty() && ListaAux.back().placa!=placa1){
        ListaAux.pop_back();
    }
    if(ListaAux.empty()){
        return false;
    }else{
        return true;
    }
}

void MostrarAuto(vector<automovil> *ListaDeAutos, string placa1){
    vector<automovil> ListaAux = *ListaDeAutos;

        while(!ListaAux.empty() && ListaAux.back().placa!=placa1){
        ListaAux.pop_back();
    }
        if(ListaAux.empty()){
            cout<<endl<<"No hay ningun auto con esta placa"<<endl;
        }else{
            cout<<"Auto: "<<ListaAux.back().marca<<endl;
            cout<<"Placa: "<<ListaAux.back().placa<<endl;
            cout<<"Precio: $" <<ListaAux.back().precio<<endl;
        }
    
}


void ComprarAuto(vector<automovil> *ListaDeAutos, string placa1, queue<automovil> *autosVendidos){
    automovil autoVendido;
    for(int i=0; i<ListaDeAutos->size(); i++){
        if(ListaDeAutos->at(i).placa==placa1){
            autoVendido=ListaDeAutos->at(i);
            autosVendidos->push(autoVendido);
            ListaDeAutos->erase(ListaDeAutos->begin()+i);
            
        }
    }
   
}

int menuAgencia(vector<automovil> *autosDisponibles, vector<automovil> *autosImportacion, queue<automovil> *autosVendidos){
    int opcion;
    bool status = true;

    while(status){
        cout<<"\n"<<"-----MENU DE LA AGENCIA-----"<<endl;
        cout<<"1. Agregar un auto disponible."<< endl;
        cout<<"2. Agregar un auto de importacion."<< endl;
        cout<<"3. Convertir un auto de importacion en disponible."<< endl;
        cout<<"4. Revisar ganacias totales."<< endl;
        cout<<"5. Regresar."<< endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>> opcion;

        switch(opcion){
            case 1:
                agregardisponibles(autosDisponibles);
            break;
            case 2:
                agregarimportacion(autosImportacion);
                
            break;
            case 3:
            if(autosImportacion->empty()){
                cout<<endl<<"No hay autos en importacion"<<endl<<endl;
            }else{
            cout<<endl<<"Lista de autos en Importacion"<<endl;
            MostrarImportacion(autosImportacion);
            Importar(autosDisponibles, autosImportacion);
            }
            break;
            case 4:
            if(autosVendidos->empty()){
                cout<<endl<<"No se han vendido autos hasta el momento"<<endl<<endl;
            }else{
            Mostrarvendidos(autosVendidos);
            }
            break;
            case 5:
            status=false;
           
            break;
            default:
            cout<<"Opcion no valida";
            break;
        }
    }
}

int menuCliente(vector<automovil> *autosDisponibles, vector<automovil> *autosImportacion, queue<automovil> *autosVendidos){
int opcion;
    bool status = true;
    string placa1;
    string compra;

    while(status){
        cout<<"\n"<<"-----MENU DE CLIENTES-----"<<endl;
        cout<<"1. Mostrar el catalogo de autos disponibles."<< endl;
        cout<<"2. Mostrar catalogo de autos proximamente disponibles."<< endl;
        cout<<"3. Adquirir un auto."<< endl;
        cout<<"4. Regresar."<< endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>> opcion;

        switch(opcion){
            case 1:
            if(autosDisponibles->empty()){
                cout<<endl<<"No hay autos en inventario. Regrese otro dia"<<endl<<endl;
            }else{
                Mostrardisponibles(autosDisponibles);
            }
            break;
            case 2:
            if(autosDisponibles->empty()){
                cout<<endl<<"No hay autos en inventario. Regrese otro dia"<<endl<<endl;
            }else{
            MostrarImportacion(autosImportacion);
            }
            break;
            case 3:
            cout<<endl<<"Ingrese la placa del auto que desea adquirir: ";
            cin>>placa1;
            if(verificar(autosDisponibles, placa1)){
                MostrarAuto(autosDisponibles, placa1);

                cout<<"Desea adquirir este auto?"<<endl;
                cin>>compra;
                if(compra=="Si"||compra=="si"){
                    ComprarAuto(autosDisponibles, placa1, autosVendidos);
                    cout<<"Compra realizada con exito"<<endl;
                    
                }else{
                    cout<<"Compra no realizada"<<endl;
                }

            }else{
                cout<<"La placa introducida no coincide con ninguno de nuestros autos"<<endl;
            }
            break;
            case 4:
            status=false;
            break;
            default:
            cout<<"Opcion no valida";
            break;
        }
    }
}

int main(){
    vector<automovil> autosDisponibles;
    vector<automovil> autosImportacion;
    queue<automovil> autosVendidos;

    Automovil Auto;
    Auto.marca="Chevrolet Camaro";
    Auto.placa="019233";
    Auto.precio=23000;
    autosDisponibles.push_back(Auto);
    Auto.marca="Toyota Supra";
    Auto.placa="1403212";
    Auto.precio=45000;
    autosDisponibles.push_back(Auto);
    Auto.marca="BMW m3";
    Auto.placa="9132780";
    Auto.precio=57000;
    autosDisponibles.push_back(Auto);
    Auto.marca="Mazda rx8";
    Auto.placa="900123";
    Auto.precio=18000;
    autosDisponibles.push_back(Auto);
    Auto.marca="Maserati levante";
    Auto.placa="900123";
    Auto.precio=18000;
    autosImportacion.push_back(Auto);
    Auto.marca="Porsche Boxter";
    Auto.placa="120412";
    Auto.precio=18000;
    autosImportacion.push_back(Auto);


    int opcion;
    bool status = true;
    string clave;

    while(status){
        cout<<"\n"<<"-----AGENCIA NEXT CAR INDUSTRIES-----"<<endl;
        cout<<"1. Ir al menu de la agencia."<< endl;
        cout<<"2. Ir al menu de atencion al cliente."<< endl;
        cout<<"3. Salir del programa."<< endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>> opcion;

        switch(opcion){
            case 1:
            cout<<endl<<"Ingrese la clave de empleado para poder acceder a esta opcion"<<endl;
            cin>>clave;
            if(clave =="0220ped"||clave =="0220PED"){
            cout<<endl<<"Accediendo..."<<endl<<endl;
            menuAgencia(&autosDisponibles, &autosImportacion, &autosVendidos);
            }else{
                cout<<endl<<"Clave incorrecta!"<<endl<<endl;
            }
            break;
            case 2:
            menuCliente(&autosDisponibles, &autosImportacion, &autosVendidos);
            break;
            case 3:
            cout<<"Fin del programa";
            status=false;
            break;
            default:
            cout<<"Opcion no valida";
            break;
        }
    }
}
