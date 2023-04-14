#information
#Time = 
#Description: 

#Answer
def solution(n, m, section):
    #define
    painting_Progress = section[0] + m -1
    painting = 1

    #Main
    for i in section:
        print("i:", i, " painting_Progress:", painting_Progress) #CheckingCode
        if(i <= painting_Progress):
            continue
        elif(i > painting_Progress):
            painting += 1
            painting_Progress = i + (m-1)

            if(painting_Progress > max(section)):
                break
    
    return painting

#Test Code
n = 20
m = 3
section = [2,3,5,7]
print(solution(n, m, section))