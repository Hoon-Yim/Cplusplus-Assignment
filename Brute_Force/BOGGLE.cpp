/*
 * Last Update : Dec 11 2020
 * Problem : BOGGLE(algospot)
 * Link : algospot.com/judge/problem/read/BOGGLE
 */

#include <iostream>

/*
 * Problem : BOGGLE
 * Algorithm to apply : Brute-Force
 * Function Definition : void hasWord(int y, iny x, std::string word)
 * Base condition : if the start point is wrong, then return false
 *                  if the length of the string is 1, then return true. in the case the first base condition is passed
 */

char board[5][5]
        {{'U', 'R', 'L', 'P', 'M'},
         {'X', 'P', 'R', 'E', 'T'},
         {'G', 'I', 'A', 'E', 'T'},
         {'X', 'T', 'N', 'Z', 'Y'},
         {'X', 'O', 'Q', 'R', 'S'}};
int dx[8]{1, 1, 1, 0, 0, -1, -1, -1};
int dy[8]{-1, 0, 1, 1, -1, 1, 0, -1};

bool isRange(int y, int x)
{
    if(y < 0 || x < 0) return false;
    if(y >= 5 || x >= 5) return false;
    return true;
}

bool hasWord(int y, int x, const std::string& word)
{
    if(!isRange(y, x)) return false;
    if(board[y][x] != word[0]) return false;
    if(word.length() == 1) return true;

    for(int dir = 0; dir < 8; ++dir)
    {
        int ny = y + dy[dir], nx = x + dx[dir];
        if(hasWord(ny, nx, word.substr(1))) return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    std::cout << hasWord(1, 1, "PRETTY");
}