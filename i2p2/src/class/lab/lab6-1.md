# Lab 6: Complex Number Calculator

## Lab 6-1: Enhanced Complex Numbers (40%)

* 輸入：
  1. 以 `double` 格式輸入複數的實數及虛數部分，以空格分開，一行輸入一個複數
  2. 以 `char` 格式輸入複數的運算子，包含 `+`、`-`、`*`、`/`，一行輸入一個運算子
  3. 複數與運算子以交錯的方式輸入，一行輸入一個複數接著一個運算子，倒數兩行為複數與完成輸入指令
  4. 輸入 <kbd>Ctrl</kbd>+<kbd>D</kbd> 完成輸入
     * Windows 請輸入 <kbd>Ctrl</kbd>+<kbd>Z</kbd> (會在螢幕上顯示 `^Z`) 再輸入 <kbd>Enter</kbd> (Format 中的 `⏎`) 完成輸入
* 輸出：
  1. 顯示運算複數的結果
     1. 格式請參考 [Format](#format) 中的說明
  2. 若虛數部分為 0 則僅顯示實數部分
  3. 虛數及實數部分皆以預設 `double` 格式顯示
* 檔名：`lab6-1_<學號>.cpp` (e.g. `lab6-1_106062802.cpp`)

注意事項：
* 程式不會輸出任何使用者提示，只會輸出程式結果
* 使用者不需要處理錯誤輸入
* 請使用 pseudo code 提供的 main function 來處理輸入與輸出
* 程式需要於 10 秒內完成，所有的測資皆會保證於 10 秒內完成

### Format

``` text
<real 1> <imag 1>⏎
<op 1>⏎
<real 2> <imag 2>⏎
<op 2>⏎
...
<real n-1> <imag n-1>⏎
<op n-1>⏎
<real n> <imag n>⏎
^Z⏎
(-)<real result> (+|-) (<imag result>i)
```

### Example

```console
$ ./a.out
1.0 0.0⏎
^Z⏎
1
$ ./a.out
0.0 1.0⏎
^Z⏎
0 + 1i⏎
$ ./a.out
1.0 0.0⏎
+⏎
2.0 1.1⏎
-⏎
-3.0 -2.2⏎
*⏎
4.3 2.1⏎
/⏎
-1.2 -3.4⏎
^Z⏎
-8.74846 + 2.46231i
$ ./a.out
1.0 0.0⏎
+⏎
2.0 1.1⏎
-⏎
-3.0 -2.2⏎
*⏎
4.3 2.1⏎
/⏎
-1.2 3.4⏎
^Z⏎
5.26477 - 7.40815i
```

### Pseudo Code

```c++
{{#include lab6-1_pseudo.cpp}}
```

### Reference Code: 

#### 陳誼倫(110021127)

```c++
{{#include lab6-1_110021127.cpp}}
```

#### 林恩佑(109021107)

```c++
{{#include lab6-1_109021107.cpp}}
```