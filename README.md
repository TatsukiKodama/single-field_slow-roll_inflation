<div id="top"></div>

## 使用技術一覧
* C言語
* Python

## 目次

1. [プロジェクトについて](#プロジェクトについて)
2. [環境](#環境)
3. [ディレクトリ構成](#ディレクトリ構成)
4. [トラブルシューティング](#トラブルシューティング)


## プロジェクト名

<!-- プロジェクトについて -->

## プロジェクトについて
<!-- プロジェクトの概要を記載 -->


<p align="right">(<a href="#top">トップへ</a>)</p>

## 環境

<!-- 言語、フレームワーク、ミドルウェア、インフラの一覧とバージョンを記載 -->

| 対象  | バージョン |
| --------------------- | ---------- |
| clang |Apple clang version 12.0.5 |
| Python | Python 3.12.6 |
| matplotlib | 3.10.0 |
| numpy | 2.2.1 |


<p align="right">(<a href="#top">トップへ</a>)</p>

## ディレクトリ構成

<!-- Treeコマンドを使ってディレクトリ構成を記載 -->
 <pre>
.
├── .gitignore
├── Makefile
├── README.md
├── obj
│   ├── src
│   └── utils
├── output
│   ├── dat
│   │   └── data.dat
│   ├── fig
│   └── make_fig
│       ├── dotphi_N.py
│       ├── phi_N.py
│       └── phi_dotphi.py
├── requirements.txt
└── src
    ├── const.c
    ├── const.h
    ├── infl_params.c
    ├── infl_params.h
    ├── main.c
    ├── run.c
    ├── run.h
    ├── setting.c
    ├── setting.h
    └── utils
        ├── utils_file.c
        ├── utils_file.h
        ├── utils_init.c
        ├── utils_init.h
        ├── utils_numerical.c
        └── utils_numerical.h
</pre>   

<p align="right">(<a href="#top">トップへ</a>)</p>

## 開発環境構築
```
cd rk4_demo
```
でワークディレクトリに入りましょう。

まずはPythonの仮想環境を作成し、アクティベートします。
```
python3 -m venv venv
source venv/bin/activate
```
必要なライブラ入りをpipでインストールします
```
pip install -r requirements.txt
```
続いて
```
make
```
と入力すると、objディレクトリやmain実行ファイルが生成されます。最後に
```
./main
```
とすれば、準備完了です。いまあなたの目の前には$\sin$カーブ$\cos$カーブが見えているはずです。

## トラブルシューティング
工事中👷

### GitHub系

#### 間違って不必要なファイルをpush
焦らずに.gitignoreに、そのファイル名を記入後、
```
git rm --cashed [file name]
```
と入力します。

#### 間違って不必要なディレクトリをpush
焦らずに.gitignoreに、そのディレクトr名を記入後、
```
git rm -r --cached [directory name]/
```
と入力します。

### 便利コマンド系
#### tree
ディレクトリ階層のツリーを表示させたいときは
```
 tree -a -I "venv|__pycache__|.git|...無視するファイルやディレクトリ|"
```
と入力します。ただし、brewでtreeをインストールしていることが前提です。インストール方法は非常に簡単で
```
brew install tree
```
と入力してください。

<p align="right">(<a href="#top">トップへ</a>)</p>
