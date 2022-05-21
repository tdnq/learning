## 脚本安装教程
1. 安装node.js; 网址: https://nodejs.org/en/; 下载LTS版本安装.
2. 下载脚本源代码; 网址: https://github.com/tdnq/learning/tree/excel_lxq; 点击Code,然后点击下载ZIP即可下载; 解压压缩包到工作目录;
3. 在源代码目录下,用CMD打开(alt+d, 然后输入cmd), 输入`npm install`;等待执行完成即可.
4. 在源代码目录下的src目录下,新建空的'data'目录(放excel原始数据表)和'build'目录(每次脚本运行完成的结果会放在这里);
5. 双击'build.bat'即可运行脚本;运行前应保证其中data目录下必须要有'物料单价表'和至少一个日耗表;
6. 运行完成后,结果会在build目录下,同时命令行窗口会有一些提示信息,可看到运行中有什么提示.