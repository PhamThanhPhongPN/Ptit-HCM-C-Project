// trien khai cac function
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"

// ShowMain
void ShowMain(){
	system("color 3");
	system("cls");
	printf("* * * Store Management System Using  * * *\n\n");
	printf("%22s","MENU\n");
	printf("%33s","+========================+\n");
	printf("%33s","|[1] Category Management |\n");
	printf("%33s","+------------------------+\n");
	printf("%33s","|[2] Product Management  |\n");
	printf("%33s","+------------------------+\n");
	printf("%33s","|[3] Order Management    |\n");
	printf("%33s","+------------------------+\n");
	printf("%33s","|[0] Exit the program    |\n");
	printf("%34s","+========================+\n\n");
}

// ShowCategory
void ShowCategory(){
	system("color 2");
	system("cls");
	printf("* * * Store Management System Using  * * *\n\n");
	printf("%25s","CATEGORY\n");
	printf("%34s","+========================+\n");
	printf("%34s","|[1] Show Category List  |\n");
	printf("%34s","+------------------------+\n");
	printf("%34s","|[2] Add New Category    |\n");
	printf("%34s","+------------------------+\n");
}


// AddCategory
void AddCategory(int a,Category CategoryList[]){
	system("color 2");
	system("cls");
	printf("Type the category Id: ");
	scanf("%s",&CategoryList[a].CategoryId);
	getchar();
	printf("Type the category Name: ");
	fgets(CategoryList[a].CategoryName,100,stdin);
}

// ShowCategoryList
void ShowCategoryList(int a,Category CategoryList[]){
	system("color 2");
	system("cls");
	if (a == 0){
		printf("* * * Store Management System Using  * * *\n\n");
		printf("%10s","Khong co danh muc nao da duoc tao.\n");
		printf("%10s","Vui long nhap bat ky ky tu de quay tro lai: ");
	} else {
		printf("* * * Store Management System Using  * * *\n\n");
		int i = 0;
		for (i; i < a; i++){
			printf("%s. %s\n",CategoryList[i].CategoryId,CategoryList[i].CategoryName);
		} 
	}
}
