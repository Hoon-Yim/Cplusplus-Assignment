#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <string>
#include <ncurses.h>
#include <unistd.h>

void func(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        func(n - 1);
    }
}

int main()
{
    int x = 3;
    func(3);

}
