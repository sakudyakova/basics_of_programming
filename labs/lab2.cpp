#include <iostream>
using namespace std;

class vect {
private:
    int dim;
    double *b;
    int num;
    static int count;

public:
    vect(int d) : dim(d) {
        b = new double[dim];
        num = count++;
        cout << "Created vector " << num << endl;
    }

    vect(const vect &v) {
        dim = v.dim;
        b = new double[dim];
        num = count++;
        for (int i = 0; i < dim; i++) {
            b[i] = v.b[i];
        }
        cout << "Copied vector " << v.num << " to vector " << num << endl;
    }

    ~vect() {
        delete[] b;
        cout << "Destroyed vector " << num << endl;
    }

    vect operator+(const vect &v) {
        vect result(dim);
        cout << "Vector " << num << " + Vector " << v.num << endl;
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] + v.b[i];
        }
        return result;
    }

    double& operator[](int index) {
        return b[index];
    }

    static int getCount() {
        return count;
    }
};

int vect::count = 0;

int main() {
    vect v1(3);
    v1[0] = 1.0;
    v1[1] = 2.0;
    v1[2] = 3.0;

    vect v2(3);
    v2[0] = 4.0;
    v2[1] = 5.0;
    v2[2] = 6.0;

    vect v3 = v1 + v2;

    cout << "Total vectors created: " << vect::getCount() << endl;

    return 0;
}
