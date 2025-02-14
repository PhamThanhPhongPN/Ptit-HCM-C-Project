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
	char id[10],name[10];
	printf("* * * Store Management System Using  * * *\n\n");
	printf("Type the category Id: ");
	scanf("%s",&id);
	getchar();
	printf("Type the category Name: ");
	fgets(name,100,stdin);
	size_t len = strlen(CategoryList[a].CategoryName);
        if (len > 0 && CategoryList[a].CategoryName[len - 1] == '\n') {
        	CategoryList[a].CategoryName[len - 1] = '\0';
        }
	if (strlen(CategoryList[a].CategoryId) > 10){
		printf("Lenght of Id is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strlen(CategoryList[a].CategoryName) > 10){
		printf("Length of name is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strcmp(CategoryList[a].CategoryId,CategoryList[a].CategoryName) == 0){
		printf("Id and Name cannot be indentical.\n");
		printf("Press any key to go back: ");
		return;
	} else {
		strcpy(CategoryList[a].CategoryId,id);
		strcpy(CategoryList[a].CategoryName,name);
		printf("Added category successfully.\n");
		printf("Press any key to go back: ");	
	}			
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

// DeleteCategory
void DeleteCategory(int a, Category CategoryList[]){
    system("color 2");
    system("cls"); 
    printf("* * * Store Management System Using * * *\n\n");
    
    char index[10];
    int confirm;
    printf("Type Category Id to delete: ");
    scanf("%s", index);
    int i,j; 
    int found = 0;
    for (i = 0; i < a; i++){
        if (strcmp(index, CategoryList[i].CategoryId) == 0){
            found = 1;
            printf("%s. %s\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            printf("Confirm deletion (yes: 1, no: 0): ");
            scanf("%d", &confirm);       
            if (confirm == 0) {
                return; 
            } else if (confirm == 1) {
                for (j = i; j < a - 1; j++) {
                    strcpy(CategoryList[j].CategoryId, CategoryList[j + 1].CategoryId);
                    strcpy(CategoryList[j].CategoryName, CategoryList[j + 1].CategoryName);
                }
                printf("Delete Category successful.\n");
                printf("Press any key to go back: "); 
            }
        }
    }
    
    if (!found) {
        printf("Unable to find mentioned Id.\n");
        printf("Press any key to go back: "); 
    }
    
    return;
}


// SortCategory
void SortCate(int a,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	int choice;
	int status = 0;
	char temp[20];
	int i,j;
	while (1){
		printf("* * * Store Management System Using * * *\n\n");
		printf("%25s","SORTING\n");
		printf("%34s","+=========================+\n");
		printf("%34s","|[1] Descending           |\n");
		printf("%34s","+-------------------------+\n");
		printf("%34s","|[2] Ascending            |\n");
		printf("%34s","+-------------------------+\n");
		printf("%34s","|[0] Return               |\n");
		printf("%34s","+-------------------------+\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				for (i = 0; i < a -1;i++){
					for (j=0; j < a - 1 - i;j++){
						if (strcmp(CategoryList[j].CategoryName,CategoryList[j+1].CategoryName) < 0){
							// swap Id
							strcpy(temp,CategoryList[j].CategoryId);
							strcpy(CategoryList[j].CategoryId,CategoryList[j+1].CategoryId);
							strcpy(CategoryList[j+1].CategoryId,temp);
							// swap name
							strcpy(temp,CategoryList[j].CategoryName);
							strcpy(CategoryList[j].CategoryName,CategoryList[j+1].CategoryName);
							strcpy(CategoryList[j+1].CategoryName,temp);
						}
					}
				}
				status = 1;
				break;
			case 2:
				for (i = 0; i < a -1;i++){
					for (j=0; j < a - 1 - i;j++){
						if (strcmp(CategoryList[j].CategoryName,CategoryList[j+1].CategoryName) > 0){
							// swap Id
							strcpy(temp,CategoryList[j].CategoryId);
							strcpy(CategoryList[j].CategoryId,CategoryList[j+1].CategoryId);
							strcpy(CategoryList[j+1].CategoryId,temp);
							// swap name
							strcpy(temp,CategoryList[j].CategoryName);
							strcpy(CategoryList[j].CategoryName,CategoryList[j+1].CategoryName);
							strcpy(CategoryList[j+1].CategoryName,temp);
						}
					}
				}
			case 0:
				status = 1;
				break;
		}
		if (status == 1){
			break;
		}
	}
}

// FindCategory
void FindCategory(int a,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	printf("* * * Store Management System Using * * *\n\n");
	char name[20];
	printf("Type the category name to search: ");
	getchar();
	fgets(name,20,stdin);
	name[strcspn(name, "\n")] = '\0';
	int i, found = 0;
    for (i = 0; i < a; i++) {
        if (strstr(CategoryList[i].CategoryName, name)){
            if (!found){
                printf("Categories that mentioned %s: \n", name);
            }
            if (CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] == '\n') {
                CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] = '\0';
            }
            if (CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] == '\n') {
                CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] = '\0';
            }
            printf("+------+----------------------------+\n");
            printf("| %-4s | %-26s |\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            found = 1;
        }
    }
    if (!found){
        printf("Unable to find mentioned name.\n");
    } else {
        printf("+------+----------------------------+\n");
    }
    printf("Press any key to go back: ");
}
