sol = []
states = []

sol_f_name = 'Phase_3B_sol.txt'
states_f_name = 'Phase_3B_states.txt'

for i in range(1,5):
	fname = str(i)+'_'+sol_f_name
	temp = []
	with open(fname,'r') as file:
		temp = file.read().split('\n')
	temp.pop(-1)
	sol.extend(temp[:])
	fname = str(i)+'_'+states_f_name
	with open(fname,'r') as file:
		temp = file.read().split('\n')
	temp.pop(-1)
	temp = [int(j) for j in temp]
	states.extend(temp[:])

new_states = list(set(states[:]))

mp = {}

assert len(states) == len(sol)

for i in new_states:
	mp[i] = '-1'

for i in range(len(sol)):
	if mp[states[i]] == '-1':
		mp[states[i]] = sol[i]
	else:
		if len(mp[states[i]]) > len(sol[i]):
			mp[states[i]] = sol[i]

sol = []
states = []

for key in mp:
	states.append(str(key)+'\n')
	sol.append(str(mp[key])+'\n')

with open('Phase_3B_states.txt','w') as file:
	file.writelines(states)

with open('Phase_3B_sol.txt','w') as file:
	file.writelines(sol)







