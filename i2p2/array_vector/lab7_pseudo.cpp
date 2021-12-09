#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std ;

int main()
{
    char buffer[10001]; // "+1" to store '\0'
    vector <int> a, b, n;
    int a_sign = 1, b_sign = 1 ;

    cin >> buffer ;
    // ToDo:逐字檢查，不合法顯示input後exit，合法則將(buffer[i] - '0')存入vector<int> n
    
    // isdigit()：判斷是否為數字
    // reverse(.begin(), .end())：顛倒，將個位數移至第一位
    // .push_back()：進位、填入數字
    // .pop_back()：清除不必的'0'和'-'
    // .size()：n的位數
    // 注意以上函數都需加上()，即便有的沒有input
    // 有加'.'在前面的，開頭需指定該vector，例如: n.size()

    switch (n[0])
    {
    case /* 1-5 */:
        /* 提示字串 */
        break;
    }
    
    for(int i=0; buffer[i] != '\0'; i++) buffer[i] = '\0' ; // 清空buffer

    cin >> buffer ;
    // ToDo:逐字檢查，不合法顯示input後exit，合法轉int存入vector<int> a

    cin >> buffer ;
    // ToDo:逐字檢查，不合法顯示input後exit，合法轉int存入vector<int> b

    cout << a << b ;

    // Initialization Done ---------------------------------------------
    
    if(n[0]==1) // "Display Only"
        return 0 ;
    else if(n[0]==2) // "+"
    {
        // ToDo
        return 0 ;
    }
    else if(n[0]==3) // "-"
    {
        // ToDo
        return 0 ;
    }
    else if(n[0]==4) // "*"
    {
        // ToDo
        return 0 ;
    }
    else if(n[0]==5) // "/"
    {
        // ToDo
        return 0 ;
    }
    
    // 乘法最簡單，加減相同作法，除法用減法

    return 0;
}
