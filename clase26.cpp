#include <iostream>
#include <fstream>
using namespace std; 

int generarArreglo(int len,double *lista);
float * leer(string nombre,int *n);
int multiplicar(string nombre,float *array1,float *array2,int n);

int main(){
    int len = 8;
    int nx;
    int ny;
    double *lista;
    lista = new double[len];
    float *x=NULL;
    float *y=NULL;
    
    generarArreglo(len,lista);
    x = leer("valores_x.txt", &nx);
    y = leer("valores_y.txt", &ny);
    multiplicar("multiplicados.dat",x,y,nx);
    
    return 0;
}

int generarArreglo(int len,double *lista){
    /*Se llena el arreglo*/
    for(int i=0;i<len;i++){
        /*Se clacula el factorial de la posición*/
        if(i==0 | i==1){
            lista[i] = 1;
        }
        else{
            lista[i] = 1;
            for(int j=2;j<=i;j++){
                lista[i] *= j;
            }
        }
        cout<<lista[i]<<endl;
    }
    delete [] lista;
    
    return 0;
}

int multiplicar(string nombre,float *array1,float *array2,int n){
    /*Esta función recibe 2 array y guarda el resultado en un archivo .dat*/
    ofstream outfile;
    outfile.open(nombre);
    /*El ciclo recorre los array y multiplica posicion por posición*/
    for(int i=0;i<n;i++){
        outfile<<array1[i]*array2[i]<<endl;
    }
    outfile.close(); 
  
    return 0;
}

float * leer(string nombre,int *n){
    /*Esta función lee un archivo de texto y retorna un array con su contenido*/
    int lineas=0;
    ifstream infile; 
    string linea;
    int i;
    float *array;

    /*cuenta lineas*/
    infile.open(nombre); 
    getline(infile, linea);
    while(infile){
      lineas++;
      getline(infile, linea);
    }
    infile.close();
    *n = lineas;

    /*inicializar el array a llenar con los datos*/
    array = new float[lineas];

    /*llenar el array*/
    i=0;
    infile.open(nombre); 
    getline(infile, linea);  
    while(infile){
      array[i] = atof(linea.c_str());
      i++;
      getline(infile, linea);
    }
    infile.close();

    return array;
}
