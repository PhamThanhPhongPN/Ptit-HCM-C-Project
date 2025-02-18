// trien khai cac function
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h> 
#include <conio.h>  
#include "datatype.h"
#include "function.h"
 
// LoadFile
void LoadFile(int *size, Category CategoryList[]){
    FILE *file = fopen("category.bin", "rb"); 
    if (file == NULL){
        *size = 0; 
        return;
    }
    size_t numRead = fread(CategoryList, sizeof(Category), 1000, file);
    fclose(file);
    *size = (int)numRead; 
}

 // FileSave
 void SaveFile(int size, Category CategoryList[]){
    FILE *file = fopen("category.bin", "wb");
    if (file == NULL){
        perror("Error opening file");
        return;
    }	
    if (fwrite(CategoryList, sizeof(Category), size, file) != size){
        perror("Error writing to file");
        fclose(file);
        return;
    }
    printf("Data written successfully.\n");
    fclose(file);
    return;
 }
 
 // FileRead
 void ReadFile(int size, Category CategoryList[]){
 	system("color 3");
 	system("cls");
 	    FILE *file = fopen("category.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
   	size_t numRead;
 	numRead = fread(CategoryList, sizeof(Category), 1000, file);
    if (numRead == 0){
        if (feof(file)){
            printf("The file is empty or contains no valid data.\n");
        } else{
            perror("Error reading file");
        }
        fclose(file);
        return;
    }
	size_t i;
    printf("Number of categories read: %zu\n", numRead);
    for (i = 0; i < numRead; i++){
        printf("========================\n");
        printf("  ID: %s\n", CategoryList[i].CategoryId);
        printf("  Name: %s\n", CategoryList[i].CategoryName);
    }
    fclose(file);
   	printf("\nPress any key to go back: ");
    return;
}

// LoadAmin
void LoadAdmin(Admin *AdminLogIn){
    FILE *file = fopen("admin.bin", "rb"); 
    if (file == NULL){
        printf("Error: Could not open file.\n");
        return;
    }
    fread(AdminLogIn, sizeof(Admin), 1, file);
    AdminLogIn->Username[sizeof(AdminLogIn->Username) - 1] = '\0'; 
    AdminLogIn->Password[sizeof(AdminLogIn->Password) - 1] = '\0';
    size_t len = strlen(AdminLogIn->Username);
    size_t i;
    for (i = len; i > 0; i--){
        if (AdminLogIn->Username[i - 1] == ' ' || AdminLogIn->Username[i - 1] == '\0'){
            AdminLogIn->Username[i - 1] = '\0';
        } else{
            break;
        }
    }
    fclose(file);
}

//========================================================================================================================================

// ShowSignIn
void ShowLogIn(){
	system("color 2");
	system("cls");
	printf("* * * Store Management System Using  C* * *\n\n");
	printf("%22s","Log In\n");
	printf("%33s","+========================+\n");
	printf("%33s","|[1] Admin login         |\n");
	printf("%33s","+------------------------+\n");
	printf("%33s","|[2] User login          |\n");
	printf("%33s","+------------------------+\n");
	printf("%33s","|[0] Exit the program    |\n");
	printf("%34s","+========================+\n\n");
} 

// LogInAdmin
int LogInAdmin(Admin AdminLogIn){
    system("color 2");
    system("cls");
    printf("* * * Store Management System Using C * * *\n\n");
    printf("%22s", "Admin Log In\n");
    char username[10];  
    char password[10]; 
    printf("Enter username: ");
	scanf("%s",&username); 
    if (strcasecmp(username, AdminLogIn.Username) == 0){
        printf("Enter password: ");
        char ch;
        int i = 0;
        while ((ch = _getch()) != '\r' && i < sizeof(password) - 1){  
            password[i] = ch;
            i++;
            printf("*");
        }
        password[i] = '\0';
        if (strcmp(password, AdminLogIn.Password) == 0){
            printf("\nPassword correct!\n");
            printf("Welcome Admin.\n");
            printf("Press any keys to proceed: ");
            return 1;
        } else{
            printf("\nIncorrect Password.\n");
            return 0;
        }
    } else{
        printf("Unable to find Username.\n");
        return 0;  // Username not found
    }
}

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
	printf("* * * Store Management System Using C* * *\n\n");
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
	printf("%34s","|[7] Read Binary File     |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[8] Save Binary File     |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[0] Return To Main Menu  |\n");
	printf("%35s","+=========================+\n\n");
}

// ShowProduct
void ShowProduct(){
	system("color 4");
	system("cls");
	printf("* * * Store Management System Using C* * *\n\n");
	printf("%24s","PRODUCT\n");
	printf("%34s","+=========================+\n");
	printf("%34s","|[1] Show Product List    |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[2] Add New Product      |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[3] Change Product Info  |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[4] Delete Product       |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[5] Find Product By Name |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[6] Sort Product By Price|\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[7] Product Filter       |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[0] Return To Main Menu  |\n");
	printf("%35s","+=========================+\n\n");
}	

// ShowOrder
void ShowOrder(){
	system("color 6");
	system("cls");
	printf("* * * Store Management System Using C* * *\n\n");
	printf("%22s","ORDER\n");
	printf("%34s","+=========================+\n");
	printf("%34s","|[1] Show Order List      |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[2] Show Order Info      |\n");
	printf("%34s","+-------------------------+\n");
	printf("%34s","|[0] Return To Main Menu  |\n");
	printf("%35s","+=========================+\n\n");
}
//================================================================================================================================================

// AddCategory
void AddCategory(int *size,Category CategoryList[]){
	system("color 2");
	system("cls");
	char id[10],name[10];
	printf("* * * Store Management System Using C* * *\n\n");
	printf("Type the category Id: ");
	scanf("%s",&id);
	getchar();
	printf("Type the category Name: ");
	fgets(name,100,stdin);
	size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n'){
        name[len - 1] = '\0';
    }
	if (strlen(id) > 10){
		printf("Lenght of Id is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strlen(name) > 10){
		printf("Length of name is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strcmp(id,name) == 0){
		printf("Id and Name cannot be indentical.\n");
		printf("Press any key to go back: ");
		return;
	} else {
		strcpy(CategoryList[*size].CategoryId,id);
		strcpy(CategoryList[*size].CategoryName,name);
		(*size)++;
		printf("Added category successfully.\n");
		printf("Press any key to go back: ");	
	}			
}

// ShowCategoryList
void ShowCategoryList(int size, Category CategoryList[]){
    system("color 2");
    system("cls");
    if (size == 0){
        printf("* * * Store Management System Using C* * *\n\n");
        printf("   No categories have been created yet.\n");
        printf("   Please enter any key to go back: ");
    } else{
        printf("* * * Store Management System Using C* * *\n\n");
        printf("+------+----------------------------+\n");
        printf("| %-4s | %-26s |\n", "ID", "Category Name");
        printf("+------+----------------------------+\n");
		int i = 0;
        for (i; i < size; i++){
        	if (CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] == '\n'){
                CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] = '\0';
            }
            if (CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] == '\n'){
                CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] = '\0';
            }
            printf("| %-4s | %-26s |\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            printf("+------+----------------------------+\n");
        }
    }
    printf("Press any key to go back: "); 
}

// ChangeCategory
void ChangeCategory(int size,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	char index[10];
	printf("Type Category Id to change: ");
	scanf("%s",&index);
	int i =0; 
	printf("* * * Store Management System Using C* * *\n\n");
	for (i;i < size;i++){
		if ((strcmp(index,CategoryList[i].CategoryId)) == 0){
			printf("%s. %s\n",CategoryList[i].CategoryId,CategoryList[i].CategoryName);
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
void DeleteCategory(int size, Category CategoryList[]){
    system("color 2");
    system("cls"); 
    printf("* * * Store Management System Using C* * *\n\n");
    
    char index[10];
    int confirm;
    printf("Type Category Id to delete: ");
    scanf("%s", index);
    int i,j; 
    int found = 0;
    for (i = 0; i < size; i++){
        if (strcmp(index, CategoryList[i].CategoryId) == 0){
            found = 1;
            printf("%s. %s\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            printf("Confirm deletion (yes: 1, no: 0): ");
            scanf("%d", &confirm);       
            if (confirm == 0) {
                return; 
            } else if (confirm == 1) {
                for (j = i; j < size - 1; j++) {
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
void SortCate(int size,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	int choice;
	int status = 0;
	char temp[20];
	int i,j;
	while (1){
		printf("* * * Store Management System Using C* * *\n\n");
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
				for (i = 0; i < size -1;i++){
					for (j=0; j < size - 1 - i;j++){
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
				for (i = 0; i < size -1;i++){
					for (j=0; j < size - 1 - i;j++){
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
void FindCategory(int size,Category CategoryList[]){
	system("color 2");
	system("cls"); 
	printf("* * * Store Management System Using C* * *\n\n");
	char name[20];
	printf("Type the category name to search: ");
	getchar();
	fgets(name,20,stdin);
	name[strcspn(name, "\n")] = '\0';
	int i, found = 0;
    for (i = 0; i < size; i++){
        if (strstr(CategoryList[i].CategoryName, name)){
            if (!found){
                printf("Categories that mentioned %s: \n", name);
            }
            if (CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] == '\n'){
                CategoryList[i].CategoryId[strlen(CategoryList[i].CategoryId) - 1] = '\0';
            }
            if (CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] == '\n'){
                CategoryList[i].CategoryName[strlen(CategoryList[i].CategoryName) - 1] = '\0';
            }
            printf("+------+----------------------------+\n");
            printf("| %-4s | %-26s |\n", CategoryList[i].CategoryId, CategoryList[i].CategoryName);
            found = 1;
        }
    }
    if (!found){
        printf("Unable to find mentioned name.\n");
    } else{
        printf("+------+----------------------------+\n");
    }
    printf("Press any key to go back: ");
}

//==================================================================================================================================

// ShowProductList
void ShowProductList(int size, Product ProductList[]){
    system("color 4");
    system("cls");
    if (size == 0){
        printf("* * * Store Management System Using C* * *\n\n");
        printf("   No products have been created yet.\n");
        printf("   Please enter any key to go back: ");
    } else{
        printf("* * * Store Management System Using C* * *\n\n");
        printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
        printf("| %-14s | %-26s | %-26s | %-14s | %-14s |\n", "Product Id", "Category Id", "Product Name", "Quantity", "Price");
        printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
		int i = 0;
        for (i; i < size; i++){
        	if (ProductList[i].ProductId[strlen(ProductList[i].ProductId) - 1] == '\n'){
                ProductList[i].ProductId[strlen(ProductList[i].ProductId) - 1] = '\0';
            }
            if (ProductList[i].CategoryId[strlen(ProductList[i].CategoryId) - 1] == '\n'){
                ProductList[i].CategoryId[strlen(ProductList[i].CategoryId) - 1] = '\0';
            }
            if (ProductList[i].ProductName[strlen(ProductList[i].ProductName) - 1] == '\n'){
                ProductList[i].ProductName[strlen(ProductList[i].ProductName) - 1] = '\0';
            }
            printf("| %-14s | %-26s | %-26s | %-14d | %-14d |\n", ProductList[i].ProductId, ProductList[i].CategoryId, ProductList[i].ProductName, ProductList[i].Quantity, ProductList[i].Price);
            printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
        }
        printf("Press any key to go back: ");
    }
}

// AddProduct
void AddProduct(int *size, Product ProductList[]){
	system("color 4");
    system("cls");
	char Pid[10],Cid[10],Pname[10];
	int quantity, price;
	printf("* * * Store Management System Using C* * *\n\n");
	printf("Type the product Id: ");
	scanf("%9s",&Pid);
	getchar();
	printf("Type the category Id: ");
	scanf("%9s",&Cid);
	getchar();
	printf("Type the product name: ");
	fgets(Pname,10,stdin);
	printf("Type the quantity: ");
	scanf("%d",&quantity);
	getchar();
	printf("Type the price: ");
	scanf("%d",&price);
	getchar();
	size_t len = strlen(Pname);
    if (len > 0 && Pname[len - 1] == '\n'){
        Pname[len - 1] = '\0';
    }
	if (strlen(Pid) > 10){
		printf("Lenght of Id is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	}else if (strlen(Cid) > 10){
		printf("Length of Id is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strlen(Pname) > 10){
		printf("Length of name is not appropriate.\n");
		printf("Press any key to go back: ");
		return;
	} else if (strcmp(Pid,Pname) == 0){
		printf("Id and Name cannot be indentical.\n");
		printf("Press any key to go back: ");
		return;
	} else {
		strcpy(ProductList[*size].ProductId,Pid);
		strcpy(ProductList[*size].CategoryId,Cid);
		strcpy(ProductList[*size].ProductName,Pname);
		ProductList[*size].Quantity = quantity;
   		ProductList[*size].Price = price;
		(*size)++;
		printf("Added Product successfully.\n");
		printf("Press any key to go back: ");	
	}			
}\

// ChangeProduct
void ChangeProduct(int size, Product ProductList[]){
	system("color 4");
	system("cls");
	printf("* * * Store Management System Using C* * *\n\n"); 
	char index[10];
	int quan, price;
	printf("Type Product Id to change: ");
	scanf("%s",&index);
	int i =0; 
	for (i;i < size;i++){
		if ((strcmp(index,ProductList[i].ProductId)) == 0){
			printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
        	printf("| %-14s | %-26s | %-26s | %-14s | %-14s |\n", "Product Id", "Category Id", "Product Name", "Quantity", "Price");
			printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
			printf("| %-14s | %-26s | %-26s | %-14d | %-14d |\n", ProductList[i].ProductId, ProductList[i].CategoryId, ProductList[i].ProductName, ProductList[i].Quantity, ProductList[i].Price);
			printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n\n");	
			printf("Type in new name: ");
			getchar(); 
			fgets(ProductList[i].ProductName,100,stdin);
			printf("Type in new quantity : ");
			scanf("%d",&quan);
			printf("Type in new price: ");
			scanf("%d",&price);
			ProductList[i].Quantity = quan;
   			ProductList[i].Price = price;
			printf("Product changed successfully.\n");
			printf("Press any key to go back.");
			return; 
		} 
	} 
	printf("Unable to find mentioned Id.\n");
	printf("Press any key to go back: "); 
} 

// DeleteProduct
void DeleteProduct(int size, Product ProductList[]){
    system("color 4");
    system("cls"); 
    printf("* * * Store Management System Using C* * *\n\n");
    char index[10];
    int confirm;
    printf("Type Product Id to delete: ");
    scanf("%s", index);
    int i,j; 
    int found = 0;
    for (i = 0; i < size; i++){
        if (strcmp(index, ProductList[i].ProductId) == 0){
            found = 1;
           	printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
        	printf("| %-14s | %-26s | %-26s | %-14s | %-14s |\n", "Product Id", "Category Id", "Product Name", "Quantity", "Price");
			printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
			printf("| %-14s | %-26s | %-26s | %-14d | %-14d |\n", ProductList[i].ProductId, ProductList[i].CategoryId, ProductList[i].ProductName, ProductList[i].Quantity, ProductList[i].Price);
			printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n\n");
            printf("Confirm deletion (yes: 1, no: 0): ");
            scanf("%d", &confirm);       
            if (confirm == 0) {
                return; 
            } else if (confirm == 1){
                for (j = i; j < size - 1; j++){
                    strcpy(ProductList[j].ProductId, ProductList[j + 1].ProductId);
                    strcpy(ProductList[j].CategoryId, ProductList[j + 1].CategoryId);
                    strcpy(ProductList[j].ProductName, ProductList[j + 1].ProductName);
                    ProductList[j].Quantity = ProductList[j +1].Quantity;
                    ProductList[j].Price = ProductList[j +1].Price;
                }
                printf("Delete Category successful.\n");
                printf("Press any key to go back: "); 
            }
        }
    }
    if (!found){
        printf("Unable to find mentioned Id.\n");
        printf("Press any key to go back: "); 
    }
    return;
}

// FindProduct
void FindProduct(int size, Product ProductList[]){
    system("color 4");
    system("cls"); 
    printf("* * * Store Management System Using C* * *\n\n");
    char name[20];
    printf("Type the Product name to search: ");
    getchar();
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0'; 
    int i,found = 0;
    for (i = 0; i < size; i++){
        if (strstr(ProductList[i].ProductName, name)){
            if (!found){
                printf("Products that mention '%s':\n", name);
                printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
                printf("| %-14s | %-26s | %-26s | %-14s | %-14s |\n", "Product Id", "Category Id", "Product Name", "Quantity", "Price");
                printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
            }
            printf("| %-14s | %-26s | %-26s | %-14d | %-14d |\n", 
                   ProductList[i].ProductId, 
                   ProductList[i].CategoryId, 
                   ProductList[i].ProductName, 
                   ProductList[i].Quantity, 
                   ProductList[i].Price);
            printf("+----------------+----------------------------+----------------------------+----------------+----------------+\n");
            found = 1;
        }
    }
    if (!found){
        printf("Unable to find a product containing '%s'.\n", name);
    }
    printf("Press any key to go back: ");
}

// SortProduct
void SortProduct(int size, Product ProductList[]){
	system("color 4");
	system("cls"); 
	int choice;
	int status = 0;
	char temp[20];
	int temp1;
	int i,j;
	while (1){
		printf("* * * Store Management System Using C* * *\n\n");
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
				for (i = 0; i < size -1;i++){
					for (j=0; j < size - 1 - i;j++){
						if (ProductList[j].Price < ProductList[j+1].Price){
							// swap Product Id
							strcpy(temp,ProductList[j].ProductId);
							strcpy(ProductList[j].ProductId,ProductList[j+1].ProductId);
							strcpy(ProductList[j+1].ProductId,temp);
							// swap name
							strcpy(temp,ProductList[j].ProductName);
							strcpy(ProductList[j].ProductName,ProductList[j+1].ProductName);
							strcpy(ProductList[j+1].ProductName,temp);
							// swap cate id 
							strcpy(temp,ProductList[j].CategoryId);
							strcpy(ProductList[j].CategoryId,ProductList[j+1].CategoryId);
							strcpy(ProductList[j+1].CategoryId,temp);
							// swap quan
							temp1 = ProductList[j].Quantity;
							ProductList[j].Quantity = ProductList[j+1].Quantity;
							ProductList[j+1].Quantity = temp1;
							// swap price
							temp1 = ProductList[j].Price;
							ProductList[j].Price = ProductList[j+1].Price;
							ProductList[j+1].Price = temp1;
						}
					}
				}
				status = 1;
				break;
			case 2:
				for (i = 0; i < size -1;i++){
					for (j=0; j < size - 1 - i;j++){
						if (ProductList[j].Price > ProductList[j+1].Price){
							// swap Product Id
							strcpy(temp,ProductList[j].ProductId);
							strcpy(ProductList[j].ProductId,ProductList[j+1].ProductId);
							strcpy(ProductList[j+1].ProductId,temp);
							// swap name
							strcpy(temp,ProductList[j].ProductName);
							strcpy(ProductList[j].ProductName,ProductList[j+1].ProductName);
							strcpy(ProductList[j+1].ProductName,temp);
							// swap cate id 
							strcpy(temp,ProductList[j].CategoryId);
							strcpy(ProductList[j].CategoryId,ProductList[j+1].CategoryId);
							strcpy(ProductList[j+1].CategoryId,temp);
							// swap quan
							temp1 = ProductList[j].Quantity;
							ProductList[j].Quantity = ProductList[j+1].Quantity;
							ProductList[j+1].Quantity = temp1;
							// swap price
							temp1 = ProductList[j].Price;
							ProductList[j].Price = ProductList[j+1].Price;
							ProductList[j+1].Price = temp1;
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
