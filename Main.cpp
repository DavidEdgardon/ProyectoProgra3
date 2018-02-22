#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int main(){

    char pista[25][25];
    int estadisticas[10] = {0};
    int cont=0;
    int velocidad=200;
    int opcNivel=1;
    int milisec=0;
    int puntos = 0;
    bool pause;

menu:
    //Cargar el mapa con 5 carriles y con bordes ya incluidos
    for(int i=0; i < 20; ++i) {
      for(int j=0; j < 20; ++j) {
        pista[i][0] = '|';
        pista[i][18] = '|';
        pista[i][j] = ' ';
      }
    }
   int y = 17, x = 9; // las cordenadas del carrito
    srand(time(0));
     //da a la función aleatoria una nueva semilla, un punto de partida
     //da el tiempo en segundos desde la época de Unix
     //UNIX descripción de instantes de tiempo: se define como la cantidad de segundos transcurridos desde la medianoche
    int a = 0, b = rand() % 15 + 2; //Cordenadas de obstaculos //rand obtencion de numero aleatorios
    bool empezar = true;
    char carros=219; //ascii
    int Menu, regresar;
    int vidas=9;
    pista[y][x] = carros;


    cout<<"======-MENU PRINCIPAL-======"<<endl;
    cout<<"1.Jugar"<<endl;
    cout<<"2.Niveles"<<endl;
    cout<<"3.Estadisticas" <<endl;
    cout<<"4.Salir"<<endl;
    cout<<"Ingrese Opcion: " <<endl;
    cin>>Menu;
    system("CLS"); //Limpiar pantalla
    switch(Menu){

    case 1:{
        clock_t tiempo;
        tiempo = clock();
        for(;;) {
            limpiarPantalla();

            //cronometro
            tiempo=clock()-tiempo;
            milisec = float (tiempo) / CLOCKS_PER_SEC;
            if(milisec==10){
                opcNivel++;
                tiempo=0.00;
                velocidad=velocidad-15;
                puntos=puntos+20;
                if(opcNivel==10){
                    opcNivel=0;
                }
            }
            Sleep(velocidad);

            //ubicar en la posicion de inicio
            pista[y][x] = carros;
            pista[y][x+1] = carros;
            pista[y][x-1] = carros;
            pista[y+1][x-1] = carros;
            pista[y+1][x+1] = carros;
            pista[y-1][x-1] = carros;
            pista[y-1][x+1] = carros;

            //generar los obstaculos
            pista[a][b] = ' ';
            pista[a][b] = ' ';
            pista[a][b+1] = ' ';
            pista[a][b-1] = ' ';
            pista[a+1][b-1] = ' ';
            pista[a+1][b+1] = ' ';
            pista[a-1][b-1] = ' ';
            pista[a-1][b+1] = ' ';
            ++a;
            pista[a][b] = carros;
            pista[a][b+1] = carros;
            pista[a][b-1] = carros;
            pista[a+1][b-1] = carros;
            pista[a+1][b+1] = carros;
            pista[a-1][b-1] = carros;
            pista[a-1][b+1] = carros;
            if(a > 20) {
                a = 0;
                b = rand() % 15 + 2;
            }

        //muestra el mapa
        if(vidas!=0){
                for(int i=0; i < 20; ++i) {
                    for(int j=0; j < 20; ++j) {
                        cout << pista[i][j];
                        if(j >= 19) {
                            cout << endl;
                    }
                }
            }
            cout<<"========DATOS======="<<endl;
            cout<<"===================="<<endl;
            cout <<"||   Puntos: "<< puntos << "   ||"<< endl;
            cout <<"||   Vidas: "<< (vidas/3) << "     ||"<<endl;
            cout <<"||   Nivel: "<< opcNivel << "     ||"<<endl;
            cout<< "||   Segundos: "<< milisec << "  ||"<<endl;
            cout<<"===================="<<endl;
        }

        //empieza el juego cuando se precona cualquier tecla;
        if(empezar) {
            _getch(); //presionar cualquier tecla
            empezar = false;
        }

      //Verificar si el carro choco
        if(pista[y-2][x] == carros || pista[y-2][x-1] == carros|| pista[y-2][x+1] == carros) {
        lost:
            vidas--;
        }

        //mueve el carro a la izquierda
        if(GetAsyncKeyState(VK_LEFT)) {
            if(pista[y][x-3] == carros) {
                goto lost;
            }else if(pista[y][x-3] != '|') {
                pista[y][x] = ' ';
                pista[y][x+1] = ' ';
                pista[y][x-1] = ' ';
                pista[y+1][x-1] = ' ';
                pista[y+1][x+1] = ' ';
                pista[y-1][x-1] = ' ';
                pista[y-1][x+1] = ' ';
                x -= 3;
                pista[y][x] = carros;
                pista[y][x+1] = carros;
                pista[y][x-1] = carros;
                pista[y+1][x-1] = carros;
                pista[y+1][x+1] = carros;
                pista[y-1][x-1] = carros;
                pista[y-1][x+1] = carros;
            }
        }
        //mover carror a la derecha
        if(GetAsyncKeyState(VK_RIGHT)) {
            if(pista[y][x+3] == carros) {
                goto lost;
            }else if(pista[y][x+3] != '|') {
                pista[y][x] = ' ';
                pista[y][x+1] = ' ';
                pista[y][x-1] = ' ';
                pista[y+1][x-1] = ' ';
                pista[y+1][x+1] = ' ';
                pista[y-1][x-1] = ' ';
                pista[y-1][x+1] = ' ';
                x += 3;
                pista[y][x] = carros;
                pista[y][x+1] = carros;
                pista[y][x-1] = carros;
                pista[y+1][x-1] = carros;
                pista[y+1][x+1] = carros;
                pista[y-1][x-1] = carros;
                pista[y-1][x+1] = carros;
            }
        }

        //pause
         if(GetAsyncKeyState(VK_SPACE)) {
         pause=true;
         Sleep(1000);
          }

        if(vidas<=0){
            system("CLS");
            cout<<"Chocaste, Game Over!"<<endl;
            cout<<"Desea seguir jugando (1.SI/2.NO)"<<endl;
            cin>>regresar;
        if(regresar==1){
        if(cont<10){
            estadisticas[cont]=puntos;
        }else{
            cont=0;
            estadisticas[cont]=puntos;
            }
            cont++;

            system("CLS");
            goto menu;
        }else if(regresar==2){
            exit(1);
        }
        }
    puntos++;
        }
    }
    case 2:{

        cout<<"1.Nivel 1"<<endl;
        cout<<"2.Nivel 2"<<endl;
        cout<<"3.Nivel 3"<<endl;
        cout<<"4.Nivel 4"<<endl;
        cout<<"5.Nivel 5"<<endl;
        cout<<"6.Nivel 6"<<endl;
        cout<<"7.Nivel 7"<<endl;
        cout<<"8.Nivel 8"<<endl;
        cout<<"9.Nivel 9"<<endl;
        cout<<"10.Nivel 10"<<endl;
        cout<<"Ingrese el nivel:"<<endl;
        cin >> opcNivel;
        system("CLS");

    if(opcNivel==1){
        velocidad=200;
    }else if(opcNivel==2){
        velocidad=180;
    }else if(opcNivel==3){
        velocidad=160;
    }else if(opcNivel==4){
        velocidad=140;
    }else if(opcNivel==5){
        velocidad=120;
    }else if(opcNivel==6){
        velocidad=100;
    }else if(opcNivel==7){
        velocidad=80;
    }else if(opcNivel==8){
        velocidad=60;
    }else if(opcNivel==9){
        velocidad=40;
    }else if(opcNivel==10){
        velocidad=20;
        }
goto menu;
}
    case 3:
    {
        cout<<"Estadisticas de los ultimos juegos"<<endl;
        for(int i=0;i<10;i++){
        cout<<i+1<<"." <<"Puntos:" <<estadisticas[i]<<endl;
    }
        goto menu;
    }

    case 4:
    {
        exit(1);
    }
    }

}

void limpiarPantalla(){
    HANDLE fuera; //proporciona una abstracción de un recurso, por lo que no necesita saber mucho sobre el recurso en sí para usarlo.
    COORD Posicion; //Define las coordenadas de una celda de caracteres en un búfer de pantalla de la consola

    fuera = GetStdHandle(STD_OUTPUT_HANDLE);

    Posicion.X = 0;
    Posicion.Y = 0;
    SetConsoleCursorPosition(fuera, Posicion);
}
