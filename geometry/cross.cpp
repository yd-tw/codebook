struct Point {
    double x, y;
};

double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
