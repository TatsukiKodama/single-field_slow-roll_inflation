import numpy as np
import matplotlib.pyplot as plt

# TeX フォントを使用するための設定
plt.rcParams.update({
    'text.usetex': True,  # LaTeX を有効にする
    'font.family': 'serif',  # セリフ体を使用
    'font.serif': ['Times New Roman'],  # 使用するフォントを指定（必要に応じて変更）
    'text.latex.preamble': r'\usepackage{amsmath}',  # 数式のためのパッケージを読み込む
    'font.size': 14
})

# データファイルの読み込み
data = np.loadtxt('./output/dat/data.dat')

# データファイルのそれぞれの列を配列に格納
x = np.log(data[:, 1])
y1 = data[:, 2] 
y2 = data[:, 3]

# グラフの描画
plt.plot(y1, y2, "-", label=r'', color='red') 

# ラベルとタイトルを追加
plt.xlabel(r'$\phi$')
plt.ylabel(r'$\dot{\phi}$')
#plt.title(r'')

# 凡例の表示
#plt.legend()

# 線形・対数プロット
#plt.yscale('log')

# 保存
plt.savefig('./output/fig/phi_dotphi.png')

# 表示
#plt.show()
