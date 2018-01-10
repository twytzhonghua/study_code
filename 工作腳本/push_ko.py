#-*- coding: utf-8 -*-

import os

if __name__ == "__main__":
	os.system('rm system/lib/modules/3.14.55-x86_64* -rf')
	os.system('find system/lib/modules/ -name *.ko > ko_list')
	os.system('adb remount')
	
	with open('ko_list') as f:
		for l in f.readlines():
			cmd = 'adb push ' + l.strip('\n') + ' /' + l.strip('\n')
			print cmd
			os.system(cmd)
		
	os.system('adb reboot bootloader')
	os.system('fastboot flash boot boot.img; fastboot reboot')
