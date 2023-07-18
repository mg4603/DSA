#include <iostream>

// overloading operators gives meaning to operators used w.r.t classes

class Point{
    public:
        int x;
        int y;
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        // overloaded + operator
        Point operator + (Point &b)
        {
            Point pt(x + b.x, y + b.y);
            return pt;
        }

        bool operator == (Point &b)
        {
            if(x == b.x && y == b.y)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    std::cout << "Operator overloading\n\n";
    Point pt1(10, 20);
    Point pt2(10, 20);

    Point pt3 = pt1 + pt2;
    std::cout << "Point 1:\n";
    std::cout << "x: " << pt1.x << "\ty: " << pt1.y<< std::endl;

    std::cout << "Point 2:\n";
    std::cout << "x: " << pt2.x << "\ty: " << pt2.y << std::endl;

    std::cout << "Sum of Point 1 and Point 2:\n";
    std::cout << "x " << pt3.x << "\ty: " << pt3.y << std::endl;

    if(pt1 == pt2)
    {
        std::cout << "Point 1 and Point 2 are the same point.\n";
    }

    if(!(pt3 == pt2))
    {
        std::cout << "Point 2 and Point 3 are not the same point.\n";
    }

    return 0;
}