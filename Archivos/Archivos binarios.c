#include<stdio.h>
#include<stdlib.h>

typedef struct Estudiante{
       char cedula[10];
       char nombre[20];
       char apellido[20];
       int edad;       
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
             case '1': insertarDatos(); break;                    
             case '2': mostrarDatos(); break;
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
         fflush(stdin); gets(est.cedula);
         printf("Nombre:   ");
         fflush(stdin); gets(est.nombre);
         printf("Apellido: ");
         fflush(stdin); gets(est.apellido);
         printf("Edad:     "); 
         fflush(stdin); scanf("%i",&est.edad);    
          
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
            printf("Cedula:     %s\n",est.cedula);          
            printf("Nombre:     %s\n",est.nombre);
            printf("Apellido:   %s\n",est.apellido);        
            printf("Edad:       %i\n\n",est.edad);   
            i++;      
            fread(&est,sizeof(ESTUDIANTE),1,archivo);
        }
        if(i==0) printf("No hay datos");
    }else printf("Error al abrir el archivo. Puede ser que no haya sido creado.");                 
    
    fclose(archivo);
    fflush(stdin);getchar();
}
