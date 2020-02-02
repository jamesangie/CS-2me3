## @file CalcModule.py
#  @author Behzad Khamneli 
#  @brief Sorts the students info based on their GPA, calculates their average and assigns them to a department.
#  @date 1/18/2019
 
## @brief Function sort takes a list of the dictionaries of students from readStdnts in ReadAllocationData.
#  @return A list of dictonaries in sorted order.
#  Citation: https://www.saltycrane.com/blog/2007/09/how-to-sort-python-dictionary-by-keys/
def sort(S):
	if S == "File Error":
		return "File Error"
	else:
		return sorted(S, key = lambda grade: grade['gpa'], reverse = True)

## @brief This function calcuates the average gpa of male or female students.
#  @details If param g is 'male', then it returns the average gpa of male students and if g is 'female' then it returns the average gpa for female students.If non of them has been entered, then it returns an error.
#  @param L Is a list of dictionaries of students. 
#  @param g Can be either male or female.
#  @return The average gpa of male or female students, with the choice depending on the param g.
def average(L, g):
	if L == "File Error":
		return "File Error"
	else:
		sumMale = 0
		numofMale = 0
		aveMale = 0
		
		sumFemale = 0
		numFemale = 0
		aveFemale = 0
		for dicty in L:
			if dicty['gender'] == 'male':
				sumMale = sumMale + dicty['gpa'] 
				numofMale += 1
			if dicty['gender'] == 'female':
				sumFemale= sumFemale + dicty['gpa'] 
				numFemale += 1
		if g == 'male':	
			aveMale = sumMale / numofMale
			return aveMale
		if g == 'female':
			aveFemale = sumFemale /numFemale
			return aveFemale
		else:
			return "g can be either male or female"
## @brief This function assigns the students to a department depending on their gpa and freechoice.
#  @details After each iteration, this function stores the macid of the students who have been assigned to a department to a list so that the same student will not be assigned to another department.
#  @param S Is a list of the dictionaries of students created by readStdnts.
#  @param F Is a list of students with free choice.
#  @param C Is a dictionary of department capacities.
#  @return A dictionary with the following format {'civil': [student, student,...], 'chemical': [student, student,...],...}.Student corresponds to the students' information.
def allocate(S, F, C):
	if (S == "File Error") or (F == "File Error") or (C == "File Error"):
		return "File Error"
	else:
		alldic = {}
		numofFree = len(F)
		assigned = []
		civil = []
		chemical = []
		electrical = []
		mechanical = []
		software = []
		materials = []
		engphys = []

		for std in sort(S):
			for i in range (numofFree): 
				if std['macid'] == F[i]:
					if std['choices'][0] == 'civil' and C['civil'] != 0:
						civil.append(std)
					
						C['civil'] = C['civil'] - 1
						
					elif std['choices'][0] == 'chemical' and C['chemical'] != 0:
						chemical.append(std)
						C['chemical'] = C['chemical'] - 1
					
					elif std['choices'][0] == 'electrical' and C['electrical'] != 0:
						electrical.append(std)
						C['electrical'] = C['electrical'] - 1
					
					elif std['choices'][0] == 'mechanical' and C['mechanical'] != 0:
						mechanical.append(std)
						C['mechanical'] = C['mechanical'] - 1
				
					elif std['choices'][0] == 'software' and C['software'] != 0:
						software.append(std)
						C['software'] = C['software'] - 1
				
					elif std['choices'][0] == 'materials' and C['materials'] != 0:
						materials.append(std)
						C['materials'] = C['materials'] - 1
				
					elif std['choices'][0] == 'engphys' and C['engphys'] != 0:
						engphys.append(std)
						C['engphys'] = C['engphys'] - 1
	
		for std in sort(S):	
			for i in range(3):
				if std['macid'] not in F and std['macid'] not in assigned and std['gpa'] >= 4.0:			
					
					if std['choices'][i] == 'civil':
						if C['civil'] != 0:
							civil.append(std)
							C['civil'] = C['civil'] - 1
							assigned.append(std['macid'])
	
							
					if std['choices'][i] == 'chemical':
						if C['chemical'] != 0:
							chemical.append(std)
							C['chemical'] = C['chemical'] - 1
							assigned.append(std['macid'])
							
					if std['choices'][i] == 'electrical':
						if C['electrical'] != 0:
							electrical.append(std)
							C['electrical'] = C['electrical'] - 1
							assigned.append(std['macid'])
							
					if std['choices'][i] == 'mechanical':
						if C['mechanical'] != 0:
							mechanical.append(std)
							C['mechanical'] = C['mechanical'] - 1
							assigned.append(std['macid'])
							
					if std['choices'][i] == 'software':
						if C['software'] != 0:
							software.append(std)
							C['software'] = C['software'] - 1
							assigned.append(std['macid'])
							
					if std['choices'][i] == 'materials':
						if C['materials'] != 0:
							materials.append(std)
							C['materials'] = C['materials'] - 1
							assigned.append(std['macid'])
							
					if std['choices'][i] == 'engphys':
						if C['engphys'] != 0:
							engphys.append(std)
							C['engphys'] = C['engphys'] - 1
							assigned.append(std['macid'])
		
		alldic['civil'] = civil
		alldic['chemical'] = chemical
		alldic['electrical'] = electrical
		alldic['mechanical'] = mechanical
		alldic['software'] = software
		alldic['materials'] = materials
		alldic['engphys'] = engphys
		return alldic
