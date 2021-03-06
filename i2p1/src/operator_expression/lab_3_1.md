# Lab 3: 科學記號

## Lab 3-1: 科學記號顯示 (40%)

* 輸入：以 10 為底的實數。
  * 實數的正負號 (sign)，正負號輸入大於等於 0 為正數，小於 0 為負數。
  * 實數的尾數 (mantissa)，尾數部分固定 9 位數字，第一位不為 `0`，數值為輸入數字乘以\\( \frac{1}{100,000,000} \\)，。
  * 實數的指數部分 (exponent)，指數部分為 -126 至 +127。
* 輸出：該實數的科學記號表示，有效位數 ([Significant figures - Wikipedia](https://en.wikipedia.org/wiki/Significant_figures)) 顯示固定為 9 位。
* 檔名：lab3_1_<學號>.cpp (e.g. lab3_1_106062802.cpp)

程式需提示使用者輸入實數的正負號 (sign)、實數的尾數 (mantissa，輸入數字乘以\\( \frac{1}{100,000,000} \\))、實數的指數部分 (exponent)，輸出該實數的科學記號表示。

### Format 

```text
Input real number, sign: <sign>⏎
Input real number, mantissa: <mantissa>⏎
Input real number, exponent: <exponent>⏎
The real number is: <output real number>
```

### Example

```console
$ ./a.out
Input real number, sign: -100⏎
Input real number, mantissa: 123456789⏎
Input real number, exponent: 10⏎
The real number is: -1.23456789e+10
```

Reference Code:

Credit: 黃芷葳 (110021115)

``` c++
{{#include lab3_1_110021115.cpp}}
```