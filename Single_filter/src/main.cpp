/**************************************************************************************************
 Copyright © 2016-2017 Md.Kamruzzaman. All rights reserved.
 The generated code is released under following licenses:
 GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007
 --------------------------------------------------------------------------------------------------
 File name: main.cpp
 Objective: Execution starts from here
 Additional information: NA
 --------------------------------------------------------------------------------------------------
 Contributors                   Date            Task details
 -------------------------    ----------      --------------------
 Md. Kamruzzaman              02/21/2016      Initial version
 
 **************************************************************************************************/

#include <iostream>
#include "PersistentHomology.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    clock_t t1, t2;
    
    t1 = clock();
    
    PersistentHomology* perHom = new PersistentHomology();
    perHom->CreateTreeAndMeshGrid();  //(25, 4); //(40, 4);
    
    perHom->CreateClusterAndGraph();
    
    t2 = clock();
    float _time = (t2-t1)/CLOCKS_PER_SEC;
    string unit = "(sec)";
    
    if(_time<1){
        _time = ((t2-t1)*1000)/CLOCKS_PER_SEC;
        unit = "(ms)";
    }
    
    cout<<"Total time:"<<_time<<unit<<endl;
    
    char ch;
    cout<<"\n\nPress any key to exit";
    ch=getchar();
    
    return 0;
}


