
import os

def checkout_all_prj():
	with open('.repo/project.list', 'r') as f:
		for l in f.readlines():
			cmd =  'cd /home/yzh/code/panasonic_newest' + ' ; ' + 'cd ' + l.strip('\n') + ' ; ' + 'git clean -xf' + ' ; ' + 'git checkout -f'
			print cmd
			os.system(cmd)


def apply_patch():
	with open('all_patch.txt', 'r') as f:
		for l in f.readlines():
			full_file = l.strip('\n')

			file = full_file.split('/')[-1]
			
			#print full_file
			i = 0
			for c in full_file:
				if c == '/':
					pos = i
				i = i+1

			path =  full_file[0:pos]

			enter_root_dir = 'cd /home/yzh/code/panasonic_newest'

			enter_cmd='cd ' + path
			apply_cmd = 'git apply ' + file

			full_cmd = enter_root_dir + ' ; ' +  enter_cmd + ' ; ' + apply_cmd 

			#os.system(enter_root_dir)
			print full_cmd
			#os.system(enter_cmd)
			#print apply_cmd
			#os.system(apply_cmd)
			os.system(full_cmd)

			#os.system('sleep 1')




#checkout_all_prj()
apply_patch()

