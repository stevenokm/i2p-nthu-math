# Lab 4: Complex Number

## Lab 4-1: Complex Numbers (50%)

* 輸入：
  1. 以 `double` 格式輸入複數的實數及虛數部分，以空格分開
  2. 一行輸入一個複數
  3. 輸入 <kbd>Ctrl</kbd>+<kbd>D</kbd> 完成輸入
     * Windows 請輸入 <kbd>Ctrl</kbd>+<kbd>Z</kbd> (會在螢幕上顯示 `^Z`) 再輸入 <kbd>Enter</kbd> 完成輸入
* 輸出：
  1. 顯示複數儲存 Complex Class 的數字
  2. 一行輸入跟著輸出一個複數
* 檔名：`lab4-1_<學號>.cpp` (e.g. `lab4-1_106062802.cpp`)

注意事項：
* 程式不會輸出任何使用者提示，只會輸出程式結果
* 請使用 pseudo code 提供的 main function 來處理輸入與輸出
* 程式需要於 10 秒內完成，所有的測資皆會保證於 10 秒內完成

### Format

``` text
<real 1> <imag 1>⏎
<real 1> + <imag 1> i
<real 2> <imag 2>⏎
<real 2> + <imag 2> i
...
<real n> <imag n>⏎
<real n> + <imag n> i
^Z⏎
```

### Example

```console
$ ./a.out
1.0 0.0⏎
1 + 0 i
2.0 1.1⏎
2 + 1.1 i
-3.0 -2.2⏎
-3 + -2.2 i
^Z⏎
$
```

### Pseudo Code

```c++
{{#include lab4-1_pseudo.cpp}}
```

### Reference Code: 

#### 陳光齊 (110021102)

```c++
{{#include lab4-1_110021102.cpp}}
```

#### 賴杰弘 (110021118)

```c++
{{#include lab4-1_110021118.cpp}}
```