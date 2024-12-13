
# 对称矩阵

步骤：

1、r2g2hist.C （无大改）

2、gate2matrix.C （修改：用户可选是否 nosmoothing；原版的 gate2mat 函数改名为 write）

3、gate2.C  （第 58 行添加 GateAxis 变量，修改 g 函数和 tpj 函数使其根据 GateAxis 决定投影的轴，其余无大改；运行方式与原版相同）




# 非对称矩阵

1、r2pdhist.C  （相比 r2g2hist.C 除添加 prompt delayed 判断条件外，无大改）

2、gate2pdmatrix.C  （对两个轴分别作投影、拟合本底；其他结构及运行方法与 gate2matrix.C 类似）

3、gate2pd.C  （直接载入 gate2 所有函数，配置文件亦与 gate2 相同，在此基础上通过修改 GateAxis 来对不同的轴开窗）