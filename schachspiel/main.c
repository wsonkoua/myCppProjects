#include <stdio.h>
//#include <conio.h>


void printField(int *field) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) 
			printf(" %d", *(field+ (i*8) + j));
		
		printf("\n");
	}
}
void move(int *field, int *posX, int *posY, char zug) {
	
	if (zug == 'w'){

		if (*posX == 0) {

			*(field + ((*posX)* 8) + *posY ) = 0;
			*posX = 7;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}else {

			*(field + ((*posX) * 8) + *posY) = 0;
			*posX -= 1;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}

	}
	if( zug=='a'){
		if (*posY == 0) {
			*(field + ((*posX) * 8) + *posY) = 0;
			*posY = 7;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
		else {

			*(field + ((*posX) * 8) + *posY) = 0;
			*posY -= 1;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
	}
	if (zug == 's') {
		if (*posX == 7) {
			*(field + ((*posX) * 8) + *posY) = 0;
			*posX = 0;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
		else {
			*(field + ((*posX) * 8) + *posY) = 0;
			*posX += 1;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
	}
	if (zug == 'd') {
		if (*posY == 7) {
			*(field + ((*posX) * 8) + *posY) = 0;
			*posY = 0;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
		else {
			*(field + ((*posX) * 8) + *posY) = 0;
			*posY += 1;
			*(field + ((*posX) * 8) + *posY) = 1;
			printField(field);
		}
	}
	
}
void main(void) {
	int arr[8][8] = { 0 };

	arr[0][0] = 1;

	int positionX = 0, positionY = 0;
	char bewegungswunsch;
	printf("beenden mit x\n");

	printField(&arr[0][0]);
	do{
		printf("Zug [w hoch, a links, s runter, d rechts]: ");
		scanf("%c", &bewegungswunsch);
		puts(" ");
		move(&arr[0][0], &positionX, &positionY, bewegungswunsch);
		/*printf("Zug [w hoch, a links, s runter, d rechts]: ");
		scanf_s("%c", &bewegungswunsch);
		puts(" ");*/
	}while (bewegungswunsch != 'x');
	//_getch();
}