#include<cmath>

class Vec3D {
    public:
        double x, y, z;

        Vec3D(double x_, double y_, double z_):
            x(x_),
            y(y_),
            z(z_) {}

        const Vec3D& operator+=(const Vec3D &pt) {
            x += pt.x, y += pt.y, z += pt.z;
            return *this;
        }

        const Vec3D& operator-=(const Vec3D &pt) {
            x -= pt.x, y -= pt.y, z -= pt.z;
            return *this;
        }

        const Vec3D& operator*=(double c) {
            x *= c, y *= c, z *= c;
            return *this;
        }

        const Vec3D& operator/=(double c) {
            x /= c, y /= c, z /= c;
            return *this;
        }

        Vec3D operator+(const Vec3D &pt) {
            return Vec3D(x + pt.x, y + pt.y, z + pt.z);
        }

        Vec3D operator-(const Vec3D &pt) {
            return Vec3D(x - pt.x, y - pt.y, z - pt.z);
        }
        
        Vec3D operator*(double c) {
            return Vec3D(x * c, y * c, z * c);
        }

        Vec3D operator/(double c) {
            return Vec3D(x / c, y / c, z / c);
        }
};

class Vec2D {
    public:
        double x, y;

        Vec2D(double x_, double y_):
            x(x_),
            y(y_) {}

        const Vec2D& operator+=(const Vec2D &pt) {
            x += pt.x, y += pt.y;
            return *this;
        }

        const Vec2D& operator-=(const Vec2D &pt) {
            x -= pt.x, y -= pt.y;
            return *this;
        }

        const Vec2D& operator*=(double c) {
            x *= c, y *= c;
            return *this;
        }

        const Vec2D& operator/=(double c) {
            x /= c, y /= c;
            return *this;
        }

        Vec2D operator+(const Vec2D &pt) {
            return Vec2D(x + pt.x, y + pt.y);
        }

        Vec2D operator-(const Vec2D &pt) {
            return Vec2D(x - pt.x, y - pt.y);
        }
        
        Vec2D operator*(double c) {
            return Vec2D(x * c, y * c);
        }

        Vec2D operator/(double c) {
            return Vec2D(x / c, y / c);
        }
};

class Plane {
    public:
        int a, b, c, d;     
};

double dot(const Vec3D &a, const Vec3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double dot(const Vec2D &a, const Vec2D &b) {
    return a.x * b.x + a.y * b.y;
}

double norm(const Vec3D &a) {
    return sqrt(dot(a, a));
}

double norm(const Vec2D &a) {
    return sqrt(dot(a, a));
}

double proj(const Vec3D &a, const Vec3D &b) {
    return dot(a, b) / norm(b);
}

double proj(const Vec2D &a, const Vec2D &b) {
    return dot(a, b) / norm(b);
}

Vec3D cross(const Vec3D &a, const Vec3D &b) {
    return Vec3D(a.y * b.z - a.z * b.y, - (a.x * b.z - a.z * b.x), (a.x * b.y - a.y * b.x));
}

double pseudo_cross(const Vec3D &a, const Vec3D &b) {
    return a.x * b.y - a.y * b.x;
}

double tripleProd(const Vec3D &a, const Vec3D &b, const Vec3D &c) {
    return dot(a, cross(b, c));
}

Vec3D planeIntersection(const Plane &p1, const Plane &p2, const Plane &p3) {
    Vec3D d = Vec3D(p1.d, p2.d, p3.d);
    Vec3D x = Vec3D(p1.a, p2.a, p3.a);
    Vec3D y = Vec3D(p1.b, p2.b, p3.b);
    Vec3D z = Vec3D(p1.c, p2.c, p3.c);
    return Vec3D(
        tripleProd(d, y, z),
        tripleProd(x, d, y),
        tripleProd(x, y, d)
    ) / tripleProd(x, y, z);
}

int main() {

    return 0;
}