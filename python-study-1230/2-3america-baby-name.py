# -*- coding:utf-8 -*-

import pandas as pd
import numpy as np

names1880 = pd.read_csv('babynames/yob1880.txt', names=['name', 'sex', 'births'])
#以birth列的sex分组统计该年度的births总计
names1880.groupby('sex').births.sum()
#由于该数据按年度被分割成了多个文件， 先把所有数据组装到一个dataframe里面， 并加一个year字段， 使用pandas.concat

years=range(1880,2011)

pieces=[]
columns=['name', 'sex', 'births']

for year in years:
    path='babynames/yob%d.txt' % year
    frame = pd.read_csv(path, names=columns)
    
    frame['year'] = year
    pieces.append(frame)
    
names=pd.concat(pieces, ignore_index=True)

#有了这些数据我们就可以用groupby或者 pivot_table在year和 sex级别上对其进行聚合了

total_births=names.pivot_table('births', index='year', columns='sex', aggfunc=sum)

