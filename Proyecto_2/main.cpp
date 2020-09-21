#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include "rapidcsv.h"
#include "CSV.h"

namespace CSV = rapidcsv;


void find(){
    
    std::ifstream inFile;
    inFile.open("WHO.bin", std::ios::in | std::ios::binary);

    WHO obj;
    inFile.seekg(0, std::ios::beg);
    
    int suma = 0;
    
 

    char pais[50] = "BD";
    char fecha[12] = "2020-04-10";
    inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));

    while (!inFile.eof())
    {
        //std::cout << obj.Country << std::endl;
        if (strcmp(obj.Country_Code, pais) == 0) {
            std::cout << obj.Date_Reported << " ";
            std::cout << obj.Country_Code  << " ";
            std::cout << obj.Country << " ";
            std::cout << obj.WHO_region << " ";
            std::cout << obj.New_cases << " ";
            std::cout << obj.Cumulative_cases << " ";
            std::cout << obj.New_deaths << " ";
            std::cout << obj.Cumulative_deaths << std::endl;
            suma++;
        }
        inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));
    }

    std::cout << "Cantidad: " << suma << std::endl;

    inFile.close();
    
}



int main (int argc, char *argv[]){

    if(argc == 1 ){
      std::cerr << "Usage: "<< argv[0] << " <function>\n";
      std::cout << "<function> convert"<< std::endl;
      std::cout << "<function> find " <<std::endl;
      return 1;
    }

    
    

    OperacionesCSV ope;
    
   
    char opcion[12];
    strcpy(opcion, argv[1]);

    if(strcmp(opcion, "convert") == 0){
        ope.convert();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /*std::cout << "0" << argv[0] << std::endl;
    std::cout << "1" << argv[1] << std::endl;
    std::cout << "2" << argv[2] << std::endl;
    std::cout << "3" << argv[3] << std::endl;
    std::cout << "4" << argv[4] << std::endl;
    std::cout << "5" << argv[5] << std::endl;
    std::cout << "6" << argv[6] << std::endl;*/

    


//IF MAYOR CONTIENE
    if(strcmp(opcion, "find") == 0){
            std::ifstream inFile;
            inFile.open("WHO.bin", std::ios::in | std::ios::binary);

            WHO obj;
            inFile.seekg(0, std::ios::beg);

            //copiar argumento pais
            char pais[50];
            strcpy(pais, argv[2]);
            
        
    
            inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));

            if(argc == 3 ){

                while (!inFile.eof())
                {
                    //Busqueda por pais
                    if (strcmp(obj.Country, pais) == 0) {
                        std::cout << obj.Date_Reported << " ";
                        std::cout << obj.Country_Code  << " ";
                        std::cout << obj.Country << " ";
                        std::cout << obj.WHO_region << " ";
                        std::cout << obj.New_cases << " ";
                        std::cout << obj.Cumulative_cases << " ";
                        std::cout << obj.New_deaths << " ";
                        std::cout << obj.Cumulative_deaths << std::endl;
                    }
                    inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));
                }

            }else if (argc == 6){
                char NumericType [15];
                strcpy(NumericType, argv[3]);

                char MasMenos[7];
                strcpy(MasMenos, argv[4]);

                int cantidad;
                cantidad = std::stoi(argv[5]);

                while (!inFile.eof())
                {
                    //Busqueda por pais y por dato numerico //NEW_CASES
                    if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "mayor") == 0 && obj.New_cases > cantidad) {
                        std::cout << obj.Date_Reported << " ";
                        std::cout << obj.Country_Code  << " ";
                        std::cout << obj.Country << " ";
                        std::cout << obj.WHO_region << " ";
                        std::cout << "New Cases: " << obj.New_cases << " ";
                        std::cout << std::endl;

                    }else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "menor") == 0 && obj.New_cases < cantidad) {
                        std::cout << obj.Date_Reported << " ";
                        std::cout << obj.Country_Code  << " ";
                        std::cout << obj.Country << " ";
                        std::cout << obj.WHO_region << " ";
                        std::cout << "New Cases: " << obj.New_cases << " ";
                        std::cout << std::endl;

                    }else if (strcmp(obj.Country, pais) == 0 && strcmp(NumericType, "New_Cases") == 0 && strcmp(MasMenos, "igual") == 0 && obj.New_cases == cantidad) {
                        std::cout << obj.Date_Reported << " ";
                        std::cout << obj.Country_Code  << " ";
                        std::cout << obj.Country << " ";
                        std::cout << obj.WHO_region << " ";
                        std::cout << "New Cases: " << obj.New_cases << " ";
                        std::cout << std::endl;
                    }
                    //fin
                    inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));
                }
            }

            inFile.close();   
    }

        //podria crear una funcion para la graph
        /*if(argv[7] == "graph"){
            //hacer graph
        }*/


    return 0;
}

