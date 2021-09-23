# Visual Studio Code Tutorial

## 設定 VSCode 環境 (Linux)

### 安裝 GCC

```bash
sudo apt update
sudo apt install -y build-essential g++ gdb
g++ -v
```

Wrong:

![g++ wrong](img/g++_wrong.png)

Correct:

![g++ correct](img/g++_correct.png)

### 安裝 VSCode & C++ plugin

Install VSCode: [https://code.visualstudio.com/docs/setup/linux](https://code.visualstudio.com/docs/setup/linux)

Install the C++ extension for VSCode: [https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

### 新增專案 (Hello world!)

```console
$ mkdir projects
$ cd projects
$ code .
```

In VSCode: `Exploer -> New File`

輸入 `test.cpp`

![new file icon](img/new_file.png)

在文字輸入區輸入以下程式碼

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
```

![input cpp code](img/input_cpp.png)

### 編譯 & 執行 Hello world!

In VSCode: `Terminal -> New Terminal`

![create terminal](img/create_terminal.png)

In VSCode Terminal:
```console
$ g++ test.cpp
$ ./a.out
Hello C++ World from VS Code and the C++ extension! 
$ 
```

### Debugger

可以設置中斷點，方便程式除錯。

#### `launch.json`

In VSCode: `Exploer -> New Folder`

輸入 `.vscode`

![new folder icon](img/new_folder.png)

In VSCode: `Exploer -> New File`

輸入 `launch.json`

在文字輸入區輸入以下設定檔

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

#### 編譯 & 執行 Debugger

In VSCode Terminal:
```console
$ g++ -g test.cpp
$ 
```

插入中斷點

在要中斷的程式碼行號左邊點一下

![insert breakpoint](img/insert_breakpoint.png)

In VSCode: `Run -> Start Debugging F5`

![start debugging](img/start_gdb.png)

![run gdb](img/run_gdb.png)

## 使用 VSCode server

![login code-server](img/login_codeserver.png)

### 安裝 GCC & C++ plugin

In VSCode: `Terminal -> New Terminal`

![create terminal](img/codeserver_create_terminal.png)

```console
sudo apt update
sudo apt install -y build-essential g++ gdb
g++ -v
curl -L https://github.com/microsoft/vscode-cpptools/releases/download/1.5.1/cpptools-linux.vsix --output cpptools-linux.vsix
code-server --install-extension cpptools-linux.vsix
```

NOTE: 須重新整理網頁才能生效

### 新增專案 (Hello world!)

In VSCode: `Exploer -> New Folder`

輸入 `projects`

![new folder projects](img/codeserver_new_folder.png)

In VSCode: `File -> Open Folder`

![open folder projects 1](img/codeserver_open_folder_1.png)

![open folder projects 2](img/codeserver_open_folder_2.png)

In VSCode: `Exploer -> New File`

輸入 `test.cpp`

![new file icon](img/new_file.png)

在文字輸入區輸入以下程式碼

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
```

![input cpp code](img/input_cpp.png)

### 編譯 & 執行 Hello world!

In VSCode Terminal:
```console
$ g++ test.cpp
$ ./a.out
Hello C++ World from VS Code and the C++ extension! 
$ 
```

### Debugger

可以設置中斷點，方便程式除錯。

#### `launch.json`

In VSCode: `Exploer -> New Folder`

輸入 `.vscode`

![new folder icon](img/new_folder.png)

In VSCode: `Exploer -> New File`

輸入 `launch.json`

在文字輸入區輸入以下設定檔

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

#### 編譯 & 執行 Debugger

In VSCode Terminal:
```console
$ g++ -g test.cpp
$ 
```

插入中斷點

在要中斷的程式碼行號左邊點一下

![insert breakpoint](img/insert_breakpoint.png)

In VSCode: `Run -> Start Debugging F5`

![start debugging](img/start_gdb.png)

![run gdb](img/run_gdb.png)


## 設定 VSCode 環境 (Windows)

Credit: [CNOCycle/cpp_tutorial by E. Chen](https://github.com/CNOCycle/cpp_tutorial)

{{#include install-windows.md}}

Reference: 

* [CNOCycle/cpp_tutorial by E. Chen](https://github.com/CNOCycle/cpp_tutorial)
* [Get Started with C++ on Linux in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-linux)
* [Get Started with C++ and Mingw-w64 in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-mingw)

延伸資訊:

* [Configure VS Code for Clang/LLVM on macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac)
* [Get Started with C++ and Windows Subsystem for Linux in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-wsl)
