
#include <iostream>
#include <cstdlib>
#include <vector>

#include <iostream>
#include <cstdlib>

#include <math.h>
#include <stdlib.h>


#include <vector>
#include <string>
#include <filesystem>
#include <map>

#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <time.h>


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

#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;

namespace fs= std::filesystem;

using namespace std;
using namespace cv;

#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

class LBPDescriptor{

    private:
        int* LBP8(const int*, int , int);

    public:
        LBPDescriptor();
        vector<int> histogramaLBP(Mat);
        vector<string> LecturaCarpeta(string c);
        Mat ConversionImagen(Mat imagen);
};