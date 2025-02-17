// tao cac function

// ham hien menu chinh
void ShowMain();

// ham hien menu chinh sua danh muc
void ShowCategory();

// ham hien menu chinh sua san pham
void ShowProduct();

// ham hien menu chinh sua don hang
void ShowOrder();

// ham hien thi danh sach danh muc
//void ShowCategoryList(int a,Category CategoryList[]);

// ham them vao mot danh muc moi
void AddCategory(int *a,Category CategoryList[]);

// ham sua doi mot danh muc
void ChangeCategory(int a,Category CategoryList[]); 

// ham xoa mot danh muc theo Id
void DeleteCategory(int a,Category CategoryList[]);

// ham sap xep danh thuc 
void SortCate(int a,Category CategoryList[]);

// ham tim kiem danh muc theo ten
void FindCategory(int a,Category CategoryList[]);

// ham luu gia tri vao file
void SaveFile(int a,Category CatgoryList[]);

// ham doc gia tri cua file
void ReadFile(int a,Category CategoryList[]);

// ham truyen gia tri file khi restart
void LoadFile(int *a, Category CategoryList[]);
