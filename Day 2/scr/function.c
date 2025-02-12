// trien khai cac function
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
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
	printf("%34s","+=========================+\n");
	printf("%34s","|[1] Show Category List   |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[2] Add New Category     |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[3] Change Category Info |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[4] Delete Category      |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[5] Find Category By Name|\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[6] Sort Category By Name|\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[0] Return To Main Menu  |\n");
	printf("%35s","+=========================+\n\n");
}


// AddCategory
void AddCategory(int a,Category CategoryList[]){
	system("color 2");
	system("cls");
	printf("* * * Store Management System Using  * * *\n\n");
	printf("Type the category Id: ");
	scanf("%s",&CategoryList[a].CategoryId);
	getchar();
	printf("Type the category Name: ");
	fgets(CategoryList[a].CategoryName,100,stdin);
	printf("Added category successfully.\n");
	printf("Press any key to go back: ");
}

// ShowCategoryList
void ShowCategoryList(int a, Category CategoryList[]){
    system("color 2");
    system("cls");
    if (a == 0){
        printf("* * * Store Management System Using * * *\n\n");
        printf("   No categories have been created yet.\n");
        printf("   Please enter any key to go back: ");
    } else{
        printf("* * * Store Management System Using * * *\n\n");
        printf("+------+----------------------------+\n");
        printf("| %-4s | %-26s |\n", "ID", "Category Name");
        printf("+------+----------------------------+\n");
		int i = 0;
        for (i; i < a; i++){
        	if (CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] == '\n') {
                CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] = '\0';
            }
            if (CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] == '\n') {
                CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] = '\0';
            }
            printf("| %-4s | %-26s |\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            printf("+------+----------------------------+\n");
        }
        
    }
}



// ChangeCategory
void ChangeCategory(int a,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	char index[10];
	printf("Type Category Id to change: ");
	scanf("%s",&index);
	int i =0; 
	for (i;i < a;i++){
		if ((strcmp(index,CategoryList[i].CategoryId)) == 0){
			printf("%s. %s",CategoryList[i].CategoryId,CategoryList[i].CategoryName);
			printf("Type in new name: ");
			getchar(); 
			fgets(CategoryList[i].CategoryName,100,stdin); 
			printf("Category changed successfully.\n");
			printf("Press any key to go back.");
			return; 
		} 
	} 
	printf("Unable to find mentioned Id.\n");
	printf("Press any key to go back: "); 
} 
