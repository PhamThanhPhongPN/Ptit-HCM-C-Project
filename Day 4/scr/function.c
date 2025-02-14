#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "datatype.h"
#include "function.h"


int main() {
	int choice1,choice2;
	char choice3[5]; // 
	int status = 0; // (0 = main, 1 = category, 2 = product, 3 = order, 4 = exit)
	int CategoryCount = 0;
	Category CategoryList[1000];
	while (1){
		if (status == 0){
			ShowMain();
			printf("Enter your choice: ");
			scanf("%d",&choice1);
		}
		switch (choice1){
			case 1:
				ShowCategory();
				status = 1;
				printf("Enter your choice: ");
				scanf("%d",&choice2);
				switch (choice2){
					case 1:
						ShowCategoryList(CategoryCount, CategoryList);
						scanf("%s",&choice3);
						break;
					case 2:	
						AddCategory(&CategoryCount,CategoryList);
						scanf("%s",&choice3);		
						break;
					case 3:
						ChangeCategory(CategoryCount,CategoryList);
						scanf("%s",&choice3);
						break; 
					case 4:
						DeleteCategory(CategoryCount,CategoryList);
						scanf("%s",&choice3);
						CategoryCount--;
						break;
					case 5:
						FindCategory(CategoryCount,CategoryList);
						scanf("%s",&choice3);
						break;
					case 6:
						SortCate(CategoryCount,CategoryList);
						ShowCategoryList(CategoryCount, CategoryList);
						scanf("%s",&choice3);
						break;
					case 0:
						status = 0; 
						ShowMain();
						break; 
					default:
						status = 0;
						ShowMain();
						break;
					}
				break; 
			case 2:
				ShowProduct();
				status = 2;
				printf("Enter your choice: ");
				scanf("%d",&choice2);
				break;
			case 3:
				ShowOrder();
				status = 3;
				printf("Enter your choice: ");
				scanf("%d",&choice2);
				break;
			case 0:
				system("cls"); 
				printf("==========Thank you==========\n");
				printf("==========*GOODBYE*==========\n");
				status = 4; 
				break; 
		}
		if (status == 4){
			break; 
		} 
	}
	return 0;
}
