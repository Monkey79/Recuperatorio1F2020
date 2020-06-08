/*
 ============================================================================
 Name        : MDangeloParc1LaboV2.c
 Author      : mdangelo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn_mdangelo_test/EntitiesTest.h"
#include "utn_mdangelo_business/VeterinaryBusiness.h"

#define TEST_MODE 1

int main(void) {
	Veterinary veterinary;

	vtBsns_initializeAllVeterinary(&veterinary,TEST_MODE);

	if(!TEST_MODE)
		vtnBsn_startVeterinary(&veterinary);
	else{
		entTst_petCreationTest(&veterinary); //ok
		//entTst_updateABreedTest(&veterinary); //ok
		//entTst_deleteAPetTest(&veterinary); //ok
		//entTst_updateAPetTest(&veterinary); //ok
		//entTst_updateOwnerTest(&veterinary); //ok
		//entTst_createOwnerTest(&veterinary); //ok
		//entTst_deleteOwner(&veterinary); //ok

		//entTst_sortPetsByTypeAndShowAll(&veterinary); //ok
		//entTst_showOwnerWithPets(&veterinary); //ok
		//entTst_showPetsMoreThan3YearsAndHisOwner(&veterinary); //ok
		//entTst_showPetsByType(&veterinary); //ok
		//entTst_sortOwnerByPetsNumberAndOwnerName(&veterinary); //ok
		//entTst_calculateAndShowAllInfo(&veterinary);//ok
	}
	printf("============END==================\n");
	return EXIT_SUCCESS;
}
