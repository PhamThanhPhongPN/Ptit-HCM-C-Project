#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"


int main() {
	int choice1,choice2,choice3;
	int status = 0; // (0 = main, 1 = category, 2 = product, 3 = order)
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
						scanf("%d",&choice2);
						break;
					case 2:
						AddCategory(CategoryCount,CategoryList);
						CategoryCount++; 
						
				}
		}
	}
	return 0;
}
