
#include "LBPDescriptor.hpp"

#include <iostream>
#include <cstdlib>

// Librerías de OpenCV
#include <opencv2/core/core.hpp>           // Contiene las definiciones base de matrices y estructuras
#include <opencv2/highgui/highgui.hpp>     // Interfaz gráfica de usuario
#include <opencv2/imgproc/imgproc.hpp>     // Procesamiento de imágenes
#include <opencv2/imgcodecs/imgcodecs.hpp> // Códecs para leer los distintos formatos de imágenes (JPG, PNG, etc.)
#include <opencv2/video/video.hpp>         // Lectura de vídeos
#include <opencv2/videoio/videoio.hpp>     // Lectura y escritura de videos

#include <opencv2/objdetect/objdetect.hpp> // Para realizar detección de objetos

#include <random>

#include <cmath>

//#include <opencv2/opencv.hpp> // Permite cargar todas las librerías de OpenCV

using namespace std;
using namespace cv; // Espacio de nombres de OpenCV para llamar a los métodos de forma más directa

vector<int> HC1_1;
vector<int> HC1_0;
vector<int> HC2_1;
vector<int> HC2_0;

int main(int argc, char *argv[])
{
    LBPDescriptor *lbp = new LBPDescriptor();

    string clase1Path = "/home/computacion/Descargas/Practica3-2/Clase-1";

    String Clase2Path = "/home/computacion/Descargas/Practica3-2/Clase-2";

    vector<string> clase1 = lbp->LecturaCarpeta(clase1Path);
    vector<string> clase2 = lbp->LecturaCarpeta(Clase2Path);

    string imagenC1_1 = clase1[0];
    string imagenC2_1 = clase2[0];
    string imagenC1_2 = clase1[1];
    string imagenC2_2 = clase2[1];

    Mat imageC1_1 = imread(imagenC1_1);
    Mat imageC2_1 = imread(imagenC2_1);
    Mat imageC1_2 = imread(imagenC1_2);
    Mat imageC2_2 = imread(imagenC2_2);

    imageC1_1=lbp->ConversionImagen(imageC1_1);
    imageC2_1=lbp->ConversionImagen(imageC2_1);
    imageC1_2=lbp->ConversionImagen(imageC1_2);
    imageC2_2=lbp->ConversionImagen(imageC2_2);


    HC1_0 = lbp->histogramaLBP(imageC1_1);
    HC2_0 = lbp->histogramaLBP(imageC2_1);
    HC1_1 = lbp->histogramaLBP(imageC1_2);
    HC2_1 = lbp->histogramaLBP(imageC2_2);

    ofstream MyFile("Histogramas.txt");

    for (int i = 0; i < 1; i++)
    {

        MyFile << '\n';
        MyFile << '\n';
        MyFile << "Histograma de la Imagen: " + imagenC1_1;
        MyFile << '\n';
        MyFile << '\n';

        for (int i = 0; i < 256; i++)
            MyFile << to_string(HC1_0[i]) + "|";

        MyFile << '\n';
        MyFile << '\n';
        MyFile << "Histograma de la Imagen: " + imagenC1_2;
        MyFile << '\n';
        MyFile << '\n';

        for (int i = 0; i < 256; i++)
            MyFile << to_string(HC1_1[i]) + "|";

        MyFile << '\n';
        MyFile << '\n';
        MyFile << "Histograma de la Imagen: " + imagenC2_1;
        MyFile << '\n';
        MyFile << '\n';

        for (int i = 0; i < 256; i++)
            MyFile << to_string(HC2_0[i]) + "|";

        MyFile << '\n';
        MyFile << '\n';
        MyFile << "Histograma de la Imagen: " + imagenC2_2;
        MyFile << '\n';
        MyFile << '\n';

        for (int i = 0; i < 256; i++)
            MyFile << to_string(HC2_1[i]) + "|";
    }
    MyFile.close();

    //----------------------------------------------------
    // vector<int> Histogramas[4];

    //----------------------------------------------------

    vector<int>resultados;


    for (int j = 0; j < 4; j++)
    {
        

        double resta1;
        double resta2;
        double resta3;

        double distancia1;
        double distancia2;
        double distancia3;

        int bandera;
       
        //Histograma 0
        if (j == 0)
        {
            for (int i = 0; i < 256; i++)
            {

                resta1 = resta1 + pow(HC1_0[i] - HC1_1[i], 2);
                resta2 = resta2 + pow(HC1_0[i] - HC2_0[i], 2);
                resta3 = resta3 + pow(HC1_0[i] - HC2_1[i], 2);
            }

            distancia1 = sqrt(resta1);
            distancia2 = sqrt(resta2);
            distancia3 = sqrt(resta3);

            if ((distancia1<distancia2)&&(distancia1<distancia3))
            {
                
                bandera=1;
            }else{
                
                bandera=0;
            }
            
            resultados.push_back(bandera);
       
        }

        
        if (j == 1)
        {
            for (int i = 0; i < 256; i++)
            {

                
                resta1 = resta1 + pow(HC1_1[i] - HC1_0[i], 2);
                
                resta2 = resta2 + pow(HC1_1[i] - HC2_0[i], 2);
                
                resta3 = resta3 + pow(HC1_1[i] - HC2_1[i], 2);
            }

            distancia1 = sqrt(resta1);
            distancia2 = sqrt(resta2);
            distancia3 = sqrt(resta3);


            if ((distancia1<distancia2)&&(distancia1<distancia3))
            {
                
                bandera=1;
                
            }else{
                
                bandera=0;
            }

            resultados.push_back(bandera);
        }

        //Histograma 2
        if (j == 2)
        {
            for (int i = 0; i < 256; i++)
            {

                
                resta1 = resta1 + pow(HC2_0[i] - HC1_0[i], 2);
                
                resta2 = resta2 + pow(HC2_0[i] - HC1_1[i], 2);
                
                resta3 = resta3 + pow(HC2_0[i] - HC2_1[i], 2);
            }

            distancia1 = sqrt(resta1);
            distancia2 = sqrt(resta2);
            distancia3 = sqrt(resta3);


            if ((distancia3<distancia1)&&(distancia3<distancia2))
            {
                
                bandera=1;
            }else{
                
                bandera=0;
            }
            resultados.push_back(bandera);
            
        }

        if (j == 3)
        {
            for (int i = 0; i < 256; i++)
            {

                
                resta1 = resta1 + pow(HC2_1[i] - HC1_0[i], 2);
                
                resta2 = resta2 + pow(HC2_1[i] - HC1_1[i], 2);
                
                resta3 = resta3 + pow(HC2_1[i] - HC2_0[i], 2);
            }

            distancia1 = sqrt(resta1);
            distancia2 = sqrt(resta2);
            distancia3 = sqrt(resta3);

            if ((distancia3<distancia1)&&(distancia3<distancia2))
            {
                bandera=1;
            }else{
                
                bandera=0;
            }
            resultados.push_back(bandera);
            
        }
    }
    int contAciertos=0;
    int contFallos=0;

    for (int i = 0; i < resultados.size(); i++)
    {
        if (resultados[i]==1)
        {
            contAciertos=contAciertos+1;
        }else{
            contFallos=contFallos+1;
        }
        
    }

    cout<<"------% de Presicion-------"<<endl;

    int tam=resultados.size();

    int presicion= contAciertos*100/tam;

    cout<<to_string(presicion)<<"%"<<endl;

    delete lbp;

    return 0;
}


