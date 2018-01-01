# coding: utf-8

import numpy as np
import pandas as pd

if __name__ == "__main__":
	pd.set_option('display.width', 300)
	data = pd.read_csv('tel.csv', skipinitialspace=True, thousands=',')
	print u'原始数据：\n', data.head(10)


