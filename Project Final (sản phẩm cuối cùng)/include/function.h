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
void ShowCategoryList(int size,Category CategoryList[]);

// ham them vao mot danh muc moi
void AddCategory(int *size,Category CategoryList[]);

// ham sua doi mot danh muc
void ChangeCategory(int size,Category CategoryList[]); 

// ham xoa mot danh muc theo Id
void DeleteCategory(int size,Category CategoryList[]);

// ham sap xep danh thuc 
void SortCate(int size,Category CategoryList[]);

// ham tim kiem danh muc theo ten
void FindCategory(int size,Category CategoryList[]);

// ham luu gia tri vao file
void SaveFile(int size,Category CatgoryList[]);

// ham doc gia tri cua file
void ReadFile(int size,Category CategoryList[]);

// ham truyen gia tri file khi restart
void LoadFile(int *size, Category CategoryList[]);

// ham hien thi danh sach san pham
void ShowProductList(int size, Product ProductList[]);

// ham them vao mot san pham moi
void AddProduct(int *size, Product ProductList[]);

// ham sua thong tin san pham
void ChangeProduct(int size, Product ProductList[]);

// ham xoa thong tin san pham
void DeleteProduct(int size, Product ProductList[]);

// ham tim kiem san pham theo ten
void FindProduct(int size, Product ProductList[]);

// ham sap xep san pham theo gia tien
void SortProduct(int size, Product ProductList[]);
