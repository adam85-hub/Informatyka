/*
    W pliku punkty.txt zapisano wspolrzedne 10000 punktow.
    W kazdej lini podano odpowiednio wartosci x oraz y (zakres short).
    Oblicz najmniejsza odleglosc miedzy punktami.
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

float square(float a) {
    return a * a;
}

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    float distanceTo(Point* other) {
        return sqrt(square(this->x - other->x) + square(this->y - other->y));
    }
};

int main() {
    vector<Point*> points;
    ifstream f;
    f.open("punkty.txt");
    int x, y;
    while(!f.eof())
    {
        f >> x;
        f >> y;

        if(f.fail()) break;

        points.push_back(new Point(x, y));
    }

    unsigned int d = -1;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            if(points[i]->distanceTo(points[j]) < d)
                d = points[i]->distanceTo(points[j]);
        }
    }

    cout << "Najmniejsza odleglosc: " << d;

    f.close();
    for(auto p : points) {
        delete p;
    }
}
