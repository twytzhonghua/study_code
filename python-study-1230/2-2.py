#!/usr/bin/python
# -*- coding:utf-8 -*-


import pandas as pd
unames =['user_id', 'gender', 'age', 'occupation', 'zip']
users = pd.read_table('movi-users.dat', sep='::', header=None, names=unames)

print users[:5]

rnames=['user_id', 'movie_id', 'rating', 'timestamp']
ratings=pd.read_table('ratings.dat', sep='::', header=None, names=rnames)
print ratings[:5]


mnames=['movie_id', 'title', 'genres']
movies=pd.read_table('movies.dat', sep='::', header=None, names=mnames)
print movies[:5]

#利用pandas的merge函数将ratings users合并 然后将movies也合并一起
data = pd.merge(pd.merge(ratings, users), movies)
#print data

print data.ix[3]

#    def pivot_table(self, index=None, columns=None,
#                    values=None, aggfunc='mean'):
#只要熟悉一下pandas, 就能轻松根据任意用户或电影属性对评分数据进行聚合操作了， 为了an性别计算每部电影的平均得分， 可以使用pivot_talbe方法
mean_ratings = data.pivot_table('rating',  index='title', columns='gender', aggfunc='mean')
print mean_ratings[:5]
# 根据size()得到一个含有个个电影分组大小的Series对象，我们想过滤掉影评小于250的电影
ratings_by_title = data.groupby('title').size()
print ratings_by_title[:10]
active_titles=ratings_by_title[ratings_by_title>=250]
print active_titles

#根据mean_ratings选取所需行了
mean_ratings=mean_ratings.ix[active_titles]
print mean_ratings

#了解女性观众喜欢看的电影， 我们可以对F降序排列
top_femal_ratings=mean_ratings.sort_index(by='F', ascending=False)
print top_femal_ratings[:10]


#计算评分分歧
mean_ratings['diff'] = mean_ratings['M'] - mean_ratings ['F']
sorted_by_diff = mean_ratings.sort_index(by=diff)
print sorted_by_diff[:15]

#对排序结果反序病取出前15行，得到的就是男性喜欢的电影
print sorted_by_diff[::-1][:15]



