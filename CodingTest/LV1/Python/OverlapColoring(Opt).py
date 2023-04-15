#information
#Time = 01:00:23
#Description: Optimize를 위해 아이디어를 생각하다보니 시간이 지연되서, 아쉬웠다..

#Answer
def solution(n, m, section):
    #Optimize: 페인트롤러가 1일때는 굳이 section을 검사할 필요가 없다.
    if(m == 1): 
         return len(section)
    
    #define
    Painted = section[0]
    painting = 1

    #Main
    for i in section:
        if(i - Painted >= m):
            painting += 1
            Painted = i
    
    return painting

#Test Code
n = 20
m = 3
section = [2,3,5,7]
print(solution(n, m, section))