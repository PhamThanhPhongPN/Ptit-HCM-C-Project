// xay dung kieu du lieu thong qua struct

typedef struct Date{
	int day, month, year;
} Date;

typedef struct Category{
	char CategoryId[10];
	char CategoryName[10];
} Category;

typedef struct Product{
	char ProductId[10];
	char CategoryId[10];
	char ProductName[10];
	int Quantity;
	int Price;
} Product;

typedef struct Order{
	char OrderId[10];
	char CustomerId[20];
	struct Date date;
	struct Product product;
} Order;
