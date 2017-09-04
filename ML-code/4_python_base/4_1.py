# -*- coding:utf-8 -*-
import numpy as np
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import time
from scipy.optimize import leastsq
from scipy import stats
import scipy.optimize as opt
import matplotlib.pyplot as plt
from scipy.stats import norm, poisson
from scipy.interpolate import BarycentricInterpolator
from scipy.interpolate import CubicSpline
import scipy as sp
import math

if __name__ == '__main__':
    L = [1, 2, 3, 4, 5, 6]
    print "L =" , L
    a = np.array(L)
    print a
    print type(a), type(L)

    b = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
    print b

    # 数组大小可以通过修改shape
    print a.shape
    print b.shape

    #可以修改shape属性改变数组
    b.shape = 4, 3
    print b

    c = b.reshape((2, -1)) # -1 会自动计算数组的维度  其实c 和 b是公用内存的
    print 'c=\n', c

    c[0][1] = 100
    print 'b=\n', b

    #在创建时指定元素类型
    d = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]], dtype=np.float)
    # 复数
    e = np.array([[1, 2, 3, 4], [5 + 7J, 6, 7, 8], [9, 10, 11, 12]], dtype=np.complex)
    print d
    print e

    #如果更改元素类型， 可以使用astype安全转换， 但是不能强制改变type , 如 d.dtype = np.int
    # 取出复数数组的实部
    f = e.astype(np.int)
    print f

    ## 使用函数创建
    a = np.arange(1, 20, 0.5)
    print a
    print type(a), a.dtype

    b = np.arange(20, dtype = float)
    print b
    print type(b), b.dtype

    #linespace  起点 终点  个数
    c = np.linspace(1, 10, 10)
    print 'c=', c
    #c= [  1.   2.   3.   4.   5.   6.   7.   8.   9.  10.]
    #可以通过endpoint 指定包含终值
    d = np.linspace(1, 10, 10, endpoint=False)
    print 'd=', d
    #d= [ 1.   1.9  2.8  3.7  4.6  5.5  6.4  7.3  8.2  9.1]

    # # # 和linspace类似，logspace可以创建等比数列
    # # 下面函数创建起始值为10^1，终止值为10^2，有10个数的等比数列
    d = np.logspace(1, 4, 4, endpoint=True, base=10)
    print d
    # [10.    100.   1000.  10000.]

    # # # # # 使用 frombuffer, fromstring, fromfile等函数可以从字节序列创建数组
    # s = 'abcdABCDEF'
    # g = np.fromstring(s, dtype=np.int8)
    # print g
    # #
    # 3.存取
    # 3.1常规办法：数组元素的存取方法和Python的标准方法相同
    # a = np.arange(10)
    # print a
    # # 获取某个元素
    # print a[3]
    # # # # # 切片[3,6)，左闭右开
    # print a[3:6]
    # # # 省略开始下标，表示从0开始
    # print a[:5]
    # # # 下标为负表示从后向前数
    # print a[3:]
    # # 步长为2
    # print a[1:9:2]
    # # # # # # 步长为-1，即翻转
    # print a[::-1]
    # # 切片数据是原数组的一个视图，与原数组共享内容空间，可以直接修改元素值
    # a[1:4] = 10, 20, 30
    # print a
    # # 因此，在实践中，切实注意原始数据是否被破坏，如：
    # b = a[2:5]
    # b[0] = 200
    # print a

    # 3.2 整数/布尔数组存取
    # 3.2.1
    # 根据整数数组存取：当使用整数序列对数组元素进行存取时，
    # 将使用整数序列中的每个元素作为下标，整数序列可以是列表(list)或者数组(ndarray)。
    # 使用整数序列作为下标获得的数组不和原始数组共享数据空间。
    a = np.logspace(0, 9, 10, base=2)
    print a
    # [1.    2.    4.    8.   16.   32.   64.  128.  256.  512.]
    i = np.arange(0, 10, 2)
    print i
    # [0 2 4 6 8]
    # # # 利用i取a中的元素
    b = a[i]
    print b
    # [1.    4.   16.   64.  256.]
    # # # b的元素更改，a中元素不受影响
    b[2] = 1.6
    print b
    print a
    # [1.     4.     1.6   64.   256.]
    # [1.    2.    4.    8.   16.   32.   64.  128.  256.  512.]

    # # 3.2.2
    # 使用布尔数组i作为下标存取数组a中的元素：返回数组a中所有在数组b中对应下标为True的元素
    # 生成10个满足[0,1)中均匀分布的随机数
    np.set_printoptions(linewidth=200)
    a = np.random.rand(10)
    print a
    # [0.29487951  0.48898043  0.08434531  0.5074662   0.19361456  0.50228105  0.92505795  0.96811179  0.53103096
     # 0.6505065]

    # # 大于0.5的元素索引
    print a > 0.5
    # # 大于0.5的元素
    b = a[a > 0.5]
    print b
    # # # 将原数组中大于0.5的元素截取成0.5
    a[a > 0.5] = 0.5
    print a
    # # # # b不受影响
    print b
    # [0.71716369  0.05186994  0.76318317  0.00679702  0.84032262  0.44427473  0.87193662  0.69464008  0.14793819
    #  0.22026981]
    # [True False  True False  True False  True  True False False]
    # [0.71716369  0.76318317  0.84032262  0.87193662  0.69464008]
    # [0.5         0.05186994  0.5         0.00679702  0.5         0.44427473  0.5         0.5         0.14793819
    #  0.22026981]
    # [0.71716369  0.76318317  0.84032262  0.87193662  0.69464008]

    # 3.3 二维数组的切片
    # [[ 0  1  2  3  4  5]
    #  [10 11 12 13 14 15]
    #  [20 21 22 23 24 25]
    #  [30 31 32 33 34 35]
    #  [40 41 42 43 44 45]
    #  [50 51 52 53 54 55]]
    a = np.arange(0, 60, 10)    # 行向量
    print a
    b = a.reshape((-1, 1))
    print b
    # [0 10 20 30 40 50]
    # [[0]
    #  [10]
    #  [20]
    #  [30]
    #  [40]
    #  [50]]
    c = np.arange(6)
    print 'c =', c
    f = b + c
    print 'f=', f
    # # 合并上述代码：
    a = np.arange(0, 60, 10).reshape((-1, 1)) + np.arange(6)
    print 'a=', a

    # # # # 二维数组的切片
    print a[[0, 1, 2], [2, 3, 4]]
    print a[4, [2, 3, 4]]
    print a[4:, [2, 3, 4]]
    i = np.array([True, False, True, False, False, True])
    print a[i]
    print a[i, 3]
    # [[0  1  2  3  4  5]
    #  [20 21 22 23 24 25]
    # [50 51  52 53 54 55]]
    # [3 23 53]

    # 4.1 numpy与Python数学库的时间比较
    for j in np.logspace(0, 7, 8):
        x = np.linspace(0, 10, j)
        start = time.clock()
        y = np.sin(x)
        t1 = time.clock() - start

        x = x.tolist()
        start = time.clock()
        for i, t in enumerate(x):
            x[i] = math.sin(t)
        t2 = time.clock() - start
        print j, ": ", t1, t2, t2/t1