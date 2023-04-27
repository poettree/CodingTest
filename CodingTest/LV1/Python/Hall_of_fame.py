#information
#Time = 
#Description: 

#Answer
def solution(k, score):
    #define
    Ranking = []
    notice = []


    #Main
    for i in score:
        Ranking.append(i)
        Ranking.sort()
        
        if(len(Ranking) > k):
            Ranking.pop(0)
        
        notice.append(Ranking[0])

        print(Ranking)

    return notice

#Test Code
k = 3
score = [10, 100, 20, 150, 1, 100, 200]
result = [10, 10, 10, 20, 20, 100, 100]

print(solution(k,score))