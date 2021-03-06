/*
 * OwnerService.c
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "OwnerService.h"

#define OWNER_MSSG_1 "De los siguientes ids de dueños seleccione uno:\n"

//********Private Functions***********
void _showAllOwners(Owner owners[],int ownerTop,Location locations[]);
void _showHeaderDataGrid(void);
//************************************

void ownerSvc_initializeAllOwners(Owner owners[], int ownerTop){
	ownerRp_initializeAllOwner(owners, ownerTop);
}

void ownerSvc_getValidOwnerId(Owner owners[],int *ownerId, int ownerTop, Location locations[]){
	printf(OWNER_MSSG_1);
	do{
		_showAllOwners(owners,ownerTop,locations);
		__fpurge(stdin);
		scanf("%d",ownerId);
	}while(!ownerSvc_checkIsValidOwnerId(owners,*ownerId));
}

int ownerSvc_deleteOwner(Owner owners[],int ownerTop, int ownerDeleteId){
	return ownerRp_deleteOwnerById(owners, ownerTop, ownerDeleteId);
}
int ownerSvc_createOwner(Owner owners[], int ownerTop, int *ownerId, Location locations[]){
	Owner newOwner;
	int locId;

	printf("Ingrese nombre del cliente:");
	__fpurge(stdin);
	fgets(newOwner.name, 50, stdin);
	utilLb_cleanStrValue(newOwner.name);

	printf("Ingrese apellido del cliente:");
	__fpurge(stdin);
	fgets(newOwner.lastName, 50, stdin);
	utilLb_cleanStrValue(newOwner.lastName);

	locSvc_getValidLocationId(locations, LOCATION_TOP, &locId);

	printf("Ingrese telefono del cliente:");
	__fpurge(stdin);
	fgets(newOwner.phoneNumber, 50, stdin);
	utilLb_cleanStrValue(newOwner.phoneNumber);

	do {
		printf("Ingrese la edad del cliente: ");
		scanf("%d", &newOwner.age);
	} while (newOwner.age < 0);
	do {
		printf("Ingrese genero del cliente [M | F]");
		__fpurge(stdin);
		scanf("%c", &newOwner.gender);
		newOwner.gender = toupper(newOwner.gender);
	} while (newOwner.gender != 'M' && newOwner.gender != 'F');

	newOwner.locationId = locId;
	newOwner.id = ++(*ownerId);
	return ownerRp_addOwner(owners, ownerTop, newOwner);
}

int ownerSvc_updateOwner(Owner owners[],int ownerTop, int ownerUpdId, Location locations[]){
	Owner updtOwner;
	int locId;

	printf("Ingrese nuevo nombre del cliente:");
	__fpurge(stdin);
	fgets(updtOwner.name, 50, stdin);
	utilLb_cleanStrValue(updtOwner.name);

	printf("Ingrese nuevo apellido del cliente:");
	__fpurge(stdin);
	fgets(updtOwner.lastName, 50, stdin);
	utilLb_cleanStrValue(updtOwner.lastName);


	printf("-----Actualice la localidad-----\n");
	locSvc_getValidLocationId(locations, LOCATION_TOP, &locId);
	printf("---------------------------------\n");

	printf("Ingrese nuevo telefono del cliente:");
	__fpurge(stdin);
	fgets(updtOwner.phoneNumber, 50, stdin);
	utilLb_cleanStrValue(updtOwner.phoneNumber);

	do {
		printf("Ingrese nueva edad del cliente: ");
		scanf("%d", &updtOwner.age);
	} while (updtOwner.age < 0);
	do {
		printf("Ingrese nuevo genero del cliente [M | F]");
		__fpurge(stdin);
		scanf("%c", &updtOwner.gender);
		updtOwner.gender = toupper(updtOwner.gender);
	} while (updtOwner.gender != 'M' && updtOwner.gender != 'F');
	updtOwner.locationId = locId;
	updtOwner.id = ownerUpdId;
	return ownerRp_updateOwner(owners, ownerTop, updtOwner);
}

int ownerSvc_checkIsValidOwnerId(Owner owners[],int ownerId){
	int i;
	for(i=0;i<OWNER_TOP && (owners[i].id != ownerId || owners[i].empty);i++);
	return (owners[i].id == ownerId);
}
void ownerSvc_getLength(Owner owners[],int *len,int ownerTop){
	for(int i=0;i<ownerTop;i++){
		if(!owners[i].empty) (*len)++;
	}
}

/*************Private functions****************************/
void _showAllOwners(Owner owners[],int ownerTop,Location locations[]){
	char locEsate[50];
	int locCodPost;
	_showHeaderDataGrid();
	for(int i=0;i<ownerTop;i++){
		if(!owners[i].empty){
			locSvc_getLocationInfoById(locations, LOCATION_TOP, owners[i].locationId, locEsate, &locCodPost);

			printf("%d \t%20s \t%15s \t%15s \t%10s \t%12d \t%12c\n", owners[i].id,
							owners[i].name, owners[i].lastName,
							locEsate,owners[i].phoneNumber,
							owners[i].age, owners[i].gender);
		}
	}
}

void _showHeaderDataGrid(void){
	printf("Owner_Id\t");
	printf("Owner_Name\t");
	printf("Owner_Lastname\t\t");
	printf("Owner_Location\t\t");
	printf("Owner_PhoneNumber\t");
	printf("Owner_Age\t");
	printf("Owner_Gender\t\n");
}
