#include<stdio.h>

float Circle_Area()
{
    float r, area;
    printf("\nEnter the radius of the circle ");
    scanf("%f", &r);
    area = 3.14*r*r;
    return area;
}

void Square_Area()
{
    float s, area;
    printf("\nEnter the length of the side of the square ");
    scanf("%f", &s);
    area = s*s;
    printf("\nThe area of the square with side length %f is %f", s, area);
}

void Cube_Area()
{
    float s, area;
    printf("\nEnter the side of the cube ");
    scanf("%f", &s);
    area = 6*s*s;
    printf("\nThe surface area of the cube with side length %f is %f", s, area);
}

void Rectangle_Area()
{
    float l, b, area;
    printf("\nEnter the length and the breadth of the rectangle with a hyphen in between ");
    scanf("%f-%f", &l, &b);
    area = l*b;
    printf("The area of the rectangle with length %f, breadth %f is %f", l, b, area);
}

void Hex_Area()
{
    float s, area;
    printf("\nEnter the side of the hexagon ");
    scanf("%f", &s);
    area = 2.598*s*s;
    printf("\nThe area of the hexagon with side length %f is %f", s, area);
}

void main()
{
    int a = 1;
    while(a < 7)
    {
        printf("\nEnter the choice you would like to find area of: \n2. Circle\n3.Square\n4.Cube\n5.rectangle\n6.Hexagon\n7.Exit");
        scanf("%d", a);
        float area = 0;
        
        switch (a)
        {
        case 1:
            continue;
        
        case 2:
            area = Circle_Area();
            printf("%f", area);
            break;

        case 3:
            Square_Area();
            break;
        
        case 4:
            Cube_Area();
            break;
        
        case 5:
            Rectangle_Area();
            break;
        
        case 6:
            Hex_Area();
            break;

        }
    }
}

        