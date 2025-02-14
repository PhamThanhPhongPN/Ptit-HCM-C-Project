// tao cac function

// ham hien menu chinh
void ShowMain();

// ham hien menu chinh sua danh muc
void ShowCategory();

// ham hien thi danh sach danh muc
void ShowCategoryList(int a,Category CategoryList[]);

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
