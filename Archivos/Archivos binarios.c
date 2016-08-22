#include<stdio.h>
#include<stdlib.h>

typedef struct Estudiante{
       char Cedula[10];
       char Nombre[20];
       char Apellido[20];
       int Edad;       
}ESTUDIANTE;

void insertarDatos();
void mostrarDatos();

int main(){
    
    char op;
    
    do{
         system("cls");
         printf(" 1) Insertar datos \n");
         printf(" 2) Mostrar datos \n");
         printf(" 3) Salir \n");
         fflush(stdin); op = getchar();
         
         switch(op){
             case '1': insertarDatos();break;                    
             case '2': mostrarDatos();break;
             case '3': op = 'Z'; break;
             default: printf("Opcion invalida"); fflush(stdin); getchar();
         }         
    }while(op != 'Z');
    
  return 0;
}

void insertarDatos(){     
     FILE *archivo;
     ESTUDIANTE est;
     
     system("cls");
     archivo = fopen("datos.dat","ab"); // Si no existe el archivo lo crea
     if(archivo){
         printf("Cedula:   ");
         fflush(stdin); scanf("%s",est.Cedula);
         printf("Nombre:   ");
         fflush(stdin); scanf("%s",est.Nombre);
         printf("Apellido: ");
         fflush(stdin); scanf("%s",est.Apellido);
         printf("Edad:     "); 
         fflush(stdin); scanf("%i",&est.Edad);    
          
         fwrite(&est,sizeof(ESTUDIANTE),1,archivo);
        
     }else printf("Error al abrir/crear archivo");
     
    fclose(archivo);
    fflush(stdin);getchar();            
}

void mostrarDatos(){
    FILE *archivo;
    ESTUDIANTE est;
    int i=0;
    
    system("cls");
    archivo = fopen("datos.dat","rb");
    if(archivo){
        fread(&est,sizeof(ESTUDIANTE),1,archivo);        
        while(!feof(archivo)){
            printf("#:          %i\n",i+1);                  
            printf("Cedula:     %s\n",est.Cedula);          
            printf("Nombre:     %s\n",est.Nombre);
            printf("Apellido:   %s\n",est.Apellido);        
            printf("Edad:       %i\n\n",est.Edad);   
            i++;      
            fread(&est,sizeof(ESTUDIANTE),1,archivo);
        }
        if(i==0) printf("No hay datos");
    }else printf("Error al abrir el archivo. Puede ser que no haya sido creado.");                 
    
    fclose(archivo);
    fflush(stdin);getchar();
}
