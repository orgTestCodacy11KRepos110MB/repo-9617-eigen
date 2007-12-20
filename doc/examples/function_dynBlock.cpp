#include "../src/Core.h"
USING_EIGEN_DATA_TYPES
using namespace std;
int main(int, char**)
{
    Matrix4d m = Matrix4d::identity();
    m.dynBlock(2,0,2,2) = m.dynBlock(0,0,2,2);
    cout << m << endl;
    return 0;
}

/* Output:

1 0 0 0
0 1 0 0
1 0 1 0
0 1 0 1

*/
