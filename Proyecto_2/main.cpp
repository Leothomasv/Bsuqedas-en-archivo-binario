#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
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
    
    



    if(strcmp(opcion, "find") == 0){
            std::ifstream inFile;
            inFile.open("WHO.bin", std::ios::in | std::ios::binary);

            WHO obj;
            inFile.seekg(0, std::ios::beg);
            
            int suma = 0;
            
        

            char pais[50];
            strcpy(pais, argv[2]);


            inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));

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
                    suma++;
                }
                inFile.read(reinterpret_cast<char*>(&obj), sizeof(WHO));
            }

            std::cout << "Cantidad: " << suma << std::endl;

            inFile.close();
    }



    return 0;
}

