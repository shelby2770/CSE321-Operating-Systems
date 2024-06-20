#include <stdio.h>

struct item
{
    int quantity;
    float price;
};

signed main()
{
    struct item p, v, m;
    int n;
    printf("Quantity Of Paratha: ");
    scanf("%d", &p.quantity);
    printf("Unit Price: ");
    scanf("%f", &p.price);
    printf("Quantity Of Vegetables:");
    scanf("%d", &v.quantity);
    printf("Unit Price: ");
    scanf("%f", &v.price);
    printf("Quantity Of Mineral Water:");
    scanf("%d", &m.quantity);
    printf("Unit Price: ");
    scanf("%f", &m.price);
    printf("Number of People: ");
    scanf("%d", &n);

    float total =
        p.quantity * p.price +
        v.quantity * v.price +
        m.quantity * m.price;
    
    printf("Individual people will pay: %.2f tk", total/n);
}