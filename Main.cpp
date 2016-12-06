# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

using namespace std;

char a[62] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
char e[62] = {'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d'};	

FILE *p, *q; 
char c;
string cadena;

int size_cad(int size){
	while(1){
		c = fgetc(p);
		if(feof(p)) break;
		if(c == '.') size--;
		size++;
	}
	return size;
}

void enc_Des(long size, int opc){
	if(opc == 1){
		for(int i = 0; i <  size; i++){
			c = fgetc(p);
			for(int j = 0; j < 62; j++){
				if(c == a[j]) { c = e[j]; cadena.append(&c); break; } 
				else if(c == 32){ c = 32; cadena.append(&c); break; }
				else if(c == 10){ c = 10; cadena.append(&c); break; }
			}
		}
		
	} else{
		for(int i = 0; i <  size; i++){
			c = fgetc(p);
			for(int j = 0; j < 62; j++){
				if(c == e[j]) { c = a[j]; cadena.append(&c); break; } 
				else if(c == 32){ c = 32; cadena.append(&c); break; }
				else if(c == 10){ c = 10; cadena.append(&c); break; }
			}
		}
	}
	c = '.'; 
	cadena.append(&c);
}

int main(void){
	int opc = 0, open = 0, size = 0;
	char Filename[50];
	printf("Elija una opc:\n1.- Encriptar Texto (Archivo Encript.txt)\n2.- Desencriptar Texto(Desencript.txt)\n");
	scanf("%i",&opc);
	system("cls");
	
	switch(opc){
		case 1:
			printf("Encriptar\n\n");
			p = fopen("Encript.txt","r");
			q = fopen("Desencript.txt","w");
			size=size_cad(size);
    		fseek(p,0,SEEK_SET);
			enc_Des(size, opc);
			fputs(cadena.c_str(),q);
			printf("Proceso Terminado, Abriendo archivo Desencript.txt\n");
			fclose(p);
			fclose(q);
			open = 1;
			break;
		case 2:
			printf("Desencriptar\n\n");
			p = fopen("Desencript.txt","r");
			q = fopen("Encript.txt","w");
			size=size_cad(size);
    		fseek(p,0,SEEK_SET);
			enc_Des(size, opc);
			fputs(cadena.c_str(),q);
			printf("Proceso Terminado, Abriendo archivo Encript.txt\n");
			fclose(p);
			fclose(q);
			open = 2;
			break;
		default:
			printf("esa no es una opcion\n");
			break;
	}
	system("pause");
	if(open == 1) system("start Desencript.txt");
	else if(open == 2) system("start Encript.txt");
}
