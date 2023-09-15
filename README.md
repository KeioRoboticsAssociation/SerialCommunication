  
#  f446-mbed-template

VSCode+PlatformioでインクルードパスやPinNameが通らないという問題がありました．includepathの方はクイック・フィックスを行なえば一時的には解決しますが，次に開いたときにはまた波線がでてしまいます．
これは，インクルードパスなどを指定するファイルである.vscode/c_cpp_properties.jsonを，platformioが勝手に書き換えてしまうことが原因でした．推奨されている方法であるplatformio.iniの編集ではどうも直せそうになかったので，
tasks.jsonおよびpythonを使って，はじめにc_cpp_properties.jsonを読んできて，includepathに必要なパスがなければ追加し，platformioがc_cpp_properties.jsonの内容を書き換えるのを待ってからさらにc_cpp_properties.jsonを無理やり書き換えるプログラムを書くことで解決しました．

先輩が作ってくれたビルドを早くするテンプレート
https://github.com/KeioRoboticsAssociation/F446_Mbed_Template
を使用しています．

# 使い方

1. このリポジトリをダウンロードする

2. .vscode/tasks.jsonの"command"のところをいい感じのpythonのパスに書き換える

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "edit c_cpp_properties.json",
            "type": "shell",
            "command": "python3",
            "args": [
                "${workspaceFolder}/edit_c_cpp_properties.py"
            ],
            "group": "build",
            "runOptions": {
                "runOn": "folderOpen"
            }
        }
    ]
}
```
