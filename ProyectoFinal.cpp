//Desarrollado por Briones Cárdenas Juan Carlos 
//Programa de control para prestamistas
#include<stdlib.h>
#include<stdio.h>
//#include<ctype.h>


int main() {
	int reiniciar;
	do {
		system("cls");
		int rep = 1;
		int validacion2;
		float saldoTotal = 75000;
		while (rep == 1) {
			system("cls");
			float abono = 0;
			float retiro = 0;
			int cambioMonto = 1;
			int menu = 0;
			int validacion;
			printf("\t\t\tNOTA IMPORTANTE 1 ES PARA 'SI' Y 0 ES PARA 'NO'");
			printf("\n\n\n\tEliga una opcion del menu");
			printf("\n\t1) Consultar saldo disponible actualmente");
			printf("\n\t2) Abonar dinero al saldo actual");
			printf("\n\t3) Retirar dinero del saldo para poder prestarlo");
			printf("\n\t4) Salir del menu");
			printf("\n\tPara elegir una opcion digite [1,2,3,4] segun sea la opcion: ");
			scanf_s("%i", &menu);
			if (menu != 1 && menu != 2 && menu != 3 && menu != 4) {
				printf("\n\t%i no es valido", menu);
				validacion = 0;
			}
			else {
				validacion = 1;
			}
			if (validacion == 1) {
				switch (menu)
				{
				case 1:
					printf("\n\tHas elegido (Consultar saldo disponible actualmente)");
					printf("\n\tEl saldo actual es de $%.2f", saldoTotal);
					break;
				case 2:
					printf("\n\tHas elegido (Abonar dinero al saldo actual)");
					do {
						printf("\n\tIngrese la cantidad a abonar: ");
						scanf_s("%f", &abono);
						printf("\n\tLa cantidad a abonar es $%.2f, desea cambiar el monto [1/0]: ", abono);
						scanf_s("%i", &cambioMonto);
						//cambioMonto = mayuscula(cambioMonto);
					} while (cambioMonto == 1);
					saldoTotal = saldoTotal + abono;
					printf("\n\tSu saldo final es $%.2f", saldoTotal);
					break;
				case 3:

					printf("\n\tHas elegido (Retirar dinero del saldo para poder prestarlo)");
					printf("\n\tSu saldo actual es de $%.2f", saldoTotal);
					if (saldoTotal <= 0) {
						printf("\n\tNo cuenta con saldo suficiente para retirar)");
						validacion2 = 0;
					}
					else {
						validacion2 = 1;
					}
					if (validacion2 == 1) {
						printf("\n\tIngrese monto a retirar: ");
						scanf_s("%f", &retiro);
						float res;
						res = saldoTotal - retiro;
						if (res < 0) {
							printf("\n\tNo cuenta con saldo suficiente para retirar");
							validacion2 = 0;
						}
						else {
							validacion2 = 1;
						}
						if (validacion2 == 1) {
							saldoTotal = res;
							printf("\n\tSu saldo final es de $%.2f", saldoTotal);
						}
					}
					break;
				case 4:
					printf("\n\tFin del menu");
					break;
				default:
					printf("\n\tError");
					break;
				}
			}
			printf("\n\tDesea repetir el programa?[1/0]: ");
			scanf_s("%i", &rep);
			//repetir = mayuscula(repetir);
		}
		printf("\n\tDesea reiniciar el programa?[1/0]");
		scanf_s("%i",&reiniciar);
	} while (reiniciar == 1);
	printf("\n\n\t\t\tFin del programa\n\n");
	return 0;
}